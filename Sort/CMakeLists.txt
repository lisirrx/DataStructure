cmake_minimum_required(VERSION 3.6)
project(Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Bubble_sort.cpp Sort_functions.hpp Insertion_sort.cpp merge_sort.cpp radix_sort.cpp quick_sort.cpp)
add_executable(Sort ${SOURCE_FILES} Bubble_sort.cpp Sort_functions.hpp Insertion_sort.cpp merge_sort.cpp radix_sort.cpp quick_sort.cpp)