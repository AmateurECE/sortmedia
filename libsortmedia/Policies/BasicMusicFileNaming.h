///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicFileNaming.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This is a basic policy which organizes music files so that
//                  on the filesystem, they can be located by:
//                      /Artist/Album/XX Track.ext,
//                  where XX is replaced with the track number.
//
// CREATED:         09/06/2019
////

#ifndef __ET_BASICMUSICFILENAMINGPOLICY__
#define __ET_BASICMUSICFILENAMINGPOLICY__

#include <libsortmedia/namespaces/Interfaces.h>
#include <libsortmedia/namespaces/Policies.h>
#include <libsortmedia/FileTypes/MusicFile.h>
#include <libsortmedia/Policies/OrganizationalBase.h>

#include <FSAdaptor/Path.h>

#include <list>
#include <memory>

class SortMedia::Policies::BasicMusicFileNaming
  : public OrganizationalBase
{
public:
  BasicMusicFileNaming(FileTypes::MusicFile path,
                       FSAdaptor::Path rootOfLibrary,
                       Interfaces::ILogger& logger);

private:
  template<class T>
  using IFList = std::list<std::unique_ptr<T>>;

  virtual void viable() const final override;
  virtual IFList<Interfaces::IOrganizationalPolicy> getPostconditions()
    final override;
  virtual IFList<Interfaces::IFileOperation> getOperations()
    const final override;

  std::string getFileArtist() const;

  FileTypes::MusicFile m_musicFile;
  FSAdaptor::Path m_rootOfLibrary;
  Interfaces::ILogger& m_logger;
};

#endif // __ET_BASICMUSICFILENAMINGPOLICY__

///////////////////////////////////////////////////////////////////////////////
