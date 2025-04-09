cmake_minimum_required(VERSION 3.14)

project(2025_04_05 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(2025_04_05
  main.cpp
  student.h student.cpp
)
add_executable(FileSize FileSize.cpp)
add_executable(Main2 main2.cpp)
target_link_libraries(2025_04_05 Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(FileSize Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Main2 Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS 2025_04_05 FileSize Main2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


