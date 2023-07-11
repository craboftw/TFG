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
    } else {
        //create the file if it doesn't exist
        std::ofstream o(path);
    }


// Add the new json object to the listaj

    json elemento = listaj[std::to_string(id)];

    //update elemento only with the fields in singlejson
    for (auto &element: singlejson.items()) {
        elemento[element.key()] = element.value();
    }
    listaj[std::to_string(id)] = elemento;


// Open the file in output mode to save the updated json
    std::ofstream o(path);
    o << std::setw(4) << listaj << std::endl;

}

json FileJsonManager::load(OID oid) {
    std::string typeOfTrackeable = oid.getPrefix();
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
    } else {
        std::ofstream o(path);
    }

    return listaj[std::to_string(id)];
}


json FileJsonManager::loadFile(OID oid) {
    std::string typeOfTrackeable = oid.getPrefix();
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
    } else {
        std::ofstream o(path);
    }

    return listaj[std::to_string(id)];
}

json FileJsonManager::loadFileAll(std::string prefix) {
    std::string path = "TFG/Jsons/" + prefix + ".json";

    std::ifstream i(path);
    json listaj;

// Check if the file exists and load its contents into listaj if it does
    if (i.good() && i.peek() != std::ifstream::traits_type::eof()) {
        i >> listaj;
    } else {
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

    for (auto &element: lista) {
        if (element["id"]["id"] == oid.getId()) {
            return true;
        }
    }
    return false;
}


Stakeholder FileJsonManager::loadStakeholder(OID id) {
    if (MEMStakeholder.find(id) == MEMStakeholder.end()) {
        throw std::invalid_argument("No existe el Stakeholder, loadStakeholder");
    }
    return MEMStakeholder[id];


}

std::list<Stakeholder> FileJsonManager::loadAllStakeholder() {
    std::list<Stakeholder> stakeholders;
    for (auto &element: MEMStakeholder) {
        stakeholders.push_back(element.second);
    }
    return stakeholders;
}

RestrictionRequirement FileJsonManager::loadRestrictionRequirement(OID id) {
    if (MEMRestrictionRequirement.find(id) == MEMRestrictionRequirement.end()) {
        throw std::invalid_argument("No existe el RestrictionRequirement, loadRestrictionRequirement");
    }
    return MEMRestrictionRequirement[id];

}

std::list<RestrictionRequirement> FileJsonManager::loadAllRestrictionRequirement() {
    std::list<RestrictionRequirement> restrictionRequirements;
    for (auto &element: MEMRestrictionRequirement) {
        restrictionRequirements.push_back(element.second);
    }
    return restrictionRequirements;
}

FunctionalRequirement FileJsonManager::loadFunctionalRequirement(OID id) {
    if (MEMFunctionalRequirement.find(id) == MEMFunctionalRequirement.end()) {
        throw std::invalid_argument("No existe el FunctionalRequirement, loadFunctionalRequirement");
    }
    return MEMFunctionalRequirement[id];
}

std::list<FunctionalRequirement> FileJsonManager::loadAllFunctionalRequirement() {
    std::list<FunctionalRequirement> functionalRequirements;
    for (auto &element: MEMFunctionalRequirement) {
        functionalRequirements.push_back(element.second);
    }
    return functionalRequirements;
}

NonFunctionalRequirement FileJsonManager::loadNonFunctionalRequirement(OID id) {
    if (MEMNonFunctionalRequirement.find(id) == MEMNonFunctionalRequirement.end()) {
        throw std::invalid_argument("No existe el NonFunctionalRequirement, loadNonFunctionalRequirement");
    }
    return MEMNonFunctionalRequirement[id];
}

std::list<NonFunctionalRequirement> FileJsonManager::loadAllNonFunctionalRequirement() {
    std::list<NonFunctionalRequirement> nonFunctionalRequirements;
    for (auto &element: MEMNonFunctionalRequirement) {
        nonFunctionalRequirements.push_back(element.second);
    }
    return nonFunctionalRequirements;
}

ActorUC FileJsonManager::loadActorUC(OID id) {
    if (MEMActorUC.find(id) == MEMActorUC.end()) {
        throw std::invalid_argument("No existe el ActorUC, loadActorUC");
    }
    return MEMActorUC[id];
}

std::list<ActorUC> FileJsonManager::loadAllActorUC() {
    std::list<ActorUC> actorUCs;
    for (auto &element: MEMActorUC) {
        actorUCs.push_back(element.second);
    }
    return actorUCs;
}

InformationRequirement FileJsonManager::loadInformationRequirement(OID id) {
    if (MEMInformationRequirement.find(id) == MEMInformationRequirement.end()) {
        throw std::invalid_argument("No existe el InformationRequirement, loadInformationRequirement");
    }
    return MEMInformationRequirement[id];
}

std::list<InformationRequirement> FileJsonManager::loadAllInformationRequirement() {
    std::list<InformationRequirement> informationRequirements;
    for (auto &element: MEMInformationRequirement) {
        informationRequirements.push_back(element.second);
    }
    return informationRequirements;
}

Organization FileJsonManager::loadOrganization(OID id) {
    if (MEMOrganization.find(id) == MEMOrganization.end()) {
        throw std::invalid_argument("No existe el Organization, loadOrganization");
    }
    return MEMOrganization[id];
}


std::list<Organization> FileJsonManager::loadAllOrganization() {
    std::list<Organization> organizations;
    for (auto &element: MEMOrganization) {
        organizations.push_back(element.second);
    }
    return organizations;
}


SystemObjective FileJsonManager::loadSystemObjective(OID id) {
    if (MEMSystemObjective.find(id) == MEMSystemObjective.end()) {
        throw std::invalid_argument("No existe el SystemObjective, loadSystemObjective");
    }
    return MEMSystemObjective[id];
}

std::list<SystemObjective> FileJsonManager::loadAllSystemObjective() {
    std::list<SystemObjective> systemObjectives;
    for (auto &element: MEMSystemObjective) {
        systemObjectives.push_back(element.second);
    }
    return systemObjectives;
}

UserCase FileJsonManager::loadUserCase(OID id) {
    if (MEMUserCase.find(id) == MEMUserCase.end()) {
        throw std::invalid_argument("No existe el UserCase, loadUserCase");
    }
    return MEMUserCase[id];
}

Text FileJsonManager::loadText(OID id) {
    if (MEMText.find(id) == MEMText.end()) {
        throw std::invalid_argument("No existe el Text, loadText");
    }
    return MEMText[id];
}

MatrixTraces FileJsonManager::loadMatrixTraces(OID id) {
    if (MEMMatrixTraces.find(id) == MEMMatrixTraces.end()) {
        throw std::invalid_argument("No existe el MatrixTraces, loadMatrixTraces");
    }
    return MEMMatrixTraces[id];
}

UserStories FileJsonManager::loadUserStories(OID id) {
    if (MEMUserStories.find(id) == MEMUserStories.end()) {
        throw std::invalid_argument("No existe el UserStories, loadUserStories");
    }
    return MEMUserStories[id];
}

Trackeable FileJsonManager::loadTrackeable(OID id) {
    Trackeable trackeable;
    Stakeholder stakeholder;
    RestrictionRequirement restrictionRequirement;
    FunctionalRequirement functionalRequirement;
    NonFunctionalRequirement nonFunctionalRequirement;
    ActorUC actorUC;
    InformationRequirement informationRequirement;
    Organization organization;
    SystemObjective systemObjective;
    UserCase userCase;
    Text text;
    MatrixTraces matrixTraces;
    UserStories userStories;

    switch (prefixes[id.getPrefix()]) {
        case STAKEHOLDER:
            stakeholder = loadStakeholder(id);
            trackeable = stakeholder;
            break;

        case RESTRICTION_REQUIREMENT:
            restrictionRequirement = loadRestrictionRequirement(id);
            trackeable = restrictionRequirement;
            break;
        case FUNCTIONAL_REQUIREMENT:
            functionalRequirement = loadFunctionalRequirement(id);
            trackeable = functionalRequirement;
            break;
        case NON_FUNCTIONAL_REQUIREMENT:

            nonFunctionalRequirement = loadNonFunctionalRequirement(id);
            trackeable = nonFunctionalRequirement;
            break;
        case ACTOR_UC:

            actorUC = loadActorUC(id);
            trackeable = actorUC;
            break;
        case INFORMATION_REQUIREMENT:

            informationRequirement = loadInformationRequirement(id);
            trackeable = informationRequirement;
            break;
        case ORGANIZATION:

            organization = loadOrganization(id);
            trackeable = organization;
            break;
        case SYSTEM_OBJECTIVE:
            systemObjective = loadSystemObjective(id);
            trackeable = systemObjective;
            break;
        case USER_CASE:

            userCase = loadUserCase(id);
            trackeable = userCase;
            break;
        case TEXT:

                text = loadText(id);
                trackeable = text;
                break;
        case MATRIX_TRACES:

                matrixTraces = loadMatrixTraces(id);
                trackeable = matrixTraces;
                break;
        case USER_STORIES:

                    userStories = loadUserStories(id);
                    trackeable = userStories;
                    break;
        default:
            throw std::invalid_argument("No existe el Trackeable con el prefijo: "+id.getPrefix()+", loadTrackeable");


    }
    return trackeable;

}



Priority FileJsonManager::loadPriority(OID id) {
    Priority priority;
    RestrictionRequirement restrictionRequirement;
    FunctionalRequirement functionalRequirement;
    NonFunctionalRequirement nonFunctionalRequirement;
    ActorUC actorUC;
    InformationRequirement informationRequirement;
    Organization organization;
    SystemObjective systemObjective;
    UserCase userCase;
    Text text;
    MatrixTraces matrixTraces;
    UserStories userStories;

    switch (prefixes[id.getPrefix()]) {

        case RESTRICTION_REQUIREMENT:
            restrictionRequirement = loadRestrictionRequirement(id);
            priority
     = restrictionRequirement;
            break;
        case FUNCTIONAL_REQUIREMENT:
            functionalRequirement = loadFunctionalRequirement(id);
            priority
     = functionalRequirement;
            break;
        case NON_FUNCTIONAL_REQUIREMENT:

            nonFunctionalRequirement = loadNonFunctionalRequirement(id);
            priority
     = nonFunctionalRequirement;
            break;
        case INFORMATION_REQUIREMENT:

            informationRequirement = loadInformationRequirement(id);
            priority
     = informationRequirement;
            break;

        case SYSTEM_OBJECTIVE:

            systemObjective = loadSystemObjective(id);
            priority
     = systemObjective;
            break;
        case USER_CASE:

            userCase = loadUserCase(id);
            priority
     = userCase;
            break;


        case USER_STORIES:

            userStories = loadUserStories(id);
            priority
     = userStories;
            break;
        default:
            throw std::invalid_argument("No existe el Priority con el prefijo: "+id.getPrefix()+", loadPriority");


    }
    priority.setID(id);
    return priority;
}

std::list<UserCase> FileJsonManager::loadAllUserCase() {
    std::list<UserCase> userCases;
    for (auto &element: MEMUserCase) {
        userCases.push_back(element.second);
    }
    return userCases;
}

std::list<Text> FileJsonManager::loadAllText() {
    std::list<Text> texts;
    for (auto &element: MEMText) {
        texts.push_back(element.second);
    }
    return texts;
}


Stakeholder FileJsonManager::loadFileStakeholder(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeStakeholder(j);
}

std::list<Stakeholder> FileJsonManager::loadFileAllStakeholder() {
    std::list<Stakeholder> stakeholders;
    json j = loadAll("SH");
    Jsoneitor jsoneitor;
    for (json element: j) {
        stakeholders.push_back(jsoneitor.deserializeStakeholder(element));
    }
    return stakeholders;
}

RestrictionRequirement FileJsonManager::loadFileRestrictionRequirement(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeRestrictionRequirement(j);
}

std::list<RestrictionRequirement> FileJsonManager::loadFileAllRestrictionRequirement() {
    std::list<RestrictionRequirement> restrictionRequirements;
    json j = loadAll("RR");
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        restrictionRequirements.push_back(jsoneitor.deserializeRestrictionRequirement(element));
    }
    return restrictionRequirements;
}

FunctionalRequirement FileJsonManager::loadFileFunctionalRequirement(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeFunctionalRequirement(j);
}

std::list<FunctionalRequirement> FileJsonManager::loadFileAllFunctionalRequirement() {
    std::list<FunctionalRequirement> functionalRequirements;
    json j = loadAll("FR");
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        functionalRequirements.push_back(jsoneitor.deserializeFunctionalRequirement(element));
    }
    return functionalRequirements;
}

NonFunctionalRequirement FileJsonManager::loadFileNonFunctionalRequirement(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeNonFunctionalRequirement(j);
}

std::list<NonFunctionalRequirement> FileJsonManager::loadFileAllNonFunctionalRequirement() {
    std::list<NonFunctionalRequirement> nonFunctionalRequirements;
    json j = loadAll("NF");
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        nonFunctionalRequirements.push_back(jsoneitor.deserializeNonFunctionalRequirement(element));
    }
    return nonFunctionalRequirements;
}

ActorUC FileJsonManager::loadFileActorUC(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeActorUC(j);
}

std::list<ActorUC> FileJsonManager::loadFileAllActorUC() {
    std::list<ActorUC> actorUCs;
    json j = loadAll("AC");
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        actorUCs.push_back(jsoneitor.deserializeActorUC(element));
    }
    return actorUCs;
}

InformationRequirement FileJsonManager::loadFileInformationRequirement(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeInformationRequirement(j);
}

std::list<InformationRequirement> FileJsonManager::loadFileAllInformationRequirement() {
    std::list<InformationRequirement> informationRequirements;
    json j = loadAll("IR");
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        informationRequirements.push_back(jsoneitor.deserializeInformationRequirement(element));
    }
    return informationRequirements;
}

Organization FileJsonManager::loadFileOrganization(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeOrganization(j);
}


std::list<Organization> FileJsonManager::loadFileAllOrganization() {
    std::list<Organization> organizations;
    json j = loadAll("OR");
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        organizations.push_back(jsoneitor.deserializeOrganization(element));
    }
    return organizations;
}


SystemObjective FileJsonManager::loadFileSystemObjective(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeSystemObjective(j);
}

std::list<SystemObjective> FileJsonManager::loadFileAllSystemObjective() {
    std::list<SystemObjective> systemObjectives;
    json j = loadAll("SO");
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        systemObjectives.push_back(jsoneitor.deserializeSystemObjective(element));
    }
    return systemObjectives;
}

UserCase FileJsonManager::loadFileUserCase(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeUserCase(j);
}

Text FileJsonManager::loadFileText(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeText(j);
}

MatrixTraces FileJsonManager::loadFileMatrixTraces(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeMatrixTraces(j);
}

UserStories FileJsonManager::loadFileUserStories(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeUserStories(j);
}

Trackeable *FileJsonManager::loadFileTrackeable(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    return jsoneitor.deserializeTrackeable(j);
}

Priority *FileJsonManager::loadFilePriority(OID id) {
    json j = load(id);
    Jsoneitor jsoneitor;
    Priority *p = jsoneitor.deserializePriority(j);
    p->setID(id);
    return p;
}

std::list<UserCase> FileJsonManager::loadFileAllUserCase() {
    std::list<UserCase> userCases;
    json j = loadAll("UC");
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        userCases.push_back(jsoneitor.deserializeUserCase(element));
    }
    return userCases;
}

std::list<Text> FileJsonManager::loadFileAllText() {
    std::list<Text> texts;
    json j = loadAll(Text::getPrefixID());
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        texts.push_back(jsoneitor.deserializeText(element));
    }
    return texts;
}

std::list<MatrixTraces> FileJsonManager::loadFileAllMatrixTraces() {
    std::list<MatrixTraces> matrixTraces;
    json j = loadAll(MatrixTraces::getPrefixID());
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        matrixTraces.push_back(jsoneitor.deserializeMatrixTraces(element));
    }
    return matrixTraces;
}

std::list<UserStories> FileJsonManager::loadFileAllUserStories() {
    std::list<UserStories> userStories;
    json j = loadAll(UserStories::getPrefixID());
    Jsoneitor jsoneitor;
    for (auto &element: j) {
        userStories.push_back(jsoneitor.deserializeUserStories(element));
    }
    return userStories;
}


unsigned FileJsonManager::lastStakeholder() {
    unsigned last = 0;
    for (auto &element: MEMStakeholder) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastRestrictionRequirement() {
   unsigned last = 0;
    for (auto &element: MEMRestrictionRequirement) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastFunctionalRequirement() {
    unsigned last = 0;
    for (auto &element: MEMFunctionalRequirement) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastNonFunctionalRequirement() {
    unsigned last = 0;
    for (auto &element: MEMNonFunctionalRequirement) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastActorUC() {
    unsigned last = 0;
    for (auto &element: MEMActorUC) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastInformationRequirement() {
    unsigned last = 0;
    for (auto &element: MEMInformationRequirement) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastOrganization() {
    unsigned last = 0;
    for (auto &element: MEMOrganization) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}


unsigned FileJsonManager::lastSystemObjective() {
    unsigned last = 0;
    for (auto &element: MEMSystemObjective) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastUserCase() {
   unsigned last = 0;
    for (auto &element: MEMUserCase) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastText() {
    unsigned last = 0;
    for (auto &element: MEMText) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned FileJsonManager::lastMatrixTraces() {
    unsigned last = 0;
    for (auto &element: MEMMatrixTraces) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned int FileJsonManager::lastUserStories() {
    unsigned last = 0;
    for (auto &element: MEMUserStories) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}


void FileJsonManager::save(Stakeholder stakeholder) {
    MEMStakeholder[stakeholder.getId()] = stakeholder;
    Jsoneitor jsoneitor;
    jsoneitor.visit(stakeholder);
}

void FileJsonManager::save(RestrictionRequirement restrictionRequirement) {
    MEMRestrictionRequirement[restrictionRequirement.getId()] = restrictionRequirement;
    Jsoneitor jsoneitor;
    jsoneitor.visit(restrictionRequirement);
}

void FileJsonManager::save(FunctionalRequirement functionalRequirement) {
    MEMFunctionalRequirement[functionalRequirement.getId()] = functionalRequirement;
    Jsoneitor jsoneitor;
    jsoneitor.visit(functionalRequirement);
}

void FileJsonManager::save(NonFunctionalRequirement nonFunctionalRequirement) {
    MEMNonFunctionalRequirement[nonFunctionalRequirement.getId()] = nonFunctionalRequirement;
    Jsoneitor jsoneitor;
    jsoneitor.visit(nonFunctionalRequirement);
}

void FileJsonManager::save(ActorUC actorUC) {
    MEMActorUC[actorUC.getId()] = actorUC;
    Jsoneitor jsoneitor;
    jsoneitor.visit(actorUC);
}

void FileJsonManager::save(InformationRequirement informationRequirement) {
    MEMInformationRequirement[informationRequirement.getId()] = informationRequirement;
    Jsoneitor jsoneitor;
    jsoneitor.visit(informationRequirement);
}

void FileJsonManager::save(Organization organization) {
    MEMOrganization[organization.getId()] = organization;
    Jsoneitor jsoneitor;
    jsoneitor.visit(organization);
}

void FileJsonManager::save(SystemObjective systemObjective) {
    MEMSystemObjective[systemObjective.getId()] = systemObjective;
    Jsoneitor jsoneitor;
    jsoneitor.visit(systemObjective);
}

void FileJsonManager::save(UserCase &userCase) {
    MEMUserCase[userCase.getId()] = userCase;
    Jsoneitor jsoneitor;
    jsoneitor.visit(userCase);
}


void FileJsonManager::save(Text text) {
    MEMText[text.getId()] = text;
    Jsoneitor jsoneitor;
    jsoneitor.visit(text);
}


void FileJsonManager::save(MatrixTraces matrixTraces) {
    MEMMatrixTraces[matrixTraces.getId()] = matrixTraces;
    Jsoneitor jsoneitor;
    jsoneitor.visit(matrixTraces);

}

void FileJsonManager::save(Trackeable *pTrackeable) {

    Stakeholder stakeholder;
    RestrictionRequirement restrictionRequirement;
    FunctionalRequirement functionalRequirement;
    NonFunctionalRequirement nonFunctionalRequirement;
    ActorUC actorUC;
    UserCase userCase;
    InformationRequirement informationRequirement;
    Organization organization;
    SystemObjective systemObjective;
    Text text;
    MatrixTraces matrixTraces;
    UserStories userStories;

    auto tipo = pTrackeable->getId().getPrefix();
    Jsoneitor jsoneitor;
    jsoneitor.visit(pTrackeable);
    switch (prefixes[tipo]) {
        case STAKEHOLDER:
            stakeholder = MEMStakeholder[pTrackeable->getId()];
            stakeholder.setTrackeablePart(pTrackeable);
            MEMStakeholder[pTrackeable->getId()] = stakeholder;
            break;
        case RESTRICTION_REQUIREMENT:
            restrictionRequirement = MEMRestrictionRequirement[pTrackeable->getId()];
            restrictionRequirement.setTrackeablePart(pTrackeable);
            MEMRestrictionRequirement[pTrackeable->getId()] = restrictionRequirement;
            break;
        case FUNCTIONAL_REQUIREMENT:
            functionalRequirement = MEMFunctionalRequirement[pTrackeable->getId()];
            functionalRequirement.setTrackeablePart(pTrackeable);
            MEMFunctionalRequirement[pTrackeable->getId()] = functionalRequirement;
            break;
        case NON_FUNCTIONAL_REQUIREMENT:
            nonFunctionalRequirement = MEMNonFunctionalRequirement[pTrackeable->getId()];
            nonFunctionalRequirement.setTrackeablePart(pTrackeable);
            MEMNonFunctionalRequirement[pTrackeable->getId()] = nonFunctionalRequirement;
            break;
        case ACTOR_UC:
            actorUC = MEMActorUC[pTrackeable->getId()];
            actorUC.setTrackeablePart(pTrackeable);
            MEMActorUC[pTrackeable->getId()] = actorUC;
            break;
        case INFORMATION_REQUIREMENT:
            informationRequirement = MEMInformationRequirement[pTrackeable->getId()];
            informationRequirement.setTrackeablePart(pTrackeable);
            MEMInformationRequirement[pTrackeable->getId()] = informationRequirement;
            break;
        case ORGANIZATION:
            organization = MEMOrganization[pTrackeable->getId()];
            organization.setTrackeablePart(pTrackeable);
            MEMOrganization[pTrackeable->getId()] = organization;
            break;
        case SYSTEM_OBJECTIVE:
            systemObjective = MEMSystemObjective[pTrackeable->getId()];
            systemObjective.setTrackeablePart(pTrackeable);
            MEMSystemObjective[pTrackeable->getId()] = systemObjective;
            break;
        case USER_CASE:
            userCase = MEMUserCase[pTrackeable->getId()];
            userCase.setTrackeablePart(pTrackeable);
            MEMUserCase[pTrackeable->getId()] = userCase;
            break;
        case TEXT:
            text = MEMText[pTrackeable->getId()];
            text.setTrackeablePart(pTrackeable);
            MEMText[pTrackeable->getId()] = text;
            break;
        case MATRIX_TRACES:
            matrixTraces = MEMMatrixTraces[pTrackeable->getId()];
            matrixTraces.setTrackeablePart(pTrackeable);
            MEMMatrixTraces[pTrackeable->getId()] = matrixTraces;
            break;
        case USER_STORIES:
            userStories = MEMUserStories[pTrackeable->getId()];
            userStories.setTrackeablePart(pTrackeable);
            MEMUserStories[pTrackeable->getId()] = userStories;
            break;
        default:
            throw std::invalid_argument("Tipo de Trackeable no reconocido, save Trackeable*");
    }
}

void FileJsonManager::save(Priority *pPriority) {
    auto tipo = pPriority->getId().getPrefix();
    Jsoneitor jsoneitor;
    jsoneitor.visit(pPriority);
    switch (prefixes[tipo]) {

        case RESTRICTION_REQUIREMENT:
            MEMRestrictionRequirement[pPriority->getId()].setPriorityPart(pPriority);
            break;
        case FUNCTIONAL_REQUIREMENT:
            MEMFunctionalRequirement[pPriority->getId()].setPriorityPart(pPriority);
            break;
        case NON_FUNCTIONAL_REQUIREMENT:
            MEMNonFunctionalRequirement[pPriority->getId()].setPriorityPart(pPriority);
            break;
        case INFORMATION_REQUIREMENT:
            MEMInformationRequirement[pPriority->getId()].setPriorityPart(pPriority);
            break;

        case SYSTEM_OBJECTIVE:
            MEMSystemObjective[pPriority->getId()].setPriorityPart(pPriority);
            break;
        case USER_CASE:
            MEMUserCase[pPriority->getId()].setPriorityPart(pPriority);
            break;
        case USER_STORIES:
            MEMUserStories[pPriority->getId()].setPriorityPart(pPriority);
            break;
        default:
            throw std::invalid_argument("Tipo de Priority no reconocido, save Priority*");
    }
}

void FileJsonManager::save(UserStories userStories) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(userStories);
}

void FileJsonManager::saveAll(std::list<Stakeholder> stakeholders) {
    Jsoneitor jsoneitor;
    for (auto &stakeholder: stakeholders) {
        jsoneitor.visit(stakeholder);
    }
}

void FileJsonManager::saveAll(std::list<RestrictionRequirement> restrictionRequirements) {
    Jsoneitor jsoneitor;
    for (auto &restrictionRequirement: restrictionRequirements) {
        jsoneitor.visit(restrictionRequirement);
    }
}

void FileJsonManager::saveAll(std::list<FunctionalRequirement> functionalRequirements) {
    Jsoneitor jsoneitor;
    for (auto &functionalRequirement: functionalRequirements) {
        jsoneitor.visit(functionalRequirement);
    }
}

void FileJsonManager::saveAll(std::list<NonFunctionalRequirement> nonFunctionalRequirements) {
    Jsoneitor jsoneitor;
    for (auto &nonFunctionalRequirement: nonFunctionalRequirements) {
        jsoneitor.visit(nonFunctionalRequirement);
    }
}

void FileJsonManager::saveAll(std::list<ActorUC> actorUCs) {
    Jsoneitor jsoneitor;
    for (auto &actorUC: actorUCs) {
        jsoneitor.visit(actorUC);
    }
}

void FileJsonManager::saveAll(std::list<InformationRequirement> informationRequirements) {
    Jsoneitor jsoneitor;
    for (auto &informationRequirement: informationRequirements) {
        jsoneitor.visit(informationRequirement);
    }
}

void FileJsonManager::saveAll(std::list<Organization> organizations) {
    Jsoneitor jsoneitor;
    for (auto &organization: organizations) {
        jsoneitor.visit(organization);
    }
}


void FileJsonManager::saveAll(std::list<SystemObjective> systemObjectives) {
    Jsoneitor jsoneitor;
    for (auto &systemObjective: systemObjectives) {
        jsoneitor.visit(systemObjective);
    }
}

void FileJsonManager::saveAll(std::list<UserCase> userCases) {
    Jsoneitor jsoneitor;
    for (auto &userCase: userCases) {
        jsoneitor.visit(userCase);
    }
}

json FileJsonManager::loadAll(std::string prefix) {
    std::string path = "TFG/Jsons/" + prefix + ".json";

    std::ifstream i(path);
    json listaj;

// Check if the file exists and load its contents into listaj if it does
    if (i.good() && i.peek() != std::ifstream::traits_type::eof()) {
        i >> listaj;
    } else {
        std::ofstream o(path);
    }

// Add the new json object to the listaj

    return listaj;
}


template<class T>
void save(T trackeable) {
    Jsoneitor jsoneitor;
    jsoneitor.visit(trackeable);
}

template<class T>
void saveAll(std::list<T> trackeables) {
    for (auto &trackeable: trackeables) {
        save(trackeable);
    }
}











