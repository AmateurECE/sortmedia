///////////////////////////////////////////////////////////////////////////////
// NAME:            BasicMusicOrganizationalSchema.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This is a basic schema which organizes libraries like so:
//                      * .FLAC, .m4a, and .mp3 files are organized according
//                        to the following scheme: /Artist/Album/XX Track.ext,
//                        where XX is replaced with the track number.
//                      * All other files generate a warning.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     03/31/2020
////

#ifndef __ET_BASICMUSICORGANIZATIONALSCHEMA__
#define __ET_BASICMUSICORGANIZATIONALSCHEMA__

#include <libsortmedia/namespaces/Interfaces.h>
#include <libsortmedia/namespaces/Schemas.h>
#include <libsortmedia/Factories/MusicTagEditorAdaptorFactory.h>
#include <libsortmedia/Schemas/OrganizationalSchema.h>

#include <FSAdaptor/namespace.h>

#include <memory>

class SortMedia::Schemas::BasicMusicOrganizationalSchema
  : public SortMedia::Schemas::OrganizationalSchema
{
public:
  BasicMusicOrganizationalSchema(Interfaces::ILogger& logger,
                                 const FSAdaptor::IFilesystemAdaptor& adaptor
                                 = s_stdAdaptor);

private:
  virtual std::unique_ptr<Interfaces::IOrganizationalPolicy>
  makeOrganizer(const FSAdaptor::Path& path,
                const FSAdaptor::Path& rootOfLibrary) const final override;

  const Factories::MusicTagEditorAdaptorFactory m_musicTagEditorAdaptorFactory;

  Interfaces::ILogger& m_logger;
  const FSAdaptor::IFilesystemAdaptor& m_adaptor;
  static const FSAdaptor::IFilesystemAdaptor& s_stdAdaptor;
};

#endif // __ET_BASICMUSICORGANIZATIONALSCHEMA__

///////////////////////////////////////////////////////////////////////////////
