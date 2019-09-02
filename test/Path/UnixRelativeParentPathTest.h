///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixRelativeParentPathTest.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     More tests for the Path class.
//
// CREATED:         09/01/2019
//
// LAST EDITED:     09/02/2019
////

#ifndef __ET_UNIXRELATIVEPARENTPATHTEST__
#define __ET_UNIXRELATIVEPARENTPATHTEST__

#include <SortMedia/Path.h>

class UnixRelativeParentPathTest : public ::testing::Test
{
protected:
  UnixRelativeParentPathTest();

  const std::string extension;
  const std::string filename;
  const std::string actualPath;
  SortMedia::Path path;
};

#endif // __ET_UNIXRELATIVEPARENTPATHTEST__

///////////////////////////////////////////////////////////////////////////////
