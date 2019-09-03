///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixAbsolutePathTest.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test for the Path class.
//
// CREATED:         08/30/2019
//
// LAST EDITED:     09/02/2019
////

#ifndef __ET_PATHTEST__
#define __ET_PATHTEST__

#include <SortMedia/Path.h>

class UnixAbsolutePathTest : public ::testing::Test
{
protected:
  UnixAbsolutePathTest();

  const std::string extension;
  const std::string filename;
  const std::string rootPath;
  const std::string parentPath;
  const std::string actualPath;
  SortMedia::Path path;
};

#endif // __ET_PATHTEST__

///////////////////////////////////////////////////////////////////////////////
