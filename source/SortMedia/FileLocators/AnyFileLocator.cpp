///////////////////////////////////////////////////////////////////////////////
// NAME:            AnyFileLocator.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Method definitions for the AnyFileLocator class.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/07/2019
////

#include <SortMedia/FileLocators/AnyFileLocator.h>

#include <FSAdaptor/Path.h>
#include <FSAdaptor/PathWalker.h>

const FSAdaptor::StandardFilesystemAdaptor
SortMedia::FileLocators::AnyFileLocator::s_stdAdaptor;

SortMedia::FileLocators::AnyFileLocator
::AnyFileLocator(const FSAdaptor::IFilesystemAdaptor& adaptor)
  : m_adaptor(adaptor)
{}

std::list<FSAdaptor::Path>
SortMedia::FileLocators::AnyFileLocator
::recursivelyListFilesInDirectory(const FSAdaptor::Path& directory) const
{
  FSAdaptor::PathWalker<std::list> pathWalker;
  m_adaptor.walk(pathWalker, directory);

  return std::list<FSAdaptor::Path>{pathWalker.getContainer()};
}

///////////////////////////////////////////////////////////////////////////////
