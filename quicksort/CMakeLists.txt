cmake_minimum_required (VERSION 2.6)
project (quicksort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories( "${PROJECT_SOURCE_DIR}/../common" "${PROJECT_SOURCE_DIR}/test")


get_property(inc_dirs DIRECTORY PROPERTY INCLUDE_DIRECTORIES)
message("inc_dirs = ${inc_dirs}")

add_subdirectory(test)

add_subdirectory("../common" "${CMAKE_CURRENT_BINARY_DIR}/common")

add_executable(quicksort_tests
    ../common/logger.cpp
    quicksort.cpp
    test/test_quicksort.cpp)

enable_testing()
add_Test(NAME quicksortTest COMMAND quicksort_tests)
