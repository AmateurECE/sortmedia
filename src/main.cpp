#include <CLI/CLI.hpp>
#include <iostream>

#include "library.h"
#include "version.h"

using namespace std;
using namespace std::filesystem;

int main(int argc, char** argv) {
  CLI::App app{"Media library sorting application"};
  app.set_version_flag("--version", version::VERSION);

  string input_tree{""}, output_directory{""};
  app.add_option("-i", input_tree, "Input file tree");
  app.add_option("-o", output_directory, "Output directory");

  CLI11_PARSE(app, argc, argv);

  std::cout << "input_tree=" << input_tree
            << ", output_tree=" << output_directory << "\n";

  MusicLibrary library{input_tree};
  for (const auto& entry : library) {
    std::cout << entry << '\n';
  }
}
