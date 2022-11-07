cmake_minimum_required(VERSION 3.23)
project(algorithm_big_homework_2022)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/utils)

add_executable(BubbleSort src/algo/BubbleSort.cpp)
