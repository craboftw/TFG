//
// Created by Fran- on 24/06/2023.
//

#ifndef TFG_JSONEITOR_H
#define TFG_JSONEITOR_H
#include "nlohmann/json.hpp"
#include "Visitor.h"
#include "FileJsonManager.h"
#include "Dominio/Trackeable/Organization.h"
#include "Dominio/Trackeable/Stakeholder.h"


// for convenience
using json = nlohmann::json;

class Jsoneitor : public Visitor {
private:
    int a;


public:
    Jsoneitor() = default;
    void visit(InformationRequirement informationRequirement) override;
    void visit(ActorUC actorUC) override;
    void visit(SystemObjective systemObjective) override;
    void visit(RestrictionRequirement restrictionRequirement) override;
    void visit(FunctionalRequirement functionalRequirement) override;
    void visit(NonFunctionalRequirement nonFunctionalRequirement) override;
    void visit(Stakeholder stakeholder) override;
    void visit(UserCase& userCase) override;
    void visit(Organization organization) override;

    void visit(Trackeable* trackeable) override;
    void visit(Priority *priority);


    Stakeholder deserializeStakeholder(json j);
    UserCase deserializeUserCase(json j);
    SystemObjective deserializeSystemObjective(json j);
    RestrictionRequirement deserializeRestrictionRequirement(json j);
    FunctionalRequirement deserializeFunctionalRequirement(json j);
    NonFunctionalRequirement deserializeNonFunctionalRequirement(json j);
    ActorUC deserializeActorUC(json j);
    InformationRequirement deserializeInformationRequirement(json j);
    Organization deserializeOrganization(json j);

    Trackeable *deserializeTrackeable(json j);
    Priority *deserializePriority(json j);

};


#endif //TFG_JSONEITOR_H
