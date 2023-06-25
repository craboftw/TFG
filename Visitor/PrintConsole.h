//
// Created by Fran- on 24/06/2023.
//

#ifndef TFG_PRINTCONSOLE_H
#define TFG_PRINTCONSOLE_H
#include "TFG/nlohmann/json.hpp"
#include "Visitor.h"

// for convenience
using json = nlohmann::json;

class PrintConsole : public Visitor {
     void visit(InformationRequirement informationRequirement) override;
     void visit(ActorUC actorUC) override;
     void visit(SystemObjective systemObjective) override;
     void visit(RestrictionRequirement restrictionRequirement) override;
     void visit(FunctionalRequirement functionalRequirement) override;
     void visit(NonFunctionalRequirement nonFunctionalRequirement) override;
     void visit(Stakeholder stakeholder) override;
     void visit(UserCase userCase) override;
     void visit(Change change) override;


public:
    Stakeholder deserializeStakeholder(json j);
};


#endif //TFG_PRINTCONSOLE_H
