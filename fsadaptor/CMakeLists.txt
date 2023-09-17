###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      CMake conf file
#
# CREATED:          09/03/2019
###

cmake_minimum_required(VERSION 3.15.1)

project(fsadaptor DESCRIPTION "Filesystem Adaptor")

set(VERSION_STRING "0.1.3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O3 --std=c++17")

configure_file(
    "fsadaptor/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

set(HEADERS
    fsadaptor/Path.h
    fsadaptor/StandardFilesystemAdaptor.h
    fsadaptor/IFilesystemAdaptor.h
    fsadaptor/IPathWalker.h
    fsadaptor/PathWalker.h
    fsadaptor/namespace.h
)

add_library(fsadaptor
    fsadaptor/PathConstIter.cpp
    fsadaptor/Path.cpp
    fsadaptor/StandardFilesystemAdaptor.cpp
    "${HEADERS}"
)

set_target_properties(fsadaptor PROPERTIES
    PUBLIC_HEADER "${HEADERS}"
    SOVERSION "${VERSION_STRING}"
)

target_include_directories(fsadaptor PUBLIC ${CMAKE_CURRENT_LIST_DIR})

include(GNUInstallDirs)

install(TARGETS fsadaptor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/fsadaptor"
)

# pkg-config file
configure_file(libfsadaptor.pc.in libfsadaptor.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/libfsadaptor.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# Disable testing
# enable_testing()
# add_subdirectory(test)
