This application links against [TagLib](https://taglib.org/api/), which uses
dual LGPL and MPL licenses.

# Building

This project depends on taglib, which must be located somehow. The CMake build
script will first attempt to locate taglib as if it were installed by Conan.
If this fails, the build script will fall back to using `pkg-config`.

## Building with taglib from Conan

```
$ conan install -of build .
$ cmake -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=$DESTDIR/usr \
    -DCMAKE_TOOLCHAIN_FILE=$PWD/build/conan_toolchain.cmake .
$ cmake --build build
```

## Building with taglib from pkg-config

```
$ cmake -B build -G Ninja -DCMAKE_INSTALL_PREFIX=$DESTDIR/usr
$ cmake --build build
```

# Compilation Database

CMake is configured to generate a compilation database at configure time. To
use this, e.g. with neovim, symlink it into the project root directory:

```
$ ln -s build/compile_commands.json compile_commands.json
```
