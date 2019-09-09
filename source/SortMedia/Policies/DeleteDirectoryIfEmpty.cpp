///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteDirectoryIfEmpty.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implemetation of the policy.
//
// CREATED:         09/09/2019
//
// LAST EDITED:     09/09/2019
////

#include <SortMedia/Operations/DeleteDirectoryIfEmpty.h>
#include <SortMedia/Policies/DeleteDirectoryIfEmpty.h>

SortMedia::Policies::DeleteDirectoryIfEmpty
::DeleteDirectoryIfEmpty(FSAdaptor::Path directory)
  : m_directory{directory}
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::DeleteDirectoryIfEmpty::getOperations() const
{
  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations;
  operations.push_back(std::make_unique<Operations::DeleteDirectoryIfEmpty>
                       (m_directory));
  return operations;
}

///////////////////////////////////////////////////////////////////////////////
