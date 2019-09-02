///////////////////////////////////////////////////////////////////////////////
// NAME:            StandardFilesystemAdaptor.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Standard Filesystem Adaptor.
//
// CREATED:         08/29/2019
//
// LAST EDITED:     09/02/2019
////

#include <SortMedia/Adaptors/StandardFilesystemAdaptor.h>
#include <SortMedia/Path.h>

std::iterator_traits<SortMedia::Path>
SortMedia::Adaptors::StandardFilesystemAdaptor
::walk(const SortMedia::Path& directory) const
{
  
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::isEmpty(const SortMedia::Path& p) const
{
  return false;
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::isDirectory(const SortMedia::Path& p) const
{
  return false;
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::exists(const SortMedia::Path& p) const
{
  return false;
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::createDirectory(const SortMedia::Path& p) const
{
  return false;
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::createDirectories(const SortMedia::Path& p) const
{
  return false;
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::equivalent(const SortMedia::Path& p1, const SortMedia::Path& p2) const
{
  return false;
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::remove(const SortMedia::Path& p) const
{}

SortMedia::Path
SortMedia::Adaptors::StandardFilesystemAdaptor
::absolute(const SortMedia::Path& p) const
{
  return {};
}

SortMedia::Path
SortMedia::Adaptors::StandardFilesystemAdaptor
::currentPath() const
{
  return {};
}

void
SortMedia::Adaptors::StandardFilesystemAdaptor
::rename(const SortMedia::Path& oldPath, const SortMedia::Path& newPath) const
{}

///////////////////////////////////////////////////////////////////////////////
