///////////////////////////////////////////////////////////////////////////////
// NAME:            Path.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition for a class representing a filesystem path. This
//                  class is a placeholder until C++17 filesystem library
//                  appears on my machine.
//
// CREATED:         08/30/2019
//
// LAST EDITED:     09/08/2019
////

#ifndef __ET_PATH__
#define __ET_PATH__

#include <FSAdaptor/namespace.h>

#include <iterator>
#include <regex>
#include <string>
#include <vector>

class FSAdaptor::Path
{
public:
  // Constructors
  Path() : Path{""} {}
  template<typename S>
  Path(const S& source)
    : m_components{split(*s_sep, normalizePath(std::string{source}))}
  {
    if (m_components.size() > 1 && m_components[0] == "")
      {
        m_components[0] = "/";
      }
  }

  // Format observers
  std::string string() const;

  // Decomposition
  Path extension() const;
  Path filename() const;
  Path parent_path() const;
  Path root_path() const;

  // Queries
  bool has_root_path() const; // TODO: Implement has_root_path
  bool has_filename() const; // TODO: Implement has_filename
  bool has_extension() const; // TODO: Implement has_extension

  // Operators
  // Concatenate two paths (without separator)
  Path operator+(const Path& that) const;
  Path operator+=(const Path& that) const; // TODO: Implement operator+=
  // Concatenate two paths (with separator)
  Path operator/(const Path& that) const;
  Path operator/=(const Path& that) const; // TODO: Implement operator/=
  // Equality
  bool operator==(const Path& that) const; // TODO: Implement operator==
  bool operator!=(const Path& that) const; // TODO: Implement operator!=

  // Iterators
  typedef PathConstIter const_iterator;
  const_iterator cbegin() const;
  const_iterator cend() const;

private:
  std::string join(const std::vector<std::string>::const_iterator& first,
                   const std::vector<std::string>::const_iterator& last,
                   const char *const delimiter) const;
  std::vector<std::string> split(char delimiter,
                                 const std::string& input) const;
  std::string normalizePath(std::string path) const;
  
  std::vector<std::string> m_components;
  static const std::regex s_filenameRegex;
  static const constexpr char* s_sep = "/";
};

std::ostream& operator<<(std::ostream& out, const FSAdaptor::Path& path);

class FSAdaptor::PathConstIter
  : public virtual std::iterator<std::input_iterator_tag, const Path>
{
public:
  PathConstIter() = delete;
  ~PathConstIter() {}
  PathConstIter(std::vector<std::string>::const_iterator);
  PathConstIter(const PathConstIter&);
  PathConstIter& operator=(const PathConstIter& that);
  PathConstIter& operator++();
  PathConstIter operator++(int);
  bool operator==(const PathConstIter& that) const;
  bool operator!=(const PathConstIter& that) const;
  const Path& operator*() const;

private:
  std::vector<std::string>::const_iterator m_iterator;
  Path m_element;
};

#endif // __ET_PATH__

///////////////////////////////////////////////////////////////////////////////
