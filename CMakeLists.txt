cmake_minimum_required(VERSION 3.24)
project(TFG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TFG
        Trackeable/Fecha.cpp
        Trackeable/Fecha.h
        Trackeable/Stakeholder.h
        Trackeable/Stakeholder.cpp
        Trackeable/Trackeable.cpp
        Trackeable/Trackeable.h Trackeable/Organization.h Trackeable/Organization.cpp SystemObjetive/SystemObjetive.h SystemObjetive/SystemObjetive.cpp)
