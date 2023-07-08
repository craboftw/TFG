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


// Add the new json object to the listaj

    json elemento = listaj [std::to_string(id)];

    //update elemento only with the fields in singlejson
    for (auto& element : singlejson.items()) {
        elemento[element.key()] = element.value();
    }
    listaj [std::to_string(id)] = elemento;


// Open the file in output mode to save the updated json
    std::ofstream o(path);
    o << std::setw(4) << listaj << std::endl;

}



json FileJsonManager::load(OID oid) {
    std::string typeOfTrackeable = oid.getPrefix() ;
    if (typeOfTrackeable == "XX") {
        return json();
    }
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
        std::ofstream o(path);
    }

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
        std::ofstream o(path);
    }

// Add the new json object to the listaj

    return listaj;
}

bool FileJsonManager::exist(OID oid) {
    if (oid.getPrefix() == "XX") {
        return false;
    }

    json lista = loadAll(oid.getPrefix());

    for (auto& element : lista) {
        if (element["id"]["id"] == oid.getId()) {
            return true;
        }
    }
    return false;
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
    for (json element : j) {
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

Text FileJsonManager::loadText(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeText(j);
}

MatrixTraces FileJsonManager::loadMatrixTraces(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeMatrixTraces(j);
}

UserStories FileJsonManager::loadUserStories(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeUserStories(j);
}

Trackeable *FileJsonManager::loadTrackeable(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeTrackeable(j);
}

Priority *FileJsonManager::loadPriority(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    Priority* p = jsoneitor.deserializePriority(j);
    p->setID(id);
    return p;
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

std::list<Text> FileJsonManager::loadAllText() {
    std::list<Text> texts;
    json j = loadAll(Text::getPrefixID());
    Jsoneitor jsoneitor;
    for (auto& element : j) {
        texts.push_back(jsoneitor.deserializeText(element));
    }
    return texts;
}

unsigned FileJsonManager::lastStakeholder() {
    json j = loadAll(Stakeholder::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"])
            last = element["id"]["id"];
    }
    return last;
}

unsigned FileJsonManager::lastRestrictionRequirement() {
    json j = loadAll(RestrictionRequirement::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"])
            last = element["id"]["id"];
    }
    return last;
}

unsigned FileJsonManager::lastFunctionalRequirement() {
    json j = loadAll(FunctionalRequirement::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"])
            last = element["id"]["id"];
    }
    return last;
}

unsigned FileJsonManager::lastNonFunctionalRequirement() {
    json j = loadAll(NonFunctionalRequirement::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"])
            last = element["id"]["id"];
    }
    return last;
}

unsigned FileJsonManager::lastActorUC() {
    json j = loadAll(ActorUC::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"])
            last = element["id"]["id"];
    }
    return last;
}

unsigned FileJsonManager::lastInformationRequirement() {
    json j = loadAll(InformationRequirement::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"])
            last = element["id"]["id"];
    }
    return last;
}

unsigned FileJsonManager::lastOrganization() {
    json j = loadAll(Organization::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"])
            last = element["id"]["id"];
    }
    return last;
}



unsigned FileJsonManager::lastSystemObjective() {
    json j = loadAll(SystemObjective::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"])
            last = element["id"]["id"];
    }
    return last;
}

unsigned FileJsonManager::lastUserCase() {
    json j = loadAll(UserCase::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"]) {
            last = element["id"]["id"];
        }
    }
    return last;
}

unsigned FileJsonManager::lastText() {
    json j = loadAll(Text::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"]) {
            last = element["id"]["id"];
        }
    }
    return last;
}

unsigned FileJsonManager::lastMatrixTraces() {
    json j = loadAll(MatrixTraces::getPrefixID());
    int last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"]) {
            last = element["id"]["id"];
        }
    }
    return last;
}

unsigned int FileJsonManager::lastUserStories() {
    json j = loadAll(UserStories::getPrefixID());
    unsigned last = 0;
    for (auto& element : j) {
        if (last < element["id"]["id"]) {
            last = element["id"]["id"];
        }
    }
    return last;
}


void FileJsonManager::save(Stakeholder stakeholder) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(stakeholder);
}

void FileJsonManager::save(RestrictionRequirement restrictionRequirement) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(restrictionRequirement);
}

void FileJsonManager::save(FunctionalRequirement functionalRequirement) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(functionalRequirement);
}

void FileJsonManager::save(NonFunctionalRequirement nonFunctionalRequirement) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(nonFunctionalRequirement);
}

void FileJsonManager::save(ActorUC actorUC) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(actorUC);
}

void FileJsonManager::save(InformationRequirement informationRequirement) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(informationRequirement);
}

void FileJsonManager::save(Organization organization) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(organization);
}

void FileJsonManager::save(SystemObjective systemObjective) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(systemObjective);
}

void FileJsonManager::save(UserCase& userCase) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(userCase);
}


void FileJsonManager::save(Text text) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(text);
}


void FileJsonManager::save(MatrixTraces matrixTraces) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(matrixTraces);

}

void FileJsonManager::save(Trackeable *pTrackeable) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(pTrackeable);
}

void FileJsonManager::save(Priority* pPriority) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(pPriority);
}

void FileJsonManager::save(UserStories userStories) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(userStories);
}

void FileJsonManager::saveAll(std::list<Stakeholder> stakeholders) {
    Jsoneitor jsoneitor;
    for (auto& stakeholder : stakeholders) {
        jsoneitor.visit(stakeholder);
    }
}

void FileJsonManager::saveAll(std::list<RestrictionRequirement> restrictionRequirements) {
    Jsoneitor jsoneitor;
    for (auto& restrictionRequirement : restrictionRequirements) {
        jsoneitor.visit(restrictionRequirement);
    }
}

void FileJsonManager::saveAll(std::list<FunctionalRequirement> functionalRequirements) {
    Jsoneitor jsoneitor;
    for (auto& functionalRequirement : functionalRequirements) {
        jsoneitor.visit(functionalRequirement);
    }
}

void FileJsonManager::saveAll(std::list<NonFunctionalRequirement> nonFunctionalRequirements) {
    Jsoneitor jsoneitor;
    for (auto& nonFunctionalRequirement : nonFunctionalRequirements) {
        jsoneitor.visit(nonFunctionalRequirement);
    }
}

void FileJsonManager::saveAll(std::list<ActorUC> actorUCs) {
    Jsoneitor jsoneitor;
    for (auto& actorUC : actorUCs) {
        jsoneitor.visit(actorUC);
    }
}

void FileJsonManager::saveAll(std::list<InformationRequirement> informationRequirements) {
    Jsoneitor jsoneitor;
    for (auto& informationRequirement : informationRequirements) {
        jsoneitor.visit(informationRequirement);
    }
}

void FileJsonManager::saveAll(std::list<Organization> organizations) {
    Jsoneitor jsoneitor;
    for (auto& organization : organizations) {
        jsoneitor.visit(organization);
    }
}


void FileJsonManager::saveAll(std::list<SystemObjective> systemObjectives) {
    Jsoneitor jsoneitor;
    for (auto& systemObjective : systemObjectives) {
        jsoneitor.visit(systemObjective);
    }
}

void FileJsonManager::saveAll(std::list<UserCase> userCases) {
    Jsoneitor jsoneitor;
    for (auto& userCase : userCases) {
        jsoneitor.visit(userCase);
    }
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











