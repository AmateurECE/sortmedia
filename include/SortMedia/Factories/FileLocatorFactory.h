///////////////////////////////////////////////////////////////////////////////
// NAME:            FileLocatorFactory.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Class definition for the FileLocatorFactory class.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     08/27/2019
////

#ifndef __ET_FILELOCATORFACTORY__
#define __ET_FILELOCATORFACTORY__

#include <namespaces/Factories.h>
#include <SortMedia/Interfaces/IFileLocator.h>

#include <memory>

class SortMedia::Factories::FileLocatorFactory
{
public:
  FileLocatorFactory();
  std::unique_ptr<Interfaces::IFileLocator> makeFileLocator() const;
};

#endif // __ET_FILELOCATORFACTORY__

///////////////////////////////////////////////////////////////////////////////
