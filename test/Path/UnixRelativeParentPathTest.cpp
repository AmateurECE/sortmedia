///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixRelativeParentPathTest.cpp
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
#include "UnixRelativeParentPathTest.h"

UnixRelativeParentPathTest::UnixRelativeParentPathTest()
  : extension{".test"}, filename{"path" + extension},
    actualPath{"../this/is/a/" + filename}
{}

void UnixRelativeParentPathTest::SetUp()
{
  path = SortMedia::Path{actualPath};
}

void UnixRelativeParentPathTest::TearDown()
{
  path.~Path();
}

TEST_F(UnixRelativeParentPathTest, StringEquality)
{
  ASSERT_EQ(path.string(), actualPath);
}

TEST_F(UnixRelativeParentPathTest, FilenameEquality)
{
  ASSERT_EQ(path.filename().string(), filename);
}

TEST_F(UnixRelativeParentPathTest, ExtensionEquality)
{
  ASSERT_EQ(path.extension().string(), extension);
}

///////////////////////////////////////////////////////////////////////////////
