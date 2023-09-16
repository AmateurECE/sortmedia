///////////////////////////////////////////////////////////////////////////////
// NAME:            NullLogger.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Null (no-op) logger.
//
// CREATED:         08/18/2019
//
// LAST EDITED:     09/10/2019
////

#include <libsortmedia/Logging/NullLogger.h>

SortMedia::Logging::NullLogger::NullLogger()
  : m_nextLogger(nullptr)
{}

void SortMedia::Logging::NullLogger
::log(const std::string& message, LogLevel logLevel)
{
  if (m_nextLogger)
    {
      m_nextLogger->log(message, logLevel);
    }
}

SortMedia::Interfaces::ILogger&
SortMedia::Logging::NullLogger
::appendLogger(std::unique_ptr<SortMedia::Interfaces::ILogger>&& logger)
{
  m_nextLogger = std::move(logger);
  return *m_nextLogger;
}

///////////////////////////////////////////////////////////////////////////////
