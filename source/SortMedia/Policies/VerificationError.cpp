///////////////////////////////////////////////////////////////////////////////
// NAME:            VerificationError.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/09/2019
////

#include <SortMedia/Policies/VerificationError.h>

SortMedia::Policies::VerificationError
::VerificationError(const std::string& message)
  : m_message(message)
{}

const char* SortMedia::Policies::VerificationError::what() const noexcept
{
  return m_message.c_str();
}

///////////////////////////////////////////////////////////////////////////////
