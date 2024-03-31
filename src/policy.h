#ifndef POLICY_H
#define POLICY_H

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <format>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>
#include <unordered_map>
#include <unordered_set>

#include "library.h"
#include "metadata.h"

/// The policy that dictates the final state of audio files in the library.
class AudioOrganizationPolicy : public ITransformLibraryFiles {
public:
  PolicyResult apply(PendingCopyFileTransaction& transaction) final {
    TagLib::FileRef file{transaction.source_path().c_str()};

    // Compose the filename using the artist, album, and track metadata.
    const auto artist{
        metadata::sanitize_token(file.tag()->artist().to8Bit(true))};
    const auto album{
        metadata::sanitize_token(file.tag()->album().to8Bit(true))};

    const auto alignment{
        calculate_track_number_alignment(file, transaction.source_path())};
    const auto track_number{file.tag()->track()};
    const auto title{
        metadata::sanitize_token(file.tag()->title().to8Bit(true))};
    const auto extension{transaction.source_path().extension().string()};
    auto track{std::format("{:0>{}} {}{}", track_number, alignment, title,
                           extension)};

    // Add disc number only if disc_total and disc_number are set.
    metadata::NonStandardTags tags{file};
    const auto disc_number{tags.disc_number()};
    const auto disc_total{tags.disc_total()};
    if (disc_number.has_value() && disc_total.has_value()) {
      const auto disc_alignment{std::log10(*disc_total) + 1};
      track = std::format("{:0>{}}{}", *disc_number, disc_alignment, track);
    }

    transaction.set_destination_path(
        std::filesystem::path(artist).append(album).append(track));
    return {std::monostate()};
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

/// This policy ensures that all tracks are associated with image metadata.
/// This could be embedded in the audio file itself, or as a standalone image
/// file adjacent to the audio file.
class ImagePresencePolicy : public ITransformLibraryFiles {
public:
  PolicyResult apply(PendingCopyFileTransaction& transaction) final {
    // First check to see if this policy has already copied artwork for
    // this collection by checking the cache. The heuristic we apply assumes
    // that the artwork in the source directory corresponds to the entire
    // collection, and only that collection.
    auto source_directory{transaction.source_path().parent_path()};
    if (m_collection_cache.contains(source_directory)) {
      return {std::monostate()};
    }

    // If the image has embedded metadata, we don't need to take any action.
    auto image_detector{
        metadata::ImageDetector::make(transaction.source_path())};
    if (image_detector.has_value() && image_detector->has_image()) {
      return {std::monostate()};
    }

    // Copy artwork from the source directory, if it exists, by
    // attaching a copy action to the transaction.
    static const auto artwork_filenames{known_artwork_filenames()};
    for (const auto& filename : artwork_filenames) {
      auto art{std::filesystem::path(source_directory).append(filename)};
      if (std::filesystem::exists(art)) {
        transaction.add_action([art](std::filesystem::path file) {
          auto destination{file.append(art.filename().c_str())};
          std::cout << art.filename() << "\n";
          std::filesystem::copy_file(art, destination);
        });
        m_collection_cache.insert(source_directory);
        return {std::monostate()};
      }
    }

    return {InvalidFileError{std::format(
        "{} does not contain embedded image data and {} does "
        "not contain any images that appear to be cover art.",
        transaction.source_path().c_str(), source_directory.c_str())}};
  }

private:
  std::unordered_set<std::filesystem::path> m_collection_cache;

  static std::vector<std::string> known_artwork_filenames() {
    static const std::vector<std::string> extensions = {".jpg", ".png"};
    static const std::vector<std::string> filenames = {"folder", "poster",
                                                       "cover", "default"};
    std::vector<std::string> result;
    for (auto filename : filenames) {
      for (const auto& extension : extensions) {
        result.push_back(filename + extension);
      }
    }
    return result;
  }
};

#endif // POLICY_H
