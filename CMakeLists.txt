cmake_minimum_required(VERSION 3.24)
project(TFG)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

add_library(TFG_Library
        Dominio/Trackeable/Fecha.cpp
        Dominio/Priority/Priority.cpp
        Dominio/Trackeable/Stakeholder.cpp
        Dominio/Trackeable/Trackeable.cpp
        Repository/JsonRepository.cpp
        Dominio/Generic.cpp
        Dominio/UserCase.cpp
        Dominio/InformationRequirement.cpp
        Dominio/Trackeable/Organization.cpp
        Servicio/ServicioUserCase.cpp
        Dominio/UserCaseDiagram.cpp
        Servicio/ServicioInformationRequirement.cpp
        Servicio/ServicioTrackeable.cpp
        Servicio/ServicioPriority.cpp
        Servicio/ServicioGeneric.cpp
        Servicio/ServicioStakeholder.cpp
        Servicio/ServicioOrganization.cpp
        Servicio/ServicioActorUC.cpp
        Visitor/HtmlManager.cpp
        Repository/JsonSerializer.cpp
        Dominio/Trackeable/MatrixTraces.cpp
        Servicio/ServicioMatrixTraces.cpp
        Servicio/ServicioMatrixTraces.h
        Dominio/UserStories.cpp
        Servicio/ServicioHTML.cpp
        Servicio/ServicioUserStories.cpp
        Visitor/LinkedGeneralTree.cpp)

add_executable(TFG_Executable main.cpp)

target_link_libraries(TFG_Executable PRIVATE TFG_Library)
