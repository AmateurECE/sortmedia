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
// LAST EDITED:     09/10/2019
////

#ifndef __ET_NULLLOGGER__
#define __ET_NULLLOGGER__

#include <namespaces/SortMedia.h>
#include <SortMedia/Interfaces/ILogger.h>

#include <memory>

class SortMedia::Logging::NullLogger : public SortMedia::Interfaces::ILogger
{
public:
  NullLogger();
  virtual ~NullLogger() = default;
  NullLogger(const NullLogger&) = delete;
  const NullLogger& operator=(const NullLogger&) = delete;
  virtual void log(const std::string& message, LogLevel logLevel)
    final override;
  virtual Interfaces::ILogger&
  appendLogger(std::unique_ptr<Interfaces::ILogger>&&) final override;

private:
  std::unique_ptr<Interfaces::ILogger> m_nextLogger;
};

#endif // __ET_NULLLOGGER__

///////////////////////////////////////////////////////////////////////////////
