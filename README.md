# Motivation

This is mostly a fun project for me--something to save myself a little time
(though I'm sure I've spent more time than I've saved in authoring this
application over the years). It's also an exercise to help me stay up-to-date
in modern C++. Every few years, I end up rewriting this application mostly from
scratch, and I think it gets a little better every time.

# Building

The `default` preset provides a `Find<lib>.cmake` script for required
dependencies, but there is also a `conanfile.txt` which can be used to build
using dependencies from Conan center.

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
ln -s builddir/compile_commands.json compile_commands.json
```

# Attributions

This application links against [TagLib][1], which uses dual LGPL and MPL
licenses.

[1]: https://taglib.org/api/
