//
// Created by Fran- on 03/07/2023.
//

#ifndef TFG_HTMLMANAGER_H
#define TFG_HTMLMANAGER_H


#include <string>
#include "Visitor.h"
#include "Servicio/ServicioStakeholder.h"
#include "Servicio/ServicioActorUC.h"
#include "Servicio/ServicioUserCase.h"
#include "Servicio/ServicioInformationRequirement.h"
#include "Servicio/ServicioOrganization.h"
#include "Servicio/ServicioGeneric.h"
#include "Dominio/Trackeable/MatrixTraces.h"
#include "Servicio/ServicioMatrixTraces.h"
#include "Servicio/ServicioUserStories.h"

class HtmlManager {
public:

    std::string generateTable(ActorUC actorUC);
    std::string generateTable(UserCase userCase);
    std::string generateTable(NonFunctionalRequirement nonFunctionalRequirement);
    std::string generateTable(FunctionalRequirement functionalRequirement);
    std::string generateTable(RestrictionRequirement restrictionRequirement);
    std::string generateTable(InformationRequirement requirement);
    std::string generateTable(SystemObjective systemObjective);
    std::string generateText(Text text);

    std::string generateTableStakeholder(OID stakeholder);
    std::string generateTableUserCase(OID id);
    std::string generateTableActorUC(OID actorUC);
    std::string generateTableText(OID requirement);
    std::string generateTableInformationRequirement(OID requirement);
    std::string generateTableNonFunctionalRequirement(OID requirement);
    std::string generateTableSystemObjetive(OID requirement);
    std::string generateTableFunctionalRequirement(OID requirement);
    std::string generateTableRestrictionRequirement(OID requirement);
    std::string generateTableOrganization(OID organization);
    std::string generateMatrixTraces(OID matrixTraces);
    std::string generateUserStory(OID id);
    std::string generateUserStory(const std::list<OID>& listID);
    std::string generateTableUserStory(OID id);


private:
    ServicioTrackeable servicioTrackeable;
    ServicioPriority servicioPriority;
    ServicioStakeholder servicioStakeholder;
    ServicioActorUC servicioActorUC;
    ServicioUserCase servicioUserCase;
    ServicioInformationRequirement servicioInformationRequirement;
    ServicioOrganization servicioOrganization;
    ServicioText servicioText;
    ServicioMatrixTraces servicioMatrixTraces;
    ServicioUserStories servicioUserStories;


    std::string generateTable(std::list<SpecificInformation> lista);
    std::string generateTablePriority(OID id);
    std::string generateTableTrackeable(OID id);
    std::string generateTableChanges(OID id);

    std::string generateHead(OID id);


};

class IndexHTMLelement {
public:
    IndexHTMLelement(unsigned ida) : id(prefixID,ida) {}
    unsigned getPos() const;
    void setPos(unsigned pos);
    OID getId() const;
    void setId(OID id);

    std::string getName() const;
    void setName(std::string name);

    std::set<OID> getElementsToPrint() const;
    void setElementsToPrint(const std::set<OID> &elementsToPrint);

    void addElementToPrint(OID id);
    void addElementToPrint(std::set<OID> ids);
    void removeElementToPrint(OID id);
    void removeElementToPrint(std::set<OID> ids);

    std::vector<IndexHTMLelement> getSublevels() const;
    void addsubLevel(IndexHTMLelement list);
    void setsubLevel(IndexHTMLelement hijo, unsigned pos);
    void removeSubLevel(unsigned pos);
    IndexHTMLelement getSubLevel(unsigned pos) const;

    static std::string getPrefixID() {return prefixID;}



private:
    OID id;
    std::string name;
    unsigned pos;
    std::set<OID> elementsToPrint;
    std::vector<IndexHTMLelement> sublevels;
    inline static std::string prefixID = "IE";

};


#endif //TFG_HTMLMANAGER_H
