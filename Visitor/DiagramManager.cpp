//
// Created by Fran- on 29/06/2023.
//

#include <fstream>
#include "DiagramManager.h"
#include "FileJsonManager.h"
#include "Jsoneitor.h"
#include "Dominio/Generic.h"

void DiagramManager::visit(std::list<OID> userCaseList, std::list<OID> actorUCList) {
    //Create a new file
    std::ofstream file("TFG/Diagrams/UseCaseDiagram.txt");
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
        packagesUC[servicioUserCase.getPackage(userCase)].insert(userCase);
        packages.insert(servicioUserCase.getPackage(userCase));
        nombres[userCase] = servicioUserCase.getName(userCase);

    }
    for (auto &actorUC : actorUCList) {
        //return the one that the OID is equal to the actorUC
        packagesActor[servicioActorUC.getPackage(actorUC)].insert(actorUC);
        packages.insert(servicioActorUC.getPackage(actorUC));
        nombres[actorUC] = servicioActorUC.getName(actorUC);
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
        for (auto &actorUC : servicioUserCase.getActors(userCase)) {
            file << actorUC.operator std::string() << " --> " << userCase.operator std::string() << std::endl;
        }
        for (auto step : servicioUserCase.getSteps(userCase)) {
            if (step.getType() == INCLUDE and step.getReference() != OID()) {
                file << userCase.operator std::string() << " ..> " << step.getReference().operator std::string()
                     << " : <<include>>" << std::endl;
            }
            if (step.getType() == EXTEND and step.getReference() != OID()) {
                file << userCase.operator std::string() << " ..> " << step.getReference().operator std::string()
                     << " : <<extend>>" << std::endl;
            }

        }
        for (auto exceptions : servicioUserCase.getExceptions(userCase)) {
           if(exceptions.stepType == INCLUDE) {
               file << userCase.operator std::string() << " ..> " << exceptions.reference.operator std::string()
                    << " : <<include>>" << std::endl;
           }
              if(exceptions.stepType == EXTEND) {
                file << userCase.operator std::string() << " ..> " << exceptions.reference.operator std::string()
                      << " : <<extend>>" << std::endl;
              }
        }

        if (servicioUserCase.getGeneralization(userCase) != OID())
            file <<servicioUserCase.getGeneralization(userCase).operator std::string() << " <|-- " << userCase.operator std::string() << std::endl;
    }
    for (auto actorUC : actorUCList) {
        if (actorUC.getPrefix() == ActorUC::getPrefixID() and servicioActorUC.getGeneralization(actorUC) != OID())
            file << servicioActorUC.getGeneralization(actorUC).operator std::string() << " <|-- " << actorUC.operator std::string() << std::endl;
    }
    file << "@enduml" << std::endl;
    file.close();

    //Convert the plantuml file to png
    system("java -jar TFG/plantuml.jar TFG/Diagrams/UseCaseDiagram.txt");




}