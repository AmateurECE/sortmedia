///////////////////////////////////////////////////////////////////////////////
// NAME:            LogSystemTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains testing for the Logging System.
//
// CREATED:         08/17/2019
////

#include "gtest/gtest.h"
#include "LogSystemTest.h"

#include <libsortmedia/Logging/StreamLogger.h>

// Cases to test:
// OneInfo, OneWarning, OneError: Append only one logger of each level
// OneOfEach: Append three loggers, each with only one level
// TwoOfSame: Append two or more loggers of the same level
// OneTwoLevel: Append one logger of two or more levels
// MultipleCoverage: Append Logger(INFO, WARNING) and Logger(WARNING)
// Unconfigured: Do not configure the logger
// InvalidLog: Reconfigure the logger and attempt to log to an invalid logger.
// NoListener: Log a message that does not have a corresponding logger.

using SortMedia::Logging::StreamLogger;
using SortMedia::Logging::LogLevel;

// TEST_F(LogSystemTest, OneInfo)
// {
//   std::ostringstream infoStream;
//   StreamLogger logger{infoStream, {LogLevel::INFO}};

//   logger.log("Testing INFO", LogLevel::INFO);

//   EXPECT_EQ(infoStream.str(), "INFO: Testing INFO\n");
// }

///////////////////////////////////////////////////////////////////////////////
