#ifndef POLICY_H
#define POLICY_H

#include <cmath>
#include <filesystem>
#include <format>
#include <taglib/fileref.h>

/// The policy that dictates the final state of audio files in the library.
class AudioOrganizationPolicy {
public:
  std::filesystem::path
  get_compliant_path(const std::filesystem::directory_entry& entry) const {
    TagLib::FileRef file{entry.path().c_str()};

    // TODO: Need to run all metadata through a sanitizer to replace one or
    // more non [a-zA-Z0-9 ] with '_'
    auto artist{file.tag()->artist().to8Bit(true)};
    auto album{file.tag()->album().to8Bit(true)};

    auto track_number{file.tag()->track()};
    auto alignment{
        static_cast<unsigned int>(std::ceil(std::log10(track_number)))};
    auto name{file.tag()->title().to8Bit(true)};
    auto extension{entry.path().extension().string()};
    auto track{
        std::format("{:0>{}} {}{}", track_number, alignment, name, extension)};
    return {std::filesystem::path(artist).append(album).append(track)};
  }
};

#endif // POLICY_H
