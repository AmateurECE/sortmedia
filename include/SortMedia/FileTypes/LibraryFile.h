///////////////////////////////////////////////////////////////////////////////
// NAME:            LibraryFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     A class representing any file in the library.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/10/2019
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
  LibraryFile(const FSAdaptor::Path& path,
              const FSAdaptor::IFilesystemAdaptor& adaptor = s_stdAdaptor);

  void rename(const FSAdaptor::Path& path);
  void remove();
  const FSAdaptor::Path& getPath() const;

private:
  FSAdaptor::Path m_path;
  const FSAdaptor::IFilesystemAdaptor& m_adaptor;
  static const FSAdaptor::IFilesystemAdaptor& s_stdAdaptor;
};

#endif // __ET_LIBRARYFILE__

///////////////////////////////////////////////////////////////////////////////
