///////////////////////////////////////////////////////////////////////////////
// NAME:            IPathWalker.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition of the IPathWalker interface.
//
// CREATED:         09/04/2019
//
// LAST EDITED:     09/04/2019
////

#ifndef __ET_IPATHWALKER__
#define __ET_IPATHWALKER__

#include <FSAdaptor/namespace.h>

class FSAdaptor::IPathWalker
{
public:
  virtual ~IPathWalker() {};
  virtual void insert(const Path&) = 0;
};

#endif // __ET_IPATHWALKER__

///////////////////////////////////////////////////////////////////////////////
