///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicFileNaming.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the BasicMusicFileNaming
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/12/2019
////

#include <SortMedia/Exceptions/PolicyVerificationError.h>
#include <SortMedia/Interfaces/IFileOperation.h>
#include <SortMedia/Interfaces/ILogger.h>
#include <SortMedia/Interfaces/IOrganizationalPolicy.h>
#include <SortMedia/Interfaces/IMusicTagEditorAdaptor.h>
#include <SortMedia/Policies/BasicMusicFileNaming.h>
#include <SortMedia/Policies/DeleteDirectoryIfEmpty.h>

#include <FSAdaptor/Path.h>

SortMedia::Policies::BasicMusicFileNaming
::BasicMusicFileNaming(FileTypes::MusicFile path,
                       FSAdaptor::Path rootOfLibrary,
                       Interfaces::ILogger& logger)
  : m_musicFile{std::move(path)}, m_rootOfLibrary{rootOfLibrary},
    m_logger{logger}
{}

void SortMedia::Policies::BasicMusicFileNaming::viable() const
{
  Interfaces::IMusicTagEditorAdaptor& tagEditor = m_musicFile.getTagEditor();
  std::string missingTagName = "";
  if (tagEditor.getArtist() == "")
    {
      missingTagName = "artist";
    }
  else if (tagEditor.getAlbum() == "")
    {
      missingTagName = "album";
    }
  else if (tagEditor.getTitle() == "")
    {
      missingTagName = "title";
    }
  else if (tagEditor.getTrack() == 0)
    {
      missingTagName = "track number";
    }

  if (missingTagName != "")
    {
      m_logger.log(m_musicFile.getPath().filename().string() + " is missing "
                   + missingTagName + " tag.", Logging::LogLevel::ERROR);
      throw Exceptions::PolicyVerificationError{"file is missing "
          + missingTagName + " tag"};
    }
}

std::list<std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>>
SortMedia::Policies::BasicMusicFileNaming::getPostconditions()
{
  std::list<std::unique_ptr<Interfaces::IOrganizationalPolicy>> policies;
  policies.push_back(std::make_unique<DeleteDirectoryIfEmpty>
                     (m_musicFile.getPath(), m_logger));
  return policies;
}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::BasicMusicFileNaming::getOperations() const
{
  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations;
  return operations;
}

///////////////////////////////////////////////////////////////////////////////
