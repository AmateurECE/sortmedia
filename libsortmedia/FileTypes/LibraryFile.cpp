///////////////////////////////////////////////////////////////////////////////
// NAME:            LibraryFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the LibraryFile class methods.
//
// CREATED:         09/05/2019
////

#include <libsortmedia/FileTypes/LibraryFile.h>

#include <fsadaptor/Path.h>
#include <fsadaptor/StandardFilesystemAdaptor.h>

const FSAdaptor::IFilesystemAdaptor&
SortMedia::FileTypes::LibraryFile::s_stdAdaptor
= FSAdaptor::StandardFilesystemAdaptor{};

SortMedia::FileTypes::LibraryFile
::LibraryFile(const FSAdaptor::Path& path,
              const FSAdaptor::IFilesystemAdaptor& adaptor)
  : m_path{path}, m_adaptor{adaptor}
{}

void SortMedia::FileTypes::LibraryFile::rename(const FSAdaptor::Path& path)
{
  m_adaptor.createDirectories(path.parent_path());
  m_adaptor.rename(m_path, path);
  m_path = FSAdaptor::Path{path};
}

void SortMedia::FileTypes::LibraryFile::remove()
{
  m_adaptor.remove(m_path);
}

const FSAdaptor::Path& SortMedia::FileTypes::LibraryFile::getPath() const
{
  return m_path;
}

///////////////////////////////////////////////////////////////////////////////
