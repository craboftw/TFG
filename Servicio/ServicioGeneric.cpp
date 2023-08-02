//
// Created by Fran- on 03/07/2023.
//

#include "ServicioGeneric.h"
#include "Dominio/Generic.h"



    OID ServicioGeneric::createActorUC(std::string nombre) {
    ActorUC actorUC (fileJsonManager.lastActorUC()+1);
    if (nombre.empty()) nombre = actorUC.getId().operator std::string();
    actorUC.setName(nombre);
    fileJsonManager.save(actorUC);
    return actorUC.getId();
    }

std::string ServicioGeneric::getPackage(OID id) {
    if(id.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un ActorUC, getPackage");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El ActorUC no existe, getPackage");
    ActorUC actorUC = fileJsonManager.loadActorUC(id);
    return actorUC.getPackage();
}

OID ServicioGeneric::getGeneralization(OID id) {
    if(id.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un ActorUC, getPackage");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El ActorUC no existe, getPackage");
    ActorUC actorUC = fileJsonManager.loadActorUC(id);
    auto generalization = actorUC.getGeneralization();
    if(!fileJsonManager.exist(generalization)) {
        generalization = OID();
        actorUC.setGeneralization(generalization);
        fileJsonManager.save(actorUC);
    }
    return generalization;
}

void ServicioGeneric::setPackage(OID id, std::string _package) {
    if(id.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un ActorUC, getPackage");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El ActorUC no existe, getPackage");
    ActorUC actorUC = fileJsonManager.loadActorUC(id);
    actorUC.setPackage(_package);
    fileJsonManager.save(actorUC);
}

void ServicioGeneric::setGeneralization(OID id, OID _generalization) {
    if(id.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un ActorUC, getPackage");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El ActorUC no existe, getPackage");
    if(_generalization.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un ActorUC, getPackage"   );
    if(!fileJsonManager.exist(_generalization)) throw std::invalid_argument("El ActorUC de generalizacion no existe, getPackage");
    ActorUC actorUC = fileJsonManager.loadActorUC(id);
    actorUC.setGeneralization(_generalization);
    fileJsonManager.save(actorUC);
}

std::list<std::pair<OID, std::string>> ServicioGeneric::getActorsUC() {
    std::list<std::pair<OID, std::string>> actorsUC;
    for (auto actorUC : fileJsonManager.loadAllActorUC()) {
        actorsUC.push_back(std::make_pair(actorUC.getId(), actorUC.getName()));
    }
    return actorsUC;
}


OID ServicioNonFunctionalRequirement::createNonFunctionalRequirement(std::string name) {
    NonFunctionalRequirement nonFunctionalRequirement (fileJsonManager.lastNonFunctionalRequirement()+1);
    if (name.empty()) name = nonFunctionalRequirement.getId().operator std::string();
    nonFunctionalRequirement.setName(name);
    fileJsonManager.save(nonFunctionalRequirement);
    return nonFunctionalRequirement.getId();
}

std::list<std::pair<OID, std::string>> ServicioNonFunctionalRequirement::getNonFunctionalRequirements() {
    std::list<std::pair<OID, std::string>> nonFunctionalRequirements;
    for (auto nonFunctionalRequirement : fileJsonManager.loadAllNonFunctionalRequirement()) {
        nonFunctionalRequirements.push_back(std::make_pair(nonFunctionalRequirement.getId(), nonFunctionalRequirement.getName()));
    }
    return nonFunctionalRequirements;
}

OID ServicioFunctionalRequirement::createFunctionalRequirement(std::string name) {
    FunctionalRequirement functionalRequirement (fileJsonManager.lastFunctionalRequirement()+1);
    if (name.empty()) name = functionalRequirement.getId().operator std::string();
    functionalRequirement.setName(name);
    fileJsonManager.save(functionalRequirement);
    return functionalRequirement.getId();
}

std::list<std::pair<OID, std::string>> ServicioFunctionalRequirement::getFunctionalRequirements() {
    std::list<std::pair<OID, std::string>> functionalRequirements;
    for (auto functionalRequirement : fileJsonManager.loadAllFunctionalRequirement()) {
        functionalRequirements.push_back(std::make_pair(functionalRequirement.getId(), functionalRequirement.getName()));
    }
    return functionalRequirements;
}

OID ServicioRestrictionRequirement::createRestrictionRequirement(std::string name) {
    RestrictionRequirement restrictionRequirement (fileJsonManager.lastRestrictionRequirement()+1);
    if (name.empty()) name = restrictionRequirement.getId().operator std::string();
    restrictionRequirement.setName(name);
    fileJsonManager.save(restrictionRequirement);
    return restrictionRequirement.getId();
}

std::list<std::pair<OID, std::string>> ServicioRestrictionRequirement::getRestrictionRequirements() {
    std::list<std::pair<OID, std::string>> restrictionRequirements;
    for (auto restrictionRequirement : fileJsonManager.loadAllRestrictionRequirement()) {
        restrictionRequirements.push_back(std::make_pair(restrictionRequirement.getId(), restrictionRequirement.getName()));
    }
    return restrictionRequirements;
}

OID ServicioSystemObjective::createSystemObjective(std::string name) {
    SystemObjective systemObjective (fileJsonManager.lastSystemObjective()+1);
    if (name.empty()) name = systemObjective.getId().operator std::string();
    systemObjective.setName(name);
    fileJsonManager.save(systemObjective);
    return systemObjective.getId();
}

std::list<std::pair<OID, std::string>> ServicioSystemObjective::getSystemObjectives() {
    std::list<std::pair<OID, std::string>> systemObjectives;
    for (auto systemObjective : fileJsonManager.loadAllSystemObjective()) {
        systemObjectives.push_back(std::make_pair(systemObjective.getId(), systemObjective.getName()));
    }
    return systemObjectives;
}

OID ServicioText::createText(std::string name) {
    Text text (fileJsonManager.lastText()+1);
    if (name.empty()) name = text.getId().operator std::string();
    text.setName(name);
    fileJsonManager.save(text);
    return text.getId();
}

std::list<std::pair<OID, std::string>> ServicioText::getTexts() {
    std::list<std::pair<OID, std::string>> texts;
    for (auto text : fileJsonManager.loadAllText()) {
        texts.push_back(std::make_pair(text.getId(), text.getName()));
    }
    return texts;
}

