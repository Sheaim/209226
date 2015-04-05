cmake_minimum_required (VERSION 2.6)
project (log_tests)

include_directories("${PROJECT_SOURCE_DIR}/test")
add_subdirectory(test)

add_executable(log_tests
    logger.cpp
    test/test_logger.cpp)

enable_testing()
add_Test(NAME logTest COMMAND log_Tests)
