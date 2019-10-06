cmake_minimum_required(VERSION 3.0)

project(asc++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS OFF)

add_subdirectory(tools)
add_subdirectory(examples)
add_subdirectory(modules)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif(BUILD_TESTS)

