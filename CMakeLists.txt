###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      Cmake configuration file.
#
# CREATED:          09/13/2019
#
# LAST EDITED:      05/04/2023
###

cmake_minimum_required(VERSION 3.22.2)

project(SortMedia DESCRIPTION "Media Sorter")

set(VERSION_STRING "0.1.1")
configure_file("${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3")

find_package(taglib REQUIRED)
find_package(fsadaptor REQUIRED)

# TODO: Add target to build documentation
# TODO: Fix test rule
# TODO: Add pkg-config file
# TODO: Test install
# TODO: Link to fsadaptor internally only

add_library(sortmedia STATIC
    source/SortMedia/Exceptions/PolicyVerificationError.cpp
    source/SortMedia/Exceptions/OperationalError.cpp
    source/SortMedia/Policies/UnknownFileType.cpp
    source/SortMedia/Policies/DeleteDirectoryIfEmpty.cpp
    source/SortMedia/Policies/OrganizationalBase.cpp
    source/SortMedia/Policies/BasicMusicFileNaming.cpp
    source/SortMedia/Policies/DeleteFile.cpp
    source/SortMedia/Operations/DeleteDirectoryIfEmpty.cpp
    source/SortMedia/Operations/Warn.cpp
    source/SortMedia/Operations/DeleteFile.cpp
    source/SortMedia/Operations/RenameFile.cpp
    source/SortMedia/Schemas/BasicMusicOrganizationalSchema.cpp
    source/SortMedia/Schemas/OrganizationalSchema.cpp
    source/SortMedia/FileTypes/LibraryFile.cpp
    source/SortMedia/FileTypes/MusicFile.cpp
    source/SortMedia/Adaptors/TagLibAdaptor.cpp
    source/SortMedia/Adaptors/TagLibFLACAdaptor.cpp
    source/SortMedia/MediaSorter.cpp
    source/SortMedia/Factories/FileLocatorFactory.cpp
    source/SortMedia/Factories/OrganizationalSchemaFactory.cpp
    source/SortMedia/Factories/MusicTagEditorAdaptorFactory.cpp
    source/SortMedia/FileLocators/AnyFileLocator.cpp
    source/SortMedia/Logging/NullLogger.cpp
    source/SortMedia/Logging/StreamLogger.cpp
  )

target_include_directories(sortmedia PRIVATE include fsadaptor::fsadaptor taglib::taglib)
target_link_libraries(sortmedia PRIVATE
  fsadaptor::fsadaptor
  taglib::taglib
  )

add_executable(SortLibrary source/main.cpp)
target_link_libraries(SortLibrary
  sortmedia
  fsadaptor::fsadaptor
  taglib::taglib
  )
target_include_directories(SortLibrary PRIVATE
  include
  fsadaptor::fsadaptor
  taglib::taglib
  ${PROJECT_BINARY_DIR}
  )

include(GNUInstallDirs)

set_target_properties(sortmedia PROPERTIES PUBLIC_HEADER "${INSTALL_HEADERS}")
install(TARGETS SortLibrary
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  )

# enable_testing()
# add_subdirectory(test)

###############################################################################
