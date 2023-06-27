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



json serializeListOfChanges(const std::list<Change>& listOfChanges) {
    json j;

    // Serializar cada cambio en la lista
    if (listOfChanges.empty()) {
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



void Jsoneitor::visit(InformationRequirement informationRequirement) {

    json j;

/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j["id"] = informationRequirement.getId();
    j["name"] = informationRequirement.getName();
    j["description"] = informationRequirement.getDescription();
    j["versionMajor"] = informationRequirement.getVersionMajor();
    j["versionMinor"] = informationRequirement.getVersionMinor();
    j["date_init"] = informationRequirement.getDate().toString();
    j["comments"] = informationRequirement.getComments();
    j["authors"] = informationRequirement.getAuthors();
    j["tracesFrom"] = informationRequirement.getTracesFrom();
    j["tracesTo"] = informationRequirement.getTracesTo();
    j["changes"] = serializeListOfChanges(informationRequirement.getChanges());

/*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    j["importanceLevel"] = informationRequirement.getImportanceLevel();
    j["urgencyLevel"] = informationRequirement.getUrgencyLevel();
    j["phase"] = informationRequirement.getPhase();
    j["estability"] = informationRequirement.getEstability();

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

/*｡o°✥✤✣INFORMATION REQUIREMENT PART✣✤✥°o｡*/
    unsigned int maxSimultaneousOccurrence = j["maxSimultaneousOccurrence"];
    unsigned int avgSimultaneousOccurrence = j["avgSimultaneousOccurrence"];
    TimeQuantity lifeMaxEstimate = deserializeTimeQuantity(j["lifeMaxEstimate"]);
    TimeQuantity lifeAvgEstimate = deserializeTimeQuantity(j["lifeAvgEstimate"]);

    /*---------------------------------------*/
    /*CREATION OF THE INFORMATION REQUIREMENT*/
    /*---------------------------------------*/
/*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    InformationRequirement i(id);
    i.setName(name);
    i.setDescription(description);
    i.setVersionMajor(versionMajor);
    i.setVersionMinor(versionMinor);
    i.setDate(date);
    i.setComments(comments);
    i.setAuthors(authors);
    i.setTracesFrom(tracesFrom);
    i.setTracesTo(tracesTo);
    i.setChanges(changes);

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

        /*----------------------------------------------*/
        /*DESERIALIZATION OF THE FUNCTIONAL REQUIREMENT */
        /*----------------------------------------------*/

        json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        j["id"] = functionalRequirement.getId();
        j["name"] = functionalRequirement.getName();
        j["description"] = functionalRequirement.getDescription();
        j["versionMajor"] = functionalRequirement.getVersionMajor();
        j["versionMinor"] = functionalRequirement.getVersionMinor();
        j["date_init"] = functionalRequirement.getDate().toString();
        j["comments"] = functionalRequirement.getComments();
        j["authors"] = functionalRequirement.getAuthors();
        j["tracesFrom"] = functionalRequirement.getTracesFrom();
        j["tracesTo"] = functionalRequirement.getTracesTo();
        j["changes"] = serializeListOfChanges(functionalRequirement.getChanges());

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
        j["importanceLevel"] = functionalRequirement.getImportanceLevel();
        j["urgencyLevel"] = functionalRequirement.getUrgencyLevel();
        j["phase"] = functionalRequirement.getPhase();
        j["estability"] = functionalRequirement.getEstability();

    //no tiene parte de Functional Requirement

}

FunctionalRequirement Jsoneitor::deserializeFunctionalRequirement(json j) {

        /*----------------------------------------------*/
        /*DESERIALIZATION OF THE FUNCTIONAL REQUIREMENT */
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
    j["id"] = stakeholder.getId();
    j["name"] = stakeholder.getName();
    j["description"] = stakeholder.getDescription();
    j["versionMajor"] = stakeholder.getVersionMajor();
    j["versionMinor"] = stakeholder.getVersionMinor();
    j["date_init"] = stakeholder.getDate().toString();
    j["comments"] = stakeholder.getComments();
    j["authors"] = stakeholder.getAuthors();
    j["tracesFrom"] = stakeholder.getTracesFrom();
    j["tracesTo"] = stakeholder.getTracesTo();
    j["changes"] = serializeListOfChanges(stakeholder.getChanges());

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



