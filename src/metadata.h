#ifndef METADATA_H
#define METADATA_H

#include <filesystem>
#include <optional>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>
#include <variant>

#include "convert.h"

namespace metadata {
/// Replaces one or more "invalid characters" with a single underscore.
std::string sanitize_token(const std::string& input);

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
    if (auto extension{std::filesystem::path(file.file()->name()).extension()};
        extension == ".flac") {
      m_properties = {FlacProperties(map)};
    } else {
      m_properties = {Id3v2Properties(map)};
    }
  }

  std::optional<unsigned int> track_total() const {
    return total(Quantity::Track);
  }
  std::optional<unsigned int> disc_total() const {
    return total(Quantity::Disc);
  }

  std::optional<unsigned int> disc_number() const {
    return std::visit(
        overloaded{
            [](const FlacProperties& flac) {
              return get_property<unsigned int>(flac.properties, "DISCNUMBER");
            },
            [](const Id3v2Properties& id3v2) -> std::optional<unsigned int> {
              const auto property{
                  get_property<std::string>(id3v2.properties, "DISCNUMBER")};
              if (!property.has_value()) {
                return {};
              }

              if (auto slash{property->find("/")};
                  std::string::npos != slash) {
                return {
                    Into<unsigned int>::convert(property->substr(0, slash))};
              } else {
                return {Into<unsigned int>::convert(property)};
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
  using Properties = std::variant<FlacProperties, Id3v2Properties>;

  Properties m_properties;

  /// Obtain a "total" property from the map. "quantity" may either be "DISC",
  /// in which case, the total number of discs is returned, or it may be
  /// "TRACK", in which case the total number of tracks is returned.
  std::optional<unsigned int> total(Quantity value) const {
    auto quantity{Into<std::string>::convert(value)};
    return std::visit(
        overloaded{
            [&quantity](const FlacProperties& flac) {
              return get_property<unsigned int>(
                  flac.properties, std::string("TOTAL") + quantity + "S");
            },
            [quantity](
                const Id3v2Properties& id3v2) -> std::optional<unsigned int> {
              const auto property{get_property<std::string>(
                  id3v2.properties, quantity + "NUMBER")};
              if (!property.has_value()) {
                return {};
              }

              if (const auto& slash{property->find("/")};
                  std::string::npos == slash) {
                return {std::stoi(property->substr(slash + 1))};
              } else {
                return {};
              }
            },
        },
        m_properties);
  }

  template <ConvertibleFrom<std::string> T>
  static std::optional<T> get_property(const TagLib::PropertyMap& properties,
                                       const std::string& tag_name) {
    if (const auto& list{properties.value(tag_name)}; list.isEmpty()) {
      return {};
    } else {
      auto value{list.front().to8Bit(true)};
      return {Into<T>::convert(value)};
    }
  }
};
} // namespace metadata

#endif // METADATA_H
