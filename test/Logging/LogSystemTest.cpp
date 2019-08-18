///////////////////////////////////////////////////////////////////////////////
// NAME:            LogSystemTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains testing for the Logging System.
//
// CREATED:         08/17/2019
//
// LAST EDITED:     08/18/2019
////

#include "gtest/gtest.h"
#include "LogSystemTest.h"

#include <CrossCutting/Logging/LoggerFactory.h>

// Cases to test:
// OneInfo, OneWarning, OneError: Append only one logger of each level
// OneOfEach: Append three loggers, each with only one level
// TwoOfSame: Append two or more loggers of the same level
// OneTwoLevel: Append one logger of two or more levels
// MultipleCoverage: Append Logger(INFO, WARNING) and Logger(WARNING)
// Unconfigured: Do not configure the logger
// InvalidLog: Reconfigure the logger and attempt to log to an invalid logger.
// NoListener: Log a message that does not have a corresponding logger.

TEST_F(LogSystemTest, OneInfo)
{
  CrossCutting::Logging::LoggerConfiguration config;
  std::ostringstream infoStream;

  config.appendLogger(infoStream, {LogLevel::INFO});

  std::shared_ptr<ILogger> log = \
    CrossCutting::Logging::LoggerFactory::makeLogger();
  log->log("Testing INFO", LogLevel::INFO);

  EXPECT_EQ(infoStream.str(), "INFO: Testing INFO\n");
}

///////////////////////////////////////////////////////////////////////////////
