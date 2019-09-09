///////////////////////////////////////////////////////////////////////////////
// NAME:            Warn.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition for the Warn Operation.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/09/2019
////

#include <namespaces/Logging.h>
#include <SortMedia/Operations/Warn.h>
#include <SortMedia/Interfaces/ILogger.h>

SortMedia::Operations::Warn
::Warn(Interfaces::ILogger& logger, std::string message)
  : m_logger(logger), m_message(message)
{}

void
SortMedia::Operations::Warn::apply()
{
  m_logger.log(m_message, Logging::LogLevel::WARNING);
}

void
SortMedia::Operations::Warn::revert()
{}

///////////////////////////////////////////////////////////////////////////////
