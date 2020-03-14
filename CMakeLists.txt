cmake_minimum_required(VERSION 3.15)
project(C++)

set(CMAKE_CXX_STANDARD 14)

add_executable(C++ main.cpp)
add_executable(OOP_01 OOP_01/Point.h OOP_01/Point.cpp OOP_01/OOP_01.cpp)
add_executable(OOP_02 OOP_02/Point.cpp OOP_02/Point.h OOP_02/Segment.cpp OOP_02/Segment.h OOP_02/OOP_02.cpp)
add_executable(OOP_03 OOP_03/Point.cpp OOP_03/Point.h OOP_03/Segment.cpp OOP_03/Segment.h OOP_03/Triangle.cpp OOP_03/Triangle.h OOP_03/OOP_03.cpp)
add_executable(OOP_04 OOP_04/AComplex.cpp OOP_04/AComplex.h OOP_04/TComplex.cpp OOP_04/TComplex.h OOP_04/Main.cpp)
add_executable(OOP_05 OOP_05/Date.cpp OOP_05/Date.h OOP_05/Main.cpp)
add_executable(OOP_06 OOP_06/Time.cpp OOP_06/Time.h OOP_06/Main.cpp OOP_06/Main.cpp OOP_06/Date.cpp OOP_06/Date.h OOP_06/Timer.cpp OOP_06/Timer.h)
add_executable(OOP_07 OOP_07/String.h OOP_07/String.cpp OOP_07/Main.cpp)
