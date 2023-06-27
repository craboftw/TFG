//
// Created by Fran- on 21/06/2023.
//
#include "UserCase.h"


void UserCase::setAbstract(bool _abstract) {
    abstract = _abstract;
}

void UserCase::setPrecondition(std::string _precondition) {
    precondition = std::move(_precondition);
}

void UserCase::setPostcondition(std::string _postcondition) {
    postcondition = std::move(_postcondition);
}

void UserCase::addStep(OID step) {
    steps.push_back(step);
}

void UserCase::addStep(OID step, int pos) {
    steps.insert(steps.begin() + pos, step);
}

void UserCase::addActor(OID actor) {
    actors.push_back(actor);
}

bool UserCase::isAbstract() const {
    return abstract;
}

bool UserCase::getAbstract() const {
    return abstract;
}


std::string UserCase::getPrecondition() const {
    return precondition;
}

std::string UserCase::getPostcondition() const {
    return postcondition;
}

TimeQuantity UserCase::getFrequency() const {
    return frequency;
}

std::vector<OID> UserCase::getSteps() const {
    return steps;
}

std::list<OID> UserCase::getActors() const {
    return actors;
}

void UserCase::setObjectives(std::list<OID> _objectives)
{
    objectives = std::move(_objectives);

}

void UserCase::setFrequency(TimeQuantity _frequency) {
    frequency = _frequency;

}

void UserCase::setSteps(std::vector<OID> _steps) {
    steps = std::move(_steps);

}

void UserCase::setActors(std::list<OID> _actors) {
    actors = std::move(_actors);
}

std::list<OID> UserCase::getObjectives() const {
    return std::list<OID>();
}
