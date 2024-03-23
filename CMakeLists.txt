cmake_minimum_required(VERSION 3.25)

project(sortmedia LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

find_package(taglib REQUIRED)
find_package(CLI11 REQUIRED)

add_executable(sortlibrary src/main.cpp)
target_link_libraries(sortlibrary PRIVATE
  taglib::taglib
  CLI11::CLI11)

include(GNUInstallDirs)
install(TARGETS sortlibrary
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
