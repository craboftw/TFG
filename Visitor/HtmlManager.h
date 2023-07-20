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
#include "LinkedGeneralTree.cpp"

class HtmlManager {
public:


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
    std::string generateTablePersona(OID id);


    std::string generateUserCaseDiagram(OID id);

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

#endif //TFG_HTMLMANAGER_H