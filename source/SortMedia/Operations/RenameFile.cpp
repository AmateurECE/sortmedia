///////////////////////////////////////////////////////////////////////////////
// NAME:            RenameFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of an operation that renames a file.
//
// CREATED:         09/11/2019
//
// LAST EDITED:     09/11/2019
////

#include <SortMedia/Operations/RenameFile.h>

#include <FSAdaptor/StandardFilesystemAdaptor.h>

const FSAdaptor::IFilesystemAdaptor&
SortMedia::Operations::RenameFile::s_stdAdaptor
= FSAdaptor::StandardFilesystemAdaptor{};

SortMedia::Operations::RenameFile
::RenameFile(FileTypes::LibraryFile file, FSAdaptor::Path newName,
             const FSAdaptor::IFilesystemAdaptor& adaptor)
  : m_file{std::move(file)}, m_newName{std::move(newName)},
    m_oldName{m_file.getPath()}, m_adaptor{adaptor}
{}

void SortMedia::Operations::RenameFile::apply()
{
  // Make sure that the directory we are moving to exists (prevent exceptions)
  m_adaptor.createDirectories(m_file.getPath().parent_path());
  m_file.rename(m_newName);
}

void SortMedia::Operations::RenameFile::revert()
{
  // Make sure that the directory we are moving to exists (prevent exceptions)
  m_adaptor.createDirectories(m_file.getPath().parent_path());
  m_file.rename(m_oldName);
}

///////////////////////////////////////////////////////////////////////////////
