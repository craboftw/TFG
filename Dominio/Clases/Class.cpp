//
// Created by Fran- on 24/07/2023.
//

#include "Class.h"

bool Class::getAbstract() const {
    return abstract;
}

void Class::setAbstract(bool abstract) {
    Class::abstract = abstract;
}

const std::set<OID> & Class::getSuperClasses() const {
    return superClasses;
}

void Class::setSuperClasses(const std::set<OID> &superClass) {
    Class::superClasses = superClass;
}

specializationType1 Class::getSpecialization1() const {
    return specialization1;
}

void Class::setSpecialization1(specializationType1 specialization1) {
    Class::specialization1 = specialization1;
}

specializationType2 Class::getSpecialization2() const {
    return specialization2;
}

void Class::setSpecialization2(specializationType2 specialization2) {
    Class::specialization2 = specialization2;
}

const std::vector<Attribute> &Class::getAttributes() const {
    return attributes;
}

void Class::setAttributes(const std::vector<Attribute> &attributes) {
    Class::attributes = attributes;
}

const std::vector<Invariant> &Class::getInvariants() const {
    return invariants;
}

void Class::setInvariants(const std::vector<Invariant> &invariants) {
    Class::invariants = invariants;
}

const std::vector<Component> &Class::getComponents() const {
    return components;
}

void Class::setComponents(const std::vector<Component> &components) {
    Class::components = components;
}

void Class::addAttribute(const Attribute &attribute) {
    attributes.push_back(attribute);
}

void Class::addInvariant(const Invariant &invariant) {
    invariants.push_back(invariant);
}

void Class::addComponent(const Component &component) {
    components.push_back(component);
}

void Class::addAtribute(const Attribute &attribute, unsigned int position) {
    if (position < attributes.size()) {
        attributes.insert(attributes.begin() + position, attribute);
    } else {
        attributes.push_back(attribute);
    }
}

void Class::addInvariant(const Invariant &invariant, unsigned int position) {
     if (position < invariants.size()) {
        invariants.insert(invariants.begin() + position, invariant);
    } else {
        invariants.push_back(invariant);
     }
}

void Class::addComponent(const Component &component, unsigned int position) {
    if (position < components.size()) {
        components.insert(components.begin() + position, component);
    } else {
        components.push_back(component);
    }
}

void Class::removeAttribute(unsigned int position) {
    if (position < attributes.size()) {
        attributes.erase(attributes.begin() + position);
    }
    else
        throw std::out_of_range("Index out of range");
}

void Class::removeInvariant(unsigned int position) {
    if (position < invariants.size()) {
        invariants.erase(invariants.begin() + position);
    }
    else
        throw std::out_of_range("Index out of range");
}

void Class::removeComponent(unsigned int position) {
    if (position < components.size()) {
        components.erase(components.begin() + position);
    }
    else
        throw std::out_of_range("Index out of range");
}

void Class::addSuperClass(const OID &superClass) {
    superClasses.insert(superClass);
}

void Class::removeSuperClass(const OID &superClass) {
    superClasses.erase(superClass);
}

const std::vector<AsociationEnd> &Asociation::getAsociationEnds() const {
    return asociationEnds;
}

void Asociation::setAsociationEnds(const std::vector<AsociationEnd>& _asociationEnds) {
    asociationEnds = _asociationEnds;
}

const std::vector<AtributoAsociation> &Asociation::getAttributes() const {
    return attributes;
}

void Asociation::setAttributes(const std::vector<AtributoAsociation> &_attributes) {
    attributes = _attributes;
}

const std::vector<InvariantAsociation> &Asociation::getInvariants() const {
    return invariants;
}

void Asociation::setInvariants(const std::vector<InvariantAsociation> &_invariants) {
    invariants = _invariants;
}

void Asociation::addAsociationEnd(const AsociationEnd &asociationEnd) {
    asociationEnds.push_back(asociationEnd);
}

void Asociation::addAttribute(const AtributoAsociation &attribute) {
    attributes.push_back(attribute);
}

void Asociation::addInvariant(const InvariantAsociation &invariant) {
    invariants.push_back(invariant);
}

void Asociation::addAsociationEnd(const AsociationEnd &asociationEnd, unsigned int position) {
    asociationEnds.insert(asociationEnds.begin() + position, asociationEnd);
}

void Asociation::addAttribute(const AtributoAsociation &attribute, unsigned int position) {
    attributes.insert(attributes.begin() + position, attribute);
}

void Asociation::addInvariant(const InvariantAsociation &invariant, unsigned int position) {
    invariants.insert(invariants.begin() + position, invariant);
}

void Asociation::removeAsociationEnd(unsigned int position) {
    asociationEnds.erase(asociationEnds.begin() + position);
}

void Asociation::removeAttribute(unsigned int position) {
    attributes.erase(attributes.begin() + position);
}

void Asociation::removeInvariant(unsigned int position) {
    invariants.erase(invariants.begin() + position);
}
