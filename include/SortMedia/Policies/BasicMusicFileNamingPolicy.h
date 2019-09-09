///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicFileNamingPolicy.h
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
// LAST EDITED:     09/09/2019
////

#ifndef __ET_BASICMUSICFILENAMINGPOLICY__
#define __ET_BASICMUSICFILENAMINGPOLICY__

#include <namespaces/Interfaces.h>
#include <namespaces/Policies.h>
#include <SortMedia/FileTypes/MusicFile.h>
#include <SortMedia/Policies/OrganizationalPolicy.h>

#include <FSAdaptor/namespace.h>

#include <list>
#include <memory>

class SortMedia::Policies::BasicMusicFileNamingPolicy
  : public OrganizationalPolicy
{
public:
  BasicMusicFileNamingPolicy(FileTypes::MusicFile path);

private:
  template<class T>
  using IFList = std::list<std::unique_ptr<T>>;

  virtual IFList<Interfaces::IOrganizationalPolicy> getPrerequisites()
    final override;
  virtual IFList<Interfaces::IFileOperation> getOperations()
    const final override;

  FileTypes::MusicFile m_musicFile;
};

#endif // __ET_BASICMUSICFILENAMINGPOLICY__

///////////////////////////////////////////////////////////////////////////////
