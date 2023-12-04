cmake_minimum_required(VERSION 3.5)

project(PruebaTFG VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        dialog.cpp
        dialog.h
        dialog.ui
        treemodel.h
        treemodel.cpp
        TreeNode.h
        TreeNode.cpp
        TreeView.h
        TreeView.cpp
        Dominio/UserCaseDiagram.cpp
        Dominio/UserCaseDiagram.h
        Dominio/Trackeable/OID.h
        Dominio/Trackeable/Fecha.cpp
        Dominio/Priority/Priority.cpp
        Dominio/Trackeable/Stakeholder.cpp
        Dominio/Trackeable/Trackeable.cpp
        Dominio/Trackeable/Organization.cpp Dominio/Trackeable/OID.cpp
        Repository/JsonRepository.cpp
        Repository/JsonSerializer.cpp
        Visitor/LinkedGeneralTree.cpp
        HTML/HtmlManager.cpp
        HTML/ServicioHTML.cpp
        Repository/JsonRepository.cpp
        Repository/JsonSerializer.cpp
        Dominio/Generic.cpp
        Dominio/UserCase.cpp
        Dominio/InformationRequirement.cpp
        Dominio/UserCaseDiagram.cpp
        Dominio/Trackeable/MatrixTraces.cpp
        Dominio/UserStories.cpp
        Dominio/Index.cpp
        Dominio/Persona.cpp
        Dominio/Interview.cpp
        Dominio/Clases/Class.cpp
        Servicio/ServicioGeneric.cpp
        Servicio/ServicioUserCase.cpp
        Servicio/ServicioInformationRequirement.cpp
        Servicio/ServicioTrackeable.cpp
        Servicio/ServicioPriority.cpp
        Servicio/ServicioStakeholder.cpp
        Servicio/ServicioOrganization.cpp
        Servicio/ServicioActorUC.cpp
        Servicio/ServicioMatrixTraces.cpp
        Servicio/ServicioUserStories.cpp
        Servicio/ServicioDiagramUC.cpp
        Servicio/ServicioPersona.cpp
        Servicio/ServicioInterview.cpp
        Servicio/ServicioClass/ServicioClass.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PruebaTFG
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}


        treemodel.h treemodel.cpp
        TreeNode.h TreeNode.cpp
        TreeView.h TreeView.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PruebaTFG APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PruebaTFG SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PruebaTFG
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PruebaTFG PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PruebaTFG)
endif()
set_target_properties(PruebaTFG PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PruebaTFG
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PruebaTFG)
endif()


include_directories(${CMAKE_SOURCE_DIR})
#incluir la carpeta Trackeable
include_directories(${CMAKE_SOURCE_DIR}/Dominio/Trackeable)

#Creación de la librería Base. Contiene las clases básicas del programa, Trackeable, Priority, Stakeholder, Fecha y Organization.
add_library(TFG_Base

    )

