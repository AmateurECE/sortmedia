///////////////////////////////////////////////////////////////////////////////
// NAME:            ILogger.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     An interface for Logging classes.
//
// CREATED:         08/17/2019
//
// LAST EDITED:     08/27/2019
////

#ifndef __ET_ILOGGER__
#define __ET_ILOGGER__

#include <string>

#include <namespaces/Interfaces.h>
#include <namespaces/Enums.h>

class SortMedia::Interfaces::ILogger
{
public:
  virtual ~ILogger() {};
  virtual void log(const std::string& message,
                   SortMedia::Enums::LogLevel level) = 0;
};

#endif // __ET_ILOGGER__

///////////////////////////////////////////////////////////////////////////////
