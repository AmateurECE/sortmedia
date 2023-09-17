###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      CMake conf file
#
# CREATED:          09/03/2019
###

project(fsadaptor DESCRIPTION "Filesystem Adaptor")

set(VERSION_STRING "0.1.4")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O3 --std=c++17")

configure_file(
    "config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

set(HEADERS
    Path.h
    StandardFilesystemAdaptor.h
    IFilesystemAdaptor.h
    IPathWalker.h
    PathWalker.h
    namespace.h
)

add_library(fsadaptor
    PathConstIter.cpp
    Path.cpp
    StandardFilesystemAdaptor.cpp
    "${HEADERS}"
)
add_library(fsadaptor::fsadaptor ALIAS fsadaptor)

set_target_properties(fsadaptor PROPERTIES
    PUBLIC_HEADER "${HEADERS}"
    SOVERSION "${VERSION_STRING}"
)

target_include_directories(fsadaptor PUBLIC "${CMAKE_CURRENT_LIST_DIR}/..")
