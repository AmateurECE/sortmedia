///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicFileNaming.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the BasicMusicFileNaming
//
// CREATED:         09/06/2019
//
// LAST EDITED:     02/06/2022
////

#include <SortMedia/Exceptions/PolicyVerificationError.h>
#include <SortMedia/Interfaces/IFileOperation.h>
#include <SortMedia/Interfaces/ILogger.h>
#include <SortMedia/Interfaces/IOrganizationalPolicy.h>
#include <SortMedia/Interfaces/IMusicTagEditorAdaptor.h>
#include <SortMedia/Operations/RenameFile.h>
#include <SortMedia/Operations/Warn.h>
#include <SortMedia/Policies/BasicMusicFileNaming.h>
#include <SortMedia/Policies/DeleteDirectoryIfEmpty.h>

#include <FSAdaptor/Path.h>

#include <cmath>

using Tags = SortMedia::Interfaces::IMusicTagEditorAdaptor::Tags;

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
  if (getFileArtist() == "")
    {
      missingTagName = "artist";
    }
  else if (tagEditor.getTag(Tags::Album) == "")
    {
      missingTagName = "album";
    }
  else if (tagEditor.getTag(Tags::Title) == "")
    {
      missingTagName = "title";
    }
  else if (tagEditor.getTag(Tags::Track) == "")
    {
      missingTagName = "track number";
    }
  else if (tagEditor.getTag(Tags::TrackTotal) == "")
    {
      missingTagName = "track total";
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
                     (m_musicFile.getPath().parent_path(), m_rootOfLibrary,
                      m_logger));
  return policies;
}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::BasicMusicFileNaming::getOperations() const
{
  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations;

  // Create compliant name
  static const std::regex r_charFilter{"[^A-Za-z0-9 \\-._\\[\\]\\(\\)]"};
  FSAdaptor::Path compliantPath{m_rootOfLibrary};

  Interfaces::IMusicTagEditorAdaptor& tagEditor = m_musicFile.getTagEditor();
  compliantPath /= FSAdaptor::Path{std::regex_replace(getFileArtist(),
                                                      r_charFilter, "_")};
  compliantPath /= FSAdaptor::Path
    {std::regex_replace(tagEditor.getTag(Tags::Album),
                        r_charFilter, "_")};

  std::string discNumber = tagEditor.getTag(Tags::Disc);
  const std::string discTotal = tagEditor.getTag(Tags::DiscTotal);
  if ("" != discNumber && "" != discTotal)
    {
      discNumber = std::string(discTotal.length() - discNumber.length(), '0')
        + discNumber;
    }
  else if ("" != discNumber)
    {
      operations.push_back(std::make_unique<Operations::Warn>
                           (m_logger, "\"" + tagEditor.getTag(Tags::Title)
                            + "\" has disc number set, but not disc total"));
      discNumber = "";
    }

  const std::string trackNumber = tagEditor.getTag(Tags::Track);
  // Ensure that the tracknumber is always at least two digits (e.g. "01")
  const std::string trackTotal = tagEditor.getTag(Tags::TrackTotal);
  const int trackWidth = trackTotal.length() < 2 ? 2 : trackTotal.length();
  compliantPath /= FSAdaptor::Path{
    discNumber + std::string(trackWidth - trackNumber.length(), '0')
      + trackNumber + " " + std::regex_replace(tagEditor.getTag(Tags::Title),
                                               r_charFilter, "_")};
  compliantPath += m_musicFile.getPath().extension();

  // If not equal to current filename, push a rename operation.
  if (compliantPath != m_musicFile.getPath())
    {
      m_logger.log("Renaming \"" + tagEditor.getTag(Tags::Title) + "\"",
                   Logging::LogLevel::INFO);
      operations.push_back(std::make_unique<Operations::RenameFile>
                           (m_musicFile, std::move(compliantPath), m_logger));
    }

  return operations;
}

std::string SortMedia::Policies::BasicMusicFileNaming::getFileArtist() const
{
  Interfaces::IMusicTagEditorAdaptor& tagEditor = m_musicFile.getTagEditor();
  std::string artist = tagEditor.getTag(Tags::AlbumArtist);
  if (artist != "")
    {
      return artist;
    }
  return tagEditor.getTag(Tags::Artist);
}

///////////////////////////////////////////////////////////////////////////////
