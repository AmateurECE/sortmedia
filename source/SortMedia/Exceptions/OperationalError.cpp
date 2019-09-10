///////////////////////////////////////////////////////////////////////////////
// NAME:            OperationalError.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/10/2019
////

#include <SortMedia/Exceptions/OperationalError.h>

SortMedia::Exceptions::OperationalError
::OperationalError(const std::string& message)
  : m_message(message)
{}

const char* SortMedia::Exceptions::OperationalError
::what() const noexcept
{
  return m_message.c_str();
}

///////////////////////////////////////////////////////////////////////////////
