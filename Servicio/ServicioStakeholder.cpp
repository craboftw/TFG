//
// Created by Fran- on 03/07/2023.
//

#include "ServicioStakeholder.h"

OID ServicioStakeholder::createStakeholder(std::string name) {
    Stakeholder stakeholder(fileJsonManager.lastStakeholder()+1);
    if (name.empty()) name = stakeholder.getId().operator std::string();
    stakeholder.setName(name);
    fileJsonManager.save(stakeholder);
    return stakeholder.getId();
}

void ServicioStakeholder::setEmail(OID id, std::string _email) {
    if(id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, setEmail");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setEmail");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    stakeholder.setEmail(_email);
    fileJsonManager.save(stakeholder);
}

void ServicioStakeholder::setPhone(OID id, std::string _phone) {
    if (id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, setPhone");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setPhone");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    stakeholder.setPhone(_phone);
    fileJsonManager.save(stakeholder);
}

void ServicioStakeholder::setAddress(OID id, std::string _address) {
    if (id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, setAddress");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setAddress");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    stakeholder.setAddress(_address);
    fileJsonManager.save(stakeholder);
}

void ServicioStakeholder::setStakeholderRole(OID id, std::string _stakeholderRole) {
    if (id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, setStakeholderRole");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setStakeholderRole");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    stakeholder.setStakeholderRole(_stakeholderRole);
    fileJsonManager.save(stakeholder);
}

void ServicioStakeholder::setWorksForOrganization(OID id, OID _worksForOrganization) {
    if (id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, setWorksForOrganization");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setWorksForOrganization");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    stakeholder.setWorksForOrganization(_worksForOrganization);
    fileJsonManager.save(stakeholder);
}

std::string ServicioStakeholder::getEmail(OID id) {
    if (id.getPrefix() != Stakeholder::getPrefixID())
        throw std::invalid_argument("El id a leer no es de un Stakeholder, getEmail");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getEmail");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    return stakeholder.getEmail();
}

std::string ServicioStakeholder::getPhone(OID id) {
    if (id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a leer no es de un Stakeholder, getPhone");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getPhone");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    return stakeholder.getPhone();
}

std::string ServicioStakeholder::getAddress(OID id) {
    if (id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a leer no es de un Stakeholder, getAddress");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getAddress");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    return stakeholder.getAddress();}

std::string ServicioStakeholder::getStakeholderRole(OID id) {
    if (id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a leer no es de un Stakeholder, getStakeholderRole");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getStakeholderRole");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    return stakeholder.getStakeholderRole();
}

OID ServicioStakeholder::getWorksForOrganization(OID id) {
    if (id.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a leer no es de un Stakeholder, getWorksForOrganization");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getWorksForOrganization");
    Stakeholder stakeholder = fileJsonManager.loadStakeholder(id);
    return stakeholder.getWorksForOrganization();
}

std::list<std::pair<OID, std::string>> ServicioStakeholder::getStakeholders() {
    std::list<std::pair<OID, std::string>> list;
    auto listash = fileJsonManager.loadAllStakeholder();
    for (auto sh : listash) {
        list.push_back(std::make_pair(sh.getId(), sh.getName()));
    }
    return list;
}


