///////////////////////////////////////////////////////////////////////////////
// NAME:            PolicyVerificationError.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/10/2019
////

#include <libsortmedia/Exceptions/PolicyVerificationError.h>

SortMedia::Exceptions::PolicyVerificationError
::PolicyVerificationError(const std::string& message)
  : m_message(message)
{}

const char* SortMedia::Exceptions::PolicyVerificationError
::what() const noexcept
{
  return m_message.c_str();
}

///////////////////////////////////////////////////////////////////////////////
