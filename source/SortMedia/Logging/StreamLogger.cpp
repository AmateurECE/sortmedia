///////////////////////////////////////////////////////////////////////////////
// NAME:            StreamLogger.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the StreamLogger class.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     08/27/2019
////

#include <SortMedia/Logging/StreamLogger.h>

SortMedia::Logging::StreamLogger
::StreamLogger(std::ostream& out,
               std::initializer_list<Enums::LogLevel> logLevels)
  : stream(out)
{
}

SortMedia::Logging::StreamLogger
::~StreamLogger()
{
}

void SortMedia::Logging::StreamLogger
::log(const std::string& message, Enums::LogLevel logLevel)
{
}

///////////////////////////////////////////////////////////////////////////////
