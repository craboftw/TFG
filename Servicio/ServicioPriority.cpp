//
// Created by Fran- on 02/07/2023.
//

#include "ServicioPriority.h"

std::string ServicioPriority::strImportanceLevel(OID id) {
    if (id.getPrefix() == "XX" and id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strImportanceLevel");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strImportanceLevel");
    Priority* obj = fileJsonManager.loadPriority(id);
    return obj->strImportanceLevel();
}

std::string ServicioPriority::strUrgencyLevel(OID id) {
    if (id.getPrefix() == "XX" and id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strUrgencyLevel");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strUrgencyLevel");
    Priority* obj = fileJsonManager.loadPriority(id);
    return obj->strUrgencyLevel();
}

std::string ServicioPriority::strPhase(OID id) {
    if (id.getPrefix() == "XX" and id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    Priority* obj = fileJsonManager.loadPriority(id);
    return obj->strPhase();
}

std::string ServicioPriority::strEstability(OID id) {
    if (id.getPrefix() == "XX" and id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strEstability");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strEstability");
    Priority* obj = fileJsonManager.loadPriority(id);
    return obj->strEstability();
}

Priority::Importance ServicioPriority::getImportanceLevel(OID id) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getImportanceLevel");
    Priority* obj = fileJsonManager.loadPriority(id);
    return obj->getImportanceLevel();
}

Priority::Importance ServicioPriority::getUrgencyLevel(OID id) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getUrgencyLevel");
    Priority* obj = fileJsonManager.loadPriority(id);
    return obj->getUrgencyLevel();

}

Priority::Development_phase ServicioPriority::getPhase(OID id) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getPhase");
    Priority* obj = fileJsonManager.loadPriority(id);
    return obj->getPhase();

}

Priority::Estability ServicioPriority::getEstability(OID id) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getEstability");
    Priority* obj = fileJsonManager.loadPriority(id);
    return obj->getEstability();
}

void ServicioPriority::setEstability(OID id, Priority::Estability _estability) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setEstability");
    Priority* obj = fileJsonManager.loadPriority(id);
    obj->setEstability(_estability);
    fileJsonManager.save(obj);
}

void ServicioPriority::setPhase(OID id, Priority::Development_phase _phase) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setPhase");
    Priority* obj = fileJsonManager.loadPriority(id);
    obj->setPhase(_phase);
    fileJsonManager.save(obj);
}

void ServicioPriority::setUrgencyLevel(OID id, Priority::Importance urgencyLevel) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setUrgencyLevel");
    Priority* obj = fileJsonManager.loadPriority(id);
    obj->setUrgencyLevel(urgencyLevel);
    fileJsonManager.save(obj);
}

void ServicioPriority::setImportanceLevel(OID id, Priority::Importance importanceLevel) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setImportanceLevel");
    Priority* obj = fileJsonManager.loadPriority(id);
    obj->setImportanceLevel(importanceLevel);
    fileJsonManager.save(obj);
}