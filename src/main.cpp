#include <CLI/CLI.hpp>
#include "version.h"

import std;
import library;
import policy;
import service;

using std::unique_ptr;
using std::vector;
using std::make_unique;
namespace fs = std::filesystem;

int main(int argc, char** argv) {
  CLI::App app{"Media library sorting application"};
  app.set_version_flag("--version", version::VERSION);

  std::string input_tree{""}, output_directory{""};
  app.add_option("-i", input_tree, "Input file tree");
  app.add_option("-o", output_directory, "Output directory");

  CLI11_PARSE(app, argc, argv);

  std::cout << input_tree << "\n";
  MusicLibrary input_library{input_tree};

  vector<unique_ptr<ITransformLibraryFiles>> transformations;
  transformations.push_back(make_unique<AudioOrganizationPolicy>());
  transformations.push_back(make_unique<ImagePresencePolicy>());
  LibraryCreator destination{fs::path(output_directory),
                             std::move(transformations)};

  CopyAndOrganize service;
  service.run(input_library, destination);
}
