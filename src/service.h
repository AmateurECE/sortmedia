#ifndef SERVICE_H
#define SERVICE_H

#include "library.h"
#include "policy.h"

class CopyAndOrganize {
public:
  void run(const MusicLibrary& input, AudioOrganizationPolicy& policy,
           MusicLibrary& output) {
    for (const auto& file : input) {
      // TODO: Validate the input file to make sure the tags have enough
      // fidelity to organize this file.

      auto name{policy.get_compliant_path(file)};
      auto message{
          std::format("{} -> {}\n", file.path().c_str(), name.c_str())};
      std::cout << message;

      // TODO: Copy the input file to the output library

      // TODO: Apply the policy to fix any metadata
    }
  }
};

#endif // SERVICE_H
