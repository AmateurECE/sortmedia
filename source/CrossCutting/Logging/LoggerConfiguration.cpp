///////////////////////////////////////////////////////////////////////////////
// NAME:            LoggerConfiguration.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definitions of the members of class LoggerConfiguration.
//
// CREATED:         08/18/2019
//
// LAST EDITED:     08/18/2019
////

#include <CrossCutting/Logging/LoggerConfiguration.h>

CrossCutting::Logging::LoggerConfiguration
::LoggerConfiguration()
{
}

CrossCutting::Logging::LoggerConfiguration
::~LoggerConfiguration()
{
}

CrossCutting::Logging::LoggerConfiguration&
CrossCutting::Logging::LoggerConfiguration
::appendLogger(std::ostream& out, std::initializer_list<LogLevel>)
{
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
