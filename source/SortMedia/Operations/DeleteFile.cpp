///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     The operation that deletes a file.
//
// CREATED:         09/10/2019
//
// LAST EDITED:     09/10/2019
////

#include <SortMedia/Operations/DeleteFile.h>

SortMedia::Operations::DeleteFile::DeleteFile(FileTypes::LibraryFile file)
  : m_file{std::move(file)}
{}

void SortMedia::Operations::DeleteFile::apply()
{
  m_file.remove();
}

void SortMedia::Operations::DeleteFile::revert()
{
  // TODO: Throw exception here
}

///////////////////////////////////////////////////////////////////////////////
