///////////////////////////////////////////////////////////////////////////////
// NAME:            ExceptionBase.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Base class for exceptions.
//
// CREATED:         09/10/2019
//
// LAST EDITED:     09/10/2019
////

#ifndef __ET_EXCEPTIONBASE__
#define __ET_EXCEPTIONBASE__

#include <namespaces/Exceptions.h>

#include <exception>

class SortMedia::Exceptions::ExceptionBase
  : public std::exception
{
public:
  virtual ~ExceptionBase() {}

  virtual const char* what() const noexcept = 0;
};

#endif // __ET_EXCEPTIONBASE__

///////////////////////////////////////////////////////////////////////////////
