///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixHiddenFilePathTest.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     More tests for the Path class.
//
// CREATED:         09/01/2019
//
// LAST EDITED:     09/01/2019
////

#ifndef __ET_UNIXHIDDENFILEPATHTEST__
#define __ET_UNIXHIDDENFILEPATHTEST__

#include <SortMedia/Path.h>

class UnixHiddenFilePathTest : public ::testing::Test
{
protected:
  UnixHiddenFilePathTest();
  void SetUp() override;
  void TearDown() override;

  const std::string extension;
  const std::string filename;
  const std::string actualPath;
  SortMedia::Path path;
};

#endif // __ET_UNIXHIDDENFILEPATHTEST__

///////////////////////////////////////////////////////////////////////////////
