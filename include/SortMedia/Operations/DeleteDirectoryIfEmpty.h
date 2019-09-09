///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteDirectoryIfEmpty.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This operation deletes a directory if it is empty at
//                  apply-time.
//
// CREATED:         09/09/2019
//
// LAST EDITED:     09/09/2019
////

#ifndef __ET_OPERATIONS_DELETEDIRECTORYIFEMPTY__
#define __ET_OPERATIONS_DELETEDIRECTORYIFEMPTY__

#include <namespaces/Operations.h>
#include <SortMedia/Interfaces/IFileOperation.h>

#include <FSAdaptor/namespace.h>
#include <FSAdaptor/Path.h>

class SortMedia::Operations::DeleteDirectoryIfEmpty
  : public Interfaces::IFileOperation
{
public:
  DeleteDirectoryIfEmpty(FSAdaptor::Path directory,
                         const FSAdaptor::IFilesystemAdaptor& = s_stdAdaptor);
  virtual void apply() final override;
  virtual void revert() final override;

private:
  FSAdaptor::Path m_directory;
  const FSAdaptor::IFilesystemAdaptor& m_adaptor;
  static const FSAdaptor::IFilesystemAdaptor& s_stdAdaptor;
};

#endif // __ET_OPERATIONS_DELETEDIRECTORYIFEMPTY__

///////////////////////////////////////////////////////////////////////////////
