///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixAbsolutePathTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test for the Path class.
//
// CREATED:         08/30/2019
//
// LAST EDITED:     09/02/2019
////

#include "gtest/gtest.h"
#include "UnixAbsolutePathTest.h"

#include <iostream>
#include <string>

UnixAbsolutePathTest::UnixAbsolutePathTest()
  : extension{".test"}, filename{"path" + extension},
    parentPath{"/this/is/a"},
    actualPath{parentPath + "/" + filename},
    path{SortMedia::Path{actualPath}}
{}

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

TEST_F(UnixAbsolutePathTest, ParentPathEquality)
{
  ASSERT_EQ(path.parent_path().string(), parentPath);
}

///////////////////////////////////////////////////////////////////////////////
