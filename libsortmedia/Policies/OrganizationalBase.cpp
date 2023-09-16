///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalBase.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Template class for OrganizationalPolicies.
//
// CREATED:         09/06/2019
////

#include <libsortmedia/Policies/OrganizationalBase.h>
#include <libsortmedia/Interfaces/IFileOperation.h>

SortMedia::Policies::OrganizationalBase::OrganizationalBase()
{}

void SortMedia::Policies::OrganizationalBase::verify()
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
SortMedia::Policies::OrganizationalBase
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

void SortMedia::Policies::OrganizationalBase::viable() const
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>>
SortMedia::Policies::OrganizationalBase::getPreconditions()
{
  return {};
}

std::list<std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>>
SortMedia::Policies::OrganizationalBase::getPostconditions()
{
  return {};
}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::OrganizationalBase::getOperations() const
{
  return {};
}

///////////////////////////////////////////////////////////////////////////////
