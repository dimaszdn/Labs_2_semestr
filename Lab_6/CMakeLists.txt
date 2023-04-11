cmake_minimum_required(VERSION 3.24)
project(Lab_6)

include_directories(inc/)
include_directories(src/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_6 main.cpp src/Logger.cpp inc/Logger.h)
