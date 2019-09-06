///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchema.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the OrganizationalSchema base class.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/06/2019
////

#include <SortMedia/Interfaces/IFileOperation.h>
#include <SortMedia/Interfaces/IOrganizationalPolicy.h>
#include <SortMedia/Schemas/OrganizationalSchema.h>

#include <FSAdaptor/Path.h>

SortMedia::Schemas::OrganizationalSchema::OrganizationalSchema()
{}

void
SortMedia::Schemas::OrganizationalSchema
::applyToFile(const FSAdaptor::Path& file) const
{
  std::unique_ptr<Interfaces::IOrganizationalPolicy> organizer
    = makeOrganizer(file);

  // TODO: Catch exception during verify
  organizer->verify();

  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations
    = organizer->administer();
  for (auto& operation : operations)
    {
      // TODO: Catch exception during apply
      operation->apply();
    }
}

///////////////////////////////////////////////////////////////////////////////
