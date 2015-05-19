cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)
include_directories (..)
add_executable(AVL_tests
    test/test_AVL.cpp
    AVL.cpp
    cell.cpp
)

find_library(COMMON NAMES common PATHS "../common" NO_DEFAULT_PATH)
target_link_libraries (AVL_tests LINK_PUBLIC ${COMMON})

enable_testing()
add_Test(NAME AVLTest COMMAND AVL_tests)
