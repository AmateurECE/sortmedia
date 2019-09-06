///////////////////////////////////////////////////////////////////////////////
// NAME:            StreamLogger.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains class definition for the logger class.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     09/06/2019
////

#ifndef __ET_LOGGER__
#define __ET_LOGGER__

#include <namespaces/Logging.h>
#include <SortMedia/Interfaces/ILogger.h>

#include <memory>

class SortMedia::Logging::StreamLogger : public SortMedia::Interfaces::ILogger
{
public:
  StreamLogger() = delete;
  StreamLogger(const StreamLogger&) = delete;
  StreamLogger(std::ostream&,
               std::initializer_list<LogLevel> logLevels);
  const StreamLogger& operator=(const StreamLogger&) = delete;

  virtual Interfaces::ILogger& appendLogger(std::unique_ptr<ILogger> logger)
    final override;
  virtual void log(const std::string& message, LogLevel level)
    final override;

private:
  std::ostream& m_stream;
  std::unique_ptr<Interfaces::ILogger> m_nextLogger;
  std::initializer_list<LogLevel> m_levels;
};

#endif // __ET_LOGGER__

///////////////////////////////////////////////////////////////////////////////
