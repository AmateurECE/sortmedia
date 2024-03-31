module;

#include <filesystem>
#include <functional>
#include <memory>
#include <regex>
#include <tag.h>
#include <taglib/fileref.h>
#include <variant>
#include <vector>

export module library;

using namespace std;
namespace fs = std::filesystem;

export namespace library {
/// An iterator over media files in a library. This iterator fulfills the
/// requirements of an input iterator, and is also a range type.
class LibraryFileIterator {
public:
  using difference_type = ptrdiff_t;
  using element_type = fs::directory_entry;
  using pointer = const element_type*;
  using reference = const element_type&;

  LibraryFileIterator(regex file_filter, string directory)
      : m_inner{fs::recursive_directory_iterator(directory)},
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
    return LibraryFileIterator(fs::end(fs::recursive_directory_iterator()));
  }

private:
  fs::recursive_directory_iterator m_inner;
  regex m_file_filter;

  LibraryFileIterator(fs::recursive_directory_iterator inner)
      : m_inner{inner}, m_file_filter{} {
    find_captured_element();
  }

  void find_captured_element() {
    const auto end{fs::end(fs::recursive_directory_iterator())};
    while (end != m_inner && !is_captured_element())
      ++m_inner;
  }

  bool is_captured_element() const {
    return m_inner->is_regular_file() &&
           regex_match(m_inner->path().c_str(), m_file_filter);
  }
};

static_assert(input_iterator<LibraryFileIterator>);

/// A regex builder for the MusicLibrary.
class FileFilterBuilder {
public:
  FileFilterBuilder& extension(const string& extension) {
    if (multiple_extensions) {
      m_regex += "|";
    } else {
      multiple_extensions = true;
    }

    m_regex += "\\." + extension;
    return *this;
  }

  regex build() const { return regex(string(".*(") + m_regex + ")$"); }

private:
  string m_regex;
  bool multiple_extensions;
};

/// A MusicLibrary is a tree of artifacts on disk that include music files,
/// their associated metadata, cover art images, and directory structures
/// that arbitrarily group music files together. The library yields an
/// iterator over the media files in the library.
class MusicLibrary {
public:
  MusicLibrary(string directory) : m_directory{directory} {}
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
  string m_directory;
};

/// A synchronization object that applies a number of mutations "atomically"
/// to a library file.
class PendingCopyFileTransaction {
public:
  PendingCopyFileTransaction(fs::path from_path)
      : m_from_path{from_path}, m_to_path{}, m_tag_callbacks{} {}

  void set_destination_path(fs::path to_path) { m_to_path = to_path; }

  const fs::path& source_path() const { return m_from_path; }

  void add_action(function<void(fs::path new_file)> action) {
    m_actions.push_back(action);
  }

  // TODO: Can this be passed as a reference instead?
  void set_tag(function<void(TagLib::Tag*)> callback) {
    m_tag_callbacks.push_back(callback);
  }

  /// Complete this transaction by copying the source path to the desination
  /// path within the library.
  void complete(fs::path library_path) {
    cout << "Importing " << m_to_path << "\n";
    fs::path full_path{library_path.append(m_to_path.c_str())};
    fs::create_directories(full_path.parent_path());
    fs::copy_file(m_from_path, full_path);

    // Apply all of the tag callbacks to the file.
    if (!m_tag_callbacks.empty()) {
      TagLib::FileRef file{full_path.c_str()};
      for (auto& callback : m_tag_callbacks) {
        callback(file.tag());
      }
      file.save();
    }

    for (auto& action : m_actions) {
      action(full_path);
    }
  }

private:
  fs::path m_from_path;
  fs::path m_to_path;
  vector<function<void(TagLib::Tag*)>> m_tag_callbacks;
  vector<function<void(fs::path)>> m_actions;
};

/// An exception type returned from policy application. This allows policies
/// to reject files because they don't meet the criteria required by the
/// library.
class InvalidFileError : public exception {
public:
  InvalidFileError(string message) : m_message{message} {}
  const char* what() const noexcept final { return m_message.c_str(); }

private:
  string m_message;
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
  using PolicyResult = variant<monostate, InvalidFileError>;
  virtual ~ITransformLibraryFiles() = 0;
  [[nodiscard]] virtual PolicyResult
  apply(PendingCopyFileTransaction& transaction) = 0;
};

/// Facilitates the creation of libraries by copying files from elsewhere
/// on the filesystem and applying policies to them.
class LibraryCreator {
public:
  LibraryCreator(fs::path root,
                 vector<unique_ptr<ITransformLibraryFiles>> transformations)
      : m_root{root}, m_transformations{std::move(transformations)} {}

  [[nodiscard]] ITransformLibraryFiles::PolicyResult
  add_file(const fs::directory_entry& file) {
    PendingCopyFileTransaction transaction{file.path()};
    for (auto& transformation : m_transformations) {
      auto result{transformation->apply(transaction)};
      if (holds_alternative<InvalidFileError>(result)) {
        return result;
      }
    }
    transaction.complete(m_root);
    return {monostate()};
  }

private:
  fs::path m_root;
  vector<unique_ptr<ITransformLibraryFiles>> m_transformations;
};
} // namespace library

using namespace library;

ITransformLibraryFiles::~ITransformLibraryFiles() = default;
