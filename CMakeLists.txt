cmake_minimum_required(VERSION 3.16)

project(dsa_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(hello_world setup/hello_world.cpp)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(hello_world PRIVATE -Wall -Wextra -Wpedantic)
endif()
