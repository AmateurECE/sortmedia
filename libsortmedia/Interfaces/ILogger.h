///////////////////////////////////////////////////////////////////////////////
// NAME:            ILogger.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     An interface for Logging classes.
//
// CREATED:         08/17/2019
//
// LAST EDITED:     09/10/2019
////

#ifndef __ET_ILOGGER__
#define __ET_ILOGGER__

#include <string>

#include <libsortmedia/namespaces/Interfaces.h>
#include <libsortmedia/namespaces/Logging.h>

#include <memory>

class SortMedia::Interfaces::ILogger
{
public:
  virtual ~ILogger() {};
  virtual void log(const std::string& message, Logging::LogLevel level) = 0;
  virtual ILogger& appendLogger(std::unique_ptr<ILogger>&&) = 0;
};

#endif // __ET_ILOGGER__

///////////////////////////////////////////////////////////////////////////////
