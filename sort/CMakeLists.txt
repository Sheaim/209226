cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

add_subdirectory(test)
include_directories (..)
add_executable(sort_tests
    sort.cpp
    test/test_sort.cpp)

find_library(COMMON NAMES common PATHS "../common" NO_DEFAULT_PATH)
target_link_libraries (sort_tests LINK_PUBLIC ${COMMON})

enable_testing()
add_Test(NAME sortTest COMMAND sort_tests)