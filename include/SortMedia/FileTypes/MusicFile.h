///////////////////////////////////////////////////////////////////////////////
// NAME:            MusicFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Encapsulates operations that a Music file may perform.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/05/2019
////

#ifndef __ET_MUSICFILE__
#define __ET_MUSICFILE__

#include <namespaces/Interfaces.h>
#include <namespaces/Adaptors.h>
#include <namespaces/FileTypes.h>
#include <SortMedia/FileTypes/LibraryFile.h>

#include <FSAdaptor/namespace.h>

// A Music file is a superset of a library file
// (A Music file behaves like a library file)
class SortMedia::FileTypes::MusicFile
  : public SortMedia::FileTypes::LibraryFile
{
public:
  MusicFile(const FSAdaptor::Path& path,
            std::unique_ptr<Interfaces::IMusicTagEditorAdaptor> tagAdaptor,
            const FSAdaptor::IFilesystemAdaptor& fsAdaptor
            = FSAdaptor::StandardFilesystemAdaptor{});
  Interfaces::IMusicTagEditorAdaptor& getTagEditor();

private:
  std::unique_ptr<Interfaces::IMusicTagEditorAdaptor> m_tagAdaptor;
};

#endif // __ET_MUSICFILE__

///////////////////////////////////////////////////////////////////////////////
