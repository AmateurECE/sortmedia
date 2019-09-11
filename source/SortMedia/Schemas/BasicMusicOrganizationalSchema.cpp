///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicOrganizationalSchema.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Basic Music Organizational Schema.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/11/2019
////

#include <SortMedia/Schemas/BasicMusicOrganizationalSchema.h>

#include <SortMedia/Adaptors/TagLibAdaptor.h>
#include <SortMedia/FileTypes/MusicFile.h>
#include <SortMedia/Policies/BasicMusicFileNaming.h>
#include <SortMedia/Policies/DeleteDirectoryIfEmpty.h>
#include <SortMedia/Policies/DeleteFile.h>
#include <SortMedia/Policies/DoNothing.h>
#include <SortMedia/Policies/UnknownFileType.h>

#include <FSAdaptor/IFilesystemAdaptor.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>
#include <FSAdaptor/Path.h>

const FSAdaptor::IFilesystemAdaptor&
SortMedia::Schemas::BasicMusicOrganizationalSchema::s_stdAdaptor
= FSAdaptor::StandardFilesystemAdaptor{};

SortMedia::Schemas::BasicMusicOrganizationalSchema
::BasicMusicOrganizationalSchema(Interfaces::ILogger& logger,
                                 const FSAdaptor::IFilesystemAdaptor& adaptor)
  : m_logger(logger), m_adaptor(adaptor)
{}

std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>
SortMedia::Schemas::BasicMusicOrganizationalSchema
::makeOrganizer(const FSAdaptor::Path& path) const
{
  std::unique_ptr<Interfaces::IOrganizationalPolicy> policy;
  std::string extension = path.extension().string();

  if (m_adaptor.isDirectory(path))
    {
      policy = std::make_unique<Policies::DeleteDirectoryIfEmpty>
        (path, m_logger);
    }

  else if (extension == ".flac"
      || extension == ".m4a"
      || extension == ".mp3")
    {
      policy = std::make_unique<Policies::BasicMusicFileNaming>
        (FileTypes::MusicFile{path,
            std::make_unique<Adaptors::TagLibAdaptor>(path)});
    }

  else if (extension == ".cue"
           || extension == ".log"
           || extension == ".txt"
           || extension == ".m3u")
    {
      policy = std::make_unique<Policies::DeleteFile>
        (FileTypes::LibraryFile{path}, m_logger);
    }

  else
    {
      policy = std::make_unique<Policies::UnknownFileType>
        (path, m_logger);
    }

  return policy;
}


///////////////////////////////////////////////////////////////////////////////
