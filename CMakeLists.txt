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
        HTML/HtmlManager.cpp
        Repository/JsonSerializer.cpp
        Dominio/Trackeable/MatrixTraces.cpp
        Servicio/ServicioMatrixTraces.cpp
        Dominio/UserStories.cpp
        HTML/ServicioHTML.cpp
        Servicio/ServicioUserStories.cpp
        Visitor/LinkedGeneralTree.cpp
        Servicio/ServicioDiagramUC.cpp
<<<<<<< HEAD
        Dominio/Index.cpp
        Dominio/Persona.cpp
        Servicio/ServicioPersona.cpp
        Dominio/Interview.cpp
        Servicio/ServicioInterview.cpp
        Dominio/Clases/Class.cpp)
=======
        Dominio/Index.cpp Dominio/Index.h Dominio/Persona.cpp Dominio/Persona.h Servicio/ServicioPersona.cpp Servicio/ServicioPersona.h Dominio/Interview.cpp Dominio/Interview.h Servicio/ServicioInterview.cpp Servicio/ServicioInterview.h)
>>>>>>> main

add_executable(TFG_Executable main.cpp Servicio/ServicioClass/ServicioClass.cpp Servicio/ServicioClass/ServicioClass.h)

target_link_libraries(TFG_Executable PRIVATE TFG_Library)
