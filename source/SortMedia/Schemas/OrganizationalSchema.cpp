///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchema.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the OrganizationalSchema base class.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/12/2019
////

#include <SortMedia/Exceptions/ExceptionBase.h>
#include <SortMedia/Interfaces/IFileOperation.h>
#include <SortMedia/Interfaces/IOrganizationalPolicy.h>
#include <SortMedia/Schemas/OrganizationalSchema.h>

#include <FSAdaptor/Path.h>

SortMedia::Schemas::OrganizationalSchema::OrganizationalSchema()
{}

void
SortMedia::Schemas::OrganizationalSchema
::applyToFile(const FSAdaptor::Path& file,
              const FSAdaptor::Path& rootOfLibrary) const
{
  std::unique_ptr<Interfaces::IOrganizationalPolicy> organizer
    = makeOrganizer(file, rootOfLibrary);

  try
    {
      organizer->verify();
    }
  catch (Exceptions::ExceptionBase& e)
    {
      return;
    }

  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations
    = organizer->administer();
  for (auto& operation : operations)
    {
      // TODO: Catch exception during apply, revert previous operations
      operation->apply();
    }
}

///////////////////////////////////////////////////////////////////////////////
