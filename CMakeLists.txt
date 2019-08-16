cmake_minimum_required(VERSION 3.1...3.15)

project(GCPP VERSION 1.0 LANGUAGES CXX)

add_subdirectory("src")

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory("tests")
endif()




