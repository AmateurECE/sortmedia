///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicOrganizationalSchema.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Basic Music Organizational Schema.
//
// CREATED:         09/06/2019
////

#include <libsortmedia/Schemas/BasicMusicOrganizationalSchema.h>

#include <libsortmedia/FileTypes/MusicFile.h>
#include <libsortmedia/Policies/BasicMusicFileNaming.h>
#include <libsortmedia/Policies/DeleteDirectoryIfEmpty.h>
#include <libsortmedia/Policies/DeleteFile.h>
#include <libsortmedia/Policies/DoNothing.h>
#include <libsortmedia/Policies/UnknownFileType.h>

#include <fsadaptor/IFilesystemAdaptor.h>
#include <fsadaptor/StandardFilesystemAdaptor.h>
#include <fsadaptor/Path.h>

const FSAdaptor::IFilesystemAdaptor&
SortMedia::Schemas::BasicMusicOrganizationalSchema::s_stdAdaptor
= FSAdaptor::StandardFilesystemAdaptor{};

// TODO: Standardize pos. of logger in ctor arg list
SortMedia::Schemas::BasicMusicOrganizationalSchema
::BasicMusicOrganizationalSchema(Interfaces::ILogger& logger,
                                 const FSAdaptor::IFilesystemAdaptor& adaptor)
  : m_musicTagEditorAdaptorFactory{}, m_logger(logger), m_adaptor(adaptor)
{}

std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>
SortMedia::Schemas::BasicMusicOrganizationalSchema
::makeOrganizer(const FSAdaptor::Path& path,
                const FSAdaptor::Path& rootOfLibrary) const
{
  std::unique_ptr<Interfaces::IOrganizationalPolicy> policy;
  std::string extension = path.extension().string();

  if (m_adaptor.isDirectory(path))
    {
      policy = std::make_unique<Policies::DeleteDirectoryIfEmpty>
        (path, rootOfLibrary, m_logger);
    }

  else if (extension == ".flac"
      || extension == ".m4a"
      || extension == ".mp3")
    {
      policy = std::make_unique<Policies::BasicMusicFileNaming>
        (FileTypes::MusicFile{path,
            m_musicTagEditorAdaptorFactory.makeMusicTagEditorAdaptor(path)},
          rootOfLibrary, m_logger);
    }

  else if (extension == ".cue"
           || extension == ".log"
           || extension == ".nfo"
           || extension == ".txt"
           || extension == ".m3u"
           || extension == ".m3u8"
           || extension == ".jpg"
           || extension == ".png"
           || extension == ".bmp")
    {
      policy = std::make_unique<Policies::DeleteFile>
        (FileTypes::LibraryFile{path}, rootOfLibrary, m_logger);
    }

  else
    {
      policy = std::make_unique<Policies::UnknownFileType>
        (path, m_logger);
    }

  return policy;
}


///////////////////////////////////////////////////////////////////////////////
