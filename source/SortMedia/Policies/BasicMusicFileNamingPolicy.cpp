///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicFileNamingPolicy.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the BasicMusicFileNamingPolicy
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/06/2019
////

#include <SortMedia/Policies/BasicMusicFileNamingPolicy.h>

SortMedia::Policies::BasicMusicFileNamingPolicy
::BasicMusicFileNamingPolicy(const FSAdaptor::Path& path)
  : m_path{path}
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>>
SortMedia::Policies::BasicMusicFileNamingPolicy::getPrerequisites()
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::BasicMusicFileNamingPolicy::getOperations() const
{}

///////////////////////////////////////////////////////////////////////////////
