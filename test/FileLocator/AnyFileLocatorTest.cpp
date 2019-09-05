///////////////////////////////////////////////////////////////////////////////
// NAME:            AnyFileLocatorTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Tests.
//
// CREATED:         08/29/2019
//
// LAST EDITED:     09/05/2019
////

#include "gtest/gtest.h"

#include "../MockFilesystemAdaptor/MockFSAdaptorWalker.h"
#include "AnyFileLocatorTest.h"

#include <namespaces/Interfaces.h>
#include <SortMedia/FileLocators/AnyFileLocator.h>

#include <FSAdaptor/Path.h>

#include <algorithm>
#include <list>
#include <vector>

TEST_F(AnyFileLocatorTest, ListTest)
{
  std::ifstream inputFile{"test/testData/TestFileList.txt"};
  MockFSAdaptorWalker adaptor{inputFile};
  const std::vector<FSAdaptor::Path>& control = adaptor.getFiles();

  SortMedia::FileLocators::AnyFileLocator fileLocator{adaptor};

  const std::list<FSAdaptor::Path> underTest
    = fileLocator.recursivelyListFilesInDirectory(FSAdaptor::Path{});

  ASSERT_EQ(control.size(), underTest.size());

  bool discovered;
  for (auto i : control)
    {
      discovered = false;
      for (auto j : underTest)
        {
          if (i.string() == j.string())
            {
              discovered = true;
            }
        }
      ASSERT_TRUE(discovered);
    }
}

///////////////////////////////////////////////////////////////////////////////
