///////////////////////////////////////////////////////////////////////////////
// NAME:            NullLogger.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Null (no-op) logger.
//
// CREATED:         08/18/2019
//
// LAST EDITED:     08/27/2019
////

#include <SortMedia/Logging/NullLogger.h>

SortMedia::Logging::NullLogger::NullLogger()
{
}

void SortMedia::Logging::NullLogger
::log(const std::string& message, Enums::LogLevel logLevel)
{
}

///////////////////////////////////////////////////////////////////////////////
