//
// Created by Fran- on 08/07/2023.
//

#ifndef TFG_SERVICIOHTML_H
#define TFG_SERVICIOHTML_H
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
#define TEXT 10
#define MATRIX_TRACES 11
#define USER_STORIES 12
#define NULLTYPE 13

#include "Visitor/HtmlManager.h"

class ServicioHTML {
    public:
    inline static std::map<std::string, unsigned> prefixes = {{Stakeholder::getPrefixID(),STAKEHOLDER},
                                                                {RestrictionRequirement::getPrefixID(),RESTRICTION_REQUIREMENT},
                                                                {FunctionalRequirement::getPrefixID(),FUNCTIONAL_REQUIREMENT},
                                                                {NonFunctionalRequirement::getPrefixID(),NON_FUNCTIONAL_REQUIREMENT},
                                                                {ActorUC::getPrefixID(),ACTOR_UC},
                                                                {InformationRequirement::getPrefixID(),INFORMATION_REQUIREMENT},
                                                                {Organization::getPrefixID(),ORGANIZATION},
                                                                {SystemObjective::getPrefixID(),SYSTEM_OBJECTIVE},
                                                                {UserCase::getPrefixID(),USER_CASE},
                                                                {Text::getPrefixID(),TEXT},
                                                                {MatrixTraces::getPrefixID(),MATRIX_TRACES},
                                                                {UserStories::getPrefixID(),USER_STORIES},
                                                                {OID().getPrefix(),NULL}};



    static void printElement(OID it);
    void printHTML();
    unsigned createIndex(std::string titulo,unsigned id);
    void deleteIndex(unsigned id);
    void moveIndex(unsigned id,unsigned pos);
    std::string printIndex(unsigned id);
    std::vector<ElementosIndex> getIndex();
    std::vector<OID> getElements(unsigned id);
    void addElement(unsigned id, OID oid);
    void deleteElement(unsigned index,OID id);
    void moveElementInIndex(unsigned index,OID id,unsigned pos);
private:
    Index index;
};


#endif //TFG_SERVICIOHTML_H
