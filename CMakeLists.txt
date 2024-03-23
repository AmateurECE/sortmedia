cmake_minimum_required(VERSION 3.25)

project(sortmedia LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

add_executable(sortlibrary src/main.cpp)

include(GNUInstallDirs)
install(TARGETS sortlibrary
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
