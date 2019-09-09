///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteDirectoryIfEmpty.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the operation.
//
// CREATED:         09/09/2019
//
// LAST EDITED:     09/09/2019
////

#include <SortMedia/Operations/DeleteDirectoryIfEmpty.h>

#include <FSAdaptor/PathWalker.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>

#include <list>

const FSAdaptor::IFilesystemAdaptor&
SortMedia::Operations::DeleteDirectoryIfEmpty::s_stdAdaptor
= FSAdaptor::StandardFilesystemAdaptor{};

SortMedia::Operations::DeleteDirectoryIfEmpty
::DeleteDirectoryIfEmpty(FSAdaptor::Path directory,
                         const FSAdaptor::IFilesystemAdaptor& adaptor)
  : m_directory{directory}, m_adaptor{adaptor}
{}

void SortMedia::Operations::DeleteDirectoryIfEmpty::apply()
{
  if (m_adaptor.isDirectory(m_directory))
    {
      FSAdaptor::PathWalker<std::list> walker;
      m_adaptor.walk(walker, m_directory);
      if (0 == walker.getContainer().size())
        {
          m_adaptor.remove(m_directory);
        }
    }
}

void SortMedia::Operations::DeleteDirectoryIfEmpty::revert()
{
  m_adaptor.createDirectory(m_directory);
}

///////////////////////////////////////////////////////////////////////////////
