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
//
// LAST EDITED:     09/11/2019
////

#ifndef __ET_BASICMUSICFILENAMINGPOLICY__
#define __ET_BASICMUSICFILENAMINGPOLICY__

#include <namespaces/Interfaces.h>
#include <namespaces/Policies.h>
#include <SortMedia/FileTypes/MusicFile.h>
#include <SortMedia/Policies/OrganizationalBase.h>

#include <list>
#include <memory>

class SortMedia::Policies::BasicMusicFileNaming
  : public OrganizationalBase
{
public:
  BasicMusicFileNaming(FileTypes::MusicFile path, Interfaces::ILogger& logger);

private:
  template<class T>
  using IFList = std::list<std::unique_ptr<T>>;

  virtual IFList<Interfaces::IOrganizationalPolicy> getPostconditions()
    final override;

  FileTypes::MusicFile m_musicFile;
  Interfaces::ILogger& m_logger;
};

#endif // __ET_BASICMUSICFILENAMINGPOLICY__

///////////////////////////////////////////////////////////////////////////////
