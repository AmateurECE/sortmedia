///////////////////////////////////////////////////////////////////////////////
// NAME:            main.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Includes the main function of the program.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     09/06/2019
////

#include <iostream>
#include <memory>

#include <SortMedia/MediaSorter.h>
#include <SortMedia/Logging/StreamLogger.h>
#include <SortMedia/Factories/FileLocatorFactory.h>
#include <SortMedia/Factories/OrganizationalSchemaFactory.h>

int main(int argc, char** argv)
{
  using LogLevel = SortMedia::Logging::LogLevel;
  auto allLevels = {LogLevel::INFO, LogLevel::WARNING, LogLevel::ERROR};

  std::unique_ptr<SortMedia::Interfaces::ILogger> logger =
    std::make_unique<SortMedia::Logging::StreamLogger>(std::cout, allLevels);

  SortMedia::Factories::OrganizationalSchemaFactory schemaFactory;
  SortMedia::Factories::FileLocatorFactory locatorFactory;

  auto schema = schemaFactory.makeOrganizationalSchema();
  auto locator = locatorFactory.makeFileLocator();

  SortMedia::MediaSorter sorter{*logger, *schema, *locator};
  sorter.sortDirectory("./Music");
}

///////////////////////////////////////////////////////////////////////////////
