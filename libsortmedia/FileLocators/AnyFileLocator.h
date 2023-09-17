///////////////////////////////////////////////////////////////////////////////
// NAME:            AnyFileLocator.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Class definition for a FileLocator that does not perform
//                  filtering on the input files.
//
// CREATED:         09/05/2019
////

#ifndef __ET_ANYFILELOCATOR__
#define __ET_ANYFILELOCATOR__

#include <libsortmedia/namespaces/FileLocators.h>
#include <libsortmedia/Interfaces/IFileLocator.h>

#include <fsadaptor/namespace.h>
#include <fsadaptor/StandardFilesystemAdaptor.h>

#include <list>

class SortMedia::FileLocators::AnyFileLocator
  : public SortMedia::Interfaces::IFileLocator
{
public:
  AnyFileLocator(const FSAdaptor::IFilesystemAdaptor& adaptor = s_stdAdaptor);
  virtual std::list<FSAdaptor::Path> recursivelyListFilesInDirectory
  (const FSAdaptor::Path& directory) const final override;

private:
  const FSAdaptor::IFilesystemAdaptor& m_adaptor;
  static const FSAdaptor::StandardFilesystemAdaptor s_stdAdaptor;
};

#endif // __ET_ANYFILELOCATOR__

///////////////////////////////////////////////////////////////////////////////
