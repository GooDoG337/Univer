cmake_minimum_required(VERSION 3.29)
project(21_02_2025)

set(CMAKE_CXX_STANDARD 20)

add_executable(21_02_2025 main.cpp
        dateCheck.h)
add_executable(tests tests.cpp
       doctest.h  dateCheck.h)
