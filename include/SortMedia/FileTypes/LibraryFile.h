///////////////////////////////////////////////////////////////////////////////
// NAME:            LibraryFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     A class representing any file in the library.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/09/2019
////

#ifndef __ET_LIBRARYFILE__
#define __ET_LIBRARYFILE__

#include <namespaces/FileTypes.h>

#include <FSAdaptor/namespace.h>
#include <FSAdaptor/Path.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>

#include <memory>

class SortMedia::FileTypes::LibraryFile
{
public:
  LibraryFile(FSAdaptor::Path path,
              const FSAdaptor::IFilesystemAdaptor& adaptor
              = FSAdaptor::StandardFilesystemAdaptor{});
  LibraryFile(const LibraryFile&) = delete;
  LibraryFile(LibraryFile&&);
  LibraryFile& operator=(const LibraryFile&) = delete;

  void rename(const FSAdaptor::Path& path);
  void remove();
  const FSAdaptor::Path& getPath() const;

private:
  std::unique_ptr<FSAdaptor::Path> m_path;
  const FSAdaptor::IFilesystemAdaptor& m_adaptor;
};

#endif // __ET_LIBRARYFILE__

///////////////////////////////////////////////////////////////////////////////
