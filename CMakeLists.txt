cmake_minimum_required(VERSION 3.15)
project(C++)

set(CMAKE_CXX_STANDARD 14)

add_executable(C++ main.cpp)
add_executable(OOP_01 OOP_01/Point.h OOP_01/Point.cpp OOP_01/OOP_01.cpp)
add_executable(OOP_02 OOP_02/Point.cpp OOP_02/Point.h OOP_02/Segment.cpp OOP_02/Segment.h OOP_02/OOP_02.cpp)
add_executable(OOP_03 OOP_03/Point.cpp OOP_03/Point.h OOP_03/Segment.cpp OOP_03/Segment.h OOP_03/Triangle.cpp OOP_03/Triangle.h OOP_03/OOP_03.cpp)
