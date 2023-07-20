//
// Created by Fran- on 20/07/2023.
//

#include "ServicioPersona.h"
#include "Dominio/Persona.h"

OID ServicioPersona::createPersona() {
    Persona persona(JsonRepository::lastPersona() + 1);
    JsonRepository::save(persona);
    return persona.getId();
}

void ServicioPersona::setAge(OID id, unsigned age) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setAge");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setAge");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setAge(age);
    JsonRepository::save(persona);
}

void ServicioPersona::setGender(OID id, const std::string& gender) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setGender");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setGender");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setGender(gender);
    JsonRepository::save(persona);
}

void ServicioPersona::setLocation(OID id, const std::string& location) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setLocation");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setLocation");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setLocation(location);
    JsonRepository::save(persona);
}

void ServicioPersona::setOccupation(OID id, const std::string& occupation) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setOccupation");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setOccupation");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setOccupation(occupation);
    JsonRepository::save(persona);
}

void ServicioPersona::setBackground(OID id, const std::string& background) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setBackground");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setBackground");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setBackground(background);
    JsonRepository::save(persona);
}

void ServicioPersona::setGoals(OID id, const std::string& goals) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setGoals");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setGoals");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setGoals(goals);
    JsonRepository::save(persona);
}

void ServicioPersona::setChallenges(OID id, const std::string& challenges) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setChallenges");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setChallenges");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setChallenges(challenges);
    JsonRepository::save(persona);
}

void ServicioPersona::setBehavior(OID id, const std::string& behavior) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setBehavior");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setBehavior");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setBehavior(behavior);
    JsonRepository::save(persona);
}

void ServicioPersona::setCommunicationStyle(OID id, const std::string& communicationStyle) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setCommunicationStyle");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setCommunicationStyle");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setCommunicationStyle(communicationStyle);
    JsonRepository::save(persona);
}

void ServicioPersona::setTechnologyAdoption(OID id, const std::string& technologyAdoption) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setTechnologyAdoption");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setTechnologyAdoption");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setTechnologyAdoption(technologyAdoption);
    JsonRepository::save(persona);
}

void ServicioPersona::setInfluences(OID id, const std::string& influences) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setInfluences");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setInfluences");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setInfluences(influences);
    JsonRepository::save(persona);
}

void ServicioPersona::setInformationSources(OID id, const std::string& informationSources) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setInformationSources");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setInformationSources");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setInformationSources(informationSources);
    JsonRepository::save(persona);
}

void ServicioPersona::setUserJourney(OID id, const std::string& userJourney) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setUserJourney");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setUserJourney");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setUserJourney(userJourney);
    JsonRepository::save(persona);
}

void ServicioPersona::setBrandRelationship(OID id, const std::string& brandRelationship) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a modificar no es de una Persona, setBrandRelationship");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setBrandRelationship");
    Persona persona = JsonRepository::loadPersona(id);
    persona.setBrandRelationship(brandRelationship);
    JsonRepository::save(persona);
}

unsigned ServicioPersona::getAge(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getAge");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getAge");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getAge();
}

std::string ServicioPersona::getGender(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getGender");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getGender");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getGender();
}

std::string ServicioPersona::getLocation(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getLocation");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getLocation");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getLocation();
}

std::string ServicioPersona::getOccupation(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getOccupation");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getOccupation");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getOccupation();
}

std::string ServicioPersona::getBackground(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getBackground");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getBackground");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getBackground();
}

std::string ServicioPersona::getGoals(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getGoals");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getGoals");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getGoals();
}

std::string ServicioPersona::getChallenges(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getChallenges");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getChallenges");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getChallenges();
}

std::string ServicioPersona::getBehavior(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getBehavior");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getBehavior");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getBehavior();
}

std::string ServicioPersona::getCommunicationStyle(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getCommunicationStyle");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getCommunicationStyle");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getCommunicationStyle();
}

std::string ServicioPersona::getTechnologyAdoption(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getTechnologyAdoption");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getTechnologyAdoption");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getTechnologyAdoption();
}

std::string ServicioPersona::getInfluences(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getInfluences");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getInfluences");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getInfluences();
}

std::string ServicioPersona::getInformationSources(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getInformationSources");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getInformationSources");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getInformationSources();
}

std::string ServicioPersona::getUserJourney(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getUserJourney");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getUserJourney");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getUserJourney();
}

std::string ServicioPersona::getBrandRelationship(OID id) {
    if (id.getPrefix() != Persona::getPrefixID()) throw std::invalid_argument("El id a leer no es de una Persona, getBrandRelationship");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getBrandRelationship");
    Persona persona = JsonRepository::loadPersona(id);
    return persona.getBrandRelationship();
}