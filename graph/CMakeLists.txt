cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)
include_directories (..)
add_executable(finder_tests
test/test_finder.cpp
finder.cpp
graph.cpp
)

find_library(COMMON NAMES common PATHS "../common" NO_DEFAULT_PATH)
target_link_libraries (finder_tests LINK_PUBLIC ${COMMON})

enable_testing()
add_Test(NAME finderTest COMMAND finder_tests)