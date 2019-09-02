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
// LAST EDITED:     09/02/2019
////

#ifndef __ET_PATH__
#define __ET_PATH__

#include <namespaces/SortMedia.h>

#include <regex>
#include <string>
#include <vector>

class SortMedia::Path
{
public:
  // Constructors
  Path() : Path{""} {}
  template<typename S>
  Path(const S& source)
    : m_components{split(*s_sep, std::string{source})}
  {}

  // Format observers
  std::string string() const;

  // Decomposition
  Path filename() const;
  Path extension() const;
  Path parent_path() const;

private:
  std::string join(const std::vector<std::string>& elements,
                   const char *const delimiter) const;
  std::vector<std::string> split(char delimiter,
                                 const std::string& input) const;
  
  std::vector<std::string> m_components;
  static const std::regex s_filenameRegex;
  static const constexpr char* s_sep = "/";
};

#endif // __ET_PATH__

///////////////////////////////////////////////////////////////////////////////
