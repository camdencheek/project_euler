cmake_minimum_required(VERSION 3.5)
project(p003)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(p003 ${SOURCE_FILES})