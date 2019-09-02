///////////////////////////////////////////////////////////////////////////////
// NAME:            StandardFilesystemAdaptor.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     The default Filesystem Adaptor. Used by SortMedia classes
//                  when not substituted with a mock impelementation.
//
// CREATED:         08/29/2019
//
// LAST EDITED:     09/02/2019
////

#ifndef __ET_STANDARDFILESYSTEMADAPTOR__
#define __ET_STANDARDFILESYSTEMADAPTOR__

#include <SortMedia/Interfaces/IFilesystemAdaptor.h>
#include <namespaces/Adaptors.h>

class SortMedia::Adaptors::StandardFilesystemAdaptor
  : public SortMedia::Interfaces::IFilesystemAdaptor
{
public:
  ~StandardFilesystemAdaptor() {};
  virtual std::iterator_traits<Path> walk(const Path& directory)
    const final override;

  // TODO: Test isEmpty
  virtual bool isEmpty(const Path& p) const final override;
  // TODO: Test isDirectory
  virtual bool isDirectory(const Path& p) const final override;

  // TODO: Test rename
  virtual void rename(const Path& oldPath, const Path& newPath)
    const final override;
  // TODO: Test remove
  virtual bool remove(const Path& p) const final override;
  // TODO: Test equivalent
  virtual bool equivalent(const Path& p1, const Path& p2) const final override;
  // TODO: Test exists
  virtual bool exists(const Path& p) const final override;
  // TODO: Test currentPath
  virtual Path currentPath() const final override;
  // TODO: Test createDirectory
  virtual bool createDirectory(const Path& p) const final override;
  // TODO: Test createDirectories
  virtual bool createDirectories(const Path& p) const final override;
  // TODO: Test absolute
  virtual Path absolute(const Path& p) const final override;
};

#endif // __ET_STANDARDFILESYSTEMADAPTOR__

///////////////////////////////////////////////////////////////////////////////
