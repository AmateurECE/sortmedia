///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixHiddenFilePathTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     
//
// CREATED:         09/01/2019
//
// LAST EDITED:     09/01/2019
////

#include "gtest/gtest.h"
#include "UnixHiddenFilePathTest.h"

UnixHiddenFilePathTest::UnixHiddenFilePathTest()
  : filename{".test"},
    actualPath{"/this/is/a/" + filename}
{}

void UnixHiddenFilePathTest::SetUp()
{
  path = SortMedia::Path{actualPath};
}

void UnixHiddenFilePathTest::TearDown()
{
  path.~Path();
}

TEST_F(UnixHiddenFilePathTest, StringEquality)
{
  ASSERT_EQ(path.string(), actualPath);
}

TEST_F(UnixHiddenFilePathTest, FilenameEquality)
{
  ASSERT_EQ(path.filename().string(), filename);
}

TEST_F(UnixHiddenFilePathTest, ExtensionEquality)
{
  ASSERT_EQ(path.extension().string(), "");
}

///////////////////////////////////////////////////////////////////////////////
