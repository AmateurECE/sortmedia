///////////////////////////////////////////////////////////////////////////////
// NAME:            MediaSorter.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains definitions for the functions of the class
//                  MediaSorter.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     09/06/2019
////

#include <SortMedia/Interfaces/IFileLocator.h>
#include <SortMedia/Interfaces/IOrganizationalSchema.h>
#include <SortMedia/Interfaces/ILogger.h>
#include <SortMedia/MediaSorter.h>

#include <FSAdaptor/Path.h>

#include <list>

SortMedia::MediaSorter::MediaSorter(Interfaces::ILogger& logger,
                                    Interfaces::IOrganizationalSchema& schema,
                                    Interfaces::IFileLocator& locator)
  : m_logger(logger), m_schema(schema), m_locator(locator)
{}

SortMedia::MediaSorter::~MediaSorter()
{}

int SortMedia::MediaSorter::sortDirectory(const std::string& directory)
{
  m_logger.log("Sorting " + directory, Logging::LogLevel::INFO);

  const FSAdaptor::Path theDirectory{directory};
  std::list<FSAdaptor::Path> paths
    = m_locator.recursivelyListFilesInDirectory(theDirectory);

  for (auto path : paths)
    {
      m_schema.applyToFile(path);
    }

  return 0;
}

///////////////////////////////////////////////////////////////////////////////
