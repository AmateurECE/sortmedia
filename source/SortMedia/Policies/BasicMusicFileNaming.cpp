///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicFileNaming.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the BasicMusicFileNaming
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/11/2019
////

#include <SortMedia/Interfaces/IOrganizationalPolicy.h>
#include <SortMedia/Policies/BasicMusicFileNaming.h>
#include <SortMedia/Policies/DeleteDirectoryIfEmpty.h>

#include <FSAdaptor/Path.h>

SortMedia::Policies::BasicMusicFileNaming
::BasicMusicFileNaming(FileTypes::MusicFile path, Interfaces::ILogger& logger)
  : m_musicFile{std::move(path)}, m_logger{logger}
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>>
SortMedia::Policies::BasicMusicFileNaming
::getPostconditions()
{
  std::list<std::unique_ptr<Interfaces::IOrganizationalPolicy>> policies;
  policies.push_back(std::make_unique<DeleteDirectoryIfEmpty>
                     (m_musicFile.getPath(), m_logger));
  return policies;
}

///////////////////////////////////////////////////////////////////////////////
