//
// Created by Fran- on 29/06/2023.
//

#include "UserCaseDiagram.h"
#include "Servicio/ServicioActorUC.h"
#include "Servicio/ServicioUserCase.h"
#include "OID.h"
//include qstring and qstring list and qcoreapplication
#include <QString>
#include <QStringList>
#include <QCoreApplication>
#include <QProcess>


#include <fstream>
#include <thread>


void UserCaseDiagram::setElements(std::set<OID> userCaseList, std::set<OID> actorUCList) {
    //Categorizamos los actores y los casos de uso por paquetes
    ServicioUserCase servicioUserCase;
    ServicioActorUC servicioActorUC;

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
}

void UserCaseDiagram::addUserCase(OID userCase) {
    ServicioUserCase servicioUserCase;
    ServicioActorUC servicioActorUC;
    packagesUC[servicioUserCase.getPackage(userCase)].insert(userCase);
    packages.insert(servicioUserCase.getPackage(userCase));
    nombres[userCase] = servicioUserCase.getName(userCase);
    userCaseList.insert(userCase);
    auto steps = servicioUserCase.getSteps(userCase);
    for (auto &step : steps) {
        if (step.getType() == ACTOR and step.getReference() != OID()) {
            packagesActor[servicioActorUC.getPackage(step.getReference())].insert(step.getReference());
            packages.insert(servicioActorUC.getPackage(step.getReference()));
            nombres[step.getReference()] = servicioActorUC.getName(step.getReference());
            actorUCList.insert(step.getReference());
        }
    }
    update();
}

void UserCaseDiagram::removeUserCase(OID userCase) {
    ServicioUserCase servicioUserCase;
    ServicioActorUC servicioActorUC;
    packagesUC[servicioUserCase.getPackage(userCase)].erase(userCase);
    if (packagesUC[servicioUserCase.getPackage(userCase)].empty())
        packages.erase(servicioUserCase.getPackage(userCase));
    nombres.erase(userCase);
    auto steps = servicioUserCase.getSteps(userCase);
    for (auto &step : steps) {
        if (step.getType() == ACTOR and step.getReference() != OID()) {
            packagesActor[servicioActorUC.getPackage(step.getReference())].erase(step.getReference());
            if (packagesActor[servicioActorUC.getPackage(step.getReference())].empty())
                packages.erase(servicioActorUC.getPackage(step.getReference()));
            nombres.erase(step.getReference());
        }
    }
}

void UserCaseDiagram::visit(Visitor *visitor) {
    visitor->visit(this);
}

void executeCommandOnAnotherCore(const std::string& command) {
    std::system(command.c_str());
}

void UserCaseDiagram::update() {
    ServicioUserCase servicioUserCase;
    ServicioActorUC servicioActorUC;
    //setup the necessary to load the spanish language
    setlocale(LC_ALL, "spanish");
    //Create a new file
    std::ofstream file(getId().operator std::string()+".puml", std::ios::out | std::ios::binary);
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8_utf16<char16_t>));    //Write the header of the file
    file << "@startuml" << std::endl;
    file << "left to right direction" << std::endl;
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

    std::list<std::pair<OID,OID>> UserCaseDoActor;
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
            if (step.getType() == ACTOR and step.getReference() != OID()) {
                UserCaseDoActor.push_back(std::make_pair(userCase, step.getReference()));
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
            if (exceptions.stepType == ACTOR and exceptions.reference != OID()) {
                //search if the combination of userCase and actorUC is already in the set
                UserCaseDoActor.push_back(std::make_pair(userCase, exceptions.reference));
                }
            }



        if (servicioUserCase.getGeneralization(userCase) != OID())
            file <<servicioUserCase.getGeneralization(userCase).operator std::string() << " <|-- " << userCase.operator std::string() << std::endl;
    }

    for (auto actorUC : actorUCList) {
        if (actorUC.getPrefix() == ActorUC::getPrefixID() and servicioActorUC.getGeneralization(actorUC) != OID())
            file << servicioActorUC.getGeneralization(actorUC).operator std::string() << " <|-- " << actorUC.operator std::string() << std::endl;
    }
    std::list<std::pair<OID,OID>> finalList;
    for(auto it : UserCaseDoActor) {
        bool found = false;
        for (auto jt : finalList) {
            if (it.first == jt.first and it.second == jt.second) {
                found = true;
                break;
            }
        }
        if (!found) {
            finalList.push_back(it);
        }
    }
    for (auto it : finalList) {
        file << it.second.operator std::string() << " --> " << it.first.operator std::string() << std::endl;
    }
    file << "@enduml" << std::endl;
    file.close();
    //make sure it doesn't show in the console

    // Define the command to run the JAR file
    QString program = "java";
    QStringList arguments;
    std::string stringArg = "-jar TFG/plantuml.jar -charset UTF-8" + getId().operator std::string() + ".puml";
    QString qstringArg = QString::fromStdString(stringArg);
    arguments << qstringArg;

    // Create a QProcess object to run the command
    QProcess process;
    process.start(program, arguments);

    // Wait for the process to finish
    if (process.waitForFinished(-1)) {
        // Process finished successfully
        int exitCode = process.exitCode();
    } else {
        // Error handling if the process fails
    }
    // Wait for the execution thread to finish
}

std::set<OID> UserCaseDiagram::getUserCaseList() {
    return userCaseList;
}

std::set<OID> UserCaseDiagram::getActorUCList() {
    return actorUCList;
}




