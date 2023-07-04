//
// Created by craboftw on 4/07/23.
//

#include "ServicioActorUC.h"

std::string ServicioActorUC::getName(OID oid) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, getName");
    if(!fileJsonManager.exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = fileJsonManager.loadActorUC(oid);
    return actorUC.getName();
}
