#ifndef SERVICE_H
#define SERVICE_H

#include "library.h"
#include "policy.h"

// TODO: When we eventually support more than just audio, this class can
// become templated.
class CopyAndOrganize {
public:
  // TODO: The organizational policy _feels_ like a property of the library...
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

      // TODO: What about library-wide policies? E.g, "every album folder
      // shall have artwork, whether in the audio files themselves or as a
      // separate file." Where do those checks go, and when do they happen?
      // What about collection-wide heuristics? E.g., TOTALTRACKS isn't set,
      // but we can assume that all tracks are present, so we can set the
      // value of TOTALTRACKS based on that assumption.
    }
  }
};

#endif // SERVICE_H
