cmake_minimum_required(VERSION 3.10.2)
project(Tarea2_DL)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets Multimedia REQUIRED)

add_executable(Tarea2_DL src/main.cpp src/ui/nrzi.cpp src/ui/nrzi.h src/ui/nrzi.ui src/logic/hamming.cpp src/logic/hamming.h src/logic/Converter.cpp src/logic/Converter.h src/ui/mainwindow.ui src/ui/mainwindow.cpp src/ui/mainwindow.h)

target_link_libraries(Tarea2_DL Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia)
