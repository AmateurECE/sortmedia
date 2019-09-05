///////////////////////////////////////////////////////////////////////////////
// NAME:            Path.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition of the Path class.
//
// CREATED:         08/30/2019
//
// LAST EDITED:     09/05/2019
////

#include <FSAdaptor/Path.h>

#include <sstream>
#include <iterator>

const std::regex FSAdaptor::Path::s_filenameRegex{"(\\..+)$"};

///////////////////////////////////////////////////////////////////////////////
// API Functions
////

// Format observers
std::string FSAdaptor::Path::string() const
{
  return join(m_components.begin(), m_components.end(), s_sep);
}

// Decomposition
FSAdaptor::Path FSAdaptor::Path::filename() const
{
  return Path{m_components.back()};
}

FSAdaptor::Path FSAdaptor::Path::extension() const
{
  std::smatch results;
  if (m_components.back()[0] != '.' // Extension of hidden files is ""
      && std::regex_search(m_components.back(), results, s_filenameRegex))
    {
      return Path{results[0].str()};
    }
  return Path{""};
}

FSAdaptor::Path FSAdaptor::Path::root_path() const
{
  if (m_components.front() == "."
      || m_components.front() == "..")
    {
      return {};
    }

  return Path{s_sep};
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

///////////////////////////////////////////////////////////////////////////////
// Private Functions
////

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
