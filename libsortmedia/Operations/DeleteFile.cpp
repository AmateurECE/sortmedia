///////////////////////////////////////////////////////////////////////////////
// NAME:            DeleteFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     The operation that deletes a file.
//
// CREATED:         09/10/2019
//
// LAST EDITED:     09/11/2019
////

#include <libsortmedia/Exceptions/OperationalError.h>
#include <libsortmedia/Interfaces/ILogger.h>
#include <libsortmedia/Operations/DeleteFile.h>

SortMedia::Operations::DeleteFile
::DeleteFile(FileTypes::LibraryFile file, Interfaces::ILogger& logger)
  : m_file{std::move(file)}, m_logger{logger}
{}

void SortMedia::Operations::DeleteFile::apply()
{
  m_logger.log("Deleting file " + m_file.getPath().string(),
               Logging::LogLevel::INFO);
  m_file.remove();
}

void SortMedia::Operations::DeleteFile::revert()
{
  throw Exceptions::OperationalError("This exception cannot be reverted.");
}

///////////////////////////////////////////////////////////////////////////////
