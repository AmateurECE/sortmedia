///////////////////////////////////////////////////////////////////////////////
// NAME:            MusicFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Encapsulates operations that a Music file may perform.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     03/31/2020
////

#ifndef __ET_MUSICFILE__
#define __ET_MUSICFILE__

#include <namespaces/Interfaces.h>
#include <namespaces/Adaptors.h>
#include <namespaces/FileTypes.h>
#include <SortMedia/Interfaces/IMusicTagEditorAdaptor.h>
#include <SortMedia/FileTypes/LibraryFile.h>

#include <FSAdaptor/namespace.h>

// A Music file is a superset of a library file
// (A Music file behaves like a library file)
class SortMedia::FileTypes::MusicFile
  : public SortMedia::FileTypes::LibraryFile
{
public:
  // TODO: Investigate whether it's necessary to take r-value ref to unique_ptr
  MusicFile(const FSAdaptor::Path& path,
            std::unique_ptr<Interfaces::IMusicTagEditorAdaptor>&& tagAdaptor,
            const FSAdaptor::IFilesystemAdaptor& fsAdaptor = s_stdAdaptor);
  MusicFile(const MusicFile&) = delete;
  MusicFile(MusicFile&&);
  MusicFile& operator=(const MusicFile&) = delete;

  Interfaces::IMusicTagEditorAdaptor& getTagEditor() const;

private:
  std::unique_ptr<Interfaces::IMusicTagEditorAdaptor> m_tagAdaptor;
  static const FSAdaptor::IFilesystemAdaptor& s_stdAdaptor;
};

#endif // __ET_MUSICFILE__

///////////////////////////////////////////////////////////////////////////////
