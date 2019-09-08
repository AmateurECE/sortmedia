///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchemaFactory.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Class definition for the OrganizationalSchemaFactory.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     09/06/2019
////

#include <SortMedia/Factories/OrganizationalSchemaFactory.h>
#include <SortMedia/Schemas/BasicMusicOrganizationalSchema.h>

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
