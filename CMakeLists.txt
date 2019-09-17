cmake_minimum_required(VERSION 3.14)
project(ai_hw_1)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp Board.cpp BFS.cpp)

add_executable(ai_hw_1 ${SOURCE_FILES})
