cmake_minimum_required (VERSION 2.6)
project (quicksort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("${PROJECT_SOURCE_DIR}/test")
add_subdirectory(test)

add_executable(quicksort_tests
    quicksort.cpp
    test/test_quicksort.cpp)

enable_testing()
add_Test(NAME quicksortTest COMMAND quicksort_tests)
