###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <ethan.twardy@gmail.com>
#
# DESCRIPTION:      Cmake configuration file.
#
# CREATED:          09/13/2019
###

cmake_minimum_required(VERSION 3.22.2)

project(SortMedia DESCRIPTION "Media Sorter")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(VERSION_STRING "0.1.4")
configure_file("sortlibrary/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  add_compile_options(-fdiagnostics-color=always)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  add_compile_options(-fcolor-diagnostics)
endif()

include(find_taglib.cmake)
find_taglib()
add_subdirectory(fsadaptor)

add_library(sortmedia STATIC
    libsortmedia/Exceptions/PolicyVerificationError.cpp
    libsortmedia/Exceptions/OperationalError.cpp
    libsortmedia/Policies/UnknownFileType.cpp
    libsortmedia/Policies/DeleteDirectoryIfEmpty.cpp
    libsortmedia/Policies/OrganizationalBase.cpp
    libsortmedia/Policies/BasicMusicFileNaming.cpp
    libsortmedia/Policies/DeleteFile.cpp
    libsortmedia/Operations/DeleteDirectoryIfEmpty.cpp
    libsortmedia/Operations/Warn.cpp
    libsortmedia/Operations/DeleteFile.cpp
    libsortmedia/Operations/RenameFile.cpp
    libsortmedia/Schemas/BasicMusicOrganizationalSchema.cpp
    libsortmedia/Schemas/OrganizationalSchema.cpp
    libsortmedia/FileTypes/LibraryFile.cpp
    libsortmedia/FileTypes/MusicFile.cpp
    libsortmedia/Adaptors/TagLibAdaptor.cpp
    libsortmedia/Adaptors/TagLibFLACAdaptor.cpp
    libsortmedia/MediaSorter.cpp
    libsortmedia/Factories/FileLocatorFactory.cpp
    libsortmedia/Factories/OrganizationalSchemaFactory.cpp
    libsortmedia/Factories/MusicTagEditorAdaptorFactory.cpp
    libsortmedia/FileLocators/AnyFileLocator.cpp
    libsortmedia/Logging/NullLogger.cpp
    libsortmedia/Logging/StreamLogger.cpp
  )

target_include_directories(sortmedia PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(sortmedia PUBLIC taglib::taglib fsadaptor::fsadaptor)

add_executable(sortlibrary sortlibrary/main.cpp)
target_link_libraries(sortlibrary sortmedia)
target_include_directories(sortlibrary PRIVATE ${PROJECT_BINARY_DIR})

include(GNUInstallDirs)

install(TARGETS sortlibrary
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  )

# enable_testing()
# add_subdirectory(test)
