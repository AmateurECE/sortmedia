///////////////////////////////////////////////////////////////////////////////
// NAME:            Warn.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This operation creates a log warning using the given text.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/09/2019
////

#ifndef __ET_WARNOPERATION__
#define __ET_WARNOPERATION__

#include <libsortmedia/namespaces/Operations.h>
#include <libsortmedia/namespaces/Interfaces.h>
#include <libsortmedia/Interfaces/IFileOperation.h>

#include <string>

class SortMedia::Operations::Warn
  : public SortMedia::Interfaces::IFileOperation
{
public:
  Warn(Interfaces::ILogger& logger, std::string message);
  virtual void apply() final override;
  virtual void revert() final override;

private:
  Interfaces::ILogger& m_logger;
  std::string m_message;
};

#endif // __ET_WARNOPERATION__

///////////////////////////////////////////////////////////////////////////////
