This application links against [TagLib](https://taglib.org/api/), which uses
dual LGPL and MPL licenses.

# Building

This project depends on a few libraries, which must be located somehow. The
`default` preset provides a `Find<lib>.cmake` script for each of these
dependencies, but there is also a `conanfile.txt` which can be used to build
with dependencies from Conan.

## Building with dependencies from Conan

```
conan install --build=missing -of builddir .
cmake --preset conan-release
cmake --build build
```

## Building with system libraries

```
cmake --preset default
cmake --build build
```

# Compilation Database

CMake is configured to generate a compilation database at configure time. To
use this, e.g. with neovim, symlink it into the project root directory:

```
ln -s build/compile_commands.json compile_commands.json
```
