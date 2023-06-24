//
// Created by Fran- on 24/06/2023.
//

#include "PrintConsole.h"
#include "../InformationRequirement.h"
#include "../Generic.h"
#include "../Trackeable/Stakeholder.h"

class InformationRequirement;
class ActorUC;
class SystemObjective;
class RestrictionRequirement;
class FunctionalRequirement;
class NonFunctionalRequirement;
class Stakeholder;


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

void PrintConsole::visit(Stakeholder stakeholder) {
//Imprimir todos los parametros de la clase

//TRACKEABLE INFO
/*OID id;
    std::string name;
    std::string description;
    std::string versionMajor;
    std::string versionMinor;
    Fecha date_init;
    std::string comments;
    std::set<OID> authors;
    std::list<OID> tracesFrom;
    std::list<OID> tracesTo;*/
std::cout<<"Stakeholder"<<std::endl;
std::cout<<"Id: "<<stakeholder.getId()<<std::endl;
std::cout<<"Name: "<<stakeholder.getName()<<std::endl;
std::cout<<"Description: "<<stakeholder.getDescription()<<std::endl;
std::cout<<"VersionMajor: "<<stakeholder.getVersionMajor()<<std::endl;
std::cout<<"VersionMinor: "<<stakeholder.getVersionMinor()<<std::endl;
auto date = stakeholder.getDate();
std::cout<<"Date: "<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear()<<std::endl;
std::cout<<"Comments: "<<stakeholder.getComments()<<std::endl;
auto authors = stakeholder.getAuthors();
std::cout<<"Authors:  WIP" <<std::endl;
//auto tracesFrom = stakeholder.getTracesFrom();
std::cout<<"TracesFrom:  WIP" <<std::endl;
//auto tracesTo = stakeholder.getTracesTo();
std::cout<<"TracesTo:  WIP" <<std::endl;

//STAKEHOLDER INFO
/*std::string email;
    std::string phone;
    std::string address;
    OID stakeholderRole;
    OID worksForOrganization;*/
std::cout<<"Email: "<<stakeholder.getEmail()<<std::endl;
std::cout<<"Phone: "<<stakeholder.getPhone()<<std::endl;
std::cout<<"Address: "<<stakeholder.getAddress()<<std::endl;
std::cout<<"StakeholderRole: "<<stakeholder.getStakeholderRole()<<std::endl;
std::cout<<"WorksForOrganization: "<<stakeholder.getWorksForOrganization()<<std::endl;

}

