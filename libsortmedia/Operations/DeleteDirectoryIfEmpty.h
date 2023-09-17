///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteDirectoryIfEmpty.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This operation deletes a directory if it is empty at
//                  apply-time.
//
// CREATED:         09/09/2019
////

#ifndef __ET_OPERATIONS_DELETEDIRECTORYIFEMPTY__
#define __ET_OPERATIONS_DELETEDIRECTORYIFEMPTY__

#include <libsortmedia/namespaces/Operations.h>
#include <libsortmedia/Interfaces/IFileOperation.h>

#include <fsadaptor/namespace.h>
#include <fsadaptor/Path.h>

class SortMedia::Operations::DeleteDirectoryIfEmpty
  : public Interfaces::IFileOperation
{
public:
  // TODO: Take logger as shared_ptr
  DeleteDirectoryIfEmpty(FSAdaptor::Path directory,
                         Interfaces::ILogger& logger,
                         const FSAdaptor::IFilesystemAdaptor& = s_stdAdaptor);
  virtual void apply() final override;
  virtual void revert() final override;

private:
  FSAdaptor::Path m_directory;
  Interfaces::ILogger& m_logger;
  const FSAdaptor::IFilesystemAdaptor& m_adaptor;
  static const FSAdaptor::IFilesystemAdaptor& s_stdAdaptor;
};

#endif // __ET_OPERATIONS_DELETEDIRECTORYIFEMPTY__

///////////////////////////////////////////////////////////////////////////////
