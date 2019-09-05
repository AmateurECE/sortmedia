///////////////////////////////////////////////////////////////////////////////
// NAME:            PathWalker.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition of the PathWalker template class.
//
// CREATED:         09/04/2019
//
// LAST EDITED:     09/04/2019
////

#ifndef __ET_PATHWALKER__
#define __ET_PATHWALKER__

#include <FSAdaptor/namespace.h>
#include <FSAdaptor/IPathWalker.h>

template<template<class...> class Container>
class FSAdaptor::PathWalker : public FSAdaptor::IPathWalker
{
public:
  PathWalker() = default;
  virtual void insert(const Path& path) final override
  {
    m_paths.push_back(path);
  }

  Container<Path>& getContainer()
  {
    return m_paths;
  }

private:
  Container<Path> m_paths;
};

#endif // __ET_PATHWALKER__

///////////////////////////////////////////////////////////////////////////////
