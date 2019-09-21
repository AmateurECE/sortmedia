///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteDirectoryIfEmpty.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implemetation of the policy.
//
// CREATED:         09/09/2019
//
// LAST EDITED:     09/14/2019
////

#include <SortMedia/Interfaces/ILogger.h>
#include <SortMedia/Operations/DeleteDirectoryIfEmpty.h>
#include <SortMedia/Policies/DeleteDirectoryIfEmpty.h>

SortMedia::Policies::DeleteDirectoryIfEmpty
::DeleteDirectoryIfEmpty(FSAdaptor::Path directory,
                         FSAdaptor::Path rootOfLibrary,
                         Interfaces::ILogger& logger)
  : m_directory{std::move(directory)},
    m_rootOfLibrary{std::move(rootOfLibrary)}, m_logger{logger}
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::DeleteDirectoryIfEmpty::getOperations() const
{
  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations;
  FSAdaptor::Path temp{m_directory};

  // Because "rootPath" != "rootPath/"
  FSAdaptor::Path rootOtherForm;
  if (m_rootOfLibrary.string().back() == '/')
    {
      rootOtherForm = m_rootOfLibrary.parent_path();
    }
  else
    {
      rootOtherForm = m_rootOfLibrary / "";
    }

  while (temp != m_rootOfLibrary && temp != rootOtherForm)
    {
      operations.push_back(std::make_unique<Operations::DeleteDirectoryIfEmpty>
                           (temp, m_logger));
      temp = temp.parent_path();
    }
  return operations;
}

///////////////////////////////////////////////////////////////////////////////
