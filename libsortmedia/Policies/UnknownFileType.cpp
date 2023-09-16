///////////////////////////////////////////////////////////////////////////////
// NAME:            UnknownFileType.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Unknown File Type Policy.
//
// CREATED:         09/06/2019
////

#include <cstring>
#include <libsortmedia/Operations/Warn.h>
#include <libsortmedia/Policies/UnknownFileType.h>

#include <FSAdaptor/Path.h>

SortMedia::Policies::UnknownFileType
::UnknownFileType(const FSAdaptor::Path& path,
                        Interfaces::ILogger& logger)
  : m_logger{logger}, m_path{path}
{}

std::list<std::unique_ptr<SortMedia::Interfaces::IFileOperation>>
SortMedia::Policies::UnknownFileType::getOperations() const
{
  char message[128];
  memset(&message, 0, sizeof(message));
  snprintf(message, sizeof(message) - 1,
           "No rule to organize file \"%s\"",
           m_path.filename().string().c_str());

  std::list<std::unique_ptr<Interfaces::IFileOperation>> policy;
  policy.push_back(std::make_unique<Operations::Warn>
                   (m_logger, std::string{message}));
  return policy;
}

///////////////////////////////////////////////////////////////////////////////
