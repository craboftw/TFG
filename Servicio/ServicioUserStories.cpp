//
// Created by Fran- on 08/07/2023.
//

#include "ServicioUserStories.h"

OID ServicioUserStories::createUserStories(std::string name) {
    UserStories userStories(filejsonManager.lastUserStories()+1);
    if (name.empty()) {
        userStories.setName("UserStories"+userStories.getId().operator std::string());
    } else {
        userStories.setName(name);
    }
    filejsonManager.save(userStories);
    return userStories.getId();
}

void ServicioUserStories::setRole(OID id, std::string role) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setRole");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setRole");
    UserStories obj = filejsonManager.loadUserStories(id);
    obj.setRole(role);
    filejsonManager.save(obj);
}

void ServicioUserStories::setGoal(OID id, std::string goal) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setGoal");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setGoal");
    UserStories obj = filejsonManager.loadUserStories(id);
    obj.setGoal(goal);
    filejsonManager.save(obj);
}

void ServicioUserStories::setBenefit(OID id, std::string benefit) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setBenefit");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setBenefit");
    UserStories obj = filejsonManager.loadUserStories(id);
    obj.setBenefit(benefit);
    filejsonManager.save(obj);
}

std::string ServicioUserStories::getRole(OID id) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getRole");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getRole");
    UserStories obj = filejsonManager.loadUserStories(id);
    return obj.getRole();
}

std::string ServicioUserStories::getGoal(OID id) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getGoal");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getGoal");
    UserStories obj = filejsonManager.loadUserStories(id);
    return obj.getGoal();
}

std::string ServicioUserStories::getBenefit(OID id) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getBenefit");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getBenefit");
    UserStories obj = filejsonManager.loadUserStories(id);
    return obj.getBenefit();
}

unsigned ServicioUserStories::getPriorityPoints(OID id) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getPriorityPoints");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getPriorityPoints");
    UserStories obj = filejsonManager.loadUserStories(id);
    return obj.getPriorityPoints();
}

unsigned ServicioUserStories::getDevTimePoints(OID id) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getDevTimePoints");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getDevTimePoints");
    UserStories obj = filejsonManager.loadUserStories(id);
    return obj.getDevTimePoints();

}

void ServicioUserStories::setDevTimePoints(OID id, unsigned int DevTimePoints) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setDevTimePoints");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setDevTimePoints");
    UserStories obj = filejsonManager.loadUserStories(id);
    obj.setDevTimePoints(DevTimePoints);
    filejsonManager.save(obj);
}

void ServicioUserStories::setPriorityPoints(OID id, unsigned int PriorityPoints) {
    if (id.getPrefix() != UserStories::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setPriorityPoints");
    if (!filejsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setPriorityPoints");
    UserStories obj = filejsonManager.loadUserStories(id);
    obj.setPriorityPoints(PriorityPoints);
    filejsonManager.save(obj);
}
