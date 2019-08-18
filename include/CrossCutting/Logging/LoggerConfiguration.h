///////////////////////////////////////////////////////////////////////////////
// NAME:            LoggerConfiguration.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains class definition for LoggerConfiguration class.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     08/18/2019
////

#ifndef __ET_LOGGERCONFIGURATION__
#define __ET_LOGGERCONFIGURATION__

#include <namespaces/CrossCutting.h>
#include <interfaces/ILogger.h>

#include <ostream>

class CrossCutting::Logging::LoggerConfiguration
{
public:
  LoggerConfiguration(const LoggerConfiguration&) = delete;
  const LoggerConfiguration& operator=(const LoggerConfiguration&) = delete;

  LoggerConfiguration();
  ~LoggerConfiguration();
  LoggerConfiguration& appendLogger(std::ostream&,
                                    std::initializer_list<LogLevel>);
};

#endif // __ET_LOGGERCONFIGURATION__

///////////////////////////////////////////////////////////////////////////////
