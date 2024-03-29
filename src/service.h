#ifndef SERVICE_H
#define SERVICE_H

#include "library.h"

// TODO: When we eventually support more than just audio, this class can
// become templated.
class CopyAndOrganize {
public:
  void run(const MusicLibrary& input, LibraryCreator& output) {
    for (const auto& file : input) {
      output.add_file(file);
    }
  }
};

#endif // SERVICE_H
