//
// Created by Fran- on 24/06/2023.
//

#ifndef TFG_JSONEITOR_H
#define TFG_JSONEITOR_H
#include "TFG/nlohmann/json.hpp"
#include "Visitor.h"
#include "FileJsonManager.h"


// for convenience
using json = nlohmann::json;

class Jsoneitor : public Visitor {



public:
    void visit(InformationRequirement informationRequirement) override;
    void visit(ActorUC actorUC) override;
    void visit(SystemObjective systemObjective) override;
    void visit(RestrictionRequirement restrictionRequirement) override;
    void visit(FunctionalRequirement functionalRequirement) override;
    void visit(NonFunctionalRequirement nonFunctionalRequirement) override;
    void visit(Stakeholder stakeholder) override;
    void visit(UserCase userCase) override;
    void visit(Rol_Stakeholder rolStakeholder) override;


    Stakeholder deserializeStakeholder(json j);
    UserCase deserializeUserCase(json j);
    Change deserializeChange(json j);
    SystemObjective deserializeSystemObjective(json j);
    RestrictionRequirement deserializeRestrictionRequirement(json j);
    FunctionalRequirement deserializeFunctionalRequirement(json j);
    NonFunctionalRequirement deserializeNonFunctionalRequirement(json j);
    ActorUC deserializeActorUC(json j);
    InformationRequirement deserializeInformationRequirement(json j);

};


#endif //TFG_JSONEITOR_H
