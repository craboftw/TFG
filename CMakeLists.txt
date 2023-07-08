cmake_minimum_required(VERSION 3.24)
project(TFG)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

add_library(TFG_Library
        Dominio/Trackeable/Fecha.cpp
        Dominio/Priority/Priority.cpp
        Dominio/Trackeable/Stakeholder.cpp
        Dominio/Trackeable/Trackeable.cpp
        Visitor/FileJsonManager.cpp
        Dominio/Generic.cpp
        Dominio/UserCase.cpp
        Dominio/InformationRequirement.cpp
        Dominio/Trackeable/Organization.cpp
        Servicio/ServicioUserCase.cpp
        Visitor/DiagramManager.cpp
        Servicio/ServicioInformationRequirement.cpp
        Servicio/ServicioTrackeable.cpp
        Servicio/ServicioPriority.cpp
        Servicio/ServicioGeneric.cpp
        Servicio/ServicioStakeholder.cpp
        Servicio/ServicioOrganization.cpp
        Servicio/ServicioActorUC.cpp
        Visitor/HtmlManager.cpp
        Visitor/Jsoneitor.cpp
        Dominio/Trackeable/MatrixTraces.cpp Servicio/ServicioMatrixTraces.cpp Servicio/ServicioMatrixTraces.h Dominio/UserStories.cpp Dominio/UserStories.h Servicio/ServicioUserStories.cpp Servicio/ServicioUserStories.h Servicio/ServicioHTML.cpp Servicio/ServicioHTML.h)

add_executable(TFG_Executable main.cpp)

target_link_libraries(TFG_Executable PRIVATE TFG_Library)
