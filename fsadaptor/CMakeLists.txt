###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      CMake conf file
#
# CREATED:          09/03/2019
#
# LAST EDITED:      05/04/2023
###

cmake_minimum_required(VERSION 3.15.1)

project(fsadaptor DESCRIPTION "Filesystem Adaptor")

set(VERSION_STRING "0.1.3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O3 --std=c++17")

configure_file(
    "${PROJECT_SOURCE_DIR}/include/fsadaptor_config.h.in"
    "${PROJECT_BINARY_DIR}/include/fsadaptor_config.h"
)

# TODO: Ensure that the library can be installed correctly.

set(HEADERS
    include/FSAdaptor/Path.h
    include/FSAdaptor/StandardFilesystemAdaptor.h
    include/FSAdaptor/IFilesystemAdaptor.h
    include/FSAdaptor/IPathWalker.h
    include/FSAdaptor/PathWalker.h
    include/FSAdaptor/namespace.h
)

add_library(fsadaptor
    source/PathConstIter.cpp
    source/Path.cpp
    source/StandardFilesystemAdaptor.cpp
    "${HEADERS}"
)

set_target_properties(fsadaptor PROPERTIES
    PUBLIC_HEADER "${HEADERS}"
    SOVERSION "${VERSION_STRING}"
)

target_include_directories(fsadaptor PRIVATE include)

include(GNUInstallDirs)

install(TARGETS fsadaptor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/FSAdaptor"
)

# pkg-config file
configure_file(libfsadaptor.pc.in libfsadaptor.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/libfsadaptor.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# Disable testing
# enable_testing()
# add_subdirectory(test)

###############################################################################
