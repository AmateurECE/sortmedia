find_package(PkgConfig)
pkg_check_modules(taglib REQUIRED taglib)
message("Using system taglib")

add_library(taglib::taglib INTERFACE IMPORTED)
target_link_libraries(taglib::taglib INTERFACE ${taglib_LIBRARIES})
target_include_directories(taglib::taglib INTERFACE ${taglib_INCLUDE_DIRS})
