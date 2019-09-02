///////////////////////////////////////////////////////////////////////////////
// NAME:            Path.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition of the Path class.
//
// CREATED:         08/30/2019
//
// LAST EDITED:     09/02/2019
////

#include <SortMedia/Path.h>

#include <sstream>
#include <iterator>

const std::regex SortMedia::Path::s_filenameRegex{"(\\..+)$"};

// Format observers
std::string SortMedia::Path::string() const
{
  return join(m_components, s_sep);
}

// Decomposition
SortMedia::Path SortMedia::Path::filename() const
{
  return Path{m_components.back()};
}

SortMedia::Path SortMedia::Path::extension() const
{
  std::smatch results;
  if (m_components.back()[0] != '.' // Extension of hidden files is ""
      && std::regex_search(m_components.back(), results, s_filenameRegex))
    {
      return Path{results[0].str()};
    }
  return Path{""};
}

SortMedia::Path SortMedia::Path::parent_path() const
{}

std::string SortMedia::Path::join(const std::vector<std::string>& elements,
                                  const char *const delimiter) const
{
  std::ostringstream os;
  auto b = begin(elements), e = end(elements);

  if (b != e) {
    std::copy(b, prev(e), std::ostream_iterator<std::string>(os, delimiter));
    b = prev(e);
  }
  if (b != e) {
    os << *b;
  }

  return os.str();
}

std::vector<std::string> SortMedia::Path::split(char delimiter,
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
