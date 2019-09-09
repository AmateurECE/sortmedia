///////////////////////////////////////////////////////////////////////////////
// NAME:            LibraryFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the LibraryFile class methods.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/09/2019
////

#include <SortMedia/FileTypes/LibraryFile.h>

#include <FSAdaptor/Path.h>

SortMedia::FileTypes::LibraryFile
::LibraryFile(FSAdaptor::Path path,
              const FSAdaptor::IFilesystemAdaptor& adaptor)
  : m_path{std::make_unique<FSAdaptor::Path>(path)}, m_adaptor(adaptor)
{}

SortMedia::FileTypes::LibraryFile
::LibraryFile(LibraryFile&& that)
  : m_path{std::move(that.m_path)}, m_adaptor{that.m_adaptor}
{}

void SortMedia::FileTypes::LibraryFile::rename(const FSAdaptor::Path& path)
{
  m_adaptor.rename(*m_path, path);
  m_path.reset();
  m_path = std::make_unique<FSAdaptor::Path>(path);
}

void SortMedia::FileTypes::LibraryFile::remove()
{
  m_adaptor.remove(*m_path);
  m_path.reset();
}

const FSAdaptor::Path& SortMedia::FileTypes::LibraryFile::getPath() const
{
  return *m_path;
}

///////////////////////////////////////////////////////////////////////////////
