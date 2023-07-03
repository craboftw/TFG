//
// Created by Fran- on 03/07/2023.
//

#ifndef TFG_HTMLMANAGER_H
#define TFG_HTMLMANAGER_H


#include <string>
#include "Visitor.h"
#include "Servicio/ServicioStakeholder.h"

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
private:
    ServicioStakeholder servicioStakeholder;


    std::string generateTable(std::list<SpecificInformation> lista);
};


#endif //TFG_HTMLMANAGER_H
