///////////////////////////////////////////////////////////////////////////////
// NAME:            PathConstIter.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#include <fsadaptor/Path.h>

FSAdaptor::Path::PathConstIter
::PathConstIter(std::vector<std::string>::const_iterator iter)
  : m_iterator{iter}
{}

FSAdaptor::Path::PathConstIter::PathConstIter(const PathConstIter& that)
  : m_iterator{that.m_iterator}
{}

FSAdaptor::Path FSAdaptor::Path::PathConstIter::operator*() const
{
  return Path{*m_iterator};
}

FSAdaptor::Path::PathConstIter& FSAdaptor::Path::PathConstIter::operator++()
{
  m_iterator++;
  return *this;
}

FSAdaptor::Path::PathConstIter FSAdaptor::Path::PathConstIter::operator++(int)
{
  PathConstIter temp{*this};
  operator++();
  return temp;
}

FSAdaptor::Path::PathConstIter&
FSAdaptor::Path::PathConstIter::operator=(const PathConstIter& that)
{
  m_iterator = that.m_iterator;
  return *this;
}

bool FSAdaptor::Path::PathConstIter::operator==(const PathConstIter& that) const
{
  return m_iterator == that.m_iterator;
}

bool FSAdaptor::Path::PathConstIter::operator!=(const PathConstIter& that) const
{
  return !operator==(that);
}

///////////////////////////////////////////////////////////////////////////////
