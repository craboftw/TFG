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

class HtmlManager {
public:
    std::string generateTable(Priority* priority);
    std::string generateTable(Trackeable* trackeable);
    std::string generateTableChanges(Trackeable* trackeable);
    std::string generateTable(Stakeholder stakeholder);
    std::string generateTable(ActorUC actorUC);
    std::string generateTable(UserCase userCase);
    std::string generateTable(NonFunctionalRequirement nonFunctionalRequirement);
    std::string generateTable(FunctionalRequirement functionalRequirement);
    std::string generateTable(RestrictionRequirement restrictionRequirement);
    std::string generateTable(InformationRequirement requirement);
    std::string generateTable(SystemObjective systemObjective);
    std::string generateText(Text text);

    std::string generateTableUserCase(OID id);

private:
    ServicioTrackeable servicioTrackeable;
    ServicioPriority servicioPriority;
    ServicioStakeholder servicioStakeholder;
    ServicioActorUC servicioActorUC;
    ServicioUserCase servicioUserCase;


    std::string generateTable(std::list<SpecificInformation> lista);

    std::string generateTablePriority(OID id);

    std::string generateTableTrackeable(OID id);

    std::string generateTableChanges(OID id);

};


#endif //TFG_HTMLMANAGER_H
