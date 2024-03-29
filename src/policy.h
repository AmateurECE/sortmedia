#ifndef POLICY_H
#define POLICY_H

#include <cmath>
#include <filesystem>
#include <format>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>

#include "library.h"
#include "metadata.h"

/// The policy that dictates the final state of audio files in the library.
class AudioOrganizationPolicy : public ITransformLibraryFiles {
public:
  void apply(PendingCopyFileTransaction& transaction) final {
    TagLib::FileRef file{transaction.source_path().c_str()};

    auto artist{metadata::sanitize_token(file.tag()->artist().to8Bit(true))};
    auto album{metadata::sanitize_token(file.tag()->album().to8Bit(true))};

    metadata::NonStandardTags tags{file};
    auto track_total{tags.track_total().or_else(
        [&transaction]() -> std::optional<unsigned int> {
          return {track_total_heuristic(transaction)};
        })};
    auto alignment{static_cast<unsigned int>(std::log10(*track_total)) + 1};

    auto track_number{file.tag()->track()};
    auto name{metadata::sanitize_token(file.tag()->title().to8Bit(true))};
    auto extension{transaction.source_path().extension().string()};
    auto track{
        std::format("{:0>{}} {}{}", track_number, alignment, name, extension)};

    transaction.set_destination_path(
        std::filesystem::path(artist).append(album).append(track));
  }

private:
  /// Assume that all tracks in the collection are present in the directory
  /// that also contains our source file. This should provide enough
  /// granularity to calculate the alignment for the track number.
  static unsigned int
  track_total_heuristic(const PendingCopyFileTransaction& transaction) {
    // TODO
    return 10U;
  }
};

#endif // POLICY_H
