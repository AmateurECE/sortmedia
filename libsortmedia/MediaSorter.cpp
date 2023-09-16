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
// LAST EDITED:     09/26/2019
////

#include <libsortmedia/Interfaces/IFileLocator.h>
#include <libsortmedia/Interfaces/IOrganizationalSchema.h>
#include <libsortmedia/Interfaces/ILogger.h>
#include <libsortmedia/MediaSorter.h>

#include <FSAdaptor/Path.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>

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

  const FSAdaptor::StandardFilesystemAdaptor adaptor;
  const FSAdaptor::Path theDirectory
  {adaptor.absolute(FSAdaptor::Path{directory})};
  std::list<FSAdaptor::Path> paths
    = m_locator.recursivelyListFilesInDirectory(theDirectory);

  for (auto path : paths)
    {
      m_schema.applyToFile(path, theDirectory);
    }

  return 0;
}

///////////////////////////////////////////////////////////////////////////////
