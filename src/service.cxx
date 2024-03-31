module;

#include <iostream>
#include <variant>

export module service;

import library;

using namespace library;

export namespace service {
// TODO: When we eventually support more than just audio, this class can
// become templated.
class CopyAndOrganize {
public:
  void run(const MusicLibrary& input, LibraryCreator& output) {
    for (const auto& file : input) {
      auto result{output.add_file(file)};
      if (auto error{std::get_if<InvalidFileError>(&result)};
          nullptr != error) {
        std::cerr << "Error: " << error->what() << "\n";
      }
    }
  }
};
} // namespace service
