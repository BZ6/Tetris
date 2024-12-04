cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.cpp
    src/*.h
    include/*.h
)

add_executable(Tetris ${sources})
target_include_directories(Tetris PRIVATE src include)
