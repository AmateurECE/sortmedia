///////////////////////////////////////////////////////////////////////////////
// NAME:            StreamLogger.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the StreamLogger class.
//
// CREATED:         08/27/2019
////

#include <libsortmedia/Logging/StreamLogger.h>

#include <array>
#include <ostream>

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
          m_stream << getMessagePrefix(logLevel) << message << '\n';
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
::appendLogger(std::unique_ptr<Interfaces::ILogger>&& logger)
{
  m_nextLogger = std::move(logger);
  return *m_nextLogger;
}

const char*
SortMedia::Logging::StreamLogger
::getMessagePrefix(LogLevel level) const
{
#define RED     "\033[31;1m"
#define GREEN   "\033[32;1m"
#define YELLOW  "\033[33;1m"
#define NONE    "\033[0m"

  static const char* infoPrefix = GREEN   "INFO    " NONE;
  static const char* warnPrefix = YELLOW  "WARNING " NONE;
  static const char* errorPrefix = RED    "ERROR   " NONE;

#undef RED
#undef GREEN
#undef YELLOW
#undef NONE

  switch (level)
    {
    case ERROR:
      return errorPrefix;

    case WARNING:
      return warnPrefix;

    case INFO:
    default:
      return infoPrefix;
    }
}

///////////////////////////////////////////////////////////////////////////////
