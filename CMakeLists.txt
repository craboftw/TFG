cmake_minimum_required(VERSION 3.24)
project(TFG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TFG
        Fecha.cpp
        Fecha.h
        Stakeholder.h
        Stakeholder.cpp
        Trackeable.cpp
        Trackeable.h)
