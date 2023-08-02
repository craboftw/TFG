//
// Created by Fran- on 24/06/2023.
//

#ifndef TFG_JSONSERIALIZER_H
#define TFG_JSONSERIALIZER_H
#include "nlohmann/json.hpp"
#include "Visitor/Visitor.h"
#include "JsonRepository.h"
#include "Dominio/Trackeable/MatrixTraces.h"
#include "Dominio/Trackeable/Organization.h"
#include "Dominio/Trackeable/Stakeholder.h"
#include "Dominio/Index.h"
#include "Dominio/Persona.h"
#include "Dominio/Interview.h"
<<<<<<< HEAD
#include "Dominio/Clases/Class.h"
=======
>>>>>>> main



// for convenience
using json = nlohmann::json;

class Trackeable;
class Priority;
class UserCaseDiagram;

class JsonSerializer : public Visitor {
private:

public:
    JsonSerializer() = default;
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
    void visit(UserCaseDiagram userCaseDiagram);
    void visit(Index index);
    void visit(Persona persona);
    void visit(Interview interview);
<<<<<<< HEAD
    void visit(Class class1);
    void visit(Asociation asociation);
=======
>>>>>>> main

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
    UserCaseDiagram deserializerUserCaseDiagram(json j);
    Index deserializeIndex(json j);
    Persona deserializePersona(json j);
    Interview deserializeInterview(json j);
<<<<<<< HEAD
    Class deserializeClass(json j);
    Asociation deserializeAsociation(json j);
=======
>>>>>>> main


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


    json serializeElementosIndex(ElementosIndex obj);
    json serializeGeneralTree(Agen<ElementosIndex>::nodo n);

    ElementosIndex deserializeElementosIndex(const json &j);

    Agen<ElementosIndex> deserializeGeneralTree(const json &j);

    void deserializeChildren(Agen<ElementosIndex>::nodo parent, const json &children);

    json serializeVectorOfQuestions(std::vector<Question> questions);

    std::vector<Question> deserializeVectorOfQuestions(json j);
<<<<<<< HEAD

    json serializeVectorOfAsociationEnd(std::vector<AsociationEnd> associationEnds);

    json serializeVectorOfAttribute(Attribute attribute);

    json serializeVectorOfAttribute(std::vector<Attribute> attributevector);

    json serializeVectorOfInvariants(std::vector<Invariant> invariants);

    void serializeClass(json j);


    std::vector<Attribute> deserializeVectorOfAttribute(json reference);

    std::vector<Invariant> deserializeVectorOfInvariants(json reference);

    std::vector<AsociationEnd> deserializeVectorOfAsociationEnd(json j);
=======
>>>>>>> main
};


#endif //TFG_JSONSERIALIZER_H
