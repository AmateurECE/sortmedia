///////////////////////////////////////////////////////////////////////////////
// NAME:            Logger.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains class definition for the logger class.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     08/18/2019
////

#ifndef __ET_LOGGER__
#define __ET_LOGGER__

#include <namespaces/CrossCutting.h>
#include <interfaces/ILogger.h>

class CrossCutting::Logging::Logger : public ILogger
{
public:
  virtual ~Logger();

  Logger() = delete;
  Logger(const Logger&) = delete;
  const Logger& operator=(const Logger&) = delete;

  virtual void log(const std::string& message, LogLevel level) override;

private:
  Logger(std::ostream&, std::initializer_list<LogLevel> logLevels);

  std::ostream& stream;
  std::unique_ptr<Logger> nextLogger;
  std::unique_ptr<LogLevel[]> level;

  friend class LoggerConfiguration;
};

#endif // __ET_LOGGER__

///////////////////////////////////////////////////////////////////////////////
