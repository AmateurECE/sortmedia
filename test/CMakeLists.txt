###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      Builds the tests for the project.
#
# CREATED:          09/13/2019
#
# LAST EDITED:      09/13/2019
###

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(SortMediaTests
    TestMain.cpp
    
)

target_include_directories(SortMediaTests
    SYSTEM PRIVATE "${GTEST_INCLUDE_DIRS}"
)

target_include_directories(SortMediaTests
    PRIVATE ../include
)

target_link_libraries(SortMediaTests
    sortmedia
    "${GTEST_BOTH_LIBRARIES}"
)

enable_testing()
gtest_discover_tests(SortMediaTests)

###############################################################################
