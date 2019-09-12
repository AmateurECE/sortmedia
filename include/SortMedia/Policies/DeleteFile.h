///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteFile.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Policy that deletes a file.
//
// CREATED:         09/10/2019
//
// LAST EDITED:     09/11/2019
////

#ifndef __ET_POLICIES_DELETEFILE__
#define __ET_POLICIES_DELETEFILE__

#include <namespaces/Interfaces.h>
#include <namespaces/Policies.h>
#include <SortMedia/Policies/OrganizationalBase.h>
#include <SortMedia/FileTypes/LibraryFile.h>

#include <list>
#include <memory>

class SortMedia::Policies::DeleteFile
  : public OrganizationalBase
{
public:
  // TODO: Take file by value.
  DeleteFile(const FileTypes::LibraryFile& file, Interfaces::ILogger& logger);

private:
  template<class T>
  using IFList = std::list<std::unique_ptr<T>>;

  virtual IFList<Interfaces::IOrganizationalPolicy> getPostconditions()
    final override;
  virtual IFList<Interfaces::IFileOperation> getOperations()
    const final override;

  FileTypes::LibraryFile m_file;
  Interfaces::ILogger& m_logger;
};

#endif // __ET_POLICIES_DELETEFILE__

///////////////////////////////////////////////////////////////////////////////
