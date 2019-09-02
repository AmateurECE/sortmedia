///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixAbsolutePathTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test for the Path class.
//
// CREATED:         08/30/2019
//
// LAST EDITED:     09/01/2019
////

#include "gtest/gtest.h"
#include "UnixAbsolutePathTest.h"

#include <iostream>
#include <string>

UnixAbsolutePathTest::UnixAbsolutePathTest()
  : extension{".test"}, filename{"path" + extension},
    actualPath{"/this/is/a/" + filename}
{}

void UnixAbsolutePathTest::SetUp()
{
  path = SortMedia::Path{actualPath};
}

void UnixAbsolutePathTest::TearDown()
{
  path.~Path();
}

TEST_F(UnixAbsolutePathTest, StringEquality)
{
  ASSERT_EQ(path.string(), actualPath);
}

TEST_F(UnixAbsolutePathTest, FilenameEquality)
{
  ASSERT_EQ(path.filename().string(), filename);
}

TEST_F(UnixAbsolutePathTest, ExtensionEquality)
{
  ASSERT_EQ(path.extension().string(), extension);
}

///////////////////////////////////////////////////////////////////////////////
