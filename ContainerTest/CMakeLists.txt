cmake_minimum_required(VERSION 3.6)
project(ContainerTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp StrBlob.cpp StrBlob.hpp)
add_executable(ContainerTest ${SOURCE_FILES})