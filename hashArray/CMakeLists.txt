cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)
include_directories (..)
add_executable(hArray_tests
    hArray.cpp
    test/test_hArray.cpp)

find_library(COMMON NAMES common PATHS "../common" NO_DEFAULT_PATH)
target_link_libraries (hArray_tests LINK_PUBLIC ${COMMON})

enable_testing()
add_Test(NAME hArrayTest COMMAND hArray_tests)