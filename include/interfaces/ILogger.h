///////////////////////////////////////////////////////////////////////////////
// NAME:            ILogger.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     An interface for Logging classes.
//
// CREATED:         08/17/2019
//
// LAST EDITED:     08/18/2019
////

#ifndef __ET_ILOGGER__
#define __ET_ILOGGER__

#include <string>

enum LogLevel
{
  INFO,
  WARNING,
  ERROR
};

class ILogger
{
public:
  virtual void log(const std::string& message, LogLevel level) = 0;
};

#endif // __ET_ILOGGER__

///////////////////////////////////////////////////////////////////////////////
