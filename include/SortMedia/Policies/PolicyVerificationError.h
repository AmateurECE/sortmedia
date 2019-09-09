///////////////////////////////////////////////////////////////////////////////
// NAME:            PolicyVerificationError.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Custom Exception type thrown if an error is encountered
//                  during verification.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#ifndef __ET_POLICYVERIFICATIONERROR__
#define __ET_POLICYVERIFICATIONERROR__

#include <namespaces/Policies.h>

#include <exception>
#include <string>

class SortMedia::Policies::PolicyVerificationError
  : public std::exception
{
public:
  PolicyVerificationError(const std::string& message);
  const char* what() const noexcept;

private:
  const std::string& m_message;
};

#endif // __ET_POLICYVERIFICATIONERROR__

///////////////////////////////////////////////////////////////////////////////
