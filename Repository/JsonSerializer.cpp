//
// Created by Fran- on 24/06/2023.
//

#include <fstream>
#include "JsonSerializer.h"
#include "Dominio/InformationRequirement.h"
#include "Dominio/Generic.h"
#include "Dominio/Trackeable/Stakeholder.h"
#include "Dominio/Trackeable/MatrixTraces.h"
#include "Dominio/UserCaseDiagram.h"
#include "OID.h"

using json = nlohmann::json;

class ActorUC;
class SystemObjective;
class RestrictionRequirement;
class FunctionalRequirement;
class NonFunctionalRequirement;
class Stakeholder;






json JsonSerializer::serializeOID(OID oid) {
    json j;
    j ["prefix"] = oid.getPrefix();
    j ["id"] = oid.getId();
    return j;
}

OID JsonSerializer::deserializeOID(json j) {
    OID oid(j["prefix"], j["id"]);
    return oid;
}


//Deserializar la lista de cambios
std::list<Change> deserializeListOfChanges(const json& j) {
    std::list<Change> listOfChanges;

    // Deserializar cada cambio en la lista
    for (const json& cambioJson : j) {
        Change cambio(cambioJson["id"]);
        cambio.setVersion(cambioJson["version"]);
        std::string date = cambioJson["date"];
        cambio.setDate(Fecha(date));
        cambio.setComments(cambioJson["comments"]);
        listOfChanges.push_back(cambio);
    }
    return listOfChanges;
}


//Deserializar la lista de autores
std::set<OID> JsonSerializer::deserializeSetOfOID(const json& j) {
    std::set<OID> listOfOID;

    // Deserializar cada autor en la lista
    for (json authorJson : j) {
        OID author = deserializeOID(authorJson);
        listOfOID.insert(author);
    }
    return listOfOID;
}


json JsonSerializer::serializeSetOfOID(const std::set<OID> setOfOID) {
    json j;

    // Serializar cada autor en la lista
    for (const OID& author : setOfOID) {
        json authorJson = serializeOID(author);
        j.push_back(authorJson);
    }
    return j;
}

std::vector<OID> JsonSerializer::deserializeVectorOfOID(const json& j) {
    std::vector<OID> listOfOID;

    // Deserializar cada autor en la lista
    for (json authorJson : j) {
        OID author = deserializeOID(authorJson);
        listOfOID.push_back(author);
    }
    return listOfOID;
}

json JsonSerializer::serializeVectorOfOID(const std::vector<OID>& vectorOfOID) {
    json j;

    // Serializar cada autor en la lista
    for (const OID& author : vectorOfOID) {
        json authorJson = serializeOID(author);
        j.push_back(authorJson);
    }
    return j;
}

//Deserializar la lista de OID
std::list<OID> JsonSerializer::deserializeListOfOID(const json& j) {
    std::list<OID> listOfOID;

    // Deserializar cada OID en la lista
    for (auto oidJson : j) {
        OID oid = deserializeOID(oidJson);
        listOfOID.push_back(oid);
    }
    return listOfOID;
}

//Serializar la lista de OID
json JsonSerializer::serializeListOfOID(const std::list<OID>& listOfOID) {
    json j;

    // Serializar cada OID en la lista
    for (const OID& oid : listOfOID) {
        json oidJson = serializeOID(oid);
        j.push_back(oidJson);
    }
    return j;
}

json JsonSerializer::serializeVectorOfExceptions(std::vector<Exception> vectorOfExceptions) {
    json j;

    // Serializar cada excepcion en la lista
    for (const Exception& exception : vectorOfExceptions) {
        json exceptionJson;

        exceptionJson["step"] = exception.step;
        exceptionJson["stepType"] = exception.stepType;
        exceptionJson["description"] = exception.description;
        exceptionJson["condition"] = exception.condition;
        exceptionJson["comments"] = exception.comments;
        exceptionJson["reference"] = serializeOID(exception.reference);
        j.push_back(exceptionJson);
    }
    return j;
}

std::vector<Exception> JsonSerializer::deserializeVectorOfExceptions(const json& j) {
    std::vector<Exception> listOfExceptions;

    // Deserializar cada excepcion en la lista
    for (const json& exceptionJson : j) {
        Exception exception;
        exception.step = exceptionJson["step"];
        exception.stepType = exceptionJson["stepType"];
        exception.description = exceptionJson["description"];
        exception.condition = exceptionJson["condition"];
        exception.comments = exceptionJson["comments"];
        exception.reference = deserializeOID(exceptionJson["reference"]);
        listOfExceptions.push_back(exception);
    }
    return listOfExceptions;
}


json JsonSerializer::serializeListOfChanges(const std::list<Change>& listOfChanges) {
    json j;

    // Serializar cada cambio en la lista
    if (listOfChanges.empty()) {
        j = std::list<int>();
    }
    for (const Change& cambio : listOfChanges) {
        json cambioJson;
        cambioJson["id"] = cambio.getId();
        cambioJson["version"] = cambio.getVersion();
        cambioJson["date"] = cambio.getDate().toString();
        cambioJson["comments"] = cambio.getComments();
        j.push_back(cambioJson);
    }
    return j;
}




json JsonSerializer::serializeVectorOfSteps(const std::vector<Step>& vectorOfSteps) {
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

std::vector<Step> JsonSerializer::deserializeVectorOfSteps(json reference) {
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


std::list<SpecificInformation> JsonSerializer::deserializeListOfSpecificInformation(json j) {
    std::list<SpecificInformation> listOfSpecificInformation;
    for (auto specificInformationJson : j) {
        SpecificInformation o{specificInformationJson["id"],specificInformationJson["name"],specificInformationJson["description"]};
        listOfSpecificInformation.push_back(o);
    }
    return listOfSpecificInformation;

}
json JsonSerializer::serializeListOfSpecificInformation(std::list<SpecificInformation> lista)
{
    json j;
    for (auto specificInformation : lista) {
        json specificInformationJson;
        specificInformationJson["id"] = specificInformation.id;
        specificInformationJson["name"] = specificInformation.name;
        specificInformationJson["description"] = specificInformation.description;
        j.push_back(specificInformationJson);
    }
    return j;
}

json JsonSerializer::trackeablePart(Trackeable* objeto, json& j)
{
    j["id"] = serializeOID(objeto->getId());
    j["name"] = objeto->getName();
    j["description"] = objeto->getDescription();
    j["versionMajor"] = objeto->getVersionMajor();
    j["versionMinor"] = objeto->getVersionMinor();
    j["date_init"] = objeto->getDate().toString();
    j["comments"] = objeto->getComments();
    j["authors"] = serializeSetOfOID(objeto->getAuthors());
    j["tracesFrom"] = serializeSetOfOID(objeto->getTracesFrom());
    j["tracesTo"] = serializeSetOfOID(objeto->getTracesTo());
    j["changes"] = serializeListOfChanges(objeto->getChanges());

    return j;
}



json JsonSerializer::priorityPart(Priority* objeto, json& j)
{
    j["importanceLevel"] = objeto->getImportanceLevel();
    j["urgencyLevel"] = objeto->getUrgencyLevel();
    j["phase"] = objeto->getPhase();
    j["estability"] = objeto->getEstability();

    return j;
}



TrackeableDTO JsonSerializer::deserializeTrackeableDTO(const json& j) {
    TrackeableDTO trackeableDTO;
    trackeableDTO.id = deserializeOID(j["id"]);
    trackeableDTO.name = j["name"];
    trackeableDTO.description = j["description"];
    trackeableDTO.versionMajor = j["versionMajor"];
    trackeableDTO.versionMinor = j["versionMinor"];
    trackeableDTO.date_init = Fecha(j["date_init"]);
    trackeableDTO.comments = j["comments"];
    trackeableDTO.authors = deserializeSetOfOID(j["authors"]);
    trackeableDTO.tracesFrom = deserializeSetOfOID(j["tracesFrom"]);
    trackeableDTO.tracesTo = deserializeSetOfOID(j["tracesTo"]);
    trackeableDTO.changes = deserializeListOfChanges(j["changes"]);
    return trackeableDTO;
}

PriorityDTO JsonSerializer::deserializePriorityDTO(const json& j) {
    PriorityDTO priorityDTO;
    priorityDTO.importanceLevel = j["importanceLevel"];
    priorityDTO.urgencyLevel = j["urgencyLevel"];
    priorityDTO.phase = j["phase"];
    priorityDTO.estability = j["estability"];
    return priorityDTO;
}

json JsonSerializer::serializeTimeQuantity(const TimeQuantity& timeQuantity) {
    json j;
    j["quantity"] = timeQuantity.getQuantity();
    j["unit"] = timeQuantity.getUnit();
    return j;
}

TimeQuantity JsonSerializer::deserializeTimeQuantity(const json& j) {
    TimeQuantity timeQuantity;
    timeQuantity.setQuantity(j["quantity"]);
    timeQuantity.setUnit(j["unit"]);
    return timeQuantity;
}

void JsonSerializer::setTrackeablePart(TrackeableDTO trackeableDTO, Trackeable* trackeable) {
    trackeable->setName(trackeableDTO.name);
    trackeable->setDescription(trackeableDTO.description);
    trackeable->setVersionMajor(trackeableDTO.versionMajor);
    trackeable->setVersionMinor(trackeableDTO.versionMinor);
    trackeable->setDate(trackeableDTO.date_init);
    trackeable->setComments(trackeableDTO.comments);
    trackeable->setAuthors(trackeableDTO.authors);
    trackeable->setTracesFrom(trackeableDTO.tracesFrom);
    trackeable->setTracesTo(trackeableDTO.tracesTo);
    trackeable->setChanges(trackeableDTO.changes);
}

void JsonSerializer::setPriorityPart(PriorityDTO priorityDTO, Priority* priority) {
    priority->setImportanceLevel(priorityDTO.importanceLevel);
    priority->setUrgencyLevel(priorityDTO.urgencyLevel);
    priority->setPhase(priorityDTO.phase);
    priority->setEstability(priorityDTO.estability);
}


void JsonSerializer::visit(InformationRequirement informationRequirement) {

    json j;

/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j = trackeablePart(&informationRequirement,j);
    j = priorityPart(&informationRequirement,j);

/*｡o°✥✤✣INFORMATION REQUIREMENT GET✣✤✥°o｡*/
    j["maxSimultaneousOccurrence"] = informationRequirement.getMaxSimultaneousOccurrence();
    j["avgSimultaneousOccurrence"] = informationRequirement.getAvgSimultaneousOccurrence();
    j["lifeMaxEstimate"] = serializeTimeQuantity(informationRequirement.getLifeMaxEstimate());
    j["lifeAvgEstimate"] = serializeTimeQuantity(informationRequirement.getLifeAvgEstimate());
    j["specificInformation"] = serializeListOfSpecificInformation(informationRequirement.getSpecificInformation());

    JsonRepository::save(j);
}
json JsonSerializer::serializeElementosIndex(ElementosIndex obj)
{
    json j;
    j["id"] = obj.id;
    j["titulo"] = obj.titulo;
    j["elementos"] = serializeVectorOfOID(obj.elementos);

    return j;
}

ElementosIndex JsonSerializer::deserializeElementosIndex(const json& j)
{
    ElementosIndex obj;
    obj.id = j["id"];
    obj.titulo = j["titulo"];
    obj.elementos = deserializeVectorOfOID(j["elementos"]);

    return obj;
}

json JsonSerializer::serializeGeneralTree(const Agen<ElementosIndex>::nodo n)
{
    Agen<ElementosIndex> A;
    json j;
    if (n != Agen<ElementosIndex>::NODO_NULO)
    {
        j["content"] = serializeElementosIndex(A.elemento(n));
        if (A.hijoIzqdo(n) != Agen<ElementosIndex>::NODO_NULO) {
            Agen<ElementosIndex>::nodo child = A.hijoIzqdo(n);
            while (child != Agen<ElementosIndex>::NODO_NULO) {
                j["childrens"].push_back(serializeGeneralTree(child));
                child = A.hermDrcho(child);
            }
        }
    }
    return j;
}

void JsonSerializer::deserializeChildren(Agen<ElementosIndex>::nodo parent, const json& children)
{
    Agen<ElementosIndex> A;
    Agen<ElementosIndex>::nodo child = Agen<ElementosIndex>::NODO_NULO;
    for (const json& childJson : children) {
        ElementosIndex element = deserializeElementosIndex(childJson["content"]);
        if (child == Agen<ElementosIndex>::NODO_NULO) {
            A.insertarHijoIzqdo(parent, element);
            child = A.hijoIzqdo(parent);
            if (childJson.contains("childrens") && childJson["childrens"].is_array())
            deserializeChildren(child, childJson["childrens"]);
        } else {
            A.insertarHermDrcho(child, element);
            child = A.hijoIzqdo(parent);
            if (childJson.contains("childrens") && childJson["childrens"].is_array())
            deserializeChildren(child, childJson["childrens"]);
        }
    }
}

Agen<ElementosIndex> JsonSerializer::deserializeGeneralTree(const json& j)
{
    Agen<ElementosIndex> A;
    A.insertarRaiz(deserializeElementosIndex(j["content"]));
    if (j.contains("childrens") && j["childrens"].is_array()) {
        const json& children = j["childrens"];
        if (!children.empty()) {
            Agen<ElementosIndex>::nodo root = A.raiz();
            deserializeChildren(root, children);
        }
    }
    return A;
}




void JsonSerializer::visit(Index index) {

    json j;
    j = trackeablePart(&index,j);
    j["tree"] = serializeGeneralTree(index.getIndexTree().raiz());
    j["lastID"] = index.getLastID();
    JsonRepository::save(j);
}

Index JsonSerializer::deserializeIndex(json j) {

        Index index(deserializeGeneralTree(j["tree"]),deserializeOID(j["id"]).getId());
        index.setLastID(j["lastID"]);
        setTrackeablePart(deserializeTrackeableDTO(j), &index);
        return index;
}






InformationRequirement JsonSerializer::deserializeInformationRequirement(json j) {

/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

/*｡o°✥✤✣INFORMATION REQUIREMENT GET✣✤✥°o｡*/
    unsigned int maxSimultaneousOccurrence = j["maxSimultaneousOccurrence"];
    unsigned int avgSimultaneousOccurrence = j["avgSimultaneousOccurrence"];
    TimeQuantity lifeMaxEstimate = deserializeTimeQuantity(j["lifeMaxEstimate"]);
    TimeQuantity lifeAvgEstimate = deserializeTimeQuantity(j["lifeAvgEstimate"]);
    std::list<SpecificInformation> specificInformation = deserializeListOfSpecificInformation(j["specificInformation"]);

/*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    InformationRequirement o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);


/*｡o°✥✤✣INFORMATION REQUIREMENT SET✣✤✥°o｡*/
    o.setMaxSimultaneousOccurrence(maxSimultaneousOccurrence);
    o.setAvgSimultaneousOccurrence(avgSimultaneousOccurrence);
    o.setLifeMaxEstimate(lifeMaxEstimate);
    o.setLifeAvgEstimate(lifeAvgEstimate);
    o.setSpecificInformation(specificInformation);

    return o;
}



void JsonSerializer::visit(ActorUC actorUC) {
    json j;
/*｡o°✥✤✣TRACKEABLE GET✣✤✥°o｡*/
    j = trackeablePart(&actorUC,j);
    j ["package"] = actorUC.getPackage();
    j ["generalization"] = serializeOID(actorUC.getGeneralization());

    JsonRepository::save(j);
}

ActorUC JsonSerializer::deserializeActorUC(json j) {
/*｡o°✥✤✣TRACKEABLE GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    std::string package = j["package"];
    OID generalization = deserializeOID(j["generalization"]);
/*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    ActorUC o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    o.setPackage(package);
    o.setGeneralization(generalization);
    return o;
}


void JsonSerializer::visit(RestrictionRequirement restrictionRequirement) {
    json j;
/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j = trackeablePart(&restrictionRequirement,j);
    j = priorityPart(&restrictionRequirement,j);

    JsonRepository::save(j);

}

RestrictionRequirement JsonSerializer::deserializeRestrictionRequirement(json j) {

/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

/*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    RestrictionRequirement o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);

    return o;
}

void JsonSerializer::visit(FunctionalRequirement functionalRequirement) {
    json j;

/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j= trackeablePart(&functionalRequirement, j);
    j= priorityPart(&functionalRequirement, j);

    JsonRepository::save(j);
}

FunctionalRequirement JsonSerializer::deserializeFunctionalRequirement(json j) {

    /*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

    /*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    FunctionalRequirement o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);

    return o;
}

void JsonSerializer::visit(NonFunctionalRequirement nonFunctionalRequirement) {

        json j;
/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
        j= trackeablePart(&nonFunctionalRequirement, j);
        j= priorityPart(&nonFunctionalRequirement, j);

        JsonRepository::save(j);
}

NonFunctionalRequirement JsonSerializer::deserializeNonFunctionalRequirement(json j) {

    /*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

    /*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    NonFunctionalRequirement o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);

    return o;
}


void JsonSerializer::visit(SystemObjective systemObjective) {

    json j;
/*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    j= trackeablePart(&systemObjective, j);
    j= priorityPart(&systemObjective, j);

    JsonRepository::save(j);
}

SystemObjective JsonSerializer::deserializeSystemObjective(json j) {

    /*｡o°✥✤✣TRACKEABLE PRIORITY GET✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    PriorityDTO priorityDTO = deserializePriorityDTO(j);

    /*｡o°✥✤✣TRACKEABLE PRIORITY SET✣✤✥°o｡*/
    SystemObjective o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);
    setPriorityPart(priorityDTO, &o);
    return o;
}

void JsonSerializer::visit(UserCase& userCase) {

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
    j["generalization"] = serializeOID(userCase.getGeneralization());
    j["exceptions"] = serializeVectorOfExceptions(userCase.getExceptions());

    JsonRepository::save(j);

}

UserCase JsonSerializer::deserializeUserCase(json j) {

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
        std::vector<Exception> exceptions = deserializeVectorOfExceptions(j["exceptions"]);
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
        u.setGeneralization(generalization);
        u.setExceptions(exceptions);

        return u;
}

void JsonSerializer::visit(Organization organization) {

    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(&organization, j);

    /*｡o°✥✤✣ORGANIZATION PART✣✤✥°o｡*/
    j["contactInfo"] = organization.getContactInfo();

    JsonRepository::save(j);

}

Organization JsonSerializer::deserializeOrganization(json j) {

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    /*｡o°✥✤✣ORGANIZATION PART✣✤✥°o｡*/
    std::string contactInfo = j["contactInfo"];

    /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    Organization o(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &o);

    /*｡o°✥✤✣ORGANIZATION SET✣✤✥°o｡*/
    o.setContactInfo(contactInfo);

    return o;
}

void JsonSerializer::visit(Stakeholder stakeholder) {

    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(&stakeholder,j);

    /*｡o°✥✤✣STAKEHOLDER PART✣✤✥°o｡*/
    j["email"] = stakeholder.getEmail();
    j["phone"] = stakeholder.getPhone();
    j["address"] = stakeholder.getAddress();
    j["stakeholderRole"] = stakeholder.getStakeholderRole();
    j["worksForOrganization"] = serializeOID(stakeholder.getWorksForOrganization());

    JsonRepository::save(j);
}

Stakeholder JsonSerializer::deserializeStakeholder(json j) {

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    /*｡o°✥✤✣STAKEHOLDER GET✣✤✥°o｡*/
    std::string email = j["email"];
    std::string phone = j["phone"];
    std::string address = j["address"];
    std::string stakeholderRole = j["stakeholderRole"];
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

Trackeable* JsonSerializer::deserializeTrackeable(json j) {

    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);
    Trackeable* t = new Trackeable(trackeableDTO.id.getPrefix(), trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, t);
    return t;
}

Priority* JsonSerializer::deserializePriority(json j) {

    PriorityDTO priorityDTO = deserializePriorityDTO(j);
    Priority* p = new Priority();
    setPriorityPart(priorityDTO, p);
    return p;
}




void JsonSerializer::visit(Trackeable *trackeable) {

    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(trackeable,j);

    JsonRepository::save(j);
}

void JsonSerializer::visit(Priority* priority)
{
    json j;

    /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
    j= priorityPart(priority,j);
    j["id"] = serializeOID(priority->getId());

    JsonRepository::save(j);
}

void JsonSerializer::visit(Text text) {

        json j;

        /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        j= trackeablePart(&text,j);

        JsonRepository::save(j);
}

Text JsonSerializer::deserializeText(json j) {

        /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

        /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
        Text t(trackeableDTO.id.getId());
        setTrackeablePart(trackeableDTO, &t);

        return t;
}

void JsonSerializer::visit(MatrixTraces matrixTraces) {

        json j;

        /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        j= trackeablePart(&matrixTraces,j);

        /*｡o°✥✤✣MATRIX TRACES PART✣✤✥°o｡*/
        j["prefixesTracesTo"] = matrixTraces.getPrefixesTracesTo();
        j["prefixesTracesFrom"] = matrixTraces.getPrefixesTracesFrom();
        j["TrackeableTo"] = serializeSetOfOID(matrixTraces.getTrackeablesTo());
        j["TrackeableFrom"] = serializeSetOfOID(matrixTraces.getTrackeablesFrom());
        JsonRepository::save(j);
}

MatrixTraces JsonSerializer::deserializeMatrixTraces(json j) {

        /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

        /*｡o°✥✤✣MATRIX TRACES GET✣✤✥°o｡*/
        std::set<std::string> prefixesTracesTo = j["prefixesTracesTo"];
        std::set<std::string> prefixesTracesFrom = j["prefixesTracesFrom"];
        std::set<OID> trackeablesTo = deserializeSetOfOID(j["TrackeableTo"]);
        std::set<OID> trackeablesFrom = deserializeSetOfOID(j["TrackeableFrom"]);



        /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
        MatrixTraces m(trackeableDTO.id.getId());
        setTrackeablePart(trackeableDTO, &m);

        for (OID oid : trackeablesTo) {
            trackeablesFrom.insert(oid);
        }
        m.initMatrix(prefixesTracesTo, prefixesTracesFrom,trackeablesFrom);



        /*｡o°✥✤✣MATRIX TRACES SET✣✤✥°o｡*/

        return m;
}

void JsonSerializer::visit(UserStories userStories) {

            json j;

            /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
            j= trackeablePart(&userStories,j);
            j= priorityPart(&userStories,j);

            /*｡o°✥✤✣USER STORIES PART✣✤✥°o｡*/
            //std::string getRole();
    //    std::string getGoal();
    //    std::string getBenefit();
    //    unsigned getPriorityPoints();
    //    unsigned getDevTimePoints();

            j["role"] = userStories.getRole();
            j["goal"] = userStories.getGoal();
            j["benefit"] = userStories.getBenefit();
            j["priorityPoints"] = userStories.getPriorityPoints();
            j["devTimePoints"] = userStories.getDevTimePoints();

            JsonRepository::save(j);
}

UserStories JsonSerializer::deserializeUserStories(json j) {

                /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
                TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

                /*｡o°✥✤✣PRIORITY PART✣✤✥°o｡*/
                PriorityDTO priorityDTO = deserializePriorityDTO(j);

                /*｡o°✥✤✣USER STORIES GET✣✤✥°o｡*/
                std::string role = j["role"];
                std::string goal = j["goal"];
                std::string benefit = j["benefit"];
                unsigned priorityPoints = j["priorityPoints"];
                unsigned devTimePoints = j["devTimePoints"];

                /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
                UserStories u(trackeableDTO.id.getId());
                setTrackeablePart(trackeableDTO, &u);

                /*｡o°✥✤✣PRIORITY SET✣✤✥°o｡*/
                setPriorityPart(priorityDTO, &u);

                /*｡o°✥✤✣USER STORIES SET✣✤✥°o｡*/
                u.setRole(role);
                u.setGoal(goal);
                u.setBenefit(benefit);
                u.setPriorityPoints(priorityPoints);
                u.setDevTimePoints(devTimePoints);

                return u;
}

void JsonSerializer::visit(UserCaseDiagram userCaseDiagram)
{
    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(&userCaseDiagram,j);

    /*｡o°✥✤✣USER CASE DIAGRAM PART✣✤✥°o｡*/
    j["actors"] = serializeSetOfOID(userCaseDiagram.getActorUCList());
    j["useCases"] = serializeSetOfOID(userCaseDiagram.getUserCaseList());

    JsonRepository::save(j);
}

UserCaseDiagram JsonSerializer::deserializerUserCaseDiagram(json j)
{
    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    /*｡o°✥✤✣USER CASE DIAGRAM GET✣✤✥°o｡*/
    std::set<OID> actors = deserializeSetOfOID(j["actors"]);
    std::set<OID> useCases = deserializeSetOfOID(j["useCases"]);

    /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    UserCaseDiagram u(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &u);

    /*｡o°✥✤✣USER CASE DIAGRAM SET✣✤✥°o｡*/
    u.setElements(useCases, actors);

    return u;
}

void JsonSerializer::visit(Persona persona) {
    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(&persona,j);

    /*｡o°✥✤✣PERSONA PART✣✤✥°o｡*/
    j["age"] = persona.getAge();
    j["gender"] = persona.getGender();
    j["location"] = persona.getLocation();
    j["occupation"] = persona.getOccupation();
    j["background"] = persona.getBackground();
    j["goals"] = persona.getGoals();
    j["challenges"] = persona.getChallenges();
    j["behavior"] = persona.getBehavior();
    j["communicationStyle"] = persona.getCommunicationStyle();
    j["technologyAdoption"] = persona.getTechnologyAdoption();
    j["influences"] = persona.getInfluences();
    j["informationSources"] = persona.getInformationSources();

    JsonRepository::save(j);
}


Persona JsonSerializer::deserializePersona(json j) {

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    /*｡o°✥✤✣PERSONA GET✣✤✥°o｡*/
    unsigned age = j["age"];
    std::string gender = j["gender"];
    std::string location = j["location"];
    std::string occupation = j["occupation"];
    std::string background = j["background"];
    std::string goals = j["goals"];
    std::string challenges = j["challenges"];
    std::string behavior = j["behavior"];
    std::string communicationStyle = j["communicationStyle"];
    std::string technologyAdoption = j["technologyAdoption"];
    std::string influences = j["influences"];
    std::string informationSources = j["informationSources"];

    /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    Persona p(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &p);

    /*｡o°✥✤✣PERSONA SET✣✤✥°o｡*/
    p.setAge(age);
    p.setGender(gender);
    p.setLocation(location);
    p.setOccupation(occupation);
    p.setBackground(background);
    p.setGoals(goals);
    p.setChallenges(challenges);
    p.setBehavior(behavior);
    p.setCommunicationStyle(communicationStyle);
    p.setTechnologyAdoption(technologyAdoption);
    p.setInfluences(influences);
    p.setInformationSources(informationSources);

    return p;
}

json JsonSerializer::serializeVectorOfQuestions(std::vector<Question> questions) {
    json j;
    for (auto &question : questions) {
        json jQuestion;
        jQuestion["question"] = question.question;
        jQuestion["answer"] = question.answer;
        j.push_back(jQuestion);
    }
    return j;
}

void JsonSerializer::visit(Interview interview) {
    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(&interview,j);

    /*｡o°✥✤✣INTERVIEW PART✣✤✥°o｡*/
    j["questions"] = serializeVectorOfQuestions(interview.getQuestions());
    j["stakeholdersAsking"] = serializeSetOfOID(interview.getStakeholdersAsking());
    j["stakeholdersInterviewed"] = serializeSetOfOID(interview.getStakeholdersInterviewed());
    j["place"] = interview.getPlace();


    JsonRepository::save(j);
}




Interview JsonSerializer::deserializeInterview(json j) {

        /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
        TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

        /*｡o°✥✤✣INTERVIEW GET✣✤✥°o｡*/
        std::vector<Question> questions = deserializeVectorOfQuestions(j["questions"]);
        std::set<OID> stakeholdersAsking = deserializeSetOfOID(j["stakeholdersAsking"]);
        std::set<OID> stakeholdersInterviewed = deserializeSetOfOID(j["stakeholdersInterviewed"]);
        std::string place = j["place"];

        /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
        Interview i(trackeableDTO.id.getId());
        setTrackeablePart(trackeableDTO, &i);

        /*｡o°✥✤✣INTERVIEW SET✣✤✥°o｡*/
        i.setQuestions(questions);
        i.setStakeholdersAsking(stakeholdersAsking);
        i.setStakeholdersInterviewed(stakeholdersInterviewed);
        i.setPlace(place);

        return i;
}

std::vector<Question> JsonSerializer::deserializeVectorOfQuestions(json j) {
    std::vector<Question> questions;
    for (auto &question : j) {
        Question q;
        q.question = question["question"];
        q.answer = question["answer"];
        questions.push_back(q);
    }
    return questions;
}


json JsonSerializer::serializeVectorOfAsociationEnd(std::vector<AsociationEnd> associationEnds) {
    json j;
    for (auto &associationEnd : associationEnds) {
        json jAssociationEnd;
        jAssociationEnd["classID"] = serializeOID(associationEnd.classID);
        jAssociationEnd["name"] = associationEnd.name;
        jAssociationEnd["min"] = associationEnd.min;
        jAssociationEnd["max"] = associationEnd.max;
        jAssociationEnd["description"] = associationEnd.description;
        jAssociationEnd["comentario"] = associationEnd.comentario;

        j.push_back(jAssociationEnd);
    }
    return j;
}

std::vector<AsociationEnd> JsonSerializer::deserializeVectorOfAsociationEnd(json j) {
    std::vector<AsociationEnd> associationEnds;
    for (auto &associationEnd : j) {
        AsociationEnd a;
        a.classID = deserializeOID(associationEnd["classID"]);
        a.name = associationEnd["name"];
        a.min = associationEnd["min"];
        a.max = associationEnd["max"];
        a.description = associationEnd["description"];
        a.comentario = associationEnd["comentario"];

        associationEnds.push_back(a);
    }
    return associationEnds;
}

json JsonSerializer::serializeVectorOfAttribute(std::vector<Attribute> attributevector) {
    json j;
    for (auto &attribute : attributevector) {
        json jAttribute;
        jAttribute["name"] = attribute.name;
        jAttribute["componentClass"] = serializeOID(attribute.componentClass);
        jAttribute["type"] = attribute.type;
        jAttribute["min"] = attribute.min;
        jAttribute["max"] = attribute.max;
        jAttribute["defaultValue"] = attribute.defaultValue;
        jAttribute["description"] = attribute.description;
        jAttribute["comentario"] = attribute.comentario;

        j.push_back(jAttribute);
    }
    return j;
}

json JsonSerializer::serializeVectorOfInvariants(std::vector<Invariant> invariants) {
    json j;
    for (auto &invariant : invariants) {
        json jInvariant;
        jInvariant["name"] = invariant.name;
        jInvariant["description"] = invariant.description;
        jInvariant["OCL"] = invariant.OCL;
        jInvariant["comentario"] = invariant.comentario;

        j.push_back(jInvariant);
    }
    return j;
}

void JsonSerializer::visit(Class class1)
{
    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(&class1,j);

    /*｡o°✥✤✣CLASS PART✣✤✥°o｡*/
    j["abstract"] = class1.getAbstract();
    j["superClasses"] = serializeSetOfOID(class1.getSuperClasses());
    j["specializationType1"] = class1.getSpecialization1();
    j["specializationType2"] = class1.getSpecialization2();
    j["attributes"] = serializeVectorOfAttribute(class1.getAttributes());
    j["invariants"] = serializeVectorOfInvariants(class1.getInvariants());
    j["components"] = serializeVectorOfAttribute(class1.getComponents());

    JsonRepository::save(j);
}

Class JsonSerializer::deserializeClass(json j)
{
    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    /*｡o°✥✤✣CLASS GET✣✤✥°o｡*/
    bool abstract = j["abstract"];
    std::set<OID> superClasses = deserializeSetOfOID(j["superClasses"]);
    specializationType1 specializationType1 = j["specializationType1"];
    specializationType2 specializationType2 = j["specializationType2"];
    std::vector<Attribute> attributes = deserializeVectorOfAttribute(j["attributes"]);
    std::vector<Invariant> invariants = deserializeVectorOfInvariants(j["invariants"]);
    std::vector<Attribute> components = deserializeVectorOfAttribute(j["components"]);

    /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    Class class1(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &class1);

    /*｡o°✥✤✣CLASS SET✣✤✥°o｡*/
    class1.setAbstract(abstract);
    class1.setSuperClasses(superClasses);
    class1.setSpecialization1(specializationType1);
    class1.setSpecialization2(specializationType2);
    class1.setAttributes(attributes);
    class1.setInvariants(invariants);
    class1.setComponents(components);

    return class1;
}

std::vector<Attribute> JsonSerializer::deserializeVectorOfAttribute(json reference) {
    std::vector<Attribute> attributes;
    for (auto &attribute : reference) {
        Attribute a;
        a.name = attribute["name"];
        a.componentClass = deserializeOID(attribute["componentClass"]);
        a.type = attribute["type"];
        a.min = attribute["min"];
        a.max = attribute["max"];
        a.defaultValue = attribute["defaultValue"];
        a.description = attribute["description"];
        a.comentario = attribute["comentario"];

        attributes.push_back(a);
    }
    return attributes;
}

std::vector<Invariant> JsonSerializer::deserializeVectorOfInvariants(json reference) {
    std::vector<Invariant> invariants;
    for (auto &invariant : reference) {
        Invariant i;
        i.name = invariant["name"];
        i.description = invariant["description"];
        i.OCL = invariant["OCL"];
        i.comentario = invariant["comentario"];

        invariants.push_back(i);
    }
    return invariants;
}

void JsonSerializer::visit(Asociation asociation) {
    json j;

    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    j= trackeablePart(&asociation,j);

    /*｡o°✥✤✣ASOCIATION PART✣✤✥°o｡*/

    j["asociationEnds"] = serializeVectorOfAsociationEnd(asociation.getAsociationEnds());
    j["attributes"] = serializeVectorOfAttribute(asociation.getAttributes());
    j["invariants"] = serializeVectorOfInvariants( asociation.getInvariants());

    JsonRepository::save(j);
}

Asociation JsonSerializer::deserializeAsociation(json j) {
    /*｡o°✥✤✣TRACKEABLE PART✣✤✥°o｡*/
    TrackeableDTO trackeableDTO = deserializeTrackeableDTO(j);

    /*｡o°✥✤✣ASOCIATION GET✣✤✥°o｡*/
    std::vector<AsociationEnd> asociationEnds = deserializeVectorOfAsociationEnd(j["asociationEnds"]);
    std::vector<Attribute> attributes = deserializeVectorOfAttribute(j["attributes"]);
    std::vector<InvariantAsociation> invariants = deserializeVectorOfInvariants(j["invariants"]);

    /*｡o°✥✤✣TRACKEABLE SET✣✤✥°o｡*/
    Asociation asociation(trackeableDTO.id.getId());
    setTrackeablePart(trackeableDTO, &asociation);

    /*｡o°✥✤✣ASOCIATION SET✣✤✥°o｡*/
    asociation.setAsociationEnds(asociationEnds);
    asociation.setAttributes(attributes);
    asociation.setInvariants(invariants);

    return asociation;
}







