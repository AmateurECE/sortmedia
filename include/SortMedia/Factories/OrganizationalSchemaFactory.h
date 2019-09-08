///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchemaFactory.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Factory for OrganizationalSchema classes.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     09/06/2019
////

#ifndef __ET_ORGANIZATIONALSCHEMAFACTORY__
#define __ET_ORGANIZATIONALSCHEMAFACTORY__

#include <namespaces/Interfaces.h>
#include <namespaces/Factories.h>
#include <SortMedia/Interfaces/IOrganizationalSchema.h>

#include <memory>

class SortMedia::Factories::OrganizationalSchemaFactory
{
public:
  OrganizationalSchemaFactory();
  std::unique_ptr<Interfaces::IOrganizationalSchema>
  makeOrganizationalSchema(Interfaces::ILogger& logger) const;
};

#endif // __ET_ORGANIZATIONALSCHEMAFACTORY__

///////////////////////////////////////////////////////////////////////////////
