cmake_minimum_required(VERSION 3.29.0 FATAL_ERROR)

# Enables the Standard module support. This needs to be done
# before selecting the languages.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
set(CMAKE_CXX_MODULE_STD ON)

project(sortmedia LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

find_package(taglib REQUIRED)
find_package(CLI11 REQUIRED)

include(cmake/version.cmake)

add_executable(sortlibrary)
target_sources(sortlibrary PRIVATE src/main.cpp)
target_sources(sortlibrary
  PRIVATE
    FILE_SET modules TYPE CXX_MODULES FILES
#     src/metadata.cppm
      src/convert.cppm
      src/library.cppm)

target_link_libraries(sortlibrary PRIVATE
  taglib::taglib
  CLI11::CLI11
  version::version)

include(GNUInstallDirs)
install(TARGETS sortlibrary
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
