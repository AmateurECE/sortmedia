///////////////////////////////////////////////////////////////////////////////
// NAME:            IFileLocator.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     An interface for FileLocator classes.
//
// CREATED:         08/07/2019
////

#ifndef __ET_IFILELOCATOR__
#define __ET_IFILELOCATOR__

#include <libsortmedia/namespaces/Interfaces.h>

#include <FSAdaptor/namespace.h>

#include <list>

class SortMedia::Interfaces::IFileLocator
{
public:
  virtual ~IFileLocator() {}
  virtual std::list<FSAdaptor::Path> recursivelyListFilesInDirectory
  (const FSAdaptor::Path& directory) const = 0;
};

#endif // __ET_IFILELOCATOR__

///////////////////////////////////////////////////////////////////////////////
