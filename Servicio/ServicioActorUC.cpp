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

std::string ServicioActorUC::getPackage(OID &oid) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, getPackage");
    if(!fileJsonManager.exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = fileJsonManager.loadActorUC(oid);
    return actorUC.getPackage();
}

OID ServicioActorUC::getGeneralization(OID oid) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, getGeneralization");
    if(!fileJsonManager.exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = fileJsonManager.loadActorUC(oid);
    return actorUC.getGeneralization();
}

void ServicioActorUC::setGeneralization(OID oid, OID generalization) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, setGeneralization");
    if(!fileJsonManager.exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = fileJsonManager.loadActorUC(oid);
    actorUC.setGeneralization(generalization);
    fileJsonManager.save(actorUC);
}

void ServicioActorUC::setPackage(OID oid, std::string package) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, setPackage");
    if(!fileJsonManager.exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = fileJsonManager.loadActorUC(oid);
    actorUC.setPackage(package);
    fileJsonManager.save(actorUC);
}

void ServicioActorUC::setName(OID oid, std::string name) {
    if (oid.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id no es de un actor, setName");
    if(!fileJsonManager.exist(oid))  throw std::invalid_argument("El id a leer no existe, addChange");
    ActorUC actorUC = fileJsonManager.loadActorUC(oid);
    actorUC.setName(name);
    fileJsonManager.save(actorUC);
}

OID ServicioActorUC::createActorUC(std::string name) {
    ActorUC actorUC(fileJsonManager.lastActorUC()+1);
    if (name.empty()) name = actorUC.getId().operator std::string();
    actorUC.setName(name);
    fileJsonManager.save(actorUC);
    return actorUC.getId();
}
