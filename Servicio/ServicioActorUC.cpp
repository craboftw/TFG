//
// Created by craboftw on 4/07/23.
//

#include "ServicioActorUC.h"

std::string ServicioActorUC::getPackage(OID oid) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, getPackage");
    if(!JsonRepository::exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = JsonRepository::loadActorUC(oid);
    return actorUC.getPackage();
}

OID ServicioActorUC::getGeneralization(OID oid) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, getGeneralization");
    if(!JsonRepository::exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = JsonRepository::loadActorUC(oid);
    return actorUC.getGeneralization();
}

void ServicioActorUC::setGeneralization(OID oid, OID generalization) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, setGeneralization");
    if(!JsonRepository::exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = JsonRepository::loadActorUC(oid);
    actorUC.setGeneralization(generalization);
    JsonRepository::save(actorUC);
}

void ServicioActorUC::setPackage(OID oid, std::string package) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, setPackage");
    if(!JsonRepository::exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = JsonRepository::loadActorUC(oid);
    actorUC.setPackage(package);
    JsonRepository::save(actorUC);
}


OID ServicioActorUC::createActorUC(std::string name) {
    ActorUC actorUC(JsonRepository::lastActorUC()+1);
    if (name.empty()) name = actorUC.getId().operator std::string();
    actorUC.setName(name);
    JsonRepository::save(actorUC);
    return actorUC.getId();
}
