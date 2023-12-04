//
// Created by Fran- on 21/06/2023.
//

#include "Generic.h"

void FunctionalRequirement::accept(Visitor* visitor)
{
    visitor->visit(*this);

}

void ActorUC::accept(Visitor* visitor)
{
    visitor->visit(*this);

}

std::string ActorUC::getPackage() {
    return this->package;
}

void ActorUC::setPackage(std::string reference) {
    this->package = reference;
}

std::string ActorUC::getPrefixID() {
    return prefixID;
}

OID ActorUC::getGeneralization() const {
    return generalization;
}

void ActorUC::setGeneralization(OID generalization) {
    this->generalization = generalization;
}

void NonFunctionalRequirement::accept(Visitor* visitor)
{
    visitor->visit(*this);

}

void RestrictionRequirement::accept(Visitor* visitor) {
    visitor->visit(*this);

}

void SystemObjective::accept(Visitor* visitor) {
    visitor->visit(*this);
}

std::string SystemObjective::getPrefixID() {
    return prefixID;
}

std::string RestrictionRequirement::getPrefixID() {
    return prefixID;
}

std::string FunctionalRequirement::getPrefixID() {
    return prefixID;
}

std::string NonFunctionalRequirement::getPrefixID() {
    return prefixID;
}

std::string Step::getDescription() const {
    return description;
}

void Text::accept(Visitor *visitor) {
    visitor->visit(*this);
}

