///////////////////////////////////////////////////////////////////////////////
// NAME:            StandardFilesystemAdaptor.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     The default Filesystem Adaptor. Used by SortMedia classes
//                  when not substituted with a mock impelementation.
//
// CREATED:         08/29/2019
//
// LAST EDITED:     08/30/2019
////

#ifndef __ET_STANDARDFILESYSTEMADAPTOR__
#define __ET_STANDARDFILESYSTEMADAPTOR__

#include <SortMedia/Interfaces/IFilesystemAdaptor.h>
#include <namespaces/Adaptors.h>

class SortMedia::Adaptors::StandardFilesystemAdaptor
  : public SortMedia::Interfaces::IFilesystemAdaptor
{
public:
  ~StandardFilesystemAdaptor() {};
  virtual std::iterator_traits<Path> walk(const Path& directory)
    const final override;
};

#endif // __ET_STANDARDFILESYSTEMADAPTOR__

///////////////////////////////////////////////////////////////////////////////
