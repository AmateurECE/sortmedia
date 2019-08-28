///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchemaFactory.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Class definition for the OrganizationalSchemaFactory.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     08/27/2019
////

#include <SortMedia/Factories/OrganizationalSchemaFactory.h>

SortMedia::Factories::OrganizationalSchemaFactory
::OrganizationalSchemaFactory()
{
}

std::unique_ptr<SortMedia::Interfaces::IOrganizationalSchema>
SortMedia::Factories::OrganizationalSchemaFactory
::makeOrganizationalSchema() const
{
  return nullptr;
}

///////////////////////////////////////////////////////////////////////////////
