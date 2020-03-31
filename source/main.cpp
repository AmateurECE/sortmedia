///////////////////////////////////////////////////////////////////////////////
// NAME:            main.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Includes the main function of the program.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     03/31/2020
////

#include <iostream>
#include <memory>

#include <ArgumentParser.h>

#include <SortMedia/MediaSorter.h>
#include <SortMedia/Logging/StreamLogger.h>
#include <SortMedia/Factories/FileLocatorFactory.h>
#include <SortMedia/Factories/OrganizationalSchemaFactory.h>

int ApplicationMain(CommandLine::ArgumentParser& parser)
{
  using LogLevel = SortMedia::Logging::LogLevel;
  auto outLevels = {LogLevel::INFO};
  auto errLevels = {LogLevel::WARNING, LogLevel::ERROR};

  std::unique_ptr<SortMedia::Interfaces::ILogger> logger =
    std::make_unique<SortMedia::Logging::StreamLogger>(std::cout, outLevels);
  logger->appendLogger(std::make_unique<SortMedia::Logging::StreamLogger>
                       (std::cerr, errLevels));

  SortMedia::Factories::OrganizationalSchemaFactory schemaFactory;
  SortMedia::Factories::FileLocatorFactory locatorFactory;

  auto schema = schemaFactory.makeOrganizationalSchema(*logger);
  auto locator = locatorFactory.makeFileLocator();

  SortMedia::MediaSorter sorter{*logger, *schema, *locator};
  std::string theLibrary
    = parser.getArgument<std::string>(CommandLine::ArgumentKey::DIRECTORY);
  sorter.sortDirectory(theLibrary);
  return 0;
}

int main(int argc, char** argv)
{
  CommandLine::ArgumentParser parser;
  try { parser = CommandLine::ArgumentParser{argc, argv}; }
  catch (const std::invalid_argument& e)
    {
      std::cerr << parser.getUsage() << std::endl;
      return 1;
    }

  try { return ApplicationMain(parser); }
  // I'm aware that it's typically bad practice to catch std::exception.
  // However, this is the only way that we can guarantee that a useful message
  // will be printed to stderr.
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }
}

///////////////////////////////////////////////////////////////////////////////
