///////////////////////////////////////////////////////////////////////////////
// NAME:            OperationalError.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Custom Exception type thrown if an error is encountered
//                  during verification.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/10/2019
////

#ifndef __ET_OPERATIONALERROR__
#define __ET_OPERATIONALERROR__

#include <namespaces/Exceptions.h>
#include <SortMedia/Exceptions/ExceptionBase.h>

#include <string>

class SortMedia::Exceptions::OperationalError
  : public SortMedia::Exceptions::ExceptionBase
{
public:
  OperationalError(const std::string& message);
  const char* what() const noexcept;

private:
  const std::string& m_message;
};

#endif // __ET_OPERATIONALERROR__

///////////////////////////////////////////////////////////////////////////////
