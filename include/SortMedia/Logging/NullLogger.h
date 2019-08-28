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
// LAST EDITED:     08/27/2019
////

#ifndef __ET_NULLLOGGER__
#define __ET_NULLLOGGER__

#include <namespaces/SortMedia.h>
#include <SortMedia/Interfaces/ILogger.h>

class SortMedia::Logging::NullLogger : public SortMedia::Interfaces::ILogger
{
public:
  NullLogger();
  virtual ~NullLogger() = default;
  NullLogger(const NullLogger&) = delete;
  const NullLogger& operator=(const NullLogger&) = delete;
  virtual void log(const std::string& message, Enums::LogLevel logLevel)
    final override;
};

#endif // __ET_NULLLOGGER__

///////////////////////////////////////////////////////////////////////////////
