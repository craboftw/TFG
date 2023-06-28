cmake_minimum_required(VERSION 3.24)
project(TFG)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

add_library(TFG_Library
        TFG/Dominio/Trackeable/Fecha.cpp
        TFG/Dominio/Priority/Priority.cpp
        TFG/Dominio/Trackeable/Stakeholder.cpp
        TFG/Dominio/Trackeable/Trackeable.cpp
        TFG/Dominio/Generic.cpp
        TFG/Visitor/Jsoneitor.cpp
        TFG/Dominio/UserCase.cpp
        TFG/Dominio/InformationRequirement.cpp
        TFG/Dominio/Trackeable/Organization.cpp
        TFG/Visitor/FileJsonManager.cpp
        )

add_executable(TFG_Executable main.cpp)

target_link_libraries(TFG_Executable PRIVATE TFG_Library)
