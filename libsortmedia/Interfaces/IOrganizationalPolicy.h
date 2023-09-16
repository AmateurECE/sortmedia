///////////////////////////////////////////////////////////////////////////////
// NAME:            IOrganizationalPolicy.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Interface for Organizational Policies.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     09/06/2019
////

#ifndef __ET_IORGANIZATIONALPOLICY__
#define __ET_IORGANIZATIONALPOLICY__

#include <libsortmedia/namespaces/Interfaces.h>

#include <list>
#include <memory>

class SortMedia::Interfaces::IOrganizationalPolicy
{
public:
  virtual ~IOrganizationalPolicy() {};

  // Ensures that the policy can take effect (Exceptions used to report errors)
  virtual void verify() = 0;

  // Determines the operations necessary to enforce conformance.
  virtual std::list<std::unique_ptr<IFileOperation>> administer() const = 0;
};

#endif // __ET_IORGANIZATIONALPOLICY__

///////////////////////////////////////////////////////////////////////////////
