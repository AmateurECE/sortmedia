#ifndef POLICY_H
#define POLICY_H

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <format>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>
#include <unordered_map>

#include "library.h"
#include "metadata.h"

/// The policy that dictates the final state of audio files in the library.
class AudioOrganizationPolicy : public ITransformLibraryFiles {
public:
  void apply(PendingCopyFileTransaction& transaction) final {
    TagLib::FileRef file{transaction.source_path().c_str()};

    auto artist{metadata::sanitize_token(file.tag()->artist().to8Bit(true))};
    auto album{metadata::sanitize_token(file.tag()->album().to8Bit(true))};

    auto alignment{
        calculate_track_number_alignment(file, transaction.source_path())};
    auto track_number{file.tag()->track()};
    auto title{metadata::sanitize_token(file.tag()->title().to8Bit(true))};
    auto extension{transaction.source_path().extension().string()};
    auto track{std::format("{:0>{}} {}{}", track_number, alignment, title,
                           extension)};

    transaction.set_destination_path(
        std::filesystem::path(artist).append(album).append(track));
  }

private:
  static inline constexpr unsigned int MINIMUM_ALIGNMENT = 2;
  std::unordered_map<std::filesystem::path, unsigned int> m_track_total_cache;

  // Calculate the track number alignment. This is the number of digits that
  // should form the track number in the filename. Generally, it should be
  // of equal width for all tracks in the album.
  unsigned int
  calculate_track_number_alignment(const TagLib::FileRef& file,
                                   const std::filesystem::path& source_path) {
    metadata::NonStandardTags tags{file};
    auto track_total{tags.track_total().or_else(
        [this, &source_path]() -> std::optional<unsigned int> {
          return {track_total_heuristic(source_path)};
        })};
    return std::max(static_cast<unsigned int>(std::log10(*track_total)) + 1,
                    MINIMUM_ALIGNMENT);
  }

  /// Assume that all tracks in the collection are present in the directory
  /// that also contains our source file. This should provide enough
  /// granularity to calculate the alignment for the track number.
  unsigned int track_total_heuristic(const std::filesystem::path& file) {
    auto parent{file.parent_path()};

    // First, check if the cache contains the parent path of our file. If it
    // does, return the cached value.
    if (auto value{m_track_total_cache.find(parent)};
        value != m_track_total_cache.end()) {
      return value->second;
    }

    // If it doesn't, calculate the value as the number of files in the parent
    // directory with the same extension as our file.
    unsigned int count = 0;
    for (const auto& entry : std::filesystem::directory_iterator(parent)) {
      if (entry.path().extension() == file.extension()) {
        ++count;
      }
    }

    // Insert the calculated value into the cache for future queries.
    m_track_total_cache.insert({parent, count});
    return count;
  }
};

#endif // POLICY_H
