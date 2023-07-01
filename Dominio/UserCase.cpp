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

void UserCase::addStep(Step step) {
    steps.push_back(step);
}

void UserCase::addStep(Step step, int pos) {
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

std::vector<Step> UserCase::getSteps() const {
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

void UserCase::setSteps(std::vector<Step> _steps) {
    steps = std::move(_steps);

}

void UserCase::setActors(std::list<OID> _actors) {
    actors = std::move(_actors);
}

std::list<OID> UserCase::getObjectives() const {
    return std::list<OID>();
}

void UserCase::addObjective(OID objective) {
    objectives.push_back(objective);
}

void UserCase::removeObjective(OID objective) {
    objectives.remove(objective);
}

void UserCase::setPackage(std::string _package) {
    package = std::move(_package);
}

std::string UserCase::getPackage() const {
    return package;
}

OID UserCase::getGeneralization() const {
    return generalization;
}

void UserCase::setGeneralization(OID _generalization) {
    generalization = _generalization;
}

std::string UserCase::getPrefixID() {
    return prefixID;
}

void UserCase::removeStep(int pos) {
    steps.erase(steps.begin() + pos);
}

bool Step::getAbstract() const {
    return abstract;
}

std::string Step::getCondition() const {
    return condition;
}

std::string Step::getComments() const {
    return comments;
}

void Step::setAbstract(bool _abstract) {
    abstract = _abstract;
}

void Step::setCondition(std::string _condition) {
    condition = std::move(_condition);
}

void Step::setComments(std::string _comments) {
    comments = std::move(_comments);
}

OID Step::getReference() const {
    return reference;
}

void Step::setDescription(std::string _description) {
    description = std::move(_description);

}

void Step::setType(Step::type _type) {
    this->stepType = _type;
}

void Step::setReference(OID _reference) {
    reference = _reference;
}

Step::type Step::getType() const {
    return stepType;
}
