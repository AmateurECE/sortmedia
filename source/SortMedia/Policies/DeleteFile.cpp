///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Policy that deletes a file.
//
// CREATED:         09/10/2019
//
// LAST EDITED:     09/12/2019
////

#include <SortMedia/Interfaces/IFileOperation.h>
#include <SortMedia/Interfaces/ILogger.h>
#include <SortMedia/Operations/DeleteFile.h>
#include <SortMedia/Policies/DeleteDirectoryIfEmpty.h>
#include <SortMedia/Policies/DeleteFile.h>

SortMedia::Policies::DeleteFile
::DeleteFile(const FileTypes::LibraryFile& file, FSAdaptor::Path rootOfLibrary,
             Interfaces::ILogger& logger)
  : m_file{file}, m_rootOfLibrary{std::move(rootOfLibrary)}, m_logger{logger}
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IOrganizationalPolicy>>
SortMedia::Policies::DeleteFile::getPostconditions()
{
  std::list<std::unique_ptr<Interfaces::IOrganizationalPolicy>> policies;
  policies.push_back(std::make_unique<Policies::DeleteDirectoryIfEmpty>
                     (m_file.getPath().parent_path(),
                      std::move(m_rootOfLibrary), m_logger));
  return policies;
}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::DeleteFile::getOperations() const
{
  std::list<std::unique_ptr<Interfaces::IFileOperation>> operations;
  operations.push_back(std::make_unique<Operations::DeleteFile>
                       (std::move(m_file), m_logger));
  return operations;
}

///////////////////////////////////////////////////////////////////////////////
