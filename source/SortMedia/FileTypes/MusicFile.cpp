///////////////////////////////////////////////////////////////////////////////
// NAME:            MusicFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definitions for the MusicFile methods.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/11/2019
////

#include <SortMedia/FileTypes/MusicFile.h>
#include <SortMedia/Interfaces/IMusicTagEditorAdaptor.h>

#include <FSAdaptor/Path.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>

const FSAdaptor::IFilesystemAdaptor&
SortMedia::FileTypes::MusicFile::s_stdAdaptor
= FSAdaptor::StandardFilesystemAdaptor{};

SortMedia::FileTypes::MusicFile
::MusicFile(const FSAdaptor::Path& path,
            std::unique_ptr<Interfaces::IMusicTagEditorAdaptor>&& tagAdaptor,
            const FSAdaptor::IFilesystemAdaptor& fsAdaptor)
  : LibraryFile{path, fsAdaptor}, m_tagAdaptor{std::move(tagAdaptor)}
{}

SortMedia::FileTypes::MusicFile::MusicFile(MusicFile&& that)
  : LibraryFile{that}, m_tagAdaptor{std::move(that.m_tagAdaptor)}
{}

SortMedia::Interfaces::IMusicTagEditorAdaptor&
SortMedia::FileTypes::MusicFile::getTagEditor() const
{
  return *m_tagAdaptor;
}

///////////////////////////////////////////////////////////////////////////////
