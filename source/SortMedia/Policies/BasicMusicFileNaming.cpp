///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicFileNaming.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the BasicMusicFileNaming
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/10/2019
////

#include <SortMedia/Interfaces/IFileOperation.h>
#include <SortMedia/Policies/BasicMusicFileNaming.h>

SortMedia::Policies::BasicMusicFileNaming
::BasicMusicFileNaming(FileTypes::MusicFile&& path)
  : m_musicFile{std::move(path)}
{}

///////////////////////////////////////////////////////////////////////////////
