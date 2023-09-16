///////////////////////////////////////////////////////////////////////////////
// NAME:            MusicFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Encapsulates operations that a Music file may perform.
//
// CREATED:         09/05/2019
////

#ifndef __ET_MUSICFILE__
#define __ET_MUSICFILE__

#include <libsortmedia/namespaces/Interfaces.h>
#include <libsortmedia/namespaces/Adaptors.h>
#include <libsortmedia/namespaces/FileTypes.h>
#include <libsortmedia/Interfaces/IMusicTagEditorAdaptor.h>
#include <libsortmedia/FileTypes/LibraryFile.h>

#include <FSAdaptor/namespace.h>

// A Music file is a superset of a library file
// (A Music file behaves like a library file)
class SortMedia::FileTypes::MusicFile
  : public SortMedia::FileTypes::LibraryFile
{
public:
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
