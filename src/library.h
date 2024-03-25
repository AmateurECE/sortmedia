#ifndef LIBRARY_H
#define LIBRARY_H

#include <filesystem>
#include <regex>

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

/// A MusicLibrary is a tree of artifacts on disk that include music files,
/// their associated metadata, cover art images, and directory structures
/// that arbitrarily group music files together. The library yields an
/// iterator over the media files in the library.
class MusicLibrary {
public:
  MusicLibrary(std::string directory) : m_directory{directory} {}
  LibraryFileIterator begin() const {
    return {std::regex(".*\\.flac$"), m_directory};
  }
  LibraryFileIterator end() const { return LibraryFileIterator::end(); }

private:
  std::string m_directory;
};

#endif // LIBRARY_H
