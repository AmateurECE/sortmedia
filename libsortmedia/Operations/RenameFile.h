///////////////////////////////////////////////////////////////////////////////
// NAME:            RenameFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Renames a file.
//
// CREATED:         09/11/2019
//
// LAST EDITED:     09/12/2019
////

#ifndef __ET_RENAMEFILE__
#define __ET_RENAMEFILE__

#include <libsortmedia/namespaces/Operations.h>
#include <libsortmedia/FileTypes/LibraryFile.h>
#include <libsortmedia/Interfaces/IFileOperation.h>

#include <FSAdaptor/Path.h>

class SortMedia::Operations::RenameFile
  : public Interfaces::IFileOperation
{
public:
  RenameFile(FileTypes::LibraryFile file, FSAdaptor::Path newName,
             Interfaces::ILogger& logger);

  virtual void apply() final override;
  virtual void revert() final override;

private:
  void doRename(FileTypes::LibraryFile& oldName,
                const FSAdaptor::Path& newName) const;

  FileTypes::LibraryFile m_file;
  FSAdaptor::Path m_newName;
  FSAdaptor::Path m_oldName;
  Interfaces::ILogger& m_logger;
};

#endif // __ET_RENAMEFILE__

///////////////////////////////////////////////////////////////////////////////
