###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      Cmake configuration file.
#
# CREATED:          09/13/2019
#
# LAST EDITED:      01/17/2022
###

cmake_minimum_required(VERSION 3.13.4)

project(SortMedia DESCRIPTION "Media Sorter")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 --std=c++17")
# GCC Flags for Debug build
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O0 --std=c++17")

# TODO: Add target to build documentation
# TODO: Fix test rule
# TODO: Add pkg-config file
# TODO: Test install
# TODO: Link to fsadaptor internally only

include(./CMakeDefs.txt)

add_subdirectory(dependencies/FSAdaptor)

add_library(sortmedia STATIC
    "${SORTMEDIA_SOURCES}"
)

target_include_directories(sortmedia PRIVATE
    include
    ${CONAN_INCLUDE_DIRS}
    dependencies/FSAdaptor/include
)

add_executable(SortLibrary
    source/main.cpp
    source/ArgumentParser.cpp
)
target_link_libraries(SortLibrary
    sortmedia
    fsadaptor
    ${CONAN_LIBS}
)
target_include_directories(SortLibrary PRIVATE
    include
    dependencies/FSAdaptor/include
)

include(GNUInstallDirs)

set_target_properties(sortmedia PROPERTIES PUBLIC_HEADER "${INSTALL_HEADERS}")
install(TARGETS sortmedia
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(TARGETS SortLibrary
        DESTINATION ${CMAKE_INSTALL_BINDIR}
)

enable_testing()
add_subdirectory(test)

###############################################################################
