//
// Created by Fran- on 26/06/2023.
//

#ifndef TFG_FILEJSONMANAGER_H
#define TFG_FILEJSONMANAGER_H

#include "nlohmann/json.hpp"
#include "Dominio/Trackeable/Trackeable.h"
#include "Jsoneitor.h"
#include <fstream>
#include <iostream>
#include <string>
#define STAKEHOLDER 0
#define RESTRICTION_REQUIREMENT 1
#define FUNCTIONAL_REQUIREMENT 2
#define NON_FUNCTIONAL_REQUIREMENT 3
#define ACTOR_UC 4
#define INFORMATION_REQUIREMENT 5
#define ORGANIZATION 6
#define ROL_STAKEHOLDER 7
#define SYSTEM_OBJECTIVE 8
#define USER_CASE 9

using json = nlohmann::json;



class FileJsonManager {
private:
    json loadAll(std::string prefix);

    std::map<unsigned , std::string > prefixes = { {STAKEHOLDER,"SH",},{RESTRICTION_REQUIREMENT,"RR"},{FUNCTIONAL_REQUIREMENT,"FR"},{NON_FUNCTIONAL_REQUIREMENT,"NF"},{ACTOR_UC,"AC"},{INFORMATION_REQUIREMENT,"IR"},{ORGANIZATION,"OR"},{ROL_STAKEHOLDER,"RS"},{SYSTEM_OBJECTIVE,"SO"},{USER_CASE,"UC"}};
public:


    Stakeholder loadStakeholder(OID id);
    RestrictionRequirement loadRestrictionRequirement(OID id);
    FunctionalRequirement loadFunctionalRequirement(OID id);
    NonFunctionalRequirement loadNonFunctionalRequirement(OID id);
    ActorUC loadActorUC(OID id);
    InformationRequirement loadInformationRequirement(OID id);
    Organization loadOrganization(OID id);
    Rol_Stakeholder loadRolStakeholder(OID id);
    SystemObjective loadSystemObjective(OID id);
    UserCase loadUserCase(OID id);

    std::list<Stakeholder> loadAllStakeholder();
    std::list<RestrictionRequirement> loadAllRestrictionRequirement();
    std::list<FunctionalRequirement> loadAllFunctionalRequirement();
    std::list<NonFunctionalRequirement> loadAllNonFunctionalRequirement();
    std::list<ActorUC> loadAllActorUC();
    std::list<InformationRequirement> loadAllInformationRequirement();
    std::list<Organization> loadAllOrganization();
    std::list<Rol_Stakeholder> loadAllRolStakeholder();
    std::list<SystemObjective> loadAllSystemObjective();
    std::list<UserCase> loadAllUserCase();

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

    static void save(json singlejson);

    void save(Stakeholder stakeholder);
    void save(RestrictionRequirement restrictionRequirement);
    void save(FunctionalRequirement functionalRequirement);
    void save(NonFunctionalRequirement nonFunctionalRequirement);
    void save(ActorUC actorUC);
    void save(InformationRequirement informationRequirement);
    void save(Organization organization);
    void save(Rol_Stakeholder rolStakeholder);
    void save(SystemObjective systemObjective);
    void save(UserCase userCase);

    void saveAll(std::list<Stakeholder> stakeholders);
    void saveAll(std::list<RestrictionRequirement> restrictionRequirements);
    void saveAll(std::list<FunctionalRequirement> functionalRequirements);
    void saveAll(std::list<NonFunctionalRequirement> nonFunctionalRequirements);
    void saveAll(std::list<ActorUC> actorUCs);
    void saveAll(std::list<InformationRequirement> informationRequirements);
    void saveAll(std::list<Organization> organizations);
    void saveAll(std::list<Rol_Stakeholder> rolStakeholders);
    void saveAll(std::list<SystemObjective> systemObjectives);
    void saveAll(std::list<UserCase> userCases);
    bool exist(OID id);


    json load(OID id);
};


#endif //TFG_FILEJSONMANAGER_H
