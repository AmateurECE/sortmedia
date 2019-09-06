///////////////////////////////////////////////////////////////////////////////
// NAME:            ArgumentParser.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition for a class that parses command line arguments
//                  to the Command Line Tool.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/06/2019
////

#ifndef __ET_ARGUMENTPARSER__
#define __ET_ARGUMENTPARSER__

#include <map>
#include <string>
#include <stdint.h>

namespace CommandLine
{
  class ArgumentParser;
  enum ArgumentKey : uint8_t
    {
      DIRECTORY
    };
};

class CommandLine::ArgumentParser
{
public:
  ArgumentParser();
  ArgumentParser(int argc, char** argv);

  template<class T>
  T getArgument(ArgumentKey key) const;

  const std::string& getUsage() const;

private:
  // TODO: The value type in the map must be replaced
  //   With an interface implementing a type erasure system.
  std::map<ArgumentKey, std::string> m_arguments;
  static const int s_expectedNumberOfArguments = 1;
  static const std::string s_usage;
};

#endif // __ET_ARGUMENTPARSER__

///////////////////////////////////////////////////////////////////////////////
