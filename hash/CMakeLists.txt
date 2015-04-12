cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)
include_directories (..)
add_executable(hash_tests
    hash.cpp
    test/test_hash.cpp)

find_library(COMMON NAMES common PATHS "../common" NO_DEFAULT_PATH)
target_link_libraries (hash_tests LINK_PUBLIC ${COMMON})

enable_testing()
add_Test(NAME hashTest COMMAND hash_tests)