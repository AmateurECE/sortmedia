///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicOrganizationalSchema.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Basic Music Organizational Schema.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/06/2019
////

#include <SortMedia/Schemas/BasicMusicOrganizationalSchema.h>

#include <SortMedia/Policies/UnknownFileTypePolicy.h>
#include <SortMedia/Policies/BasicMusicFileNamingPolicy.h>

SortMedia::Schemas::BasicMusicOrganizationalPolicy
::BasicMusicOrganizationalPolicy(const ILogger& logger)
  : m_logger(logger)
{}

std::unique_ptr<Interfaces::IOrganizationalPolicy>
SortMedia::Schemas::BasicMusicOrganizationalPolicy
::makeOrganizer(const FSAdaptor::Path& path) const
{
  std::unique_ptr<Interfaces::IOrganizationalPolicy> policy;
  if (path.extension().string() == ".flac"
      || path.extension().string() == ".m4a"
      || path.extension().string() == ".mp3")
    {
      policy = std::make_unique<BasicMusicFileNamingPolicy>(path);
    }
  else
    {
      policy = std::make_unique<UnknownFileTypePolicy>(path, m_logger);
    }

  return policy;
}


///////////////////////////////////////////////////////////////////////////////
