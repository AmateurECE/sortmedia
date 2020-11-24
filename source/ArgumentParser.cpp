///////////////////////////////////////////////////////////////////////////////
// NAME:            ArgumentParser.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Class that parses the arguments to the Command Line Tool.
//
// CREATED:         09/06/2019
//
// LAST EDITED:     09/06/2019
////

#include <ArgumentParser.h>

#include <cstdio>
#include <cstring>

const std::string CommandLine::ArgumentParser::s_usage =
  std::string{"Usage: SortMedia <rootPathOfLibrary>"};

CommandLine::ArgumentParser::ArgumentParser()
{}

CommandLine::ArgumentParser::ArgumentParser(int argc, char** argv)
{
  if (argc != s_expectedNumberOfArguments + 1)
    {
      char errorMessage[128];
      memset(errorMessage, 0, sizeof(errorMessage));
      snprintf(errorMessage, sizeof(errorMessage) - 1,
               "Wrong number of arguments. Expected %d, got %d",
               s_expectedNumberOfArguments, argc);
      throw std::invalid_argument{errorMessage};
    }

  m_arguments.insert(std::make_pair<>(DIRECTORY, std::string{argv[1]}));
}

template<>
std::string
CommandLine::ArgumentParser::getArgument(ArgumentKey key) const
{
  auto result = m_arguments.end();
  if ((result = m_arguments.find(key)) != m_arguments.end())
    {
      return result->second;
    }

  throw std::invalid_argument{"No argument matching provided key."};
}

const std::string& CommandLine::ArgumentParser::getUsage() const
{
  return s_usage;
}

///////////////////////////////////////////////////////////////////////////////
