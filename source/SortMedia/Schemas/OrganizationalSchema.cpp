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
#include <SortMedia/Exceptions/OperationalError.h>
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
  std::list<std::unique_ptr<Interfaces::IFileOperation>> completedOperations;
  while (0 < operations.size())
    {
      try
        {
          std::unique_ptr<Interfaces::IFileOperation> currentOperation
            = std::move(operations.front());
          operations.pop_front();
          currentOperation->apply();
          completedOperations.push_front(std::move(currentOperation));
        }
      catch (Exceptions::OperationalError& e)
        {
          revertOperations(completedOperations);
          return;
        }
    }
}

void SortMedia::Schemas::OrganizationalSchema
::revertOperations(IFList<Interfaces::IFileOperation>& operations) const
{
  while (0 < operations.size())
    {
      try
        {
          std::unique_ptr<Interfaces::IFileOperation> currentOperation
            = std::move(operations.front());
          operations.pop_front();
          currentOperation->revert();
        }
      catch (Exceptions::OperationalError& e)
        {
          // The point is that we aren't going to catch this.
          throw "Error: Encountered exception while reverting (due to a"
            " previous exception). Exiting.";
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
