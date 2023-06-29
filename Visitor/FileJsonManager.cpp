//
// Created by Fran- on 26/06/2023.
//

#include <list>
#include "FileJsonManager.h"
#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Trackeable/Stakeholder.h"



void FileJsonManager::save(json singlejson) {

    std::string typeOfTrackeable = singlejson["id"]["prefix"];
    std::string path = "TFG/Jsons/" + typeOfTrackeable + ".json";
    int id = singlejson["id"]["id"];

// Open the file in input mode to check if it exists
    std::ifstream i(path);
    json listaj;

// Check if the file exists and load its contents into listaj if it does
    if (i.good() && i.peek() != std::ifstream::traits_type::eof()) {
        i >> listaj;
    }
    else
    {
        //create the file if it doesn't exist
        std::ofstream o(path);
    }

    std::string fullPath = std::filesystem::absolute(path).string();
    std::cout << "fullPath: " << fullPath << std::endl;

// Add the new json object to the listaj

    listaj [std::to_string(id)] = singlejson;

// Open the file in output mode to save the updated json
    std::ofstream o(path);
    o << std::setw(4) << listaj << std::endl;

}

json FileJsonManager::load(OID oid) {
    std::string typeOfTrackeable = oid.getPrefix() ;
    std::string path = "TFG/Jsons/" + typeOfTrackeable + ".json";
    unsigned id = oid.getId();
// Open the file in input mode to check if it exists
    std::ifstream i(path);
    json listaj;

// Check if the file exists and load its contents into listaj if it does
    if (i.good() && i.peek() != std::ifstream::traits_type::eof()) {
        i >> listaj;
    }
    else
    {
        //create the file if it doesn't exist
        std::ofstream o(path);
    }

    std::string fullPath = std::filesystem::absolute(path).string();
    std::cout << "fullPath: " << fullPath << std::endl;

// Add the new json object to the listaj

    return listaj [std::to_string(id)];
}

json FileJsonManager::loadAll(std::string prefix) {
    std::string path = "TFG/Jsons/" + prefix + ".json";
    std::ifstream i(path);
    json listaj;

// Check if the file exists and load its contents into listaj if it does
    if (i.good() && i.peek() != std::ifstream::traits_type::eof()) {
        i >> listaj;
    }
    else
    {
        //create the file if it doesn't exist
        std::ofstream o(path);
    }

    std::string fullPath = std::filesystem::absolute(path).string();
    std::cout << "fullPath: " << fullPath << std::endl;

// Add the new json object to the listaj

    return listaj;
}

Stakeholder FileJsonManager::loadStakeholder(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeStakeholder(j);
}

std::list<Stakeholder> FileJsonManager::loadAllStakeholder() {
    std::list<Stakeholder> stakeholders;
    json j = loadAll("SH");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        stakeholders.push_back(jsoneitor.deserializeStakeholder(element));
    }
    return stakeholders;
}

RestrictionRequirement FileJsonManager::loadRestrictionRequirement(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeRestrictionRequirement(j);
}

std::list<RestrictionRequirement> FileJsonManager::loadAllRestrictionRequirement() {
    std::list<RestrictionRequirement> restrictionRequirements;
    json j = loadAll("RR");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        restrictionRequirements.push_back(jsoneitor.deserializeRestrictionRequirement(element));
    }
    return restrictionRequirements;
}

FunctionalRequirement FileJsonManager::loadFunctionalRequirement(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeFunctionalRequirement(j);
}

std::list<FunctionalRequirement> FileJsonManager::loadAllFunctionalRequirement() {
    std::list<FunctionalRequirement> functionalRequirements;
    json j = loadAll("FR");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        functionalRequirements.push_back(jsoneitor.deserializeFunctionalRequirement(element));
    }
    return functionalRequirements;
}

NonFunctionalRequirement FileJsonManager::loadNonFunctionalRequirement(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeNonFunctionalRequirement(j);
}

std::list<NonFunctionalRequirement> FileJsonManager::loadAllNonFunctionalRequirement() {
    std::list<NonFunctionalRequirement> nonFunctionalRequirements;
    json j = loadAll("NF");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        nonFunctionalRequirements.push_back(jsoneitor.deserializeNonFunctionalRequirement(element));
    }
    return nonFunctionalRequirements;
}

ActorUC FileJsonManager::loadActorUC(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeActorUC(j);
}

std::list<ActorUC> FileJsonManager::loadAllActorUC() {
    std::list<ActorUC> actorUCs;
    json j = loadAll("AC");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        actorUCs.push_back(jsoneitor.deserializeActorUC(element));
    }
    return actorUCs;
}

InformationRequirement FileJsonManager::loadInformationRequirement(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeInformationRequirement(j);
}

std::list<InformationRequirement> FileJsonManager::loadAllInformationRequirement() {
    std::list<InformationRequirement> informationRequirements;
    json j = loadAll("IR");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        informationRequirements.push_back(jsoneitor.deserializeInformationRequirement(element));
    }
    return informationRequirements;
}

Organization FileJsonManager::loadOrganization(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeOrganization(j);
}

std::list<Organization> FileJsonManager::loadAllOrganization() {
    std::list<Organization> organizations;
    json j = loadAll("OR");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        organizations.push_back(jsoneitor.deserializeOrganization(element));
    }
    return organizations;
}

Rol_Stakeholder FileJsonManager::loadRolStakeholder(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeRolStakeholder(j);
}

std::list<Rol_Stakeholder> FileJsonManager::loadAllRolStakeholder() {
    std::list<Rol_Stakeholder> rol_stakeholders;
    json j = loadAll("RS");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        rol_stakeholders.push_back(jsoneitor.deserializeRolStakeholder(element));
    }
    return rol_stakeholders;
}

SystemObjective FileJsonManager::loadSystemObjective(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeSystemObjective(j);
}

std::list<SystemObjective> FileJsonManager::loadAllSystemObjective() {
    std::list<SystemObjective> systemObjectives;
    json j = loadAll("SO");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        systemObjectives.push_back(jsoneitor.deserializeSystemObjective(element));
    }
    return systemObjectives;
}

UserCase FileJsonManager::loadUserCase(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeUserCase(j);
}

std::list<UserCase> FileJsonManager::loadAllUserCase() {
    std::list<UserCase> userCases;
    json j = loadAll("UC");
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        userCases.push_back(jsoneitor.deserializeUserCase(element));
    }
    return userCases;
}







template <class T>
void save(T trackeable) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(trackeable);
}

template <class T>
void saveAll(std::list<T> trackeables) {
    for (auto& trackeable : trackeables) {
        save(trackeable);
    }
}











