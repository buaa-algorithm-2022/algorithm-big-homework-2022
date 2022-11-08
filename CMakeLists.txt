cmake_minimum_required(VERSION 3.23)
project(algorithm_big_homework_2022)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(src/utils)

add_executable(Runner src/Runner.cpp)
# add_executable(BubbleSort src/algo/BubbleSort.cpp)
# add_executable(RadixSort src/algo/RadixSort.cpp)