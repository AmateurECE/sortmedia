///////////////////////////////////////////////////////////////////////////////
// NAME:            Path.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition of the Path class.
//
// CREATED:         08/30/2019
//
// LAST EDITED:     09/08/2019
////

#include <FSAdaptor/Path.h>

#include <sstream>
#include <iterator>

///////////////////////////////////////////////////////////////////////////////
// API Functions
////

// Format observers
std::string FSAdaptor::Path::string() const
{
  if (m_components[0] == "/")
    {
      return "/" + join(std::next(m_components.begin()),
                        m_components.end(), s_sep);
    }
  else
    {
      return join(m_components.begin(), m_components.end(), s_sep);
    }
}

// Decomposition
FSAdaptor::Path FSAdaptor::Path::filename() const
{
  return Path{m_components.back()};
}

FSAdaptor::Path FSAdaptor::Path::extension() const
{
  static const std::regex extensionRegex{"(\\.[^.]+)$"};
  std::smatch results;
  if (m_components.back()[0] != '.' // Extension of hidden files is ""
      && std::regex_search(m_components.back(), results, extensionRegex))
    {
      return Path{results[0].str()};
    }
  return Path{""};
}

FSAdaptor::Path FSAdaptor::Path::root_path() const
{
  if (m_components.front() == "/")
    {
      return Path{"/"};
    }

  return {};
}

FSAdaptor::Path FSAdaptor::Path::parent_path() const
{
  return Path{join(m_components.begin(), std::prev(m_components.end()),
                   s_sep)};
}

// Operators
FSAdaptor::Path FSAdaptor::Path::operator+(const FSAdaptor::Path& that) const
{
  return Path{join(this->m_components.begin(), this->m_components.end(), s_sep)
      + join(that.m_components.begin(), that.m_components.end(), s_sep)};
}

FSAdaptor::Path FSAdaptor::Path::operator/(const FSAdaptor::Path& that) const
{
  return Path{join(this->m_components.begin(), this->m_components.end(), s_sep)
      + s_sep
      + join(that.m_components.begin(), that.m_components.end(), s_sep)};
}

std::ostream& operator<<(std::ostream& out, const FSAdaptor::Path& that)
{
  out << that.string();
  return out;
}

FSAdaptor::Path& FSAdaptor::Path::operator+=(const Path& that)
{
  auto it = that.cbegin();
  m_components.back() += (*it).string();
  for (it = std::next(it); it != that.cend(); ++it)
    {
      m_components.push_back((*it).string());
    }
  return *this;
}

FSAdaptor::Path& FSAdaptor::Path::operator/=(const Path& that)
{
  if (m_components.back() == "")
    {
      m_components.back() = (*that.cbegin()).string();
    }
  else
    {
      m_components.push_back((*that.cbegin()).string());
    }

  for (auto it = std::next(that.cbegin()); it != that.cend(); ++it)
    {
      m_components.push_back((*it).string());
    }
  return *this;
}

bool FSAdaptor::Path::operator==(const Path& that) const
{
  if (m_components.size() != that.m_components.size())
    {
      return false;
    }

  for (size_t i = 0; i < m_components.size(); ++i)
    {
      if (m_components[i] != that.m_components[i])
        {
          return false;
        }
    }

  return true;
}

bool FSAdaptor::Path::operator!=(const Path& that) const
{
  return !operator==(that);
}

// Iterators
FSAdaptor::Path::const_iterator FSAdaptor::Path::cbegin() const
{
  return const_iterator{m_components.cbegin()};
}

FSAdaptor::Path::const_iterator FSAdaptor::Path::cend() const
{
  return const_iterator{m_components.cend()};
}

///////////////////////////////////////////////////////////////////////////////
// Private Functions
////

std::string FSAdaptor::Path::normalizePath(std::string path)
  const
{
  // 1. If the path is empty, stop (normal form of empty path is empty path)
  if (path == "") return path;

  // 2. Replace each directory-separator (which may consist of multiple
  //    slashes) with a single path::preferred_separator.
  static const std::regex multSep{std::string{s_sep} + "+"};
  path = std::regex_replace(path, multSep, "/");

  // 4. Remove each dot and any immediately following directory-separator.
  static const std::regex dotAtBegin{"^\\./"};
  path = std::regex_replace(path, dotAtBegin, "");
  static const std::regex dotInMiddle{"/\\./"};
  path = std::regex_replace(path, dotInMiddle, "/");

  // TODO: Implement tests and rest of normalizePath
  // 5. Remove each non-dot-dot filename immediately followed by a
  //    directory-separator and a dot-dot, along with any immediately following
  //    directory-separator.
  // 6. If there is root-directory, remove all dot-dots and any
  //    directory-separators immediately following them.
  // 7. If the last filename is dot-dot, remove any trailing
  //    directory-separator.
  // 8. If the path is empty, add a dot (normal form of ./ is .)

  return path;
}

std::string
FSAdaptor::Path::join(const std::vector<std::string>::const_iterator& first,
                      const std::vector<std::string>::const_iterator& last,
                      const char *const delimiter) const
{
  std::ostringstream os;

  if (first != last) {
    std::copy(first, prev(last),
              std::ostream_iterator<std::string>(os, delimiter));
    if (prev(last) != last)
      {
        os << *prev(last);
      }
  }

  return os.str();
}

std::vector<std::string> FSAdaptor::Path::split(char delimiter,
                                                const std::string& input) const
{
  using namespace std;
  vector<std::string> output;

  for (auto cur = begin(input), beg = cur; ; ++cur)
    {
      if (cur == end(input) || *cur == delimiter || !*cur)
        {
          output.insert(output.end(), std::string{beg, cur});

          if (cur == end(input) || !*cur)
            {
              break;                
            }
          else
            {
              beg = next(cur);                
            }
        }
    }

  return output;
}
///////////////////////////////////////////////////////////////////////////////
