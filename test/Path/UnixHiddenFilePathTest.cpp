///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixHiddenFilePathTest.cpp
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
#include "UnixHiddenFilePathTest.h"

UnixHiddenFilePathTest::UnixHiddenFilePathTest()
  : filename{".test"}, rootPath{"/"},
    parentPath{rootPath + "this/is/a"},
    actualPath{parentPath + "/" + filename},
    path{SortMedia::Path{actualPath}}
{}

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

TEST_F(UnixHiddenFilePathTest, ParentPathEquality)
{
  ASSERT_EQ(path.parent_path().string(), parentPath);
}

TEST_F(UnixHiddenFilePathTest, RootPathEquality)
{
  ASSERT_EQ(path.root_path().string(), rootPath);
}

///////////////////////////////////////////////////////////////////////////////
