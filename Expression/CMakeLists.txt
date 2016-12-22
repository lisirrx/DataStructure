cmake_minimum_required(VERSION 3.7)
project(Expression)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Scanner.hpp Token.hpp Token.cpp)
add_executable(Expression ${SOURCE_FILES} Scanner.hpp Token.hpp Token.cpp)