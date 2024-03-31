module;

#include "version.h"
#include <CLI/CLI.hpp>

export module main;

import library;
import policy;
import service;

using namespace std;
using namespace library;
using namespace policy;
using namespace service;

int main(int argc, char** argv) {
  CLI::App app{"Media library sorting application"};
  app.set_version_flag("--version", version::VERSION);

  string input_tree{""}, output_directory{""};
  app.add_option("-i", input_tree, "Input file tree");
  app.add_option("-o", output_directory, "Output directory");

  CLI11_PARSE(app, argc, argv);

  MusicLibrary input_library{input_tree};

  vector<unique_ptr<ITransformLibraryFiles>> transformations;
  transformations.push_back(make_unique<AudioOrganizationPolicy>());
  transformations.push_back(make_unique<ImagePresencePolicy>());
  LibraryCreator destination{filesystem::path(output_directory),
                             std::move(transformations)};

  CopyAndOrganize service;
  service.run(input_library, destination);
}
