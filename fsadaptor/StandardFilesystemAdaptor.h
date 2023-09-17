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
// LAST EDITED:     09/04/2019
////

#ifndef __ET_STANDARDFILESYSTEMADAPTOR__
#define __ET_STANDARDFILESYSTEMADAPTOR__

#include <fsadaptor/namespace.h>
#include <fsadaptor/IFilesystemAdaptor.h>

class FSAdaptor::StandardFilesystemAdaptor
  : public FSAdaptor::IFilesystemAdaptor
{
public:
  ~StandardFilesystemAdaptor() {};
  virtual void walk(IPathWalker& walker, const Path& directory)
    const final override;

  virtual bool isEmpty(const Path& p) const final override;
  virtual bool isDirectory(const Path& p) const final override;

  virtual void rename(const Path& oldPath, const Path& newPath)
    const final override;
  virtual void remove(const Path& p) const final override;
  virtual bool equivalent(const Path& p1, const Path& p2) const final override;
  virtual bool exists(const Path& p) const final override;
  virtual Path currentPath() const final override;
  virtual void createDirectory(const Path& p) const final override;
  virtual void createDirectories(const Path& p) const final override;
  virtual Path absolute(const Path& p) const final override;

private:
  // TODO: Move listDirectory to the public interface
  void listDirectory(IPathWalker& walker, const Path& directory) const;
};

#endif // __ET_STANDARDFILESYSTEMADAPTOR__

///////////////////////////////////////////////////////////////////////////////
