///////////////////////////////////////////////////////////////////////////////
// NAME:            main.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Includes the main function of the program.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     08/27/2019
////

#include <iostream>
#include <memory>

#include <SortMedia/MediaSorter.h>
#include <SortMedia/Logging/StreamLogger.h>

int main(int argc, char** argv)
{
  using LogLevel = SortMedia::Enums::LogLevel;
  auto allLevels = {LogLevel::INFO, LogLevel::WARNING, LogLevel::ERROR};

  std::unique_ptr<SortMedia::Interfaces::ILogger> logger =
    std::make_unique<SortMedia::Logging::StreamLogger>(std::cout, allLevels);

  SortMedia::MediaSorter sorter{*logger};
  sorter.sortDirectory("./Music");
}

///////////////////////////////////////////////////////////////////////////////
