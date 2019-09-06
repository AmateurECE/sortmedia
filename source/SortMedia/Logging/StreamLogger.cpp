///////////////////////////////////////////////////////////////////////////////
// NAME:            StreamLogger.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the StreamLogger class.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     09/06/2019
////

#include <SortMedia/Logging/StreamLogger.h>

#include <array>

SortMedia::Logging::StreamLogger
::StreamLogger(std::ostream& out,
               std::initializer_list<LogLevel> logLevels)
  : m_stream(out), m_nextLogger(nullptr), m_levels(logLevels)
{}

void SortMedia::Logging::StreamLogger
::log(const std::string& message, LogLevel logLevel)
{
  for (auto& level : m_levels)
    {
      if (level == logLevel)
        {
          m_stream << message;
          break;
        }
    }

  if (m_nextLogger)
    {
      m_nextLogger->log(message, logLevel);
    }
}

SortMedia::Interfaces::ILogger&
SortMedia::Logging::StreamLogger
::appendLogger(std::unique_ptr<Interfaces::ILogger> logger)
{
  m_nextLogger = std::move(logger);
  return *m_nextLogger;
}

///////////////////////////////////////////////////////////////////////////////
