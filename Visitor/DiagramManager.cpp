//
// Created by Fran- on 29/06/2023.
//

#include <fstream>
#include "DiagramManager.h"
#include "FileJsonManager.h"
#include "Jsoneitor.h"
#include "Dominio/Generic.h"

void DiagramManager::visit(std::list<UserCase> userCaseList) {
    //Create a new file
    std::ofstream file("TFG/Diagrams/UseCaseDiagram.txt");
    FileJsonManager fileJsonManager;
    Jsoneitor jsoneitor;
    //Write the header of the file
    file << "@startuml" << std::endl;
    file << "left to right direction" << std::endl;
    //Find the actors
    std::string actor = "";
    std::map<std::string,OID> packagesUC;
    std::map<std::string,OID> packagesActor;
    for (auto &userCase : userCaseList) {
        packagesUC[userCase.getPackage()] = userCase.getId();
    }
    for (auto &userCase : userCaseList) {
        for (auto &actorUC : userCase.getActors()) {
            auto actor = jsoneitor.deserializeActorUC(fileJsonManager.load(actorUC));
            packagesActor[actor.getPackage()] = actorUC;
        }
    }

    //iterate over the map and write the packages
    for (auto &package : packagesUC) {
        if (package.first != "") {
            file << "package \"" << package.first << "\" {" << std::endl;
        }
            for (auto &userCase: userCaseList) {
                if (userCase.getPackage() == package.first) {
                    file << "usecase \"" << userCase.getName() << "\" as " << userCase.getId().operator std::string()
                         << std::endl;
                }
            }
        if (package.first != "") {
            file << "}" << std::endl;
        }
    }

    for (auto &package : packagesActor) {
        if (package.first != "") {
            file << "package \"" << package.first << "\" {" << std::endl;
        }
            for (auto &userCase: userCaseList) {
                for (auto &actorUC : userCase.getActors()) {
                    auto actor = jsoneitor.deserializeActorUC(fileJsonManager.load(actorUC));
                    if (actor.getPackage() == package.first) {
                        file << "actor \"" << actor.getName() <<"\" as " << actorUC.operator std::string()<< std::endl;
                    }
                }
            }
        if (package.first != "") {
            file << "}" << std::endl;
        }
    }

    for (auto &userCase : userCaseList) {
        for (auto &actorUC : userCase.getActors()) {
            file << actorUC.operator std::string() << " --> " << userCase.getId().operator std::string() << std::endl;
        }
        for (auto step : userCase.getSteps()) {
            if (step.getType() == Step::INCLUDE) {
                file << userCase.getId().operator std::string() << " ..> " << step.getReference().operator std::string()
                     << " : <<include>>" << std::endl;
            }
            if (step.getType() == Step::EXTEND) {
                file << userCase.getId().operator std::string() << " ..> " << step.getReference().operator std::string()
                     << " : <<extend>>" << std::endl;
            }
        }
        file << userCase.getGeneralization().operator std::string() << " <|-- " << userCase.getId().operator std::string() << std::endl;
    }
    file << "@enduml" << std::endl;
    file.close();

    //Convert the plantuml file to png
    system("java -jar TFG/plantuml.jar TFG/Diagrams/UseCaseDiagram.txt");




}
