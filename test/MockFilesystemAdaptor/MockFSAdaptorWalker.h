///////////////////////////////////////////////////////////////////////////////
// NAME:            MockFSAdaptorWalker.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     A Mock of the IFilesystemAdaptor interface for testing.
//                  This class mocks the walk() method. It takes, in its
//                  constructor, an input stream. During a call to walk(), it
//                  reads paths, line by line, from this input stream, and then
//                  inserts them into the IPathWalker object that it is passed.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/05/2019
////

#ifndef __ET_MOCKFSADAPTORWALKER__
#define __ET_MOCKFSADAPTORWALKER__

#include <FSAdaptor/IFilesystemAdaptor.h>
#include <FSAdaptor/IPathWalker.h>
#include <FSAdaptor/Path.h>

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

class MockFSAdaptorWalker : public FSAdaptor::IFilesystemAdaptor
{
public:
  MockFSAdaptorWalker(std::ifstream& input)
  {
    std::string line;

    while (std::getline(input, line))
      {
        m_paths.push_back(FSAdaptor::Path{line});
      }
  }

  virtual void walk(FSAdaptor::IPathWalker& walker,
                    const FSAdaptor::Path& directory)
    const final override
  {
    for_each(m_paths.begin(), m_paths.end(),
             [&walker](const FSAdaptor::Path& e)
             {
               walker.insert(e);
             });
  }

  const std::vector<FSAdaptor::Path>& getFiles() const
  {
    return m_paths;
  }

  virtual bool isEmpty(const FSAdaptor::Path& p)
    const final override { return false; }
  virtual bool isDirectory(const FSAdaptor::Path& p)
    const final override { return false; }

  virtual void rename(const FSAdaptor::Path& oldPath,
                      const FSAdaptor::Path& newPath)
    const final override {}
  virtual void remove(const FSAdaptor::Path& p) const final override {}
  virtual bool equivalent(const FSAdaptor::Path& p1, const FSAdaptor::Path& p2)
    const final override { return false; }
  virtual bool exists(const FSAdaptor::Path& p)
    const final override { return false; }
  virtual FSAdaptor::Path currentPath() const final override { return {}; }
  virtual void createDirectory(const FSAdaptor::Path& p)
    const final override {}
  virtual void createDirectories(const FSAdaptor::Path& p)
    const final override {}
  virtual FSAdaptor::Path absolute(const FSAdaptor::Path& p)
    const final override { return {}; }

private:
  std::vector<FSAdaptor::Path> m_paths;
};

#endif // __ET_MOCKFSADAPTORWALKER__

///////////////////////////////////////////////////////////////////////////////
