///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Policy that deletes a file.
//
// CREATED:         09/10/2019
////

#ifndef __ET_POLICIES_DELETEFILE__
#define __ET_POLICIES_DELETEFILE__

#include <libsortmedia/namespaces/Interfaces.h>
#include <libsortmedia/namespaces/Policies.h>
#include <libsortmedia/Policies/OrganizationalBase.h>
#include <libsortmedia/FileTypes/LibraryFile.h>

#include <fsadaptor/Path.h>

#include <list>
#include <memory>

class SortMedia::Policies::DeleteFile
  : public OrganizationalBase
{
public:
  // TODO: Take file by value.
  DeleteFile(const FileTypes::LibraryFile& file, FSAdaptor::Path rootOfLibrary,
             Interfaces::ILogger& logger);

private:
  template<class T>
  using IFList = std::list<std::unique_ptr<T>>;

  virtual IFList<Interfaces::IOrganizationalPolicy> getPostconditions()
    final override;
  virtual IFList<Interfaces::IFileOperation> getOperations()
    const final override;

  FileTypes::LibraryFile m_file;
  FSAdaptor::Path m_rootOfLibrary;
  Interfaces::ILogger& m_logger;
};

#endif // __ET_POLICIES_DELETEFILE__

///////////////////////////////////////////////////////////////////////////////
