///////////////////////////////////////////////////////////////////////////////
// NAME:            UnixRelativeParentPathTest.cpp
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
#include "UnixRelativeParentPathTest.h"

UnixRelativeParentPathTest::UnixRelativeParentPathTest()
  : extension{".test"}, filename{"path" + extension},
    parentPath{"../this/is/a/"},
    actualPath{parentPath + "/" + filename},
    path{SortMedia::Path{actualPath}}
{}

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

TEST_F(UnixRelativeParentPathTest, ParentPathEquality)
{
  ASSERT_EQ(path.parent_path().string(), parentPath);
}

TEST_F(UnixRelativeParentPathTest, RootPathEquality)
{
  ASSERT_EQ(path.root_path().string(), "");
}

///////////////////////////////////////////////////////////////////////////////
