///////////////////////////////////////////////////////////////////////////////
// NAME:            IFileOperation.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     An interface for File Operations.
//
// CREATED:         08/07/2019
//
// LAST EDITED:     09/05/2019
////

#ifndef __ET_IFILEOPERATION__
#define __ET_IFILEOPERATION__

#include <libsortmedia/namespaces/Interfaces.h>

class SortMedia::Interfaces::IFileOperation
{
public:
  virtual ~IFileOperation() {}
  virtual void apply() = 0;
  virtual void revert() = 0;
};

#endif // __ET_IFILEOPERATION__

///////////////////////////////////////////////////////////////////////////////
