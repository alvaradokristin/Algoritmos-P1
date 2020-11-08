cmake_minimum_required(VERSION 3.17)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_1 main.cpp headers/Timer.h sources/Timer.cpp headers/Country.h sources/Country.cpp headers/List.h sources/List.cpp)