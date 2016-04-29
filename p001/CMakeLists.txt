cmake_minimum_required(VERSION 3.5)
project(p001)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(p001 ${SOURCE_FILES})