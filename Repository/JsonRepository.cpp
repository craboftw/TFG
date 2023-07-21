//
// Created by Fran- on 26/06/2023.
//

#include <list>
#include "JsonRepository.h"
#include "HTML/ServicioHTML.h"


void JsonRepository::save(json singlejson) {

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

json JsonRepository::load(OID oid) {
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


json JsonRepository::loadFile(OID oid) {
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

json JsonRepository::loadFileAll(std::string prefix) {
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

bool JsonRepository::exist(OID id) {
    if (id.getPrefix() == "XX") {
        return false;
    }
    switch (prefixes[id.getPrefix()]) {
        case STAKEHOLDER:
            if (MEMStakeholder.find(id) == MEMStakeholder.end()) {
                return false;
            }
            break;

        case RESTRICTION_REQUIREMENT:
            if (MEMRestrictionRequirement.find(id) == MEMRestrictionRequirement.end()) {
                return false;
            }
            break;
        case FUNCTIONAL_REQUIREMENT:
            if (MEMFunctionalRequirement.find(id) == MEMFunctionalRequirement.end()) {
                return false;
            }
            break;
        case NON_FUNCTIONAL_REQUIREMENT:

            if (MEMNonFunctionalRequirement.find(id) == MEMNonFunctionalRequirement.end()) {
                return false;
            }
            break;
        case ACTOR_UC:
            if (MEMActorUC.find(id) == MEMActorUC.end()) {
                return false;
            }
            break;
        case INFORMATION_REQUIREMENT:
            if (MEMInformationRequirement.find(id) == MEMInformationRequirement.end()) {
                return false;
            }
            break;
        case ORGANIZATION:
            if (MEMOrganization.find(id) == MEMOrganization.end()) {
                return false;
            }
            break;
        case SYSTEM_OBJECTIVE:
            if (MEMSystemObjective.find(id) == MEMSystemObjective.end()) {
                return false;
            }
            break;
        case USER_CASE:
            if (MEMUserCase.find(id) == MEMUserCase.end()) {
                return false;
            }
            break;
        case TEXT:
            if (MEMText.find(id) == MEMText.end()) {
                return false;
            }
            break;
        case MATRIX_TRACES:
            if (MEMMatrixTraces.find(id) == MEMMatrixTraces.end()) {
                return false;
            }
            break;
        case USER_STORIES:
            if (MEMUserStories.find(id) == MEMUserStories.end()) {
                return false;
            }
        case USER_CASE_DIAGRAM:
            if (MEMUserCaseDiagram.find(id) == MEMUserCaseDiagram.end()) {
                return false;
            }
            break;
        case INDEX:
            if (MEMIndex.find(id) == MEMIndex.end()) {
                return false;
            }
            break;
        default:
            throw std::invalid_argument(
                    "No existe el Trackeable con el prefijo: " + id.getPrefix() + ", exist");


    }
    return true;

}


Stakeholder JsonRepository::loadStakeholder(OID id) {
    if (MEMStakeholder.find(id) == MEMStakeholder.end()) {
        throw std::invalid_argument("No existe el Stakeholder, loadStakeholder");
    }
    return MEMStakeholder[id];


}

std::list<Stakeholder> JsonRepository::loadAllStakeholder() {
    std::list<Stakeholder> stakeholders;
    for (auto &element: MEMStakeholder) {
        stakeholders.push_back(element.second);
    }
    return stakeholders;
}

RestrictionRequirement JsonRepository::loadRestrictionRequirement(OID id) {
    if (MEMRestrictionRequirement.find(id) == MEMRestrictionRequirement.end()) {
        throw std::invalid_argument("No existe el RestrictionRequirement, loadRestrictionRequirement");
    }
    return MEMRestrictionRequirement[id];

}

std::list<RestrictionRequirement> JsonRepository::loadAllRestrictionRequirement() {
    std::list<RestrictionRequirement> restrictionRequirements;
    for (auto &element: MEMRestrictionRequirement) {
        restrictionRequirements.push_back(element.second);
    }
    return restrictionRequirements;
}

FunctionalRequirement JsonRepository::loadFunctionalRequirement(OID id) {
    if (MEMFunctionalRequirement.find(id) == MEMFunctionalRequirement.end()) {
        throw std::invalid_argument("No existe el FunctionalRequirement, loadFunctionalRequirement");
    }
    return MEMFunctionalRequirement[id];
}

std::list<FunctionalRequirement> JsonRepository::loadAllFunctionalRequirement() {
    std::list<FunctionalRequirement> functionalRequirements;
    for (auto &element: MEMFunctionalRequirement) {
        functionalRequirements.push_back(element.second);
    }
    return functionalRequirements;
}

NonFunctionalRequirement JsonRepository::loadNonFunctionalRequirement(OID id) {
    if (MEMNonFunctionalRequirement.find(id) == MEMNonFunctionalRequirement.end()) {
        throw std::invalid_argument("No existe el NonFunctionalRequirement, loadNonFunctionalRequirement");
    }
    return MEMNonFunctionalRequirement[id];
}

std::list<NonFunctionalRequirement> JsonRepository::loadAllNonFunctionalRequirement() {
    std::list<NonFunctionalRequirement> nonFunctionalRequirements;
    for (auto &element: MEMNonFunctionalRequirement) {
        nonFunctionalRequirements.push_back(element.second);
    }
    return nonFunctionalRequirements;
}

ActorUC JsonRepository::loadActorUC(OID id) {
    if (MEMActorUC.find(id) == MEMActorUC.end()) {
        throw std::invalid_argument("No existe el ActorUC, loadActorUC");
    }
    return MEMActorUC[id];
}

std::list<ActorUC> JsonRepository::loadAllActorUC() {
    std::list<ActorUC> actorUCs;
    for (auto &element: MEMActorUC) {
        actorUCs.push_back(element.second);
    }
    return actorUCs;
}

InformationRequirement JsonRepository::loadInformationRequirement(OID id) {
    if (MEMInformationRequirement.find(id) == MEMInformationRequirement.end()) {
        throw std::invalid_argument("No existe el InformationRequirement, loadInformationRequirement");
    }
    return MEMInformationRequirement[id];
}

std::list<InformationRequirement> JsonRepository::loadAllInformationRequirement() {
    std::list<InformationRequirement> informationRequirements;
    for (auto &element: MEMInformationRequirement) {
        informationRequirements.push_back(element.second);
    }
    return informationRequirements;
}

Organization JsonRepository::loadOrganization(OID id) {
    if (MEMOrganization.find(id) == MEMOrganization.end()) {
        throw std::invalid_argument("No existe el Organization, loadOrganization");
    }
    return MEMOrganization[id];
}


std::list<Organization> JsonRepository::loadAllOrganization() {
    std::list<Organization> organizations;
    for (auto &element: MEMOrganization) {
        organizations.push_back(element.second);
    }
    return organizations;
}


SystemObjective JsonRepository::loadSystemObjective(OID id) {
    if (MEMSystemObjective.find(id) == MEMSystemObjective.end()) {
        throw std::invalid_argument("No existe el SystemObjective, loadSystemObjective");
    }
    return MEMSystemObjective[id];
}

std::list<SystemObjective> JsonRepository::loadAllSystemObjective() {
    std::list<SystemObjective> systemObjectives;
    for (auto &element: MEMSystemObjective) {
        systemObjectives.push_back(element.second);
    }
    return systemObjectives;
}

UserCase JsonRepository::loadUserCase(OID id) {
    if (MEMUserCase.find(id) == MEMUserCase.end()) {
        throw std::invalid_argument("No existe el UserCase, loadUserCase");
    }
    return MEMUserCase[id];
}

Text JsonRepository::loadText(OID id) {
    if (MEMText.find(id) == MEMText.end()) {
        throw std::invalid_argument("No existe el Text, loadText");
    }
    return MEMText[id];
}

MatrixTraces JsonRepository::loadMatrixTraces(OID id) {
    if (MEMMatrixTraces.find(id) == MEMMatrixTraces.end()) {
        throw std::invalid_argument("No existe el MatrixTraces, loadMatrixTraces");
    }
    return MEMMatrixTraces[id];
}

UserStories JsonRepository::loadUserStories(OID id) {
    if (MEMUserStories.find(id) == MEMUserStories.end()) {
        throw std::invalid_argument("No existe el UserStories, loadUserStories");
    }
    return MEMUserStories[id];
}


UserCaseDiagram JsonRepository::loadUserCaseDiagram(OID id) {
    if (MEMUserCaseDiagram.find(id) == MEMUserCaseDiagram.end()) {
        throw std::invalid_argument("No existe el UserCaseDiagram, loadUserCaseDiagram");
    }
    return MEMUserCaseDiagram[id];
}

Index JsonRepository::loadIndex(OID id) {
    if (MEMIndex.find(id) == MEMIndex.end()) {
        throw std::invalid_argument("No existe el Index, loadIndex");
    }
    return MEMIndex[id];
}

Persona JsonRepository::loadPersona(OID id) {
    if (MEMPersona.find(id) == MEMPersona.end()) {
        throw std::invalid_argument("No existe el Persona, loadPersona");
    }
    return MEMPersona[id];
}

Interview JsonRepository::loadInterview(OID id) {
    if (MEMInterview.find(id) == MEMInterview.end()) {
        throw std::invalid_argument("No existe el Interview, loadInterview");
    }
    return MEMInterview[id];
}






Trackeable JsonRepository::loadTrackeable(OID id) {
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
    UserCaseDiagram userCaseDiagram;
    Index index;

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

        case USER_CASE_DIAGRAM:
            userCaseDiagram = loadUserCaseDiagram(id);
            trackeable = userCaseDiagram;
            break;
        case INDEX:
            index = loadIndex(id);
            trackeable = index;
            break;
        default:
            throw std::invalid_argument(
                    "No existe el Trackeable con el prefijo: " + id.getPrefix() + ", loadTrackeable");


    }
    return trackeable;

}


Priority JsonRepository::loadPriority(OID id) {
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
            throw std::invalid_argument("No existe el Priority con el prefijo: " + id.getPrefix() + ", loadPriority");


    }
    priority.setID(id);
    return priority;
}

std::list<UserCase> JsonRepository::loadAllUserCase() {
    std::list<UserCase> userCases;
    for (auto &element: MEMUserCase) {
        userCases.push_back(element.second);
    }
    return userCases;
}

std::list<Text> JsonRepository::loadAllText() {
    std::list<Text> texts;
    for (auto &element: MEMText) {
        texts.push_back(element.second);
    }
    return texts;
}


std::list<MatrixTraces> JsonRepository::loadAllMatrixTraces() {
    std::list<MatrixTraces> matrixTraces;
    for (auto &element: MEMMatrixTraces) {
        matrixTraces.push_back(element.second);
    }
    return matrixTraces;
}

std::list<Index> JsonRepository::loadAllIndex() {
    std::list<Index> indexs;
    for (auto &element: MEMIndex) {
        indexs.push_back(element.second);
    }
    return indexs;
}


Stakeholder JsonRepository::loadFileStakeholder(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeStakeholder(j);
}

std::list<Stakeholder> JsonRepository::loadFileAllStakeholder() {
    std::list<Stakeholder> stakeholders;
    json j = loadAll("SH");
    JsonSerializer jsoneitor;
    for (json element: j) {
        stakeholders.push_back(jsoneitor.deserializeStakeholder(element));
    }
    return stakeholders;
}

RestrictionRequirement JsonRepository::loadFileRestrictionRequirement(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeRestrictionRequirement(j);
}

std::list<RestrictionRequirement> JsonRepository::loadFileAllRestrictionRequirement() {
    std::list<RestrictionRequirement> restrictionRequirements;
    json j = loadAll("RR");
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        restrictionRequirements.push_back(jsoneitor.deserializeRestrictionRequirement(element));
    }
    return restrictionRequirements;
}

FunctionalRequirement JsonRepository::loadFileFunctionalRequirement(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeFunctionalRequirement(j);
}

std::list<FunctionalRequirement> JsonRepository::loadFileAllFunctionalRequirement() {
    std::list<FunctionalRequirement> functionalRequirements;
    json j = loadAll("FR");
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        functionalRequirements.push_back(jsoneitor.deserializeFunctionalRequirement(element));
    }
    return functionalRequirements;
}

NonFunctionalRequirement JsonRepository::loadFileNonFunctionalRequirement(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeNonFunctionalRequirement(j);
}

std::list<NonFunctionalRequirement> JsonRepository::loadFileAllNonFunctionalRequirement() {
    std::list<NonFunctionalRequirement> nonFunctionalRequirements;
    json j = loadAll("NF");
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        nonFunctionalRequirements.push_back(jsoneitor.deserializeNonFunctionalRequirement(element));
    }
    return nonFunctionalRequirements;
}

ActorUC JsonRepository::loadFileActorUC(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeActorUC(j);
}

std::list<ActorUC> JsonRepository::loadFileAllActorUC() {
    std::list<ActorUC> actorUCs;
    json j = loadAll("AC");
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        actorUCs.push_back(jsoneitor.deserializeActorUC(element));
    }
    return actorUCs;
}

InformationRequirement JsonRepository::loadFileInformationRequirement(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeInformationRequirement(j);
}

std::list<InformationRequirement> JsonRepository::loadFileAllInformationRequirement() {
    std::list<InformationRequirement> informationRequirements;
    json j = loadAll("IR");
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        informationRequirements.push_back(jsoneitor.deserializeInformationRequirement(element));
    }
    return informationRequirements;
}

Organization JsonRepository::loadFileOrganization(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeOrganization(j);
}


std::list<Organization> JsonRepository::loadFileAllOrganization() {
    std::list<Organization> organizations;
    json j = loadAll("OR");
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        organizations.push_back(jsoneitor.deserializeOrganization(element));
    }
    return organizations;
}


SystemObjective JsonRepository::loadFileSystemObjective(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeSystemObjective(j);
}

std::list<SystemObjective> JsonRepository::loadFileAllSystemObjective() {
    std::list<SystemObjective> systemObjectives;
    json j = loadAll("SO");
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        systemObjectives.push_back(jsoneitor.deserializeSystemObjective(element));
    }
    return systemObjectives;
}

UserCase JsonRepository::loadFileUserCase(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeUserCase(j);
}

Text JsonRepository::loadFileText(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeText(j);
}

MatrixTraces JsonRepository::loadFileMatrixTraces(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeMatrixTraces(j);
}

UserStories JsonRepository::loadFileUserStories(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeUserStories(j);
}

Trackeable *JsonRepository::loadFileTrackeable(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeTrackeable(j);
}

Priority *JsonRepository::loadFilePriority(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    Priority *p = jsoneitor.deserializePriority(j);
    p->setID(id);
    return p;
}

std::list<UserCase> JsonRepository::loadFileAllUserCase() {
    std::list<UserCase> userCases;
    json j = loadAll("UC");
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        userCases.push_back(jsoneitor.deserializeUserCase(element));
    }
    return userCases;
}

std::list<Text> JsonRepository::loadFileAllText() {
    std::list<Text> texts;
    json j = loadAll(Text::getPrefixID());
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        texts.push_back(jsoneitor.deserializeText(element));
    }
    return texts;
}

std::list<MatrixTraces> JsonRepository::loadFileAllMatrixTraces() {
    std::list<MatrixTraces> matrixTraces;
    json j = loadAll(MatrixTraces::getPrefixID());
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        matrixTraces.push_back(jsoneitor.deserializeMatrixTraces(element));
    }
    return matrixTraces;
}

std::list<UserStories> JsonRepository::loadFileAllUserStories() {
    std::list<UserStories> userStories;
    json j = loadAll(UserStories::getPrefixID());
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        userStories.push_back(jsoneitor.deserializeUserStories(element));
    }
    return userStories;
}

std::list<UserCaseDiagram> JsonRepository::loadFileAllUserCaseDiagram() {
    std::list<UserCaseDiagram> userCaseDiagrams;
    json j = loadAll(UserCaseDiagram::getPrefixID());
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        userCaseDiagrams.push_back(jsoneitor.deserializerUserCaseDiagram(element));
    }
    return userCaseDiagrams;
}

Index JsonRepository::loadFileIndex(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializeIndex(j);
}

std::list<Index> JsonRepository::loadFileAllIndex() {
    std::list<Index> indexes;
    json j = loadAll(Index::getPrefixID());
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        indexes.push_back(jsoneitor.deserializeIndex(element));
    }
    return indexes;
}

Persona JsonRepository::loadFilePersona(OID id) {
    json j = load(id);
    JsonSerializer jsoneitor;
    return jsoneitor.deserializePersona(j);
}

std::list<Persona> JsonRepository::loadFileAllPersona() {
    std::list<Persona> personas;
    json j = loadAll(Persona::getPrefixID());
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        personas.push_back(jsoneitor.deserializePersona(element));
    }
    return personas;
}

std::list<Interview> JsonRepository::loadFileAllInterview() {
    std::list<Interview> interviews;
    json j = loadAll(Interview::getPrefixID());
    JsonSerializer jsoneitor;
    for (auto &element: j) {
        interviews.push_back(jsoneitor.deserializeInterview(element));
    }
    return interviews;
}


unsigned JsonRepository::lastStakeholder() {
    unsigned last = 0;
    for (auto &element: MEMStakeholder) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastRestrictionRequirement() {
    unsigned last = 0;
    for (auto &element: MEMRestrictionRequirement) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastFunctionalRequirement() {
    unsigned last = 0;
    for (auto &element: MEMFunctionalRequirement) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastNonFunctionalRequirement() {
    unsigned last = 0;
    for (auto &element: MEMNonFunctionalRequirement) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastActorUC() {
    unsigned last = 0;
    for (auto &element: MEMActorUC) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastInformationRequirement() {
    unsigned last = 0;
    for (auto &element: MEMInformationRequirement) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastOrganization() {
    unsigned last = 0;
    for (auto &element: MEMOrganization) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}


unsigned JsonRepository::lastSystemObjective() {
    unsigned last = 0;
    for (auto &element: MEMSystemObjective) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastUserCase() {
    unsigned last = 0;
    for (auto &element: MEMUserCase) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastText() {
    unsigned last = 0;
    for (auto &element: MEMText) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastMatrixTraces() {
    unsigned last = 0;
    for (auto &element: MEMMatrixTraces) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned int JsonRepository::lastUserStories() {
    unsigned last = 0;
    for (auto &element: MEMUserStories) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastUserCaseDiagram() {
    unsigned last = 0;
    for (auto &element: MEMUserCaseDiagram) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastIndex() {
    unsigned last = 0;
    for (auto &element: MEMIndex) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;

}

unsigned JsonRepository::lastPersona() {
    unsigned last = 0;
    for (auto &element: MEMPersona) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}

unsigned JsonRepository::lastInterview() {
    unsigned last = 0;
    for (auto &element: MEMInterview) {
        if (last < element.first.getId())
            last = element.first.getId();
    }
    return last;
}



void JsonRepository::save(Stakeholder stakeholder) {
    MEMStakeholder[stakeholder.getId()] = stakeholder;
    ServicioHTML::printElement(stakeholder.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(stakeholder);
}

void JsonRepository::save(RestrictionRequirement restrictionRequirement) {
    MEMRestrictionRequirement[restrictionRequirement.getId()] = restrictionRequirement;
    ServicioHTML::printElement(restrictionRequirement.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(restrictionRequirement);
}

void JsonRepository::save(FunctionalRequirement functionalRequirement) {
    MEMFunctionalRequirement[functionalRequirement.getId()] = functionalRequirement;
    ServicioHTML::printElement(functionalRequirement.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(functionalRequirement);
}

void JsonRepository::save(NonFunctionalRequirement nonFunctionalRequirement) {
    MEMNonFunctionalRequirement[nonFunctionalRequirement.getId()] = nonFunctionalRequirement;
    ServicioHTML::printElement(nonFunctionalRequirement.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(nonFunctionalRequirement);
}

void JsonRepository::save(ActorUC actorUC) {
    MEMActorUC[actorUC.getId()] = actorUC;
    ServicioHTML::printElement(actorUC.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(actorUC);
}

void JsonRepository::save(InformationRequirement informationRequirement) {
    MEMInformationRequirement[informationRequirement.getId()] = informationRequirement;
    ServicioHTML::printElement(informationRequirement.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(informationRequirement);
}

void JsonRepository::save(Organization organization) {
    MEMOrganization[organization.getId()] = organization;
    ServicioHTML::printElement(organization.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(organization);
}

void JsonRepository::save(SystemObjective systemObjective) {
    MEMSystemObjective[systemObjective.getId()] = systemObjective;
    ServicioHTML::printElement(systemObjective.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(systemObjective);
}

void JsonRepository::save(UserCase &userCase) {
    MEMUserCase[userCase.getId()] = userCase;
    ServicioHTML::printElement(userCase.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(userCase);
}


void JsonRepository::save(Text text) {
    MEMText[text.getId()] = text;
    ServicioHTML::printElement(text.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(text);
}


void JsonRepository::save(MatrixTraces matrixTraces) {
    MEMMatrixTraces[matrixTraces.getId()] = matrixTraces;
    ServicioHTML::printElement(matrixTraces.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(matrixTraces);
}

void JsonRepository::save(UserCaseDiagram userCaseDiagram) {
    MEMUserCaseDiagram[userCaseDiagram.getId()] = userCaseDiagram;
    ServicioHTML::printElement(userCaseDiagram.getId());
    JsonSerializer jsoneitor;
    jsoneitor.visit(userCaseDiagram);
}


void JsonRepository::save(Trackeable *pTrackeable) {

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
    JsonSerializer jsoneitor;
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
    ServicioHTML::printElement(pTrackeable->getId());
}

void JsonRepository::save(Priority *pPriority) {
    auto tipo = pPriority->getId().getPrefix();
    JsonSerializer jsoneitor;
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
    ServicioHTML::printElement(pPriority->getId());
}

void JsonRepository::save(UserStories userStories) {
    MEMUserStories[userStories.getId()] = userStories;
    JsonSerializer jsoneitor;
    ServicioHTML::printElement(userStories.getId());
    jsoneitor.visit(userStories);
}

void JsonRepository::save(Index index) {
    MEMIndex[index.getId()] = index;
    JsonSerializer jsoneitor;
    ServicioHTML::printHTML(index.getId());
    jsoneitor.visit(index);
}

void JsonRepository::save(Persona persona) {
    MEMPersona[persona.getId()] = persona;
    JsonSerializer jsoneitor;
    ServicioHTML::printElement(persona.getId());
    jsoneitor.visit(persona);
}


void JsonRepository::save(Interview interview) {
    MEMInterview[interview.getId()] = interview;
    JsonSerializer jsoneitor;
    ServicioHTML::printElement(interview.getId());
    jsoneitor.visit(interview);
}



void JsonRepository::saveAll(std::list<Stakeholder> stakeholders) {
    JsonSerializer jsoneitor;
    for (auto &stakeholder: stakeholders) {
        jsoneitor.visit(stakeholder);
    }
}

void JsonRepository::saveAll(std::list<RestrictionRequirement> restrictionRequirements) {
    JsonSerializer jsoneitor;
    for (auto &restrictionRequirement: restrictionRequirements) {
        jsoneitor.visit(restrictionRequirement);
    }
}

void JsonRepository::saveAll(std::list<FunctionalRequirement> functionalRequirements) {
    JsonSerializer jsoneitor;
    for (auto &functionalRequirement: functionalRequirements) {
        jsoneitor.visit(functionalRequirement);
    }
}

void JsonRepository::saveAll(std::list<NonFunctionalRequirement> nonFunctionalRequirements) {
    JsonSerializer jsoneitor;
    for (auto &nonFunctionalRequirement: nonFunctionalRequirements) {
        jsoneitor.visit(nonFunctionalRequirement);
    }
}

void JsonRepository::saveAll(std::list<ActorUC> actorUCs) {
    JsonSerializer jsoneitor;
    for (auto &actorUC: actorUCs) {
        jsoneitor.visit(actorUC);
    }
}

void JsonRepository::saveAll(std::list<InformationRequirement> informationRequirements) {
    JsonSerializer jsoneitor;
    for (auto &informationRequirement: informationRequirements) {
        jsoneitor.visit(informationRequirement);
    }
}

void JsonRepository::saveAll(std::list<Organization> organizations) {
    JsonSerializer jsoneitor;
    for (auto &organization: organizations) {
        jsoneitor.visit(organization);
    }
}


void JsonRepository::saveAll(std::list<SystemObjective> systemObjectives) {
    JsonSerializer jsoneitor;
    for (auto &systemObjective: systemObjectives) {
        jsoneitor.visit(systemObjective);
    }
}

void JsonRepository::saveAll(std::list<UserCase> userCases) {
    JsonSerializer jsoneitor;
    for (auto &userCase: userCases) {
        jsoneitor.visit(userCase);
    }
}

json JsonRepository::loadAll(std::string prefix) {
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
    JsonSerializer jsoneitor;
    jsoneitor.visit(trackeable);
}

template<class T>
void saveAll(std::list<T> trackeables) {
    for (auto &trackeable: trackeables) {
        save(trackeable);
    }
}











