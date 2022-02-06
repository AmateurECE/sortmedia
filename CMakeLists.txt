###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      Cmake configuration file.
#
# CREATED:          09/13/2019
#
# LAST EDITED:      02/06/2022
###

cmake_minimum_required(VERSION 3.22.2)

project(SortMedia DESCRIPTION "Media Sorter")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(VERSION_STRING "0.1.1")
configure_file("${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 --std=c++17")

# TODO: Add target to build documentation
# TODO: Fix test rule
# TODO: Add pkg-config file
# TODO: Test install
# TODO: Link to fsadaptor internally only

include(./CMakeDefs.txt)

find_package(PkgConfig)
pkg_check_modules(FSADAPTOR REQUIRED libfsadaptor)

add_library(sortmedia STATIC
  "${SORTMEDIA_SOURCES}"
  )

target_include_directories(sortmedia PRIVATE
  include
  ${CONAN_INCLUDE_DIRS}
  ${FSADAPTOR_INCLUDE_DIRS}
  )

add_executable(SortLibrary source/main.cpp)
target_link_libraries(SortLibrary
  sortmedia
  ${FSADAPTOR_LIBRARIES}
  ${CONAN_LIBS}
  )
target_include_directories(SortLibrary PRIVATE
  include
  ${PROJECT_BINARY_DIR}
  ${FSADAPTOR_INCLUDE_DIRS}
  )

include(GNUInstallDirs)

set_target_properties(sortmedia PROPERTIES PUBLIC_HEADER "${INSTALL_HEADERS}")
install(TARGETS SortLibrary
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  )

enable_testing()
add_subdirectory(test)

###############################################################################
