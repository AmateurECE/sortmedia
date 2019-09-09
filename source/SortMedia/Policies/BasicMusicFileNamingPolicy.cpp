///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicFileNamingPolicy.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the BasicMusicFileNamingPolicy
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/09/2019
////

#include <SortMedia/Interfaces/IFileOperation.h>
#include <SortMedia/Policies/BasicMusicFileNamingPolicy.h>

SortMedia::Policies::BasicMusicFileNamingPolicy
::BasicMusicFileNamingPolicy(FileTypes::MusicFile path)
  : m_musicFile{std::move(path)}
{}

///////////////////////////////////////////////////////////////////////////////
