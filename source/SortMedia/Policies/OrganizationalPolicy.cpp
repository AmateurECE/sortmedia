///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalPolicy.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Template class for OrganizationalPolicies.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/09/2019
////

#include <SortMedia/Policies/OrganizationalPolicy.h>
#include <SortMedia/Interfaces/IFileOperation.h>

SortMedia::Policies::OrganizationalPolicy::OrganizationalPolicy()
{}

void SortMedia::Policies::OrganizationalPolicy::verify()
{
  viable();
  m_preconditions = getPreconditions();
  for (auto& i : m_preconditions)
    {
      i->verify();
    }

  m_postconditions = getPostconditions();
  for (auto& i : m_postconditions)
    {
      i->verify();
    }
}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::OrganizationalPolicy
::administer() const
{
  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations
    = getOperations();

  for (auto& i : m_preconditions)
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

  for (auto& i : m_postconditions)
    {
      std::list<std::unique_ptr<Interfaces::IFileOperation>> postreqOps
        = i->administer();
      while (postreqOps.size() > 0)
        {
          std::unique_ptr<Interfaces::IFileOperation> nextOp
            = std::move(postreqOps.front());
          operations.push_back(std::move(nextOp));
          postreqOps.pop_front();
        }
    }

  return operations;
}

void SortMedia::Policies::OrganizationalPolicy::viable() const
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>>
SortMedia::Policies::OrganizationalPolicy::getPreconditions()
{
  return {};
}

std::list<std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>>
SortMedia::Policies::OrganizationalPolicy::getPostconditions()
{
  return {};
}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::OrganizationalPolicy::getOperations() const
{
  return {};
}

///////////////////////////////////////////////////////////////////////////////
