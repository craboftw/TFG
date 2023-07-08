//
// Created by Fran- on 26/06/2023.
//

#ifndef TFG_FILEJSONMANAGER_H
#define TFG_FILEJSONMANAGER_H

#include "nlohmann/json.hpp"
#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Trackeable/Stakeholder.h"
#include "Dominio/Trackeable/Organization.h"
#include "Dominio/Generic.h"
#include "Dominio/InformationRequirement.h"
#include "Dominio/UserCase.h"
#include "Visitor/Jsoneitor.h"
#include "Dominio/UserStories.h"
#include <fstream>
#include <iostream>
#include <string>



class MatrixTraces;

using json = nlohmann::json;





class FileJsonManager {
private:
    json loadAll(std::string prefix);
    //reverse map
public:


    Stakeholder loadStakeholder(OID id);
    RestrictionRequirement loadRestrictionRequirement(OID id);
    FunctionalRequirement loadFunctionalRequirement(OID id);
    NonFunctionalRequirement loadNonFunctionalRequirement(OID id);
    ActorUC loadActorUC(OID id);
    InformationRequirement loadInformationRequirement(OID id);
    Organization loadOrganization(OID id);
    SystemObjective loadSystemObjective(OID id);
    UserCase loadUserCase(OID id);
    Text loadText(OID id);
    MatrixTraces loadMatrixTraces(OID id);
    UserStories loadUserStories(OID id);

    Trackeable* loadTrackeable(OID id);
    Priority *loadPriority(OID oid) ;

    std::list<Stakeholder> loadAllStakeholder();
    std::list<RestrictionRequirement> loadAllRestrictionRequirement();
    std::list<FunctionalRequirement> loadAllFunctionalRequirement();
    std::list<NonFunctionalRequirement> loadAllNonFunctionalRequirement();
    std::list<ActorUC> loadAllActorUC();
    std::list<InformationRequirement> loadAllInformationRequirement();
    std::list<Organization> loadAllOrganization();
    std::list<SystemObjective> loadAllSystemObjective();
    std::list<UserCase> loadAllUserCase();
    std::list<Text> loadAllText();
    std::list<Trackeable*> loadAllTrackeable();

    unsigned lastStakeholder();
    unsigned lastRestrictionRequirement();
    unsigned lastFunctionalRequirement();
    unsigned lastNonFunctionalRequirement();
    unsigned lastActorUC();
    unsigned lastInformationRequirement();
    unsigned lastOrganization();
    unsigned lastRolStakeholder();
    unsigned lastSystemObjective();
    unsigned lastUserCase();
    unsigned lastText();
    unsigned lastMatrixTraces();
    unsigned lastUserStories();

    static void save(json singlejson);

    void save(Stakeholder stakeholder);
    void save(RestrictionRequirement restrictionRequirement);
    void save(FunctionalRequirement functionalRequirement);
    void save(NonFunctionalRequirement nonFunctionalRequirement);
    void save(ActorUC actorUC);
    void save(InformationRequirement informationRequirement);
    void save(Organization organization);
    void save(SystemObjective systemObjective);
    void save(UserCase& userCase);
    void save(Text text);
    void save(MatrixTraces matrixTraces);
    void save(UserStories userStories);
    void save(Priority* priority);
    void save(Trackeable* trackeable);

    void saveAll(std::list<Stakeholder> stakeholders);
    void saveAll(std::list<RestrictionRequirement> restrictionRequirements);
    void saveAll(std::list<FunctionalRequirement> functionalRequirements);
    void saveAll(std::list<NonFunctionalRequirement> nonFunctionalRequirements);
    void saveAll(std::list<ActorUC> actorUCs);
    void saveAll(std::list<InformationRequirement> informationRequirements);
    void saveAll(std::list<Organization> organizations);
    void saveAll(std::list<SystemObjective> systemObjectives);
    void saveAll(std::list<UserCase> userCases);
    void saveAll(std::list<Text> texts);
    bool exist(OID id);


    json load(OID id);

};


#endif //TFG_FILEJSONMANAGER_H
