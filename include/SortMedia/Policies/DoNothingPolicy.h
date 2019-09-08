///////////////////////////////////////////////////////////////////////////////
// NAME:            DoNothingPolicy.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     A DoNothing Policy that does...nothing.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#ifndef __ET_DONOTHINGPOLICY__
#define __ET_DONOTHINGPOLICY__

#include <namespaces/Interfaces.h>
#include <namespaces/Policies.h>
#include <SortMedia/Policies/OrganizationalPolicy.h>
#include <SortMedia/Interfaces/IFileOperation.h>

#include <list>
#include <memory>

class SortMedia::Policies::DoNothingPolicy
  : public OrganizationalPolicy
{
public:
  DoNothingPolicy() {}

private:
  template<class T>
  using IFList = std::list<std::unique_ptr<T>>;

  virtual IFList<Interfaces::IOrganizationalPolicy> getPrerequisites()
    final override { return {}; }
  virtual IFList<Interfaces::IFileOperation> getOperations()
    const final override { return {}; }
};

#endif // __ET_DONOTHINGPOLICY__

///////////////////////////////////////////////////////////////////////////////
