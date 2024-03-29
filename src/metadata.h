#ifndef METADATA_H
#define METADATA_H

#include <filesystem>
#include <optional>
#include <regex>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>
#include <variant>

#include "convert.h"

namespace metadata {
/// Replaces one or more "invalid characters" with a single underscore.
std::string sanitize_token(const std::string& input) {
  static const std::regex disallowed_characters{"[^A-Za-z0-9 ()\\[\\]]+"};
  return std::regex_replace(input, disallowed_characters, "_");
}

class NonStandardTags {
private:
  template <class... Ts> struct overloaded : Ts... {
    using Ts::operator()...;
  };
  template <class> inline static constexpr bool always_false_v = false;

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
    return std::visit(
        overloaded{
            [](const FlacProperties& flac) {
              return get_property<unsigned int>(flac.properties,
                                                "TOTALTRACKS");
            },
            [](const Id3v2Properties& id3v2) -> std::optional<unsigned int> {
              const auto property{
                  get_property<std::string>(id3v2.properties, "TRACKNUMBER")};
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

private:
  struct FlacProperties {
    TagLib::PropertyMap properties;
  };
  struct Id3v2Properties {
    TagLib::PropertyMap properties;
  };
  using Properties = std::variant<FlacProperties, Id3v2Properties>;

  Properties m_properties;

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
