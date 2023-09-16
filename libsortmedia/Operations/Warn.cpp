///////////////////////////////////////////////////////////////////////////////
// NAME:            Warn.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition for the Warn Operation.
//
// CREATED:         09/05/2019
////

#include <libsortmedia/namespaces/Logging.h>
#include <libsortmedia/Operations/Warn.h>
#include <libsortmedia/Interfaces/ILogger.h>

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
