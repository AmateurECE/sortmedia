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
// LAST EDITED:     08/27/2019
////

#include <SortMedia/MediaSorter.h>

SortMedia::MediaSorter::MediaSorter(Interfaces::ILogger& logger,
                                    Interfaces::IOrganizationalSchema& schema,
                                    Interfaces::IFileLocator& locator)
  : logger(logger), schema(schema), locator(locator)
{
}

SortMedia::MediaSorter::~MediaSorter()
{
}

int SortMedia::MediaSorter::sortDirectory(const std::string& directory)
{
  logger.log("Sorting " + directory, Enums::LogLevel::INFO);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
