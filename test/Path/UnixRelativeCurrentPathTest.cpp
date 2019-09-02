///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixRelativeCurrentPathTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     
//
// CREATED:         09/01/2019
//
// LAST EDITED:     09/02/2019
////

#include "gtest/gtest.h"
#include "UnixRelativeCurrentPathTest.h"

UnixRelativeCurrentPathTest::UnixRelativeCurrentPathTest()
  : extension{".test"}, filename{"path" + extension},
    actualPath{"./this/is/a/" + filename},
    path{SortMedia::Path{actualPath}}
{}

TEST_F(UnixRelativeCurrentPathTest, StringEquality)
{
  ASSERT_EQ(path.string(), actualPath);
}

TEST_F(UnixRelativeCurrentPathTest, FilenameEquality)
{
  ASSERT_EQ(path.filename().string(), filename);
}

TEST_F(UnixRelativeCurrentPathTest, ExtensionEquality)
{
  ASSERT_EQ(path.extension().string(), extension);
}

///////////////////////////////////////////////////////////////////////////////
