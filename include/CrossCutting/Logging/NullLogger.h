///////////////////////////////////////////////////////////////////////////////
// NAME:            NullLogger.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains an implementation of a no-op logger. This is used
//                  to effectively disable logging, for one reason or another.
//
// CREATED:         08/18/2019
//
// LAST EDITED:     08/18/2019
////

#ifndef __ET_NULLLOGGER__
#define __ET_NULLLOGGER__

#include <interfaces/ILogger.h>
#include <namespaces/CrossCutting.h>

class CrossCutting::Logging::NullLogger : public ILogger
{
public:
  virtual ~NullLogger() = default;
  NullLogger(const NullLogger&) = delete;
  const NullLogger& operator=(const NullLogger&) = delete;
  virtual void log(const std::string& message, LogLevel logLevel)
    final override;

private:
  NullLogger();

  friend LoggerFactory;
};

#endif // __ET_NULLLOGGER__

///////////////////////////////////////////////////////////////////////////////
