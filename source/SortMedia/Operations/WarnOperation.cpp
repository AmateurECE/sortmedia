///////////////////////////////////////////////////////////////////////////////
// NAME:            WarnOperation.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition for the Warn Operation.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/08/2019
////

#include <namespaces/Logging.h>
#include <SortMedia/Operations/WarnOperation.h>
#include <SortMedia/Interfaces/ILogger.h>

SortMedia::Operations::WarnOperation
::WarnOperation(Interfaces::ILogger& logger, std::string message)
  : m_logger(logger), m_message(message)
{}

void
SortMedia::Operations::WarnOperation::apply()
{
  m_logger.log(m_message, Logging::LogLevel::WARNING);
}

void
SortMedia::Operations::WarnOperation::revert()
{}

///////////////////////////////////////////////////////////////////////////////
