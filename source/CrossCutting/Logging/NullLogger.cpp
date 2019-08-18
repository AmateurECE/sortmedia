///////////////////////////////////////////////////////////////////////////////
// NAME:            NullLogger.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Null (no-op) logger.
//
// CREATED:         08/18/2019
//
// LAST EDITED:     08/18/2019
////

#include <CrossCutting/Logging/NullLogger.h>

CrossCutting::Logging::NullLogger::NullLogger()
{
}

void CrossCutting::Logging::NullLogger
::log(const std::string& message, LogLevel logLevel)
{
}

///////////////////////////////////////////////////////////////////////////////
