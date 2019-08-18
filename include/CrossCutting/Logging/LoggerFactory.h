///////////////////////////////////////////////////////////////////////////////
// NAME:            LoggerFactory.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains class definition for LoggerFactory class.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     08/17/2019
////

#ifndef __ET_LOGGERFACTORY__
#define __ET_LOGGERFACTORY__

#include <namespaces/CrossCutting.h>
#include <interfaces/ILogger.h>

class CrossCutting::Logging::LoggerFactory
{
public:
  ~LoggerFactory();
  LoggerFactory() = delete;
  LoggerFactory(const LoggerFactory&) = delete;
  const LoggerFactory& operator=(const LoggerFactory&) = delete;
  
  static std::shared_ptr<ILogger> makeLogger();

private:
  void setLogger(std::shared_ptr<ILogger> logger);
  static std::shared_ptr<ILogger> logChain;

  friend class LoggerConfiguration;
};

#endif // __ET_LOGGERFACTORY__

///////////////////////////////////////////////////////////////////////////////
