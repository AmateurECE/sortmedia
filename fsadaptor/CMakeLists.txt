###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      CMake conf file
#
# CREATED:          09/03/2019
#
# LAST EDITED:      09/03/2019
###

cmake_minimum_required(VERSION 3.15.1)

project(fsadaptor DESCRIPTION "Filesystem Adaptor")

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_REV 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O3 --std=c++17")

configure_file(
    "${PROJECT_SOURCE_DIR}/include/fsadaptor_config.h.in"
    "${PROJECT_BINARY_DIR}/include/fsadaptor_config.h"
)

set(HEADERS
    include/FSAdaptor/Path.h
    include/FSAdaptor/StandardFilesystemAdaptor.h
    include/FSAdaptor/IFilesystemAdaptor.h
    include/FSAdaptor/namespace.h
)

add_library(fsadaptor STATIC
    source/Path.cpp
    source/StandardFilesystemAdaptor.cpp
    "${HEADERS}"
)

list(TRANSFORM HEADERS PREPEND PUBLIC_HEADER)
set_target_properties(fsadaptor PROPERTIES
    ${HEADERS}
)

target_include_directories(fsadaptor PRIVATE include)

include(GNUInstallDirs)

install(TARGETS fsadaptor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

add_subdirectory(test)
enable_testing()
add_test(NAME UnitTests COMMAND UnitTests)

###############################################################################
