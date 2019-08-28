///////////////////////////////////////////////////////////////////////////////
// NAME:            MediaSorter.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains the definition of the MediaSorter. This class
//                  sorts directories on the filesystem using the rules
//                  specified by the injected dependencies.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     08/27/2019
////

#ifndef __ET_MEDIASORTER__
#define __ET_MEDIASORTER__

#include <namespaces/SortMedia.h>
#include <SortMedia/Interfaces/ILogger.h>

#include <string>

class SortMedia::MediaSorter
{
public:
  MediaSorter(Interfaces::ILogger& logger,
              Interfaces::IOrganizationalSchema& schema,
              Interfaces::IFileLocator& locator);
  ~MediaSorter();
  int sortDirectory(const std::string& directory);

private:
  Interfaces::ILogger& logger;
  Interfaces::IOrganizationalSchema& schema;
  Interfaces::IFileLocator& locator;
};

#endif // __ET_MEDIASORTER__

///////////////////////////////////////////////////////////////////////////////
