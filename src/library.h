#ifndef LIBRARY_H
#define LIBRARY_H

#include <filesystem>
#include <functional>
#include <memory>
#include <regex>
#include <tag.h>
#include <taglib/fileref.h>
#include <vector>

/// An iterator over media files in a library. This iterator fulfills the
/// requirements of an input iterator, and is also a range type.
class LibraryFileIterator {
public:
  using difference_type = std::ptrdiff_t;
  using element_type = std::filesystem::directory_entry;
  using pointer = const element_type*;
  using reference = const element_type&;

  LibraryFileIterator(std::regex file_filter, std::string directory)
      : m_inner{std::filesystem::recursive_directory_iterator(directory)},
        m_file_filter{file_filter} {
    find_captured_element();
  }

  reference operator*() const { return *m_inner; }
  LibraryFileIterator& operator++() {
    ++m_inner;
    find_captured_element();
    return *this;
  }
  LibraryFileIterator operator++(int) {
    LibraryFileIterator temp = *this;
    ++(*this);
    return temp;
  }
  bool operator==(const LibraryFileIterator& that) const {
    return m_inner == that.m_inner;
  }
  bool operator!=(const LibraryFileIterator& that) const {
    return !(m_inner == that.m_inner);
  }

  static LibraryFileIterator end() noexcept {
    return LibraryFileIterator(
        std::filesystem::end(std::filesystem::recursive_directory_iterator()));
  }

private:
  std::filesystem::recursive_directory_iterator m_inner;
  std::regex m_file_filter;

  LibraryFileIterator(std::filesystem::recursive_directory_iterator inner)
      : m_inner{inner}, m_file_filter{} {
    find_captured_element();
  }

  void find_captured_element() {
    const auto end{
        std::filesystem::end(std::filesystem::recursive_directory_iterator())};
    while (end != m_inner && !is_captured_element())
      ++m_inner;
  }

  bool is_captured_element() const {
    return m_inner->is_regular_file() &&
           std::regex_match(m_inner->path().c_str(), m_file_filter);
  }
};

static_assert(std::input_iterator<LibraryFileIterator>);

/// A regex builder for the MusicLibrary.
class FileFilterBuilder {
public:
  FileFilterBuilder& extension(const std::string& extension) {
    if (multiple_extensions) {
      m_regex += "|";
    } else {
      multiple_extensions = true;
    }

    m_regex += "\\." + extension;
    return *this;
  }

  std::regex build() const {
    return std::regex(std::string(".*(") + m_regex + ")$");
  }

private:
  std::string m_regex;
  bool multiple_extensions;
};

/// A MusicLibrary is a tree of artifacts on disk that include music files,
/// their associated metadata, cover art images, and directory structures
/// that arbitrarily group music files together. The library yields an
/// iterator over the media files in the library.
class MusicLibrary {
public:
  MusicLibrary(std::string directory) : m_directory{directory} {}
  LibraryFileIterator begin() const {
    auto regex{FileFilterBuilder()
                   .extension("flac")
                   .extension("mp3")
                   .extension("m4a")
                   .build()};
    return {regex, m_directory};
  }
  LibraryFileIterator end() const { return LibraryFileIterator::end(); }

private:
  std::string m_directory;
};

/// A synchronization object that applies a number of mutations "atomically"
/// to a library file.
class PendingCopyFileTransaction {
public:
  PendingCopyFileTransaction(std::filesystem::path from_path)
      : m_from_path{from_path}, m_to_path{}, m_tag_callbacks{} {}

  void set_destination_path(std::filesystem::path to_path) {
    m_to_path = to_path;
  }

  const std::filesystem::path& source_path() const { return m_from_path; }

  // TODO: Can this be passed as a reference instead?
  void set_tag(std::function<void(TagLib::Tag*)> callback) {
    m_tag_callbacks.push_back(callback);
  }

  /// Complete this transaction by copying the source path to the desination
  /// path within the library.
  void complete(std::filesystem::path library_path) {
    std::cout << "Importing " << m_to_path << "\n";
    std::filesystem::path full_path{library_path.append(m_to_path.c_str())};
    std::filesystem::create_directories(full_path.parent_path());
    std::filesystem::copy_file(m_from_path, full_path);

    // Apply all of the tag callbacks to the file.
    TagLib::FileRef file{full_path.c_str()};
    for (auto& callback : m_tag_callbacks) {
      callback(file.tag());
    }
  }

private:
  std::filesystem::path m_from_path;
  std::filesystem::path m_to_path;
  std::vector<std::function<void(TagLib::Tag*)>> m_tag_callbacks;
};

/// A transformation that's applied to library files upon their creation
/// in a library. Used primarily to implement policies about library
/// organization. A transformation is responsible for:
/// * Validating a file's metadata to ensure that it provides enough fidelity
///   to apply the policy
/// * Participating in the setup of a "transaction," which may include any
///   number of operations on a file or its audio metadata in an atomic
///   fashion.
/// * Enforcing library-wide and collection-wide policies and implementing
///   heuristics as-necessary to enforce them. E.g, "every album folder shall
///   have artwork, whether in the audio files themselves or as a separate
///   file" or, "set the value of TOTALTRACKS to be the number of files in the
///   directory, if TOTALTRACKS is unset" etc.
class ITransformLibraryFiles {
public:
  virtual ~ITransformLibraryFiles() = 0;
  virtual void apply(PendingCopyFileTransaction& transaction) = 0;
};

/// Facilitates the creation of libraries by copying files from elsewhere
/// on the filesystem and applying policies to them.
class LibraryCreator {
public:
  LibraryCreator(
      std::filesystem::path root,
      std::vector<std::unique_ptr<ITransformLibraryFiles>> transformations)
      : m_root{root}, m_transformations{std::move(transformations)} {}

  void add_file(const std::filesystem::directory_entry& file) {
    PendingCopyFileTransaction transaction{file.path()};
    for (auto& transformation : m_transformations) {
      transformation->apply(transaction);
    }
    transaction.complete(m_root);
  }

private:
  std::filesystem::path m_root;
  std::vector<std::unique_ptr<ITransformLibraryFiles>> m_transformations;
};

#endif // LIBRARY_H
