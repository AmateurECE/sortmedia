///////////////////////////////////////////////////////////////////////////////
// NAME:            AnyFileLocator.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Class definition for a FileLocator that does not perform
//                  filtering on the input files.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/05/2019
////

#ifndef __ET_ANYFILELOCATOR__
#define __ET_ANYFILELOCATOR__

#include <namespaces/FileLocators.h>
#include <SortMedia/Interfaces/IFileLocator.h>

#include <FSAdaptor/namespace.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>

#include <list>

class SortMedia::FileLocators::AnyFileLocator
  : public SortMedia::Interfaces::IFileLocator
{
public:
  AnyFileLocator(const FSAdaptor::IFilesystemAdaptor& adaptor
                 = FSAdaptor::StandardFilesystemAdaptor{});
  virtual std::list<FSAdaptor::Path> recursivelyListFilesInDirectory
  (const FSAdaptor::Path& directory) const final override;

private:
  const FSAdaptor::IFilesystemAdaptor& m_adaptor;
};

#endif // __ET_ANYFILELOCATOR__

///////////////////////////////////////////////////////////////////////////////
