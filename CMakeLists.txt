cmake_minimum_required(VERSION 3.24)
project(TFG)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

add_library(TFG_Library
        Dominio/Trackeable/Fecha.cpp
        Dominio/Priority/Priority.cpp
        Dominio/Trackeable/Stakeholder.cpp
        Dominio/Trackeable/Trackeable.cpp
        Dominio/Generic.cpp
        Visitor/Jsoneitor.cpp
        Dominio/UserCase.cpp
        Dominio/InformationRequirement.cpp
        Dominio/Trackeable/Organization.cpp
        Visitor/FileJsonManager.cpp
        Servicio/ServicioUserCase.cpp
        Visitor/DiagramManager.cpp
        Servicio/ServicioInformationRequirement.cpp
        Servicio/ServicioTrackeable.cpp
        Servicio/ServicioPriority.cpp
        Servicio/ServicioGeneric.cpp
        Servicio/ServicioStakeholder.cpp
        Servicio/ServicioOrganization.cpp
        Visitor/HtmlManager.cpp
        )

add_executable(TFG_Executable main.cpp)

target_link_libraries(TFG_Executable PRIVATE TFG_Library)
