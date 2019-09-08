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

#include <FSAdaptor/Path.h>

FSAdaptor::PathConstIter
::PathConstIter(std::vector<std::string>::const_iterator iter)
  : m_iterator{iter}, m_element{*iter}
{}

FSAdaptor::PathConstIter::PathConstIter(const PathConstIter& that)
  : m_iterator{that.m_iterator}, m_element{that.m_element}
{}

const FSAdaptor::Path& FSAdaptor::PathConstIter::operator*() const
{
  return m_element;
}

FSAdaptor::PathConstIter& FSAdaptor::PathConstIter::operator++()
{
  m_iterator++;
  m_element = Path{*m_iterator};
  return *this;
}

FSAdaptor::PathConstIter FSAdaptor::PathConstIter::operator++(int)
{
  PathConstIter temp{*this};
  operator++();
  return temp;
}

FSAdaptor::PathConstIter&
FSAdaptor::PathConstIter::operator=(const PathConstIter& that)
{
  m_iterator = that.m_iterator;
  m_element = Path{that.m_element};
  return *this;
}

bool FSAdaptor::PathConstIter::operator==(const PathConstIter& that) const
{
  return m_iterator == that.m_iterator;
}

bool FSAdaptor::PathConstIter::operator!=(const PathConstIter& that) const
{
  return !operator==(that);
}

///////////////////////////////////////////////////////////////////////////////
