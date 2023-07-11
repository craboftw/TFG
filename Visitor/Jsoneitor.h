//
// Created by Fran- on 24/06/2023.
//

#ifndef TFG_JSONEITOR_H
#define TFG_JSONEITOR_H
#include "nlohmann/json.hpp"
#include "Visitor.h"
#include "FileJsonManager.h"
#include "Dominio/Trackeable/MatrixTraces.h"
#include "Dominio/Trackeable/Organization.h"
#include "Dominio/Trackeable/Stakeholder.h"


// for convenience
using json = nlohmann::json;

class Trackeable;
class Priority;

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
    void visit(MatrixTraces matrixTraces);
    void visit(Text text) override;
    void visit(UserStories userStories) override;

    void visit(Trackeable* trackeable) override;
    void visit(Priority *priority);

    OID deserializeOID( json j);

    Stakeholder deserializeStakeholder(json j);
    UserCase deserializeUserCase(json j);
    SystemObjective deserializeSystemObjective(json j);
    RestrictionRequirement deserializeRestrictionRequirement(json j);
    FunctionalRequirement deserializeFunctionalRequirement(json j);
    NonFunctionalRequirement deserializeNonFunctionalRequirement(json j);
    ActorUC deserializeActorUC(json j);
    InformationRequirement deserializeInformationRequirement(json j);
    Organization deserializeOrganization(json j);
    Text deserializeText(json j);
    MatrixTraces deserializeMatrixTraces(json j);
    UserStories deserializeUserStories(json j);

    Trackeable *deserializeTrackeable(json j);
    Priority *deserializePriority(json j);

    std::list<SpecificInformation> deserializeListOfSpecificInformation(json j);

    json serializeListOfSpecificInformation(std::list<SpecificInformation> lista);
    json serializeTimeQuantity(const TimeQuantity &timeQuantity);
    json serializeVectorOfSteps(const std::vector<Step> &vectorOfSteps);
    json serializeListOfOID(const std::list<OID> &listOfOID);
    json serializeSetOfOID(const std::set<OID> setOfOID);
    json serializeOID(OID oid);
    json serializeVectorOfOID(const std::vector<OID> &vectorOfOID);
    json serializeListOfChanges(const std::list<Change> &listOfChanges);
    json serializeVectorOfExceptions(std::vector<Exception> listOfExceptions);

    std::set<OID> deserializeSetOfOID(const json &j);
    std::vector<OID> deserializeVectorOfOID(const json &j);
    std::list<OID> deserializeListOfOID(const json &j);
    std::vector<Step> deserializeVectorOfSteps(json reference);
    TrackeableDTO deserializeTrackeableDTO(const json &j);
    PriorityDTO deserializePriorityDTO(const json &j);
    TimeQuantity deserializeTimeQuantity(const json &j);
    std::vector<Exception> deserializeVectorOfExceptions(const json& j) ;

    json trackeablePart(Trackeable *objeto, json &j);
    json priorityPart(Priority *objeto, json &j);

    void setTrackeablePart(TrackeableDTO trackeableDTO, Trackeable *trackeable);
    void setPriorityPart(PriorityDTO priorityDTO, Priority *priority);


};


#endif //TFG_JSONEITOR_H
