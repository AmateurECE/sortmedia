///////////////////////////////////////////////////////////////////////////////
// NAME:            namespace.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Namespace declaration.
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/04/2019
////

#ifndef __ET_FSADAPTOR_NAMESPACE__
#define __ET_FSADAPTOR_NAMESPACE__

namespace FSAdaptor
{
  class Path;
  class IPathWalker;
  template<template<class...> class Container>
  class PathWalker;

  class IFilesystemAdaptor;
  class StandardFilesystemAdaptor;
};

#endif /* __ET_FSADAPTOR_NAMESPACE__ */

///////////////////////////////////////////////////////////////////////////////
