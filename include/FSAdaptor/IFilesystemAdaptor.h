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
// LAST EDITED:     09/03/2019
////

#ifndef __ET_IFILESYSTEMADAPTOR__
#define __ET_IFILESYSTEMADAPTOR__

#include <FSAdaptor/namespace.h>

#include <iterator>
#include <vector>

class FSAdaptor::IFilesystemAdaptor
{
public:
  virtual ~IFilesystemAdaptor() {};
  virtual std::iterator_traits<Path> walk(const Path& directory) const = 0;

  // Tests whether a given path points to an existing, empty file.
  virtual bool isEmpty(const Path& p) const                             = 0;
  // Tests whether a given path points to an existing directory.
  virtual bool isDirectory(const Path& p) const                         = 0;

  // Rename the file `oldPath' to the path pointed to by `newPath'
  virtual void rename(const Path& oldPath, const Path& newPath) const   = 0;
  // Remove the file from the filesystem and delete its contents.
  virtual void remove(const Path& p) const                              = 0;
  // Test whether two paths are equivalent.
  virtual bool equivalent(const Path& p1, const Path& p2) const         = 0;
  // Test whether the path `p' points to an existing location on the filesystem
  virtual bool exists(const Path& p) const                              = 0;
  // Return the current path.
  virtual Path currentPath() const                                      = 0;
  // Create a directory at the path pointed to by p.
  virtual void createDirectory(const Path& p) const                     = 0;
  // Create a directory at the path pointed to by p (and any intermediaries)
  virtual void createDirectories(const Path& p) const                   = 0;
  // If `p' starts with '.' or '..', expand to obtain the absolute path.
  virtual Path absolute(const Path& p) const                            = 0;
};

#endif // __ET_IFILESYSTEMADAPTOR__

///////////////////////////////////////////////////////////////////////////////
