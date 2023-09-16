This application links against [TagLib](https://taglib.org/api/), which uses
dual LGPL and MPL licenses.

# Building

Today, we use Conan for pulling in some dependencies. This is optional. If
the dependencies are available in the system, it should be possible to build
the application and library without the `conan install` step.

```
$ conan install -of build .
$ cmake -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=$PWD/build/conan_toolchain.cmake .
$ cmake --build build
```

# Compilation Database

CMake is configured to generate a compilation database at configure time. To
use this, e.g. with neovim, symlink it into the project root directory:

```
$ ln -s build/compile_commands.json compile_commands.json
```
