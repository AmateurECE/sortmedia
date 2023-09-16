///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchema.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the OrganizationalSchema base class.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     03/31/2020
////

#include <libsortmedia/Exceptions/ExceptionBase.h>
#include <libsortmedia/Exceptions/OperationalError.h>
#include <libsortmedia/Interfaces/IFileOperation.h>
#include <libsortmedia/Interfaces/IOrganizationalPolicy.h>
#include <libsortmedia/Schemas/OrganizationalSchema.h>

#include <FSAdaptor/Path.h>

#define str(a) str_Impl(a)
#define str_Impl(a) #a

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
  catch (const Exceptions::ExceptionBase& e)
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
      catch (const Exceptions::OperationalError& e)
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
      catch (const Exceptions::OperationalError& e)
        {
          // The point is that we aren't going to catch this.
          throw std::runtime_error{__FILE__":" str(__LINE__) ":"
              " Encountered exception while reverting completed operations"
              " (due to a previous exception). Exiting."};
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
