cmake_minimum_required(VERSION 3.10)
project(ProjectTime)
option(BUILD_SHARED_LIBS "Build using shared libraries " ON)
add_library(myTime ctime.cpp)
target_include_directories(myTime PUBLIC ${MAKE_SOURCE_DIR})
add_executable(Gambling main.cpp)
target_link_libraries(Gambling PRIVATE myTime)
