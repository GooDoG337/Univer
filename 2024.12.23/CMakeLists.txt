cmake_minimum_required(VERSION 3.29)
project(2024_12_23)
set(CMAKE_CXX_STANDARD 20)
FIND_PACKAGE(Boost 1.40 COMPONENTS
        program_options REQUIRED)
add_executable(2024_12_23 main.cpp)
TARGET_LINK_LIBRARIES(2024_12_23 Boost::program_options)
add_executable(Second main2.cpp)