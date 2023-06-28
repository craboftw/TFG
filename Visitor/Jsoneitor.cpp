//
// Created by Fran- on 24/06/2023.
//

#include <fstream>
#include "Jsoneitor.h"
#include "../Dominio/InformationRequirement.h"
#include "../Dominio/Generic.h"
#include "../Dominio/Trackeable/Stakeholder.h"

using json = nlohmann::json;

class InformationRequirement;
class ActorUC;
class SystemObjective;
class RestrictionRequirement;
class FunctionalRequirement;
class NonFunctionalRequirement;
class Stakeholder;

typedef std::string OID;


typedef struct TrackeableDTO{
    OID id;
    std::string name;
    std::string description;
    std::string versionMajor;
    std::string versionMinor;
    Fecha date;
    std::string comments;
    std::set<OID> authors;
    std::list<OID> tracesFrom;
    std::list<OID> tracesTo;
    std::list<Change> listOfChanges;
};

typedef struct PriorityDTO{
    Priority::Importance urgencyLevel;
    Priority::Importance importanceLevel;
    Priority::Estability estibility;
    Priority::Development_phase phase;
};



json serializeListOfChanges(const std::list<Change>& listOfChanges) {
    json j;

    // Serializar cada cambio en la lista
    if (listOfChanges.empty()) {
        j = std::list<int>();
    }
    for (const Change& cambio : listOfChanges) {
        json cambioJson;
        cambioJson["version"] = cambio.getVersion();
        cambioJson["date"] = cambio.getDate().toString();
        cambioJson["comments"] = cambio.getComments();
        j.push_back(cambioJson);
    }
    return j;
}


json trackeablePart(Trackeable* objeto,json& j)
{
    j["id"] = objeto->getId();
    j["name"] = objeto->getName();
    j["description"] = objeto->getDescription();
    j["versionMajor"] = objeto->getVersionMajor();
    j["versionMinor"] = objeto->getVersionMinor();
    j["date_init"] = objeto->getDate().toString();
    j["comments"] = objeto->getComments();
    j["authors"] = objeto->getAuthors();
    j["tracesFrom"] = objeto->getTracesFrom();
    j["tracesTo"] = objeto->getTracesTo();
    j["changes"] = serializeListOfChanges(objeto->getChanges());

    return j;
}



json priorityPart(Priority* objeto,json& j)
{
    j["importanceLevel"] = objeto->getImportanceLevel();
    j["urgencyLevel"] = objeto->getUrgencyLevel();
    j["phase"] = objeto->getPhase();
    j["estability"] = objeto->getEstability();

    return j;
}

//Deserializar la lista de cambios
std::list<Change> deserializeListOfChanges(const json& j) {
    std::list<Change> listOfChanges;

    // Deserializar cada cambio en la lista
    for (const json& cambioJson : j) {
        Change cambio;
        cambio.setVersion(cambioJson["version"]);
        std::string date = cambioJson["date"];
        cambio.setDate(Fecha(date));
        cambio.setComments(cambioJson["comments"]);
        listOfChanges.push_back(cambio);
    }
    return listOfChanges;
}

TrackeableDTO deserializeTrackeableDTO(const json& j) {
    TrackeableDTO trackeableDTO;
    trackeableDTO.id = j["id"];
    trackeableDTO.name = j["name"];
    trackeableDTO.description = j["description"];
    trackeableDTO.versionMajor = j["versionMajor"];
    trackeableDTO.versionMinor = j["versionMinor"];
    trackeableDTO.date = Fecha(j["date_init"]);
    trackeableDTO.comments = j["comments"];
    trackeableDTO.authors = j["authors"];
    trackeableDTO.tracesFrom = j["tracesFrom"];
    trackeableDTO.tracesTo = j["tracesTo"];
    trackeableDTO.listOfChanges = deserializeListOfChanges(j["changes"]);
    return trackeableDTO;
}

PriorityDTO deserializePriorityDTO(const json& j) {
    PriorityDTO priorityDTO;
    priorityDTO.importanceLevel = j["importanceLevel"];
    priorityDTO.urgencyLevel = j["urgencyLevel"];
    priorityDTO.phase = j["phaseestability"];
    priorityDTO.estibility = j["estability"];
    return priorityDTO;
}

json serializeTimeQuantity(const TimeQuantity& timeQuantity) {
    json j;
    j["quantity"] = timeQuantity.getQuantity();
    j["unit"] = timeQuantity.getUnit();
    return j;
}

TimeQuantity deserializeTimeQuantity(const json& j) {
    TimeQuantity timeQuantity;
    timeQuantity.setQuantity(j["quantity"]);
    timeQuantity.setUnit(j["unit"]);
    return timeQuantity;
}

void setTrackeablePart(TrackeableDTO trackeableDTO, Trackeable* trackeable) {
    trackeable->setName(trackeableDTO.name);
    trackeable->setDescription(trackeableDTO.description);
    trackeable->setVersionMajor(trackeableDTO.versionMajor);
    trackeable->setVersionMinor(trackeableDTO.versionMinor);
    trackeable->setDate(trackeableDTO.date);
    trackeable->setComments(trackeableDTO.comments);
    trackeable->setAuthors(trackeableDTO.authors);
    trackeable->setTracesFrom(trackeableDTO.tracesFrom);
    trackeable->setTracesTo(trackeableDTO.tracesTo);
    trackeable->setChanges(trackeableDTO.listOfChanges);
}


void Jsoneitor::visit(InformationRequirement informationRequirement) {

    json j;

/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    trackeablePart(&informationRequirement,j);

/*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    priorityPart(&informationRequirement,j);

/*｡o°✥✤✣INFORMATION REQUIREMENT PART✣✤✥°o｡*/
    j["maxSimultaneousOccurrence"] = informationRequirement.getMaxSimultaneousOccurrence();
    j["avgSimultaneousOccurrence"] = informationRequirement.getAvgSimultaneousOccurrence();
    j["lifeMaxEstimate"] = serializeTimeQuantity(informationRequirement.getLifeMaxEstimate());
    j["lifeAvgEstimate"] = serializeTimeQuantity(informationRequirement.getLifeAvgEstimate());
    


}

InformationRequirement Jsoneitor::deserializeInformationRequirement(json j) {

    /*----------------------------------------------*/
    /*DESERIALIZATION OF THE INFORMATION REQUIREMENT*/
    /*----------------------------------------------*/
/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);


/*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

/*｡o°✥✤✣INFORMATION REQUIREMENT PART✣✤✥°o｡*/
    unsigned int maxSimultaneousOccurrence = j["maxSimultaneousOccurrence"];
    unsigned int avgSimultaneousOccurrence = j["avgSimultaneousOccurrence"];
    TimeQuantity lifeMaxEstimate = deserializeTimeQuantity(j["lifeMaxEstimate"]);
    TimeQuantity lifeAvgEstimate = deserializeTimeQuantity(j["lifeAvgEstimate"]);

    /*---------------------------------------*/
    /*CREATION OF THE INFORMATION REQUIREMENT*/
    /*---------------------------------------*/
/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    InformationRequirement o(trackeableDTO.id);
    o.setName(trackeableDTO.name);
    o.setDescription(trackeableDTO.description);
    o.setVersionMajor(trackeableDTO.versionMajor);
    o.setVersionMinor(trackeableDTO.versionMinor);
    o.setDate(trackeableDTO.date);
    o.setComments(trackeableDTO.comments);
    o.setAuthors(trackeableDTO.authors);
    o.setTracesFrom(trackeableDTO.tracesFrom);
    o.setTracesTo(trackeableDTO.tracesTo);
    o.setChanges(trackeableDTO.listOfChanges);



/*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    i.setImportanceLevel(importanceLevel);
    i.setUrgencyLevel(urgencyLevel);
    i.setPhase(phase);
    i.setEstability(estability);

/*｡o°✥✤✣INFORMATION REQUIREMENT PART✣✤✥°o｡*/
    i.setMaxSimultaneousOccurrence(maxSimultaneousOccurrence);
    i.setAvgSimultaneousOccurrence(avgSimultaneousOccurrence);
    i.setLifeMaxEstimate(lifeMaxEstimate);
    i.setLifeAvgEstimate(lifeAvgEstimate);

    return i;
}



void Jsoneitor::visit(ActorUC actorUC) {

    /*-------------------------------------*/
    /*DESERIALIZATION OF THE ACTOR USE CASE*/
    /*-------------------------------------*/

    json j;

/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j["id"] = actorUC.getId();
    j["name"] = actorUC.getName();
    j["description"] = actorUC.getDescription();
    j["versionMajor"] = actorUC.getVersionMajor();
    j["versionMinor"] = actorUC.getVersionMinor();
    j["date_init"] = actorUC.getDate().toString();
    j["comments"] = actorUC.getComments();
    j["authors"] = actorUC.getAuthors();
    j["tracesFrom"] = actorUC.getTracesFrom();
    j["tracesTo"] = actorUC.getTracesTo();
    j["changes"] = serializeListOfChanges(actorUC.getChanges());

}

ActorUC Jsoneitor::deserializeActorUC(json j) {

    /*-------------------------------------*/
    /*DESERIALIZATION OF THE ACTOR USE CASE*/
    /*-------------------------------------*/

/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    OID id = j["id"];
    std::string name = j["name"];
    std::string description = j["description"];
    std::string versionMajor = j["versionMajor"];
    std::string versionMinor = j["versionMinor"];
    std::string date_init = j["date_init"];
    Fecha date = Fecha(date_init);
    std::string comments = j["comments"];
    std::set<std::string> authors = j["authors"];
    std::list<OID> tracesFrom = j["tracesFrom"];
    std::list<OID> tracesTo = j["tracesTo"];
    std::list<Change> changes = deserializeListOfChanges(j["changes"]);

    /*------------------------------*/
    /*CREATION OF THE ACTOR USE CASE*/
    /*------------------------------*/
/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    ActorUC a(id);
    a.setName(name);
    a.setDescription(description);
    a.setVersionMajor(versionMajor);
    a.setVersionMinor(versionMinor);
    a.setDate(date);
    a.setComments(comments);
    a.setAuthors(authors);
    a.setTracesFrom(tracesFrom);
    a.setTracesTo(tracesTo);
    a.setChanges(changes);

    return a;
}


void Jsoneitor::visit(RestrictionRequirement restrictionRequirement) {

    /*----------------------------------------------*/
    /*DESERIALIZATION OF THE RESTRICTION REQUIREMENT*/
    /*----------------------------------------------*/

    json j;

/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j["id"] = restrictionRequirement.getId();
    j["name"] = restrictionRequirement.getName();
    j["description"] = restrictionRequirement.getDescription();
    j["versionMajor"] = restrictionRequirement.getVersionMajor();
    j["versionMinor"] = restrictionRequirement.getVersionMinor();
    j["date_init"] = restrictionRequirement.getDate().toString();
    j["comments"] = restrictionRequirement.getComments();
    j["authors"] = restrictionRequirement.getAuthors();
    j["tracesFrom"] = restrictionRequirement.getTracesFrom();
    j["tracesTo"] = restrictionRequirement.getTracesTo();
    j["changes"] = serializeListOfChanges(restrictionRequirement.getChanges());

/*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    j["importanceLevel"] = restrictionRequirement.getImportanceLevel();
    j["urgencyLevel"] = restrictionRequirement.getUrgencyLevel();
    j["phase"] = restrictionRequirement.getPhase();
    j["estability"] = restrictionRequirement.getEstability();

    //No tiene parte de Information Requirement



}

RestrictionRequirement Jsoneitor::deserializeRestrictionRequirement(json j) {

    /*----------------------------------------------*/
    /*DESERIALIZATION OF THE RESTRICTION REQUIREMENT*/
    /*----------------------------------------------*/

/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    OID id = j["id"];
    std::string name = j["name"];
    std::string description = j["description"];
    std::string versionMajor = j["versionMajor"];
    std::string versionMinor = j["versionMinor"];
    std::string date_init = j["date_init"];
    Fecha date = Fecha(date_init);
    std::string comments = j["comments"];
    std::set<std::string> authors = j["authors"];
    std::list<OID> tracesFrom = j["tracesFrom"];
    std::list<OID> tracesTo = j["tracesTo"];
    std::list<Change> changes = deserializeListOfChanges(j["changes"]);

/*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    Priority::Importance importanceLevel = j["importanceLevel"];
    Priority::Importance urgencyLevel = j["urgencyLevel"];
    Priority::Development_phase phase = j["phase"];
    Priority::Estability estability = j["estability"];

    /*---------------------------------------*/
    /*CREATION OF THE RESTRICTION REQUIREMENT*/
    /*---------------------------------------*/
/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    RestrictionRequirement r(id);
    r.setName(name);
    r.setDescription(description);
    r.setVersionMajor(versionMajor);
    r.setVersionMinor(versionMinor);
    r.setDate(date);
    r.setComments(comments);
    r.setAuthors(authors);
    r.setTracesFrom(tracesFrom);
    r.setTracesTo(tracesTo);
    r.setChanges(changes);

/*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    r.setImportanceLevel(importanceLevel);
    r.setUrgencyLevel(urgencyLevel);
    r.setPhase(phase);
    r.setEstability(estability);

    return r;
}

void Jsoneitor::visit(FunctionalRequirement functionalRequirement) {

    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    trackeablePart(&functionalRequirement, j);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    priorityPart(&functionalRequirement, j);

}

FunctionalRequirement Jsoneitor::deserializeFunctionalRequirement(json j) {

        /*----------------------------------------------*/
        /*DESERIALIZATION OF THE FUNCTIONAL REQUIREMENT */
        /*----------------------------------------------*/

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    FunctionalRequirement(j["id"]);
    TrackeableDTO trackeableDTO = trackeablePart(

        OID id = j["id"];
        std::string name = j["name"];
        std::string description = j["description"];
        std::string versionMajor = j["versionMajor"];
        std::string versionMinor = j["versionMinor"];
        std::string date_init = j["date_init"];
        Fecha date = Fecha(date_init);
        std::string comments = j["comments"];
        std::set<std::string> authors = j["authors"];
        std::list<OID> tracesFrom = j["tracesFrom"];
        std::list<OID> tracesTo = j["tracesTo"];
        std::list<Change> changes = deserializeListOfChanges(j["changes"]);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        Priority::Importance importanceLevel = j["importanceLevel"];
        Priority::Importance urgencyLevel = j["urgencyLevel"];
        Priority::Development_phase phase = j["phase"];
        Priority::Estability estability = j["estability"];

        /*---------------------------------------*/
        /*CREATION OF THE FUNCTIONAL REQUIREMENT */
        /*---------------------------------------*/
    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        FunctionalRequirement f(id);
        f.setName(name);
        f.setDescription(description);
        f.setVersionMajor(versionMajor);
        f.setVersionMinor(versionMinor);
        f.setDate(date);
        f.setComments(comments);
        f.setAuthors(authors);
        f.setTracesFrom(tracesFrom);
        f.setTracesTo(tracesTo);
        f.setChanges(changes);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        f.setImportanceLevel(importanceLevel);
        f.setUrgencyLevel(urgencyLevel);
        f.setPhase(phase);
        f.setEstability(estability);

        return f;
}

void Jsoneitor::visit(NonFunctionalRequirement nonFunctionalRequirement) {

        /*--------------------------------------------------*/
        /*DESERIALIZATION OF THE NON FUNCTIONAL REQUIREMENT */
        /*--------------------------------------------------*/

        json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        j["id"] = nonFunctionalRequirement.getId();
        j["name"] = nonFunctionalRequirement.getName();
        j["description"] = nonFunctionalRequirement.getDescription();
        j["versionMajor"] = nonFunctionalRequirement.getVersionMajor();
        j["versionMinor"] = nonFunctionalRequirement.getVersionMinor();
        j["date_init"] = nonFunctionalRequirement.getDate().toString();
        j["comments"] = nonFunctionalRequirement.getComments();
        j["authors"] = nonFunctionalRequirement.getAuthors();
        j["tracesFrom"] = nonFunctionalRequirement.getTracesFrom();
        j["tracesTo"] = nonFunctionalRequirement.getTracesTo();
        j["changes"] = serializeListOfChanges(nonFunctionalRequirement.getChanges());

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        j["importanceLevel"] = nonFunctionalRequirement.getImportanceLevel();
        j["urgencyLevel"] = nonFunctionalRequirement.getUrgencyLevel();
        j["phase"] = nonFunctionalRequirement.getPhase();
        j["estability"] = nonFunctionalRequirement.getEstability();

//no tiene parte de Non Functional Requirement

}

NonFunctionalRequirement Jsoneitor::deserializeNonFunctionalRequirement(json j) {

        /*--------------------------------------------------*/
        /*DESERIALIZATION OF THE NON FUNCTIONAL REQUIREMENT */
        /*--------------------------------------------------*/

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        OID id = j["id"];
        std::string name = j["name"];
        std::string description = j["description"];
        std::string versionMajor = j["versionMajor"];
        std::string versionMinor = j["versionMinor"];
        std::string date_init = j["date_init"];
        Fecha date = Fecha(date_init);
        std::string comments = j["comments"];
        std::set<std::string> authors = j["authors"];
        std::list<OID> tracesFrom = j["tracesFrom"];
        std::list<OID> tracesTo = j["tracesTo"];
        std::list<Change> changes = deserializeListOfChanges(j["changes"]);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        Priority::Importance importanceLevel = j["importanceLevel"];
        Priority::Importance urgencyLevel = j["urgencyLevel"];
        Priority::Development_phase phase = j["phase"];
        Priority::Estability estability = j["estability"];

        /*---------------------------------------*/
        /*CREATION OF THE NON FUNCTIONAL REQUIREMENT */
        /*---------------------------------------*/
    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        NonFunctionalRequirement n(id);
        n.setName(name);
        n.setDescription(description);
        n.setVersionMajor(versionMajor);
        n.setVersionMinor(versionMinor);
        n.setDate(date);
        n.setComments(comments);
        n.setAuthors(authors);
        n.setTracesFrom(tracesFrom);
        n.setTracesTo(tracesTo);
        n.setChanges(changes);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        n.setImportanceLevel(importanceLevel);
        n.setUrgencyLevel(urgencyLevel);
        n.setPhase(phase);
        n.setEstability(estability);

        return n;
}


void Jsoneitor::visit(SystemObjective systemObjective) {

        /*--------------------------------------------------*/
        /*DESERIALIZATION OF THE SYSTEM OBJECTIVE */
        /*--------------------------------------------------*/

        json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        j["id"] = systemObjective.getId();
        j["name"] = systemObjective.getName();
        j["description"] = systemObjective.getDescription();
        j["versionMajor"] = systemObjective.getVersionMajor();
        j["versionMinor"] = systemObjective.getVersionMinor();
        j["date_init"] = systemObjective.getDate().toString();
        j["comments"] = systemObjective.getComments();
        j["authors"] = systemObjective.getAuthors();
        j["tracesFrom"] = systemObjective.getTracesFrom();
        j["tracesTo"] = systemObjective.getTracesTo();
        j["changes"] = serializeListOfChanges(systemObjective.getChanges());

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        j["importanceLevel"] = systemObjective.getImportanceLevel();
        j["urgencyLevel"] = systemObjective.getUrgencyLevel();
        j["phase"] = systemObjective.getPhase();
        j["estability"] = systemObjective.getEstability();

}

SystemObjective Jsoneitor::deserializeSystemObjective(json j) {

        /*--------------------------------------------------*/
        /*DESERIALIZATION OF THE SYSTEM OBJECTIVE */
        /*--------------------------------------------------*/

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        OID id = j["id"];
        std::string name = j["name"];
        std::string description = j["description"];
        std::string versionMajor = j["versionMajor"];
        std::string versionMinor = j["versionMinor"];
        std::string date_init = j["date_init"];
        Fecha date = Fecha(date_init);
        std::string comments = j["comments"];
        std::set<std::string> authors = j["authors"];
        std::list<OID> tracesFrom = j["tracesFrom"];
        std::list<OID> tracesTo = j["tracesTo"];
        std::list<Change> changes = deserializeListOfChanges(j["changes"]);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        Priority::Importance importanceLevel = j["importanceLevel"];
        Priority::Importance urgencyLevel = j["urgencyLevel"];
        Priority::Development_phase phase = j["phase"];
        Priority::Estability estability = j["estability"];

        /*---------------------------------------*/
        /*CREATION OF THE SYSTEM OBJECTIVE */
        /*---------------------------------------*/
    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        SystemObjective s(id);
        s.setName(name);
        s.setDescription(description);
        s.setVersionMajor(versionMajor);
        s.setVersionMinor(versionMinor);
        s.setDate(date);
        s.setComments(comments);
        s.setAuthors(authors);
        s.setTracesFrom(tracesFrom);
        s.setTracesTo(tracesTo);
        s.setChanges(changes);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        s.setImportanceLevel(importanceLevel);
        s.setUrgencyLevel(urgencyLevel);
        s.setPhase(phase);
        s.setEstability(estability);

        return s;
}

void Jsoneitor::visit(UserCase userCase) {

        /*--------------------------------------------------*/
        /*DESERIALIZATION OF THE USER CASE */
        /*--------------------------------------------------*/

        json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        j["id"] = userCase.getId();
        j["name"] = userCase.getName();
        j["description"] = userCase.getDescription();
        j["versionMajor"] = userCase.getVersionMajor();
        j["versionMinor"] = userCase.getVersionMinor();
        j["date_init"] = userCase.getDate().toString();
        j["comments"] = userCase.getComments();
        j["authors"] = userCase.getAuthors();
        j["tracesFrom"] = userCase.getTracesFrom();
        j["tracesTo"] = userCase.getTracesTo();
        j["changes"] = serializeListOfChanges(userCase.getChanges());

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        j["importanceLevel"] = userCase.getImportanceLevel();
        j["urgencyLevel"] = userCase.getUrgencyLevel();
        j["phase"] = userCase.getPhase();
        j["estability"] = userCase.getEstability();

    /*｡o°✥✤✣USER CASE PART✣✤✥°o｡*/
     //    bool abstract;
    //    std::string objective;
    //    std::string precondition;
    //    std::string postcondition;
    //    TimeQuantity frequency;
    //    std::vector<OID> steps;
    //    std::list<OID> actors;
    //    std::list <OID> objectives;

    j["abstract"] = userCase.getAbstract();
    j["precondition"] = userCase.getPrecondition();
    j["postcondition"] = userCase.getPostcondition();
    j["frequency"] = serializeTimeQuantity(userCase.getFrequency());
    j["steps"] = userCase.getSteps();
    j["actors"] = userCase.getActors();
    j["objectives"] = userCase.getObjectives();


}

UserCase Jsoneitor::deserializeUserCase(json j) {

        /*--------------------------------------------------*/
        /*DESERIALIZATION OF THE USER CASE */
        /*--------------------------------------------------*/

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        OID id = j["id"];
        std::string name = j["name"];
        std::string description = j["description"];
        std::string versionMajor = j["versionMajor"];
        std::string versionMinor = j["versionMinor"];
        std::string date_init = j["date_init"];
        Fecha date = Fecha(date_init);
        std::string comments = j["comments"];
        std::set<std::string> authors = j["authors"];
        std::list<OID> tracesFrom = j["tracesFrom"];
        std::list<OID> tracesTo = j["tracesTo"];
        std::list<Change> changes = deserializeListOfChanges(j["changes"]);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        Priority::Importance importanceLevel = j["importanceLevel"];
        Priority::Importance urgencyLevel = j["urgencyLevel"];
        Priority::Development_phase phase = j["phase"];
        Priority::Estability estability = j["estability"];

    /*｡o°✥✤✣USER CASE PART✣✤✥°o｡*/
        bool abstract = j["abstract"];
        std::string precondition = j["precondition"];
        std::string postcondition = j["postcondition"];
        TimeQuantity frequency = deserializeTimeQuantity(j["frequency"]);
        std::vector<OID> steps = j["steps"];
        std::list<OID> actors = j["actors"];
        std::list <OID> objectives = j["objectives"];

        /*---------------------------------------*/
        /*CREATION OF THE USER CASE */
        /*---------------------------------------*/
    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        UserCase u(id);
        u.setName(name);
        u.setDescription(description);
        u.setVersionMajor(versionMajor);
        u.setVersionMinor(versionMinor);
        u.setDate(date);
        u.setComments(comments);
        u.setAuthors(authors);
        u.setTracesFrom(tracesFrom);
        u.setTracesTo(tracesTo);
        u.setChanges(changes);

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        u.setImportanceLevel(importanceLevel);
        u.setUrgencyLevel(urgencyLevel);
        u.setPhase(phase);
        u.setEstability(estability);

    /*｡o°✥✤✣USER CASE PART✣✤✥°o｡*/
        u.setAbstract(abstract);
        u.setPrecondition(precondition);
        u.setPostcondition(postcondition);
        u.setFrequency(frequency);
        u.setSteps(steps);
        u.setActors(actors);
        u.setObjectives(objectives);

        return u;
}

void Jsoneitor::visit(Stakeholder stakeholder) {

    /*-----------------------------------*/
    /*DESERIALIZATION OF THE STAKEHOLDER */
    /*-----------------------------------*/

    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    trackeablePart(&stakeholder,j);

    /*｡o°✥✤✣STAKEHOLDER PART✣✤✥°o｡*/
    j["email"] = stakeholder.getEmail();
    j["phone"] = stakeholder.getPhone();
    j["address"] = stakeholder.getAddress();
    j["stakeholderRole"] = stakeholder.getStakeholderRole();
    j["worksForOrganization"] = stakeholder.getWorksForOrganization();

    FileJsonManager::save(j);
}


Stakeholder Jsoneitor::deserializeStakeholder(json j) {
    //Trackeable part
    OID id = j["id"];
    std::string name = j["name"];
    std::string description = j["description"];
    std::string versionMajor = j["versionMajor"];
    std::string versionMinor = j["versionMinor"];
    std::string date_init = j["date_init"];
    Fecha date = Fecha(date_init);
    std::string comments = j["comments"];
    std::set<std::string> authors = j["authors"];
    std::list<OID> tracesFrom = j["tracesFrom"];
    std::list<OID> tracesTo = j["tracesTo"];
    std::list<Change> changes = deserializeListOfChanges(j["changes"]);

    //Stakeholder part
    std::string email = j["email"];
    std::string phone = j["phone"];
    std::string address = j["address"];
    std::string stakeholderRole = j["stakeholderRole"];
    std::string worksForOrganization = j["worksForOrganization"];


    Stakeholder s (id);
    //set all parameters
    s.setName(name);
    s.setDescription(description);
    s.setVersionMajor(versionMajor);
    s.setVersionMinor(versionMinor);
    s.setDate(date);
    s.setComments(comments);
    s.setAuthors(authors);
    s.setTracesFrom(tracesFrom);
    s.setTracesTo(tracesTo);
    s.setChanges(changes);
    s.setEmail(email);
    s.setPhone(phone);
    s.setAddress(address);
    s.setStakeholderRole(stakeholderRole);
    s.setWorksForOrganization(worksForOrganization);

    return s;}

    void Jsoneitor::visit(Rol_Stakeholder rolStakeholder) {

    /*-----------------------------------*/
    /*DESERIALIZATION OF THE STAKEHOLDER */
    /*-----------------------------------*/

    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j["id"] = rolStakeholder.getId();
    j["name"] = rolStakeholder.getName();
    j["description"] = rolStakeholder.getDescription();
    j["versionMajor"] = rolStakeholder.getVersionMajor();
    j["versionMinor"] = rolStakeholder.getVersionMinor();
    j["date_init"] = rolStakeholder.getDate().toString();
    j["comments"] = rolStakeholder.getComments();
    j["authors"] = rolStakeholder.getAuthors();
    j["tracesFrom"] = rolStakeholder.getTracesFrom();
    j["tracesTo"] = rolStakeholder.getTracesTo();
    j["changes"] = serializeListOfChanges(rolStakeholder.getChanges());
}



