cmake_minimum_required(VERSION 3.19.0)
project(4)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(compare compare.cpp)
set_property(TARGET compare PROPERTY CXX_STANDARD 11)

add_executable(assign assign.cpp)
set_property(TARGET assign PROPERTY CXX_STANDARD 11)

add_executable(arrow arrow.cpp)
set_property(TARGET arrow PROPERTY CXX_STANDARD 11)