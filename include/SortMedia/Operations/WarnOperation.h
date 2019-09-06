///////////////////////////////////////////////////////////////////////////////
// NAME:            WarnOperation.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This operation creates a log warning using the given text.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/05/2019
////

#ifndef __ET_WARNOPERATION__
#define __ET_WARNOPERATION__

#include <namespaces/Operations.h>
#include <namespaces/Interfaces.h>
#include <SortMedia/Interfaces/IFileOperation.h>

#include <string>

class SortMedia::Operations::WarnOperation
  : public SortMedia::Interfaces::IFileOperation
{
public:
  WarnOperation(Interfaces::ILogger& logger, const std::string& message);
  virtual void apply() final override;
  virtual void revert() final override;

private:
  Interfaces::ILogger& m_logger;
  const std::string& m_message;
};

#endif // __ET_WARNOPERATION__

///////////////////////////////////////////////////////////////////////////////
