///////////////////////////////////////////////////////////////////////////////
// NAME:            PolicyVerificationError.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Custom Exception type thrown if an error is encountered
//                  during verification.
//
// CREATED:         09/08/2019
////

#ifndef __ET_POLICYVERIFICATIONERROR__
#define __ET_POLICYVERIFICATIONERROR__

#include <libsortmedia/namespaces/Exceptions.h>
#include <libsortmedia/Exceptions/ExceptionBase.h>

#include <string>

class SortMedia::Exceptions::PolicyVerificationError
  : public SortMedia::Exceptions::ExceptionBase
{
public:
  PolicyVerificationError(const std::string& message);
  const char* what() const noexcept;

private:
  const std::string& m_message;
};

#endif // __ET_POLICYVERIFICATIONERROR__

///////////////////////////////////////////////////////////////////////////////
