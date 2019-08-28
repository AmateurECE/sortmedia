///////////////////////////////////////////////////////////////////////////////
// NAME:            StreamLogger.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains class definition for the logger class.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     08/27/2019
////

#ifndef __ET_LOGGER__
#define __ET_LOGGER__

#include <namespaces/SortMedia.h>
#include <SortMedia/Interfaces/ILogger.h>

class SortMedia::Logging::StreamLogger : public SortMedia::Interfaces::ILogger
{
public:
  virtual ~StreamLogger();

  StreamLogger() = delete;
  StreamLogger(const StreamLogger&) = delete;
  StreamLogger(std::ostream&,
               std::initializer_list<Enums::LogLevel> logLevels);
  const StreamLogger& operator=(const StreamLogger&) = delete;

  virtual void log(const std::string& message, Enums::LogLevel level) override;

private:
  std::ostream& stream;
  std::unique_ptr<ILogger> nextLogger;
  std::unique_ptr<Enums::LogLevel[]> level;
};

#endif // __ET_LOGGER__

///////////////////////////////////////////////////////////////////////////////
