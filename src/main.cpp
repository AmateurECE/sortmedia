#include <CLI/CLI.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    CLI::App app{"Media library sorting application"};

    string input_tree = "", output_tree = "";
    app.add_option("-i", input_tree, "Input file tree");
    app.add_option("-o", output_tree, "Output location");

    CLI11_PARSE(app, argc, argv);

    std::cout << "input_tree=" << input_tree << ", output_tree=" << output_tree
              << "\n";
}
