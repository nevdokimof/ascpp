cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(draw_sprite)

add_executable(${PROJECT_NAME} "src/main.cpp")

include_directories("../../modules/core/include")
link_directories(${CMAKE_BINARY_DIR}/modules/core)
target_link_libraries(${PROJECT_NAME} asc++_core)

FILE(COPY res/habr.txt DESTINATION "${CMAKE_BINARY_DIR}/examples/draw_sprite")
