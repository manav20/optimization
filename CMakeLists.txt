cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(optimization)

add_executable (run src/line_search.cpp src/cost_function.cpp src/math_function.cpp src/optimization src/main.cpp)
