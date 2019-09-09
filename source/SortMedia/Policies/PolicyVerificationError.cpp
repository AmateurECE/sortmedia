///////////////////////////////////////////////////////////////////////////////
// NAME:            PolicyVerificationError.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#include <SortMedia/Policies/PolicyVerificationError.h>

SortMedia::Policies::PolicyVerificationError
::PolicyVerificationError(const std::string& message)
  : m_message(message)
{}

const char* SortMedia::Policies::PolicyVerificationError::what() const noexcept
{
  return m_message.c_str();
}

///////////////////////////////////////////////////////////////////////////////
