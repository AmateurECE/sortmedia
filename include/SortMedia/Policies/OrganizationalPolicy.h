///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalPolicy.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Abstract base class implementing a template for all
//                  OrganizationalPolicy derived classes.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/09/2019
////

#ifndef __ET_ORGANIZATIONALPOLICY__
#define __ET_ORGANIZATIONALPOLICY__

#include <namespaces/Interfaces.h>
#include <namespaces/Policies.h>
#include <SortMedia/Interfaces/IOrganizationalPolicy.h>

#include <list>
#include <memory>

class SortMedia::Policies::OrganizationalPolicy
  : public SortMedia::Interfaces::IOrganizationalPolicy
{
public:
  OrganizationalPolicy();

  // Ensures that the policy can take effect
  virtual void verify() final override;

  // Determines the operations necessary to enforce conformance.
  virtual std::list<std::unique_ptr<Interfaces::IFileOperation>> administer()
    const final override;

private:
  template<class T>
  using IFList = std::list<std::unique_ptr<T>>;

  virtual void viable() const;
  virtual IFList<Interfaces::IOrganizationalPolicy> getPreconditions();
  virtual IFList<Interfaces::IOrganizationalPolicy> getPostconditions();
  virtual IFList<Interfaces::IFileOperation> getOperations() const;

  IFList<Interfaces::IOrganizationalPolicy> m_preconditions;
  IFList<Interfaces::IOrganizationalPolicy> m_postconditions;
};

#endif // __ET_ORGANIZATIONALPOLICY__

///////////////////////////////////////////////////////////////////////////////
