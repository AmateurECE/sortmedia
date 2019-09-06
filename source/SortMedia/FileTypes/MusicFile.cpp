///////////////////////////////////////////////////////////////////////////////
// NAME:            MusicFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definitions for the MusicFile methods.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/05/2019
////

#include <SortMedia/FileTypes/MusicFile.h>
#include <SortMedia/Interfaces/IMusicTagEditorAdaptor.h>

#include <FSAdaptor/Path.h>

SortMedia::FileTypes::MusicFile
::MusicFile(const FSAdaptor::Path& path,
            std::unique_ptr<Interfaces::IMusicTagEditorAdaptor> tagAdaptor,
            const FSAdaptor::IFilesystemAdaptor& fsAdaptor)
  : LibraryFile{path, fsAdaptor}, m_tagAdaptor{std::move(tagAdaptor)}
{}

SortMedia::Interfaces::IMusicTagEditorAdaptor&
SortMedia::FileTypes::MusicFile::getTagEditor()
{
  return *m_tagAdaptor;
}

///////////////////////////////////////////////////////////////////////////////
