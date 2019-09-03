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

// SortMedia headers
#include <SortMedia/Adaptors/StandardFilesystemAdaptor.h>
#include <SortMedia/Path.h>

// LibC++ headers
#include <stdexcept>
#include <system_error>

// LibC headers
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

static std::system_error makeSystemError(int error)
{
  return std::system_error{std::make_error_code(static_cast<std::errc>(error)),
      (const char*)strerror(error)};
}

std::iterator_traits<SortMedia::Path>
SortMedia::Adaptors::StandardFilesystemAdaptor
::walk(const SortMedia::Path& directory) const
{
  // TODO: Implement walk  
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::isEmpty(const SortMedia::Path& p) const
{
  struct stat path;
  memset(&path, 0, sizeof(path));

  errno = 0;
  if (stat(p.string().c_str(), &path))
    {
      throw makeSystemError(errno);
    }

  return 0 == path.st_size;
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::isDirectory(const SortMedia::Path& p) const
{
  struct stat path;
  memset(&path, 0, sizeof(path));
  errno = 0;
  if (stat(p.string().c_str(), &path))
    {
      throw makeSystemError(errno);
    }

  return S_ISDIR(path.st_mode);
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::exists(const SortMedia::Path& p) const
{
  return access(p.string().c_str(), F_OK) != -1;
}

void
SortMedia::Adaptors::StandardFilesystemAdaptor
::createDirectory(const SortMedia::Path& p) const
{
  errno = 0;
  if (mkdir(p.string().c_str(), 0777))
    {
      throw makeSystemError(errno);
    }
}

void
SortMedia::Adaptors::StandardFilesystemAdaptor
::createDirectories(const SortMedia::Path& p) const
{
  // TODO: Implement createDirectories
  // Push all paths back into a vector
  std::vector<Path> paths;
  paths.push_back(p);
  while (paths.front().parent_path().string() != p.root_path().string())
    {
      paths.push_back(paths.front().parent_path());
    }

  // Iterate backwards through them, creating a directory where one doesn't
  //   already exist.
  for (auto i = paths.rbegin(); i != paths.rend(); ++i)
    {
      if (!exists(*i))
        {
          createDirectory(*i);
        }
    }
}

bool
SortMedia::Adaptors::StandardFilesystemAdaptor
::equivalent(const SortMedia::Path& p1, const SortMedia::Path& p2) const
{
  struct stat s1, s2;
  memset(&s1, 0, sizeof(s1));
  memset(&s2, 0, sizeof(s2));

  errno = 0;
  if (stat(p1.string().c_str(), &s1)
      || stat(p2.string().c_str(), &s2))
    {
      throw makeSystemError(errno);
    }

  return s1.st_dev == s2.st_dev && s1.st_ino == s2.st_ino;
}

void
SortMedia::Adaptors::StandardFilesystemAdaptor
::remove(const SortMedia::Path& p) const
{
  errno = 0;
  if (::remove(p.string().c_str()))
    {
      throw makeSystemError(errno);
    }
}

SortMedia::Path
SortMedia::Adaptors::StandardFilesystemAdaptor
::absolute(const SortMedia::Path& p) const
{
  char absolutePath[PATH_MAX + 1];
  if (exists(p))
    {
      return Path{realpath(p.string().c_str(), absolutePath)};
    }

  throw std::invalid_argument{"path does not exist"};
}

SortMedia::Path
SortMedia::Adaptors::StandardFilesystemAdaptor
::currentPath() const
{
  char cwd[PATH_MAX + 1];
  return Path{getcwd(cwd, PATH_MAX)};
}

void
SortMedia::Adaptors::StandardFilesystemAdaptor
::rename(const SortMedia::Path& oldPath, const SortMedia::Path& newPath) const
{
  ::rename(oldPath.string().c_str(), newPath.string().c_str());
}

///////////////////////////////////////////////////////////////////////////////
