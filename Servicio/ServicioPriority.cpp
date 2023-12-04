//
// Created by Fran- on 02/07/2023.
//

#include "ServicioPriority.h"
#include "Repository/JsonRepository.h"
#include "OID.h"

std::string ServicioPriority::strImportanceLevel(OID id) {
    if (id.getPrefix() == "XX" ) throw std::invalid_argument("El id a modificar no corresponde a un objeto valido, strImportanceLevel");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strImportanceLevel");
    Priority obj = JsonRepository::loadPriority(id);
    return obj.strImportanceLevel();
}

std::string ServicioPriority::strUrgencyLevel(OID id) {
    if (id.getPrefix() == "XX" ) throw std::invalid_argument("El id a modificar no corresponde a un objeto valido, strUrgencyLevel");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strUrgencyLevel");
    Priority obj = JsonRepository::loadPriority(id);
    return obj.strUrgencyLevel();
}

std::string ServicioPriority::strPhase(OID id) {
    if (id.getPrefix() == "XX" ) throw std::invalid_argument("El id a modificar no corresponde a un objeto valido, strPhase");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    Priority obj = JsonRepository::loadPriority(id);
    return obj.strPhase();
}

std::string ServicioPriority::strEstability(OID id) {
    if (id.getPrefix() == "XX" ) throw std::invalid_argument("El id a modificar no corresponde a un objeto valido, strEstability");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strEstability");
    Priority obj = JsonRepository::loadPriority(id);
    return obj.strEstability();
}

Priority::Importance ServicioPriority::getImportanceLevel(OID id) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getImportanceLevel");
    Priority obj = JsonRepository::loadPriority(id);
    return obj.getImportanceLevel();
}

Priority::Importance ServicioPriority::getUrgencyLevel(OID id) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getUrgencyLevel");
    Priority obj = JsonRepository::loadPriority(id);
    return obj.getUrgencyLevel();

}

Priority::Development_phase ServicioPriority::getPhase(OID id) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getPhase");
    Priority obj = JsonRepository::loadPriority(id);
    return obj.getPhase();

}

Priority::Estability ServicioPriority::getEstability(OID id) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getEstability");
    Priority obj = JsonRepository::loadPriority(id);
    return obj.getEstability();
}

void ServicioPriority::setEstability(OID id, Priority::Estability _estability) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setEstability");
    Priority obj = JsonRepository::loadPriority(id);
    obj.setEstability(_estability);
    JsonRepository::save(&obj);
}

void ServicioPriority::setPhase(OID id, Priority::Development_phase _phase) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setPhase");
    Priority obj = JsonRepository::loadPriority(id);
    obj.setPhase(_phase);
    JsonRepository::save(&obj);
}

void ServicioPriority::setUrgencyLevel(OID id, Priority::Importance urgencyLevel) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setUrgencyLevel");
    Priority obj = JsonRepository::loadPriority(id);
    obj.setUrgencyLevel(urgencyLevel);
    JsonRepository::save(&obj);
}

void ServicioPriority::setImportanceLevel(OID id, Priority::Importance importanceLevel) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setImportanceLevel");
    Priority obj = JsonRepository::loadPriority(id);
    obj.setImportanceLevel(importanceLevel);
    JsonRepository::save(&obj);
}