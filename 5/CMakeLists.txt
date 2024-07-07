cmake_minimum_required(VERSION 3.19.0)
project(4)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(placementnew placementNew.cpp)
set_property(TARGET placementnew PROPERTY CXX_STANDARD 11)

add_executable(operatornew operatorNew.cpp)
set_property(TARGET operatornew PROPERTY CXX_STANDARD 11)
