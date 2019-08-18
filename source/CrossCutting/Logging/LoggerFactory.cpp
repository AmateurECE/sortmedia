///////////////////////////////////////////////////////////////////////////////
// NAME:            LoggerFactory.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains definitions of LoggerFactory members.
//
// CREATED:         08/18/2019
//
// LAST EDITED:     08/18/2019
////

#include <CrossCutting/Logging/LoggerFactory.h>
#include <CrossCutting/Logging/Logger.h>
#include <CrossCutting/Logging/NullLogger.h>

std::shared_ptr<ILogger> CrossCutting::Logging::LoggerFactory::makeLogger()
{
  return std::shared_ptr<ILogger>(new NullLogger());
}

///////////////////////////////////////////////////////////////////////////////
