///////////////////////////////////////////////////////////////////////////////
// NAME:            LogSystemTest.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test the Logging subsystem.
//
// CREATED:         08/18/2019
//
// LAST EDITED:     08/18/2019
////

#ifndef __ET_LOGSYSTEMTEST__
#define __ET_LOGSYSTEMTEST__

#include "gtest/gtest.h"

#include <CrossCutting/Logging/LoggerConfiguration.h>

class LogSystemTest : public ::testing::Test
{
protected:
  LogSystemTest()
  {
    // Set up for the test fixture
    std::cout << "Settings up the test fixture..." << std::endl;
  }

  ~LogSystemTest()
  {
    // Tear down for the test fixture
    std::cout << "Tear down for the test fixture..." << std::endl;
  }

  void SetUp() override
  {
    // Set up for each test
    std::cout << "Setting up the test..." << std::endl;
  }

  void TearDown() override
  {
    // Tear down for each test
    std::cout << "Tearing down the test..." << std::endl;
  }
};

#endif // __ET_LOGSYSTEMTEST__

///////////////////////////////////////////////////////////////////////////////
