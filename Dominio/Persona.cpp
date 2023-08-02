//
// Created by Fran- on 20/07/2023.
//

#include "Persona.h"

unsigned Persona::getAge() const {
    return age;
}

void Persona::setAge(unsigned age) {
    Persona::age = age;
}

const std::string &Persona::getGender() const {
    return gender;
}

void Persona::setGender(const std::string &gender) {
    Persona::gender = gender;
}

const std::string &Persona::getLocation() const {
    return location;
}

void Persona::setLocation(const std::string &location) {
    Persona::location = location;
}

const std::string &Persona::getOccupation() const {
    return occupation;
}

void Persona::setOccupation(const std::string &occupation) {
    Persona::occupation = occupation;
}

const std::string &Persona::getBackground() const {
    return background;
}

void Persona::setBackground(const std::string &background) {
    Persona::background = background;
}

const std::string &Persona::getGoals() const {
    return goals;
}

void Persona::setGoals(const std::string &goals) {
    Persona::goals = goals;
}

const std::string &Persona::getChallenges() const {
    return challenges;
}

void Persona::setChallenges(const std::string &challenges) {
    Persona::challenges = challenges;
}

const std::string &Persona::getBehavior() const {
    return behavior;
}

void Persona::setBehavior(const std::string &behavior) {
    Persona::behavior = behavior;
}

const std::string &Persona::getCommunicationStyle() const {
    return communicationStyle;
}

void Persona::setCommunicationStyle(const std::string &communicationStyle) {
    Persona::communicationStyle = communicationStyle;
}

const std::string &Persona::getTechnologyAdoption() const {
    return technologyAdoption;
}

void Persona::setTechnologyAdoption(const std::string &technologyAdoption) {
    Persona::technologyAdoption = technologyAdoption;
}

const std::string &Persona::getInfluences() const {
    return influences;
}

void Persona::setInfluences(const std::string &influences) {
    Persona::influences = influences;
}

const std::string &Persona::getInformationSources() const {
    return informationSources;
}

void Persona::setInformationSources(const std::string &informationSources) {
    Persona::informationSources = informationSources;
}

const std::string &Persona::getUserJourney() const {
    return userJourney;
}

void Persona::setUserJourney(const std::string &userJourney) {
    Persona::userJourney = userJourney;
}

const std::string &Persona::getBrandRelationship() const {
    return brandRelationship;
}

void Persona::setBrandRelationship(const std::string &brandRelationship) {
    Persona::brandRelationship = brandRelationship;
}

const std::string &Persona::getPhoto() const {
    return photo;
}

void Persona::setPhoto(const std::string &photo) {
    Persona::photo = photo;
}
