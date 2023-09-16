///////////////////////////////////////////////////////////////////////////////
// NAME:            OrganizationalSchema.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Abstract base class which all Schemas must derive from.
//
// CREATED:         09/06/2019
////

#ifndef __ET_ORGANIZATIONALSCHEMA__
#define __ET_ORGANIZATIONALSCHEMA__

#include <libsortmedia/namespaces/Interfaces.h>
#include <libsortmedia/namespaces/Schemas.h>
#include <libsortmedia/Interfaces/IOrganizationalSchema.h>

#include <FSAdaptor/namespace.h>

#include <list>
#include <memory>

class SortMedia::Schemas::OrganizationalSchema
  : public SortMedia::Interfaces::IOrganizationalSchema
{
public:
  OrganizationalSchema();
  virtual void applyToFile(const FSAdaptor::Path& file,
                           const FSAdaptor::Path& rootOfLibrary)
    const final override;
  
private:
  virtual std::unique_ptr<Interfaces::IOrganizationalPolicy>
  makeOrganizer(const FSAdaptor::Path& path,
                const FSAdaptor::Path& rootOfLibrary) const = 0;

  template<class T>
  using IFList = std::list<std::unique_ptr<T>>;
  void revertOperations(IFList<Interfaces::IFileOperation>& operations) const;
};

#endif // __ET_ORGANIZATIONALSCHEMA__

///////////////////////////////////////////////////////////////////////////////
