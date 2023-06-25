//
// Created by Fran- on 24/06/2023.
//

#include <fstream>
#include "PrintConsole.h"
#include "../Dominio/InformationRequirement.h"
#include "../Dominio/Generic.h"
#include "../Dominio/Trackeable/Stakeholder.h"
#include "../nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

class InformationRequirement;
class ActorUC;
class SystemObjective;
class RestrictionRequirement;
class FunctionalRequirement;
class NonFunctionalRequirement;
class Stakeholder;

typedef std::string OID;

void PrintConsole::visit(InformationRequirement informationRequirement) {
//Imprimir todos los parametros de la clase
std::cout<<"InformationRequirement: "<<informationRequirement.getId()
<<"Nombre: "<<informationRequirement.getName()<<std::endl
<<"Descripcion: "<<informationRequirement.getEstability()<<std::endl;
}

void PrintConsole::visit(ActorUC actorUC) {
//Imprimir todos los parametros de la clase
std::cout<<"ActorUC: "<<actorUC.getId()
<<"Nombre: "<<actorUC.getName()<<std::endl
<<"Descripcion: "<<actorUC.getName()<<std::endl;
}

void PrintConsole::visit(RestrictionRequirement restrictionRequirement) {
//Imprimir todos los parametros de la clase
std::cout<<"RestrictionRequirement: "<<restrictionRequirement.getId()
<<"Nombre: "<<restrictionRequirement.getName()<<std::endl
<<"Descripcion: "<<restrictionRequirement.getName()<<std::endl;

}

void PrintConsole::visit(FunctionalRequirement functionalRequirement) {
//Imprimir todos los parametros de la clase2
std::cout<<"FunctionalRequirement: "<<functionalRequirement.getId()
<<"Nombre: "<<functionalRequirement.getName()<<std::endl
<<"Descripcion: "<<functionalRequirement.getName()<<std::endl;
}

void PrintConsole::visit(NonFunctionalRequirement nonFunctionalRequirement) {
//Imprimir todos los parametros de la clase
std::cout<<"NonFunctionalRequirement: "<<nonFunctionalRequirement.getId()
<<"Nombre: "<<nonFunctionalRequirement.getName()<<std::endl
<<"Descripcion: "<<nonFunctionalRequirement.getName()<<std::endl;



}

json serializeListOfChanges(const std::list<Change>& listOfChanges) {
    json j;

    // Serializar cada cambio en la lista
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


void PrintConsole::visit(Stakeholder stakeholder) {
    //PRUEBA DE CONCEPTO
    json j;

    //Trackeable part
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
    auto listOfChanges = stakeholder.getChanges();
    j["changes"] = serializeListOfChanges(listOfChanges);

    //Stakeholder part
    // Serializar los miembros adicionales de la clase Stakeholder
    j["email"] = stakeholder.getEmail();
    j["phone"] = stakeholder.getPhone();
    j["address"] = stakeholder.getAddress();
    j["stakeholderRole"] = stakeholder.getStakeholderRole();
    j["worksForOrganization"] = stakeholder.getWorksForOrganization();

    //make a json file
    std::ofstream o("stakeholder.json");
    o << std::setw(4) << j << std::endl;
    o.close();
}

//create a Stakeholder from a json file
Stakeholder deserializeStakeholder(json j) {
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

    return s;


}


void PrintConsole::visit(SystemObjective systemObjective) {

}

void PrintConsole::visit(UserCase userCase) {

}

void PrintConsole::visit(Change change) {

}

Stakeholder PrintConsole::deserializeStakeholder(json j) {
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


/*
void PrintConsole::visit(SystemObjective systemObjective) {
    std::cout<<"Stakeholder"<<std::endl;
    std::cout<<"Id: "<<systemObjective.getId()<<std::endl;
    std::cout<<"Name: "<<systemObjective.getName()<<std::endl;
    std::cout<<"Description: "<<systemObjective.getDescription()<<std::endl;
    std::cout<<"VersionMajor: "<<systemObjective.getVersionMajor()<<std::endl;
    std::cout<<"VersionMinor: "<<systemObjective.getVersionMinor()<<std::endl;
    auto date = systemObjective.getDate();
    std::cout<<"Date: "<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear()<<std::endl;
    std::cout<<"Comments: "<<systemObjective.getComments()<<std::endl;
    auto authors = systemObjective.getAuthors();
    std::cout<<"Authors:  WIP" <<std::endl;
//auto tracesFrom = stakeholder.getTracesFrom();
    std::cout<<"TracesFrom:  WIP" <<std::endl;
//auto tracesTo = stakeholder.getTracesTo();
    std::cout<<"TracesTo:  WIP" <<std::endl;

    //PRIORITY INFO
    std::cout<<"Priority: "<<std::endl;
    std::cout<<"Importance Level:"<<systemObjective.getImportanceLevel()<<std::endl;
    std::cout<<"Urgency Level:"<<systemObjective.getUrgencyLevel()<<std::endl;
    std::cout<<"Stability:"<<systemObjective.getEstability()<<std::endl;
    std::cout<<"Trend:"<<systemObjective.getPhase()<<std::endl;



}
*/

