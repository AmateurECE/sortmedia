///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchema.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Abstract base class which all Schemas must derive from.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/06/2019
////

#ifndef __ET_ORGANIZATIONALSCHEMA__
#define __ET_ORGANIZATIONALSCHEMA__

#include <namespaces/Interfaces.h>
#include <namespaces/Schemas.h>
#include <SortMedia/Interfaces/IOrganizationalSchema.h>

#include <FSAdaptor/namespace.h>

#include <memory>

class SortMedia::Schemas::OrganizationalSchema
  : public SortMedia::Interfaces::IOrganizationalSchema
{
public:
  OrganizationalSchema();
  virtual void applyToFile(const FSAdaptor::Path& file) const final override;
  
private:
  virtual std::unique_ptr<Interfaces::IOrganizationalPolicy>
  makeOrganizer(const FSAdaptor::Path& path) const = 0;
};

#endif // __ET_ORGANIZATIONALSCHEMA__

///////////////////////////////////////////////////////////////////////////////
