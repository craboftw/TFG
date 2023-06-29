//
// Created by Fran- on 24/06/2023.
//

#include <fstream>
#include "Jsoneitor.h"
#include "Dominio/InformationRequirement.h"
#include "Dominio/Generic.h"
#include "Dominio/Trackeable/Stakeholder.h"

using json = nlohmann::json;

class InformationRequirement;
class ActorUC;
class SystemObjective;
class RestrictionRequirement;
class FunctionalRequirement;
class NonFunctionalRequirement;
class Stakeholder;



struct TrackeableDTO{
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

struct PriorityDTO{
    Priority::Importance urgencyLevel;
    Priority::Importance importanceLevel;
    Priority::Estability estibility;
    Priority::Development_phase phase;
};


json serializeOID(OID oid) {
    json j;
    j ["prefix"] = oid.getPrefix();
    j ["id"] = oid.getId();
    return j;
}

OID deserializeOID(const json& j) {
    OID oid(j["prefix"], j["id"]);
    return oid;
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


//Deserializar la lista de autores
std::set<OID> deserializeSetOfOID(const json& j) {
    std::set<OID> listOfOID;

    // Deserializar cada autor en la lista
    for (auto authorJson : j) {
        OID author = deserializeOID(authorJson);
        listOfOID.insert(author);
    }
    return listOfOID;
}

json serializeSetOfOID(const std::set<OID>& setOfOID) {
    json j;

    // Serializar cada autor en la lista
    for (const OID& author : setOfOID) {
        json authorJson = serializeOID(author);
        j.push_back(authorJson);
    }
    return j;
}

std::vector<OID> deserializeVectorOfOID(const json& j) {
    std::vector<OID> listOfOID;

    // Deserializar cada autor en la lista
    for (auto authorJson : j) {
        OID author = deserializeOID(authorJson);
        listOfOID.push_back(author);
    }
    return listOfOID;
}

json serializeVectorOfOID(const std::vector<OID>& vectorOfOID) {
    json j;

    // Serializar cada autor en la lista
    for (const OID& author : vectorOfOID) {
        json authorJson = serializeOID(author);
        j.push_back(authorJson);
    }
    return j;
}

//Deserializar la lista de OID
std::list<OID> deserializeListOfOID(const json& j) {
    std::list<OID> listOfOID;

    // Deserializar cada OID en la lista
    for (auto oidJson : j) {
        OID oid = deserializeOID(oidJson);
        listOfOID.push_back(oid);
    }
    return listOfOID;
}

//Serializar la lista de OID
json serializeListOfOID(const std::list<OID>& listOfOID) {
    json j;

    // Serializar cada OID en la lista
    for (const OID& oid : listOfOID) {
        json oidJson = serializeOID(oid);
        j.push_back(oidJson);
    }
    return j;
}


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




json serializeVectorOfSteps(const std::vector<Step>& vectorOfSteps) {
    json j = std::list<int>();
    int i = 0;
    for (const Step& step : vectorOfSteps) {
        json stepJson;
        stepJson["abstract"] = step.getAbstract();
        stepJson["description"] = step.getDescription();
        stepJson["condition"] = step.getCondition();
        stepJson["comments"] = step.getComments();
        stepJson["stepType"] = step.getType();
        stepJson["reference"] = serializeOID(step.getReference());
        j.push_back(stepJson);
    }
    return j;
}

std::vector<Step> deserializeVectorOfSteps(json reference) {
    std::vector<Step> vectorOfSteps;
    for (auto stepJson : reference) {
        Step step;
        step.setAbstract(stepJson["abstract"]);
        step.setDescription(stepJson["description"]);
        step.setCondition(stepJson["condition"]);
        step.setComments(stepJson["comments"]);
        step.setType(stepJson["stepType"]);
        step.setReference(deserializeOID(stepJson["reference"]));
        vectorOfSteps.push_back(step);
    }
    return vectorOfSteps;
}

json trackeablePart(Trackeable* objeto,json& j)
{
    j["id"] = serializeOID(objeto->getId());
    j["name"] = objeto->getName();
    j["description"] = objeto->getDescription();
    j["versionMajor"] = objeto->getVersionMajor();
    j["versionMinor"] = objeto->getVersionMinor();
    j["date_init"] = objeto->getDate().toString();
    j["comments"] = objeto->getComments();
    j["authors"] = serializeSetOfOID(objeto->getAuthors());
    j["tracesFrom"] = serializeListOfOID(objeto->getTracesFrom());
    j["tracesTo"] = serializeListOfOID(objeto->getTracesTo());
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



TrackeableDTO deserializeTrackeableDTO(const json& j) {
    TrackeableDTO trackeableDTO;
    trackeableDTO.id = deserializeOID(j["id"]);
    trackeableDTO.name = j["name"];
    trackeableDTO.description = j["description"];
    trackeableDTO.versionMajor = j["versionMajor"];
    trackeableDTO.versionMinor = j["versionMinor"];
    trackeableDTO.date = Fecha(j["date_init"]);
    trackeableDTO.comments = j["comments"];
    trackeableDTO.authors = deserializeSetOfOID(j["authors"]);
    trackeableDTO.tracesFrom = deserializeListOfOID(j["tracesFrom"]);
    trackeableDTO.tracesTo = deserializeListOfOID(j["tracesTo"]);
    trackeableDTO.listOfChanges = deserializeListOfChanges(j["changes"]);
    return trackeableDTO;
}

PriorityDTO deserializePriorityDTO(const json& j) {
    PriorityDTO priorityDTO;
    priorityDTO.importanceLevel = j["importanceLevel"];
    priorityDTO.urgencyLevel = j["urgencyLevel"];
    priorityDTO.phase = j["phase"];
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

void setPriorityPart(PriorityDTO priorityDTO, Priority* priority) {
    priority->setImportanceLevel(priorityDTO.importanceLevel);
    priority->setUrgencyLevel(priorityDTO.urgencyLevel);
    priority->setPhase(priorityDTO.phase);
    priority->setEstability(priorityDTO.estibility);
}


void Jsoneitor::visit(InformationRequirement informationRequirement) {

    json j;

/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j = trackeablePart(&informationRequirement,j);
    j = priorityPart(&informationRequirement,j);

/*｡o°✥✤✣INFORMATION REQUIREMENT GET✣✤✥°o｡*/
    j["maxSimultaneousOccurrence"] = informationRequirement.getMaxSimultaneousOccurrence();
    j["avgSimultaneousOccurrence"] = informationRequirement.getAvgSimultaneousOccurrence();
    j["lifeMaxEstimate"] = serializeTimeQuantity(informationRequirement.getLifeMaxEstimate());
    j["lifeAvgEstimate"] = serializeTimeQuantity(informationRequirement.getLifeAvgEstimate());

    FileJsonManager::save(j);
}

InformationRequirement Jsoneitor::deserializeInformationRequirement(json j) {

/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

/*｡o°✥✤✣INFORMATION REQUIREMENT GET✣✤✥°o｡*/
    unsigned int maxSimultaneousOccurrence = j["maxSimultaneousOccurrence"];
    unsigned int avgSimultaneousOccurrence = j["avgSimultaneousOccurrence"];
    TimeQuantity lifeMaxEstimate = deserializeTimeQuantity(j["lifeMaxEstimate"]);
    TimeQuantity lifeAvgEstimate = deserializeTimeQuantity(j["lifeAvgEstimate"]);

/*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    InformationRequirement o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);


/*｡o°✥✤✣INFORMATION REQUIREMENT SET✣✤✥°o｡*/
    o.setMaxSimultaneousOccurrence(maxSimultaneousOccurrence);
    o.setAvgSimultaneousOccurrence(avgSimultaneousOccurrence);
    o.setLifeMaxEstimate(lifeMaxEstimate);
    o.setLifeAvgEstimate(lifeAvgEstimate);

    return o;
}



void Jsoneitor::visit(ActorUC actorUC) {
    json j;
/*｡o°✥✤✣TRACKEABLE GET✣✤✥°o｡*/
    j = trackeablePart(&actorUC,j);
    j ["package"] = actorUC.getPackage();

    FileJsonManager::save(j);
}

ActorUC Jsoneitor::deserializeActorUC(json j) {
/*｡o°✥✤✣TRACKEABLE GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    std::string package = j["package"];
/*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    ActorUC o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    o.setPackage(package);
    return o;
}


void Jsoneitor::visit(RestrictionRequirement restrictionRequirement) {
    json j;
/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j = trackeablePart(&restrictionRequirement,j);
    j = priorityPart(&restrictionRequirement,j);

    FileJsonManager::save(j);

}

RestrictionRequirement Jsoneitor::deserializeRestrictionRequirement(json j) {

/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

/*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    RestrictionRequirement o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);

    return o;
}

void Jsoneitor::visit(FunctionalRequirement functionalRequirement) {
    json j;

/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j= trackeablePart(&functionalRequirement, j);
    j= priorityPart(&functionalRequirement, j);

    FileJsonManager::save(j);
}

FunctionalRequirement Jsoneitor::deserializeFunctionalRequirement(json j) {

    /*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

    /*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    FunctionalRequirement o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);

    return o;
}

void Jsoneitor::visit(NonFunctionalRequirement nonFunctionalRequirement) {

        json j;
/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
        j= trackeablePart(&nonFunctionalRequirement, j);
        j= priorityPart(&nonFunctionalRequirement, j);

        FileJsonManager::save(j);
}

NonFunctionalRequirement Jsoneitor::deserializeNonFunctionalRequirement(json j) {

    /*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

    /*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    NonFunctionalRequirement o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);

    return o;
}


void Jsoneitor::visit(SystemObjective systemObjective) {

    json j;
/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j= trackeablePart(&systemObjective, j);
    j= priorityPart(&systemObjective, j);

    FileJsonManager::save(j);
}

SystemObjective Jsoneitor::deserializeSystemObjective(json j) {

    /*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

    /*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    SystemObjective o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);
    return o;
}

void Jsoneitor::visit(UserCase userCase) {

    json j;
/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j= trackeablePart(&userCase, j);
    j= priorityPart(&userCase, j);

/*｡o°✥✤✣USER CASE PART✣✤✥°o｡*/
    j["abstract"] = userCase.getAbstract();
    j["precondition"] = userCase.getPrecondition();
    j["postcondition"] = userCase.getPostcondition();
    j["frequency"] = serializeTimeQuantity(userCase.getFrequency());
    j["steps"] = serializeVectorOfSteps(userCase.getSteps());
    j["actors"] = serializeListOfOID(userCase.getActors());
    j["objectives"] = serializeListOfOID(userCase.getObjectives());
    j["package"] = userCase.getPackage();
    j["generalization"] = userCase.getGeneralization();

    FileJsonManager::save(j);

}

UserCase Jsoneitor::deserializeUserCase(json j) {

    /*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

    /*｡o°✥✤✣USER CASE GET✣✤✥°o｡*/
        bool abstract = j["abstract"];
        std::string precondition = j["precondition"];
        std::string postcondition = j["postcondition"];
        TimeQuantity frequency = deserializeTimeQuantity(j["frequency"]);
        std::vector<Step> steps = deserializeVectorOfSteps(j["steps"]);
        std::list<OID> actors = deserializeListOfOID(j["actors"]);
        std::list <OID> objectives = deserializeListOfOID(j["objectives"]);
        std::string package = j["package"];
        OID generalization = deserializeOID(j["generalization"]);


    /*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
        UserCase u(trackeableDTO.id.getId());
        setTrackeablePart(trackeableDTO, &u);
        setPriorityPart(priorityDTO, &u);

    /*｡o°✥✤✣USER CASE SET✣✤✥°o｡*/
        u.setAbstract(abstract);
        u.setPrecondition(precondition);
        u.setPostcondition(postcondition);
        u.setFrequency(frequency);
        u.setSteps(steps);
        u.setActors(actors);
        u.setObjectives(objectives);
        u.setPackage(package);

        return u;
}

void Jsoneitor::visit(Stakeholder stakeholder) {

    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(&stakeholder,j);

    /*｡o°✥✤✣STAKEHOLDER PART✣✤✥°o｡*/
    j["email"] = stakeholder.getEmail();
    j["phone"] = stakeholder.getPhone();
    j["address"] = stakeholder.getAddress();
    j["stakeholderRole"] = serializeOID(stakeholder.getStakeholderRole());
    j["worksForOrganization"] = serializeOID(stakeholder.getWorksForOrganization());

    FileJsonManager::save(j);
}


Stakeholder Jsoneitor::deserializeStakeholder(json j) {

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    /*｡o°✥✤✣STAKEHOLDER GET✣✤✥°o｡*/
    std::string email = j["email"];
    std::string phone = j["phone"];
    std::string address = j["address"];
    OID stakeholderRole = deserializeOID(j["stakeholderRole"]);
    OID worksForOrganization = deserializeOID(j["worksForOrganization"]);

    /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    Stakeholder s(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &s);

    /*｡o°✥✤✣STAKEHOLDER SET✣✤✥°o｡*/
    s.setEmail(email);
    s.setPhone(phone);
    s.setAddress(address);
    s.setStakeholderRole(stakeholderRole);
    s.setWorksForOrganization(worksForOrganization);

    return s;
}

    void Jsoneitor::visit(Rol_Stakeholder rolStakeholder) {
    json j;

    /*｡o°✥✤✣TRACKEABLE GET✣✤✥°o｡*/
    j= trackeablePart(&rolStakeholder,j);


        FileJsonManager::save(j);

    }

    Rol_Stakeholder Jsoneitor::deserializeRolStakeholder(json j) {
        /*｡o°✥✤✣TRACKEABLE  GET✣✤✥°o｡*/
        TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

        /*｡o°✥✤✣TRACKEABLE  SET✣✤✥°o｡*/
        Rol_Stakeholder o(trackeableDTO.id.getId());
        setTrackeablePart(trackeableDTO, &o);

        return o;

}

void Jsoneitor::visit(Organization organization) {

        json j;

        /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        j= trackeablePart(&organization,j);
        /*｡o°✥✤✣ORGANIZATION PART✣✤✥°o｡*/
        j["contactInfo"] = organization.getContactInfo();
        FileJsonManager::save(j);

}

Organization Jsoneitor::deserializeOrganization(json j) {

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    /*｡o°✥✤✣ORGANIZATION GET✣✤✥°o｡*/
    std::string contactInfo = j["contactInfo"];

    /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    Organization o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);

    /*｡o°✥✤✣ORGANIZATION SET✣✤✥°o｡*/
    o.setContactInfo(contactInfo);

    return o;
}



