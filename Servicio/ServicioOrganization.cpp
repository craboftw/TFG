//
// Created by Fran- on 03/07/2023.
//

#include "ServicioOrganization.h"
#include "Dominio/Trackeable/Organization.h"

OID ServicioOrganization::createOrganization(std::string name) {
    Organization organization(fileJsonManager.lastOrganization()+1);
    if (name.empty()) name = organization.getId().operator std::string();
    organization.setName(name);
    fileJsonManager.save(organization);
    return organization.getId();
}

void ServicioOrganization::setContactInfo(OID id, std::string _contactInfo) {
    if (id.getPrefix() != Organization::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Organization, setContactInfo");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setContactInfo");
    Organization organization = fileJsonManager.loadOrganization(id);
    organization.setContactInfo(_contactInfo);
    fileJsonManager.save(organization);
}

std::string ServicioOrganization::getContactInfo(OID id) {
    if (id.getPrefix() != Organization::getPrefixID()) throw std::invalid_argument("El id a leer no es de un Organization, getContactInfo");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getContactInfo");
    Organization organization = fileJsonManager.loadOrganization(id);
    return organization.getContactInfo();
}






