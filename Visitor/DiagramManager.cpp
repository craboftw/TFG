//
// Created by Fran- on 29/06/2023.
//

#include <fstream>
#include "DiagramManager.h"
#include "FileJsonManager.h"
#include "Jsoneitor.h"
#include "Dominio/Generic.h"

void DiagramManager::visit(std::list<UserCase> userCaseList, std::list<ActorUC> actorUCList) {
    //Create a new file
    std::ofstream file("TFG/Diagrams/UseCaseDiagram.txt");
    FileJsonManager fileJsonManager;
    Jsoneitor jsoneitor;
    //Write the header of the file
    file << "@startuml" << std::endl;
    file << "left to right direction" << std::endl;
    //Find the actors
    std::string actor;
    std::map<std::string,std::set<OID>> packagesUC;
    std::map<std::string,std::set<OID>> packagesActor;
    std::set<std::string > packages;
    std::map<OID,std::string> nombres;

    //Categorizamos los actores y los casos de uso por paquetes
    for (auto &userCase : userCaseList) {
        packagesUC[userCase.getPackage()].insert(userCase.getId());
        packages.insert(userCase.getPackage());
        nombres[userCase.getId()] = userCase.getName();

    }
    for (auto &actorUC : actorUCList) {
        //return the one that the OID is equal to the actorUC
        packagesActor[actorUC.getPackage()].insert(actorUC.getId());
        packages.insert(actorUC.getPackage());
        nombres[actorUC.getId()] = actorUC.getName();
    }


    //Imprimimos los paquetes con sus alias
    for (auto &package : packages) {
        if (!package.empty()) {
            file << "package \"" << package << "\" {" << std::endl;
            for (auto &userCase: packagesUC[package]) {
                file << "usecase \"" << nombres[userCase] << "\" as " << userCase.operator std::string() << std::endl;
            }

            for (auto &actorUC: packagesActor[package]) {
                if (actorUC.getPrefix() == ActorUC::getPrefixID())
                    file << "actor \"" << nombres[actorUC] << "\" as " << actorUC.operator std::string() << std::endl;
            }
            file << "}" << std::endl;
        } else {
            for (auto &userCase: packagesUC[package]) {
                file << "usecase \"" << nombres[userCase] << "\" as " << userCase.operator std::string() << std::endl;
            }

            for (auto &actorUC: packagesActor[package]) {
                if (actorUC.getPrefix() == ActorUC::getPrefixID())
                    file << "actor \"" << nombres[actorUC] << "\" as " << actorUC.operator std::string() << std::endl;
            }
        }
    }



    for (auto &userCase : userCaseList) {
        for (auto &actorUC : userCase.getActors()) {
            file << actorUC.operator std::string() << " --> " << userCase.getId().operator std::string() << std::endl;
        }
        for (auto step : userCase.getSteps()) {
            if (step.getType() == INCLUDE and step.getReference() != OID()) {
                file << userCase.getId().operator std::string() << " ..> " << step.getReference().operator std::string()
                     << " : <<include>>" << std::endl;
            }
            if (step.getType() == EXTEND and step.getReference() != OID()) {
                file << userCase.getId().operator std::string() << " ..> " << step.getReference().operator std::string()
                     << " : <<extend>>" << std::endl;
            }
        }
        if (userCase.getGeneralization() != OID())
            file << userCase.getGeneralization().operator std::string() << " <|-- " << userCase.getId().operator std::string() << std::endl;
    }
    for (auto &actorUC : actorUCList) {
        if (actorUC.getId().getPrefix() == ActorUC::getPrefixID() and actorUC.getGeneralization() != OID())
            file << actorUC.getGeneralization().operator std::string() << " <|-- " << actorUC.getId().operator std::string() << std::endl;
    }
    file << "@enduml" << std::endl;
    file.close();

    //Convert the plantuml file to png
    system("java -jar TFG/plantuml.jar TFG/Diagrams/UseCaseDiagram.txt");




}