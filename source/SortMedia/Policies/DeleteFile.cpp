///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Policy that deletes a file.
//
// CREATED:         09/10/2019
//
// LAST EDITED:     09/10/2019
////

#include <SortMedia/Interfaces/IFileOperation.h>
#include <SortMedia/Operations/DeleteFile.h>
#include <SortMedia/Policies/DeleteFile.h>

SortMedia::Policies::DeleteFile
::DeleteFile(FileTypes::LibraryFile file)
  : m_file{std::move(file)}
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::DeleteFile::getOperations() const
{
  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations;
  // TODO: Insert Operations::DeleteFile instance
  return operations;
}

///////////////////////////////////////////////////////////////////////////////
