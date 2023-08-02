//
// Created by Fran- on 26/06/2023.
//

#ifndef TFG_JSONREPOSITORY_H
#define TFG_JSONREPOSITORY_H
#define STAKEHOLDER 0
#define RESTRICTION_REQUIREMENT 1
#define FUNCTIONAL_REQUIREMENT 2
#define NON_FUNCTIONAL_REQUIREMENT 3
#define ACTOR_UC 4
#define INFORMATION_REQUIREMENT 5
#define ORGANIZATION 6
#define INDEX 7
#define SYSTEM_OBJECTIVE 8
#define USER_CASE 9
#define TEXT 10
#define MATRIX_TRACES 11
#define USER_STORIES 12
#define USER_CASE_DIAGRAM 13
#define PERSONA 14
#define INTERVIEW 15
<<<<<<< HEAD
#define CLASS 16
#define ASOCIATION 17
#define NULLTYPE 30
=======
#define NULLTYPE 16
>>>>>>> main


#include "nlohmann/json.hpp"
#include "JsonSerializer.h"
#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Trackeable/Stakeholder.h"
#include "Dominio/Trackeable/Organization.h"
#include "Dominio/Generic.h"
#include "Dominio/InformationRequirement.h"
#include "Dominio/UserCase.h"
#include "Dominio/UserStories.h"
#include "Dominio/Trackeable/MatrixTraces.h"
#include "Dominio/UserCaseDiagram.h"
#include "Dominio/Index.h"
#include "Dominio/Persona.h"
#include "Dominio/Interview.h"
<<<<<<< HEAD
#include "Dominio/Clases/Class.h"
=======
>>>>>>> main
#include <fstream>
#include <iostream>
#include <string>


using json = nlohmann::json;




class JsonRepository {


public:
    inline static std::map<std::string, unsigned> prefixes = {{Stakeholder::getPrefixID(),STAKEHOLDER},
                                                              {RestrictionRequirement::getPrefixID(),RESTRICTION_REQUIREMENT},
                                                              {FunctionalRequirement::getPrefixID(),FUNCTIONAL_REQUIREMENT},
                                                              {NonFunctionalRequirement::getPrefixID(),NON_FUNCTIONAL_REQUIREMENT},
                                                              {ActorUC::getPrefixID(),ACTOR_UC},
                                                              {InformationRequirement::getPrefixID(),INFORMATION_REQUIREMENT},
                                                              {Organization::getPrefixID(),ORGANIZATION},
                                                              {UserCaseDiagram::getPrefixID(),USER_CASE_DIAGRAM},
                                                              {SystemObjective::getPrefixID(),SYSTEM_OBJECTIVE},
                                                              {UserCase::getPrefixID(),USER_CASE},
                                                              {Text::getPrefixID(),TEXT},
                                                              {MatrixTraces::getPrefixID(),MATRIX_TRACES},
                                                              {UserStories::getPrefixID(),USER_STORIES},
                                                              {Index::getPrefixID(),INDEX},
                                                              {Persona::getPrefixID(),PERSONA},
                                                              {Interview::getPrefixID(),INTERVIEW},
                                                              {Class::getPrefixID(),CLASS},
                                                              {Asociation::getPrefixID(),ASOCIATION}
                                                              };

    static Stakeholder loadStakeholder(OID id);
    static RestrictionRequirement loadRestrictionRequirement(OID id);
    static FunctionalRequirement loadFunctionalRequirement(OID id);
    static NonFunctionalRequirement loadNonFunctionalRequirement(OID id);
    static ActorUC loadActorUC(OID id);
    static InformationRequirement loadInformationRequirement(OID id);
    static Organization loadOrganization(OID id);
    static SystemObjective loadSystemObjective(OID id);
    static UserCase loadUserCase(OID id);
    static Text loadText(OID id);
    static MatrixTraces loadMatrixTraces(OID id);
    static UserStories loadUserStories(OID id);
    static UserCaseDiagram loadUserCaseDiagram(OID id);
    static Index loadIndex(OID id);
    static Persona loadPersona(OID id);
    static Interview loadInterview(OID id);
<<<<<<< HEAD
    static Class loadClass(OID id);
    static Asociation loadAsociation(OID id);
=======
>>>>>>> main

    static Trackeable loadTrackeable(OID id);
    static TrackeableDTO loadTrackeableDTO(OID id);
    static Priority loadPriority(OID oid) ;
    static PriorityDTO loadPriorityDTO(OID oid) ;

    static Stakeholder loadFileStakeholder(OID id);
    static RestrictionRequirement loadFileRestrictionRequirement(OID id);
    static FunctionalRequirement loadFileFunctionalRequirement(OID id);
    static NonFunctionalRequirement loadFileNonFunctionalRequirement(OID id);
    static ActorUC loadFileActorUC(OID id);
    static InformationRequirement loadFileInformationRequirement(OID id);
    static Organization loadFileOrganization(OID id);
    static SystemObjective loadFileSystemObjective(OID id);
    static UserCase loadFileUserCase(OID id);
    static Text loadFileText(OID id);
    static MatrixTraces loadFileMatrixTraces(OID id);
    static UserStories loadFileUserStories(OID id);
    static UserCaseDiagram loadFileUserCaseDiagram(OID id);
    static Index loadFileIndex(OID id);
    static Persona loadFilePersona(OID id);
    static Interview loadFileInterview(OID id);
<<<<<<< HEAD
    static Class loadFileClass(OID id);
    static Asociation loadFileAsociation(OID id);
=======
>>>>>>> main

    static Trackeable* loadFileTrackeable(OID id);
    static Priority *loadFilePriority(OID oid) ;

    static std::list<Stakeholder> loadAllStakeholder();
    static std::list<RestrictionRequirement> loadAllRestrictionRequirement();
    static std::list<FunctionalRequirement> loadAllFunctionalRequirement();
    static std::list<NonFunctionalRequirement> loadAllNonFunctionalRequirement();
    static std::list<ActorUC> loadAllActorUC();
    static std::list<InformationRequirement> loadAllInformationRequirement();
    static std::list<Organization> loadAllOrganization();
    static std::list<SystemObjective> loadAllSystemObjective();
    static std::list<UserCase> loadAllUserCase();
    static std::list<Text> loadAllText();
    static std::list<MatrixTraces> loadAllMatrixTraces();
    static std::list<UserStories> loadAllUserStories();
    static std::list<UserCaseDiagram> loadAllUserCaseDiagram();
    static std::list<Index> loadAllIndex();
    static std::list<Persona> loadAllPersona();
    static std::list<Interview> loadAllInterview();
<<<<<<< HEAD
    static std::list<Class> loadAllClass();
    static std::list<Asociation> loadAllAsociation();
=======
>>>>>>> main

    static std::list<Trackeable*> loadAllTrackeable();

    static std::list<Stakeholder> loadFileAllStakeholder();
    static std::list<RestrictionRequirement> loadFileAllRestrictionRequirement();
    static std::list<FunctionalRequirement> loadFileAllFunctionalRequirement();
    static std::list<NonFunctionalRequirement> loadFileAllNonFunctionalRequirement();
    static std::list<ActorUC> loadFileAllActorUC();
    static std::list<InformationRequirement> loadFileAllInformationRequirement();
    static std::list<Organization> loadFileAllOrganization();
    static std::list<SystemObjective> loadFileAllSystemObjective();
    static std::list<UserCase> loadFileAllUserCase();
    static std::list<Text> loadFileAllText();
    static std::list<MatrixTraces> loadFileAllMatrixTraces();
    static std::list<UserStories> loadFileAllUserStories();
    static std::list<UserCaseDiagram> loadFileAllUserCaseDiagram();
    static std::list<Index> loadFileAllIndex();
    static std::list<Persona> loadFileAllPersona();
    static std::list<Interview> loadFileAllInterview();
<<<<<<< HEAD
    static std::list<Class> loadFileAllClass();
    static std::list<Asociation> loadFileAllAsociation();
=======
>>>>>>> main

    static std::list<Trackeable*> loadFileAllTrackeable();


    unsigned lastStakeholder();
    unsigned lastRestrictionRequirement();
    unsigned lastFunctionalRequirement();
    unsigned lastNonFunctionalRequirement();
    static unsigned lastActorUC();
    static unsigned lastInformationRequirement();
    static unsigned lastOrganization();
    unsigned lastRolStakeholder();
    unsigned lastSystemObjective();
    static unsigned lastUserCase();
    unsigned lastText();
    static unsigned lastMatrixTraces();
    unsigned lastUserStories();
    static unsigned lastUserCaseDiagram();
    static unsigned lastIndex();
    static unsigned lastPersona();
    static unsigned lastInterview();
<<<<<<< HEAD
    static unsigned lastClass();
    static unsigned lastAsociation();
=======
>>>>>>> main


    static void save(json singlejson);

    void save(Stakeholder stakeholder);
    static void save(RestrictionRequirement restrictionRequirement);
    static void save(FunctionalRequirement functionalRequirement);
    static void save(NonFunctionalRequirement nonFunctionalRequirement);
    static void save(ActorUC actorUC);
    static void save(InformationRequirement informationRequirement);
    static void save(Organization organization);
    static void save(SystemObjective systemObjective);
    static void save(UserCase& userCase);
    static void save(Text text);
    static void save(MatrixTraces matrixTraces);
    static void save(UserStories userStories);
    static void save(UserCaseDiagram userCaseDiagram);
    static void save(Index index);
    static void save(Persona persona);
    static void save(Interview interview);
<<<<<<< HEAD
    static void save(Class clas);
    static void save(Asociation asociation);
=======
>>>>>>> main



    static void save(Priority* priority);
    static void save(Trackeable* trackeable);


    static void saveAll(std::list<Stakeholder> stakeholders);
    static void saveAll(std::list<RestrictionRequirement> restrictionRequirements);
    static void saveAll(std::list<FunctionalRequirement> functionalRequirements);
    static void saveAll(std::list<NonFunctionalRequirement> nonFunctionalRequirements);
    static void saveAll(std::list<ActorUC> actorUCs);
    static void saveAll(std::list<InformationRequirement> informationRequirements);
    static void saveAll(std::list<Organization> organizations);
    static void saveAll(std::list<SystemObjective> systemObjectives);
    static void saveAll(std::list<UserCase> userCases);
    static void saveAll(std::list<Text> texts);
    static void saveAll(std::list<MatrixTraces> matrixTraces);
    static void saveAll(std::list<UserStories> userStories);
    static void saveAll(std::list<UserCaseDiagram> userCaseDiagrams);
    static void saveAll(std::list<Index> index);
    static void saveAll(std::list<Persona> personas);
    static void saveAll(std::list<Interview> interviews);
<<<<<<< HEAD
    static void saveAll(std::list<Class> classes);
    static void saveAll(std::list<Asociation> asociations);
=======
>>>>>>> main
    static bool exist(OID id);


    static json load(OID id);

    json loadFile(OID oid);

    json loadFileAll(std::string prefix);


private:
    static json loadAll(std::string prefix);


    inline static std::map<OID,Stakeholder> MEMStakeholder =  []() {
        std::map<OID,Stakeholder> map;
        for (auto stakeholder : loadFileAllStakeholder()) {
            Stakeholder stakeholder1 = Stakeholder(stakeholder);
            map.insert(std::pair<OID,Stakeholder>(stakeholder1.getId(),stakeholder1));
        }
        return map;
    }();
    
    inline static std::map<OID,RestrictionRequirement> MEMRestrictionRequirement = []() {
        std::map<OID,RestrictionRequirement> map;
        for (auto restrictionRequirement : loadFileAllRestrictionRequirement()) {
            RestrictionRequirement restrictionRequirement1 = RestrictionRequirement(restrictionRequirement);
            map.insert(std::pair<OID,RestrictionRequirement>(restrictionRequirement1.getId(),restrictionRequirement1));
        }
        return map;
    }();
    
    inline static std::map<OID,FunctionalRequirement> MEMFunctionalRequirement = []() {
        std::map<OID,FunctionalRequirement> map;
        for (auto functionalRequirement : loadFileAllFunctionalRequirement()) {
            FunctionalRequirement functionalRequirement1 = FunctionalRequirement(functionalRequirement);
            map.insert(std::pair<OID,FunctionalRequirement>(functionalRequirement1.getId(),functionalRequirement1));
        }
        return map;
    }();
    
    inline static std::map<OID,NonFunctionalRequirement> MEMNonFunctionalRequirement = []() {
        std::map<OID,NonFunctionalRequirement> map;
        for (auto nonFunctionalRequirement : loadFileAllNonFunctionalRequirement()) {
            NonFunctionalRequirement nonFunctionalRequirement1 = NonFunctionalRequirement(nonFunctionalRequirement);
            map.insert(std::pair<OID,NonFunctionalRequirement>(nonFunctionalRequirement1.getId(),nonFunctionalRequirement1));
        }
        return map;
    }();
    
    inline static std::map<OID,ActorUC> MEMActorUC = []() {
        std::map<OID,ActorUC> map;
        for (auto actorUC : loadFileAllActorUC()) {
            ActorUC actorUC1 = ActorUC(actorUC);
            map.insert(std::pair<OID,ActorUC>(actorUC1.getId(),actorUC1));
        }
        return map;
    }();
    
    inline static std::map<OID,InformationRequirement> MEMInformationRequirement = []() {
        std::map<OID,InformationRequirement> map;
        for (auto informationRequirement : loadFileAllInformationRequirement()) {
            InformationRequirement informationRequirement1 = InformationRequirement(informationRequirement);
            map.insert(std::pair<OID,InformationRequirement>(informationRequirement1.getId(),informationRequirement1));
        }
        return map;
    }();
    
    inline static std::map<OID,Organization> MEMOrganization = []() {
        std::map<OID,Organization> map;
        for (auto organization : loadFileAllOrganization()) {
            Organization organization1 = Organization(organization);
            map.insert(std::pair<OID,Organization>(organization1.getId(),organization1));
        }
        return map;
    }();
    
    inline static std::map<OID,SystemObjective> MEMSystemObjective = []() {
        std::map<OID,SystemObjective> map;
        for (auto systemObjective : loadFileAllSystemObjective()) {
            SystemObjective systemObjective1 = SystemObjective(systemObjective);
            map.insert(std::pair<OID,SystemObjective>(systemObjective1.getId(),systemObjective1));
        }
        return map;
    }();
    
    inline static std::map<OID,UserCase> MEMUserCase = []() {
        std::map<OID,UserCase> map;
        for (auto userCase : loadFileAllUserCase()) {
            UserCase userCase1 = UserCase(userCase);
            map.insert(std::pair<OID,UserCase>(userCase1.getId(),userCase1));
        }
        return map;
    }();
    
    inline static std::map<OID,Text> MEMText = []() {
        std::map<OID,Text> map;
        for (auto text : loadFileAllText()) {
            Text text1 = Text(text);
            map.insert(std::pair<OID,Text>(text1.getId(),text1));
        }
        return map;
    }();
    

    
    inline static std::map<OID,UserStories> MEMUserStories = []() {
        std::map<OID,UserStories> map;
        for (auto userStories : loadFileAllUserStories()) {
            UserStories userStories1 = UserStories(userStories);
            map.insert(std::pair<OID,UserStories>(userStories1.getId(),userStories1));
        }
        return map;
    }();
    inline static std::map<OID,UserCaseDiagram> MEMUserCaseDiagram = []() {
        std::map<OID,UserCaseDiagram> map;
        for (auto userCaseDiagram : loadFileAllUserCaseDiagram()) {
            UserCaseDiagram userCaseDiagram1 = UserCaseDiagram(userCaseDiagram);
            map.insert(std::pair<OID,UserCaseDiagram>(userCaseDiagram1.getId(),userCaseDiagram1));
        }
        return map;
    }();
    inline static std::map<OID,MatrixTraces> MEMMatrixTraces = []() {
        std::map<OID,MatrixTraces> map;
        for (auto matrixTraces : loadFileAllMatrixTraces()) {
            map.insert(std::pair<OID,MatrixTraces>(matrixTraces.getId(),matrixTraces));
        }
        return map;
    }();



    inline static std::map<OID,Index> MEMIndex = []() {
        std::map<OID,Index> map;
        for (Index matrixTraces : loadFileAllIndex()) {
            map.insert(std::pair<OID,Index>(matrixTraces.getId(),matrixTraces));
        }
        return map;
    }();

    inline static std::map<OID,Persona> MEMPersona = []() {
        std::map<OID,Persona> map;
        for (auto persona : loadFileAllPersona()) {
            Persona persona1 = Persona(persona);
            map.insert(std::pair<OID,Persona>(persona1.getId(),persona1));
        }
        return map;
    }();
    inline static std::map<OID,Interview> MEMInterview = []() {
        std::map<OID,Interview> map;
        for (auto interview : loadFileAllInterview()) {
            Interview interview1 = Interview(interview);
            map.insert(std::pair<OID,Interview>(interview1.getId(),interview1));
        }
        return map;
    }();

    inline static std::map<OID,Class> MEMClass = []() {
        std::map<OID,Class> map;
        for (auto class1 : loadFileAllClass()) {
            Class class2 = Class(class1);
            map.insert(std::pair<OID,Class>(class2.getId(),class2));
        }
        return map;
    }();

    inline static std::map<OID,Asociation> MEMAsociation = []() {
        std::map<OID,Asociation> map;
        for (auto asociation : loadFileAllAsociation()) {
            Asociation asociation1 = Asociation(asociation);
            map.insert(std::pair<OID,Asociation>(asociation1.getId(),asociation1));
        }
        return map;
    }();

<<<<<<< HEAD

=======
>>>>>>> main
};


#endif //TFG_JSONREPOSITORY_H
