///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This operation deletes a file.
//
// CREATED:         09/10/2019
////

#ifndef __ET_OPERATIONS_DELETEFILE__
#define __ET_OPERATIONS_DELETEFILE__

#include <libsortmedia/namespaces/Operations.h>
#include <libsortmedia/FileTypes/LibraryFile.h>
#include <libsortmedia/Interfaces/IFileOperation.h>

class SortMedia::Operations::DeleteFile
  : public Interfaces::IFileOperation
{
public:
  DeleteFile(FileTypes::LibraryFile file, Interfaces::ILogger& logger);

  virtual void apply() final override;
  virtual void revert() final override;

private:
  FileTypes::LibraryFile m_file;
  Interfaces::ILogger& m_logger;
};

#endif // __ET_OPERATIONS_DELETEFILE__

///////////////////////////////////////////////////////////////////////////////
