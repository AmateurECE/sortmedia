set(THIS_SCRIPT "cmake/version.cmake")
if(${CMAKE_SCRIPT_MODE_FILE} MATCHES ${THIS_SCRIPT})
  # We are executing as a script
  execute_process(COMMAND git describe --dirty
    OUTPUT_VARIABLE GIT_REPO_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE)
  configure_file(${INPUT_FILE} ${OUTPUT_FILE})
else()
  set(VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/version.h")
  # We have been included at configure time
  add_custom_target(version_header
    COMMAND ${CMAKE_COMMAND}
    -D INPUT_FILE="${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.h.in"
    -D OUTPUT_FILE=${VERSION_HEADER}
    -P ${CMAKE_CURRENT_SOURCE_DIR}/${THIS_SCRIPT}
    BYPRODUCTS ${VERSION_HEADER})

  add_library(version INTERFACE)
  target_include_directories(version
    INTERFACE ${CMAKE_CURRENT_BINARY_DIR})
  add_dependencies(version version_header)
  add_library(version::version ALIAS version)
endif()

