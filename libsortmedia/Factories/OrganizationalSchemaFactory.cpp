///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchemaFactory.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Class definition for the OrganizationalSchemaFactory.
//
// CREATED:         08/27/2019
////

#include <libsortmedia/Factories/OrganizationalSchemaFactory.h>
#include <libsortmedia/Schemas/BasicMusicOrganizationalSchema.h>

SortMedia::Factories::OrganizationalSchemaFactory
::OrganizationalSchemaFactory()
{
}

std::unique_ptr<SortMedia::Interfaces::IOrganizationalSchema>
SortMedia::Factories::OrganizationalSchemaFactory
::makeOrganizationalSchema(Interfaces::ILogger& logger) const
{
  return std::make_unique<Schemas::BasicMusicOrganizationalSchema>(logger);
}

///////////////////////////////////////////////////////////////////////////////
