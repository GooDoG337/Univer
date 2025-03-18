cmake_minimum_required(VERSION 3.29)
project(2025_03_18)

set(CMAKE_CXX_STANDARD 26)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_WCLUDE_DIRS})
add_executable(2025_03_18 main.cpp)
target_link_libraries(2025_03_18 ${OpenCV_LIBS})
