//
// Created by Fran- on 28/06/2023.
//

#ifndef TFG_REPOSITORIO_H
#define TFG_REPOSITORIO_H


#include <map>
#include "Dominio/Trackeable/Trackeable.h"

class Repositorio {
public:
    enum Type {
        SystemObjective,
        RestrictionRequirement,
        FunctionalRequirement,
        NonFunctionalRequirement,
        ActorUC,
        Stakeholder,
        UserCase,
        Rol_Stakeholder,
        InformationRequirement,
        Organization
    };

    std::map<Type,std::map<OID,Trackeable*>> map;

    static void save(Trackeable object);
    static Trackeable* load(OID id);
    static std::list<Trackeable*> load(Type type);
    static unsigned lastID(Type type);
    static void update(Trackeable object);
    static void remove(OID id);

};


#endif //TFG_REPOSITORIO_H
