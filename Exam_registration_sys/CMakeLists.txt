cmake_minimum_required(VERSION 3.6)
project(Exam_registration_sys)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Entry.cpp Entry.hpp Database.cpp Database.hpp list.hpp)
add_executable(Exam_registration_sys ${SOURCE_FILES} Entry.cpp Entry.hpp Database.cpp Database.hpp list.hpp)