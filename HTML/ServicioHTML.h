//
// Created by Fran- on 08/07/2023.
//

#ifndef TFG_SERVICIOHTML_H
#define TFG_SERVICIOHTML_H


#include "Servicio/ServicioTrackeable.h"
#include "Dominio/Interview.h"
#include "OID.h"

class ServicioHTML : public ServicioTrackeable {
    public:
    inline static  std::map<std::string, unsigned> prefijos = {{Stakeholder::getPrefixID(),STAKEHOLDER},
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
                                                                {UserCaseDiagram::getPrefixID(),USER_CASE_DIAGRAM},
                                                                {Persona::getPrefixID(),PERSONA},
                                                                {Interview::getPrefixID(),INTERVIEW},
                                                                {Class::getPrefixID(),CLASS},
                                                                {Asociation::getPrefixID(),ASOCIATION},
                                                                {OID().getPrefix(),NULLTYPE}};



    static void printElement(OID it);
    static void printHTML(OID id);
    OID createIndex(std::string titulo);
    unsigned createEntry(OID id, unsigned idnode);
    unsigned int createEntry(OID id, unsigned int idnode, std::string title);
    unsigned int createEntry(OID id, std::string title, unsigned int idnode);
    void deleteEntry(OID id, unsigned idnode);
    void moveEntry(OID id, unsigned idnode, unsigned newIdnode);
    std::string printEntry(OID id, unsigned idnode);
    static std::vector<ElementosIndex> getIndex(OID id);
    std::vector<OID> getElements(OID id,unsigned idnode);
    void addElement(OID id,unsigned idnode, OID element);
    void deleteElement(OID id,unsigned idnode,OID element);
    void moveElementInIndex(OID id,unsigned idnode,OID element,unsigned newIdnode);

private:


};


#endif //TFG_SERVICIOHTML_H
