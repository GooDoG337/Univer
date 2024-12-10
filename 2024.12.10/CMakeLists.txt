cmake_minimum_required(VERSION 3.10)
project(2024_12_10)
set(CMAKE_CXX_STANDARD 20)
add_executable(2024_12_10 main.cpp
        calc.cpp)
add_executable(tests test.cpp calc.cpp)
