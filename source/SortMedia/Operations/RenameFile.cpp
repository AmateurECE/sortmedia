///////////////////////////////////////////////////////////////////////////////
// NAME:            RenameFile.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of an operation that renames a file.
//
// CREATED:         09/11/2019
//
// LAST EDITED:     09/12/2019
////

#include <SortMedia/Exceptions/OperationalError.h>
#include <SortMedia/Interfaces/ILogger.h>
#include <SortMedia/Operations/RenameFile.h>

#include <FSAdaptor/StandardFilesystemAdaptor.h>

const FSAdaptor::IFilesystemAdaptor&
SortMedia::Operations::RenameFile::s_stdAdaptor
= FSAdaptor::StandardFilesystemAdaptor{};

SortMedia::Operations::RenameFile
::RenameFile(FileTypes::LibraryFile file, FSAdaptor::Path newName,
             Interfaces::ILogger& logger,
             const FSAdaptor::IFilesystemAdaptor& adaptor)
  : m_file{std::move(file)}, m_newName{std::move(newName)},
    m_oldName{m_file.getPath()}, m_logger{logger}, m_adaptor{adaptor}
{}

void SortMedia::Operations::RenameFile
::doRename(FileTypes::LibraryFile& file,
           const FSAdaptor::Path& newName) const
{
  // TODO: Ensure that other operations throw correctly
  // Make sure that the directory we are moving to exists (prevent exceptions)
  try
    {
      m_adaptor.createDirectories(file.getPath().parent_path());
      file.rename(newName);
    }
  catch (std::system_error& e) // These fns throw system_error.
    {
      std::string errorMessage = "Could not rename "
        + file.getPath().string() + " to " + newName.string();
      m_logger.log(errorMessage, Logging::LogLevel::ERROR);
      throw Exceptions::OperationalError{std::move(errorMessage)};
    }
}

void SortMedia::Operations::RenameFile::apply()
{
  doRename(m_file, m_newName);
}

void SortMedia::Operations::RenameFile::revert()
{
  doRename(m_file, m_oldName);
}

///////////////////////////////////////////////////////////////////////////////
