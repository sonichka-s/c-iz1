cmake_minimum_required(VERSION 3.16.3)

project(tp_1_iz C CXX)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "--coverage")

add_executable(main main.c)

add_subdirectory(src)
add_subdirectory(Gtest)
target_link_libraries(main LINK_PUBLIC song storage)


