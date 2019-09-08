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
// LAST EDITED:     09/06/2019
////

#ifndef __ET_BASICMUSICORGANIZATIONALSCHEMA__
#define __ET_BASICMUSICORGANIZATIONALSCHEMA__

#include <namespaces/Interfaces.h>
#include <namespaces/Schemas.h>
#include <SortMedia/Schemas/OrganizationalSchema.h>

#include <FSAdaptor/namespace.h>

#include <memory>

class SortMedia::Schemas::BasicMusicOrganizationalSchema
  : public SortMedia::Schemas::OrganizationalSchema
{
public:
  BasicMusicOrganizationalSchema(Interfaces::ILogger& logger);

private:
  virtual std::unique_ptr<Interfaces::IOrganizationalPolicy>
  makeOrganizer(const FSAdaptor::Path& path) const final override;

  Interfaces::ILogger& m_logger;
};

#endif // __ET_BASICMUSICORGANIZATIONALSCHEMA__

///////////////////////////////////////////////////////////////////////////////
