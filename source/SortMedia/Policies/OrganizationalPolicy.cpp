///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalPolicy.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Template class for OrganizationalPolicies.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/06/2019
////

#include <SortMedia/Policies/OrganizationalPolicy.h>
#include <SortMedia/Interfaces/IFileOperation.h>

SortMedia::Policies::OrganizationalPolicy::OrganizationalPolicy()
{}

void SortMedia::Policies::OrganizationalPolicy::verify()
{
  m_prerequisites = getPrerequisites();
}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::OrganizationalPolicy
::administer() const
{
  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations
    = getOperations();

  for (auto& i : m_prerequisites)
    {
      std::list<std::unique_ptr<Interfaces::IFileOperation>> prereqOps
        = i->administer();
      while (prereqOps.size() > 0)
        {
          std::unique_ptr<Interfaces::IFileOperation> nextOp
            = std::move(prereqOps.front());
          operations.push_front(std::move(nextOp));
          prereqOps.pop_front();
        }
    }

  return operations;
}

///////////////////////////////////////////////////////////////////////////////
