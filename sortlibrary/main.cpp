///////////////////////////////////////////////////////////////////////////////
// NAME:            main.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Includes the main function of the program.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     02/06/2022
////

#include <argp.h>
#include <iostream>
#include <memory>

#include <config.h>
#include <libsortmedia/MediaSorter.h>
#include <libsortmedia/Logging/StreamLogger.h>
#include <libsortmedia/Factories/FileLocatorFactory.h>
#include <libsortmedia/Factories/OrganizationalSchemaFactory.h>

const char* argp_program_version = "SortLibrary " PROGRAM_VERSION_STRING;
const char* argp_program_bug_address = "<ethan.twardy@gmail.com>";

static char doc[] =
    "Sort a music library according to pre-defined organizational policies";
static char args_doc[] = "DIRECTORY";
static const int NUMBER_OF_ARGUMENTS = 1;

struct Arguments {
    const char* directory;
};

static error_t parse_opt(int key, char* arg, struct argp_state* state) {
    Arguments* arguments = (Arguments*)state->input;
    switch (key) {
    case ARGP_KEY_ARG:
        if (state->arg_num >= NUMBER_OF_ARGUMENTS) {
            argp_usage(state);
        }

        arguments->directory = arg;
        break;
    case ARGP_KEY_END:
        if (state->arg_num < NUMBER_OF_ARGUMENTS) {
            argp_usage(state);
        }
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

int ApplicationMain(Arguments& args)
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
  std::string theLibrary{args.directory};
  sorter.sortDirectory(theLibrary);
  return 0;
}

static struct argp argp = { 0, parse_opt, args_doc, doc, 0, 0, 0 };
int main(int argc, char** argv)
{
    Arguments args = {0};
    argp_parse(&argp, argc, argv, 0, 0, &args);
    return ApplicationMain(args);
}

///////////////////////////////////////////////////////////////////////////////
