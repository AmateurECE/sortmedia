///////////////////////////////////////////////////////////////////////////////
// NAME:            IFilesystemAdaptor.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     An adaptor class used to encapsulate all filesystem
//                  operations. The real purpose of this interface is to allow
//                  greater ease of mock development for testing.
//
// CREATED:         08/29/2019
//
// LAST EDITED:     09/02/2019
////

#ifndef __ET_IFILESYSTEMADAPTOR__
#define __ET_IFILESYSTEMADAPTOR__

#include <namespaces/SortMedia.h>
#include <namespaces/Interfaces.h>

#include <vector>

class SortMedia::Interfaces::IFilesystemAdaptor
{
public:
  virtual ~IFilesystemAdaptor() {};
  virtual std::iterator_traits<Path> walk(const Path& directory) const = 0;

  virtual bool isEmpty(const Path& p) const                             = 0;
  virtual bool isDirectory(const Path& p) const                         = 0;

  virtual void rename(const Path& oldPath, const Path& newPath) const   = 0;
  virtual bool remove(const Path& p) const                              = 0;
  virtual bool equivalent(const Path& p1, const Path& p2) const         = 0;
  virtual bool exists(const Path& p) const                              = 0;
  virtual Path currentPath() const                                      = 0;
  virtual bool createDirectory(const Path& p) const                     = 0;
  virtual bool createDirectories(const Path& p) const                   = 0;
  virtual Path absolute(const Path& p) const                            = 0;
};

#endif // __ET_IFILESYSTEMADAPTOR__

///////////////////////////////////////////////////////////////////////////////
