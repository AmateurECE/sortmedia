module;

#include <filesystem>
#include <memory>
#include <optional>
#include <regex>
#include <stdexcept>
#include <string>
#include <taglib/apetag.h>
#include <taglib/fileref.h>
#include <taglib/flacfile.h>
#include <taglib/id3v2tag.h>
#include <taglib/mp4file.h>
#include <taglib/mpegfile.h>
#include <taglib/tpropertymap.h>
#include <variant>

export module metadata;

import convert;

namespace fs = std::filesystem;
using namespace std;
using namespace convert;

export namespace metadata {
/// Replaces one or more "invalid characters" with a single underscore.
string sanitize_token(const string& input);

class NonStandardTags {
private:
  template <class... Ts> struct overloaded : Ts... {
    using Ts::operator()...;
  };

  enum class Quantity {
    Disc,
    Track,
  };

  friend struct From<Quantity>;

public:
  NonStandardTags(const TagLib::FileRef& file) {
    TagLib::PropertyMap map = file.file()->properties();
    map.removeEmpty();
    if (auto extension{fs::path(file.file()->name()).extension()};
        extension == ".flac") {
      m_properties = {FlacProperties(map)};
    } else {
      m_properties = {Id3v2Properties(map)};
    }
  }

  optional<unsigned int> track_total() const { return total(Quantity::Track); }
  optional<unsigned int> disc_total() const { return total(Quantity::Disc); }

  optional<unsigned int> disc_number() const {
    return std::visit(
        overloaded{
            [](const FlacProperties& flac) {
              return get_property<unsigned int>(flac.properties, "DISCNUMBER");
            },
            [](const Id3v2Properties& id3v2) -> optional<unsigned int> {
              const auto property{
                  get_property<string>(id3v2.properties, "DISCNUMBER")};
              if (!property.has_value()) {
                return {};
              }

              if (auto slash{property->find("/")}; string::npos != slash) {
                return {
                    Into<unsigned int>::convert(property->substr(0, slash))};
              } else {
                return {Into<unsigned int>::convert(*property)};
              }
            },
        },
        m_properties);
  }

private:
  struct FlacProperties {
    TagLib::PropertyMap properties;
  };
  struct Id3v2Properties {
    TagLib::PropertyMap properties;
  };
  using Properties = variant<FlacProperties, Id3v2Properties>;

  Properties m_properties;

  /// Obtain a "total" property from the map. "quantity" may either be "DISC",
  /// in which case, the total number of discs is returned, or it may be
  /// "TRACK", in which case the total number of tracks is returned.
  optional<unsigned int> total(Quantity value) const {
    auto quantity{Into<string>::convert(value)};
    return std::visit(
        overloaded{
            [&quantity](const FlacProperties& flac) {
              return get_property<unsigned int>(
                  flac.properties, string("TOTAL") + quantity + "S");
            },
            [quantity](
                const Id3v2Properties& id3v2) -> optional<unsigned int> {
              const auto property{
                  get_property<string>(id3v2.properties, quantity + "NUMBER")};
              if (!property.has_value()) {
                return {};
              }

              if (const auto& slash{property->find("/")};
                  string::npos == slash) {
                return {std::stoi(property->substr(slash + 1))};
              } else {
                return {};
              }
            },
        },
        m_properties);
  }

  template <ConvertibleFrom<string> T>
  static optional<T> get_property(const TagLib::PropertyMap& properties,
                                  const string& tag_name) {
    if (const auto& list{properties.value(tag_name)}; list.isEmpty()) {
      return {};
    } else {
      auto value{list.front().to8Bit(true)};
      return {Into<T>::convert(value)};
    }
  }
};

/// Detects embedded cover art in audio files.
class ImageDetector {
public:
  static optional<ImageDetector> make(fs::path path) {
    string extension{path.extension().c_str()};

    if (extension == ".mp3") {
      auto file{make_unique<TagLib::MPEG::File>(path.c_str())};
      if (file->hasAPETag()) {
        return {ImageDetector{Image{APEv2Image{std::move(file)}}}};
      } else if (file->hasID3v1Tag()) {
        return {ImageDetector{Image{ID3v1Image{}}}};
      } else if (file->hasID3v2Tag()) {
        return {ImageDetector{Image{ID3v2Image{std::move(file)}}}};
      } else {
        return {};
      }
    } else if (extension == ".m4a") {
      return {ImageDetector{
          Image{Mp4Image{make_unique<TagLib::MP4::File>(path.c_str())}}}};
    } else if (extension == ".flac") {
      return {ImageDetector{
          Image{FlacImage{make_unique<TagLib::FLAC::File>(path.c_str())}}}};
    } else {
      return {};
    }
  }

  bool has_image() const {
    return std::visit([](const auto& image) { return image.has_image(); },
                      m_image);
  }

private:
  struct FlacImage {
    unique_ptr<TagLib::FLAC::File> file;
    bool has_image() const { return !file->pictureList().isEmpty(); }
  };
  struct APEv2Image {
    unique_ptr<TagLib::MPEG::File> file;
    bool has_image() const {
      // APEv2 embedded pictures may appear under a number of keys,
      // all of which start with "Cover Art". See:
      // https://wiki.hydrogenaud.io/index.php?title=Tag_Mapping#Ape_pictures
      for (const auto& item : file->APETag()->itemListMap()) {
        if (item.first.startsWith("Cover Art")) {
          return true;
        }
      }

      return false;
    }
  };
  struct ID3v2Image {
    unique_ptr<TagLib::MPEG::File> file;
    bool has_image() const {
      return !file->ID3v2Tag()->frameListMap()["APIC"].isEmpty();
    }
  };
  struct ID3v1Image {
    // ID3v1 does not support embedded cover art.
    bool has_image() const { return false; }
  };
  struct Mp4Image {
    unique_ptr<TagLib::MP4::File> file;
    bool has_image() const { return file->tag()->itemMap().contains("covr"); };
  };
  using Image =
      variant<FlacImage, APEv2Image, ID3v1Image, ID3v2Image, Mp4Image>;

  ImageDetector(Image image) : m_image{std::move(image)} {}

  Image m_image;
};
} // namespace metadata

using namespace std;
using namespace metadata;

template <>
template <>
string From<NonStandardTags::Quantity>::convert<string>(
    NonStandardTags::Quantity quantity) {
  switch (quantity) {
  case NonStandardTags::Quantity::Track:
    return "TRACK";
  case NonStandardTags::Quantity::Disc:
    return "DISC";
  default:
    throw runtime_error{"non-exhaustive conversion"};
  }
}

string metadata::sanitize_token(const string& input) {
  static const regex disallowed_characters{"[^A-Za-z0-9 ()\\[\\]]+"};
  return regex_replace(input, disallowed_characters, "_");
}
