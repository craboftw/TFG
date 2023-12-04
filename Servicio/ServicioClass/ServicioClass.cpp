//
// Created by Fran- on 01/08/2023.
//

#include "ServicioClass.h"
#include "OID.h"

OID ServicioClass::createClass(std::string name) {
     Class cless(JsonRepository::lastClass() +1);
        if (name.empty()) name = cless.getId().operator std::string();
        cless.setName(name);
     JsonRepository::save(cless);
        return cless.getId();
}

void ServicioClass::setAbstract(OID id, bool abstract) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, setAbstract");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setAbstract");
    Class cless = JsonRepository::loadClass(id);
    cless.setAbstract(abstract);
    JsonRepository::save(cless);
}

void ServicioClass::addSuperClass(OID id, OID superClass) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, addSuperClass");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addSuperClass");
    Class cless = JsonRepository::loadClass(id);
    cless.addSuperClass(superClass);
    JsonRepository::save(cless);
}

void ServicioClass::removeSuperClass(OID id, OID superClass) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, removeSuperClass");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeSuperClass");
    Class cless = JsonRepository::loadClass(id);
    cless.removeSuperClass(superClass);
    JsonRepository::save(cless);
}

void ServicioClass::setSpecialization1(OID id, specializationType1 specialization1) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, setSpecialization1");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setSpecialization1");
    Class cless = JsonRepository::loadClass(id);
    cless.setSpecialization1(specialization1);
    JsonRepository::save(cless);
}

void ServicioClass::setSpecialization2(OID id, specializationType2 specialization2) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, setSpecialization2");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setSpecialization2");
    Class cless = JsonRepository::loadClass(id);
    cless.setSpecialization2(specialization2);
    JsonRepository::save(cless);
}

void ServicioClass::removeAttribute(OID id, unsigned int position) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, removeAttribute");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeAttribute");
    Class cless = JsonRepository::loadClass(id);
    cless.removeAttribute(position);
    JsonRepository::save(cless);
}

void ServicioClass::removeInvariant(OID id, unsigned int position) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, removeInvariant");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeInvariant");
    Class cless = JsonRepository::loadClass(id);
    cless.removeInvariant(position);
    JsonRepository::save(cless);
}

void ServicioClass::removeComponent(OID id, unsigned int position) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, removeComponent");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeComponent");
    Class cless = JsonRepository::loadClass(id);
    cless.removeComponent(position);
    JsonRepository::save(cless);
}

void ServicioClass::addAttribute(OID id, Attribute attribute) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, addAttribute");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addAttribute");
    Class cless = JsonRepository::loadClass(id);
    cless.addAttribute(attribute);
    JsonRepository::save(cless);

}

void ServicioClass::addInvariant(OID id, Invariant invariant) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, addInvariant");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addInvariant");
    Class cless = JsonRepository::loadClass(id);
    cless.addInvariant(invariant);
    JsonRepository::save(cless);
}

void ServicioClass::addComponent(OID id, Component component) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, addComponent");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addComponent");
    Class cless = JsonRepository::loadClass(id);
    cless.addComponent(component);
    JsonRepository::save(cless);
}

std::set<OID> ServicioClass::getSuperClasses(OID id) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, getSuperClasses");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getSuperClasses");
    Class cless = JsonRepository::loadClass(id);
    return cless.getSuperClasses();
}

specializationType1 ServicioClass::getSpecialization1(OID id) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, getSpecialization1");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getSpecialization1");
    Class cless = JsonRepository::loadClass(id);
    return cless.getSpecialization1();
}

specializationType2 ServicioClass::getSpecialization2(OID id) {
   if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, getSpecialization2");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getSpecialization2");
    Class cless = JsonRepository::loadClass(id);
    return cless.getSpecialization2();
}

std::vector<Attribute> ServicioClass::getAttributes(OID id) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, getAttributes");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getAttributes");
    Class cless = JsonRepository::loadClass(id);
    return cless.getAttributes();
}

std::vector<Invariant> ServicioClass::getInvariants(OID id) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, getInvariants");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getInvariants");
    Class cless = JsonRepository::loadClass(id);
    return cless.getInvariants();
}

std::vector<Component> ServicioClass::getComponents(OID id) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, getComponents");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getComponents");
    Class cless = JsonRepository::loadClass(id);
    return cless.getComponents();
}

void ServicioClass::setAttributes(OID id, std::vector<Attribute> attributes) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, setAttributes");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setAttributes");
    Class cless = JsonRepository::loadClass(id);
    cless.setAttributes(attributes);
    JsonRepository::save(cless);
}

void ServicioClass::setInvariants(OID id, std::vector<Invariant> invariants) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, setInvariants");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setInvariants");
    Class cless = JsonRepository::loadClass(id);
    cless.setInvariants(invariants);
    JsonRepository::save(cless);
}

void ServicioClass::setComponents(OID id, std::vector<Component> components) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, setComponents");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setComponents");
    Class cless = JsonRepository::loadClass(id);
    cless.setComponents(components);
    JsonRepository::save(cless);
}

void ServicioClass::setSuperClasses(OID id, std::set<OID> superClasses) {
    if (id.getPrefix() != Class::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Class, setSuperClasses");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setSuperClasses");
    Class cless = JsonRepository::loadClass(id);
    cless.setSuperClasses(superClasses);
    JsonRepository::save(cless);
}

/*OID createAsociation(std::string name);
    void addAsociationEnd(OID id, AsociationEnd asociationEnd);
    void addAttribute(OID id, AtributoAsociation attribute);
    void addInvariant(OID id, InvariantAsociation invariant);
    void removeAsociationEnd(OID id, unsigned int position);
    void removeAttribute(OID id, unsigned int position);
    void removeInvariant(OID id, unsigned int position);
    void setAsociationEnds(OID id, std::vector<AsociationEnd> asociationEnds);
    void setAttributes(OID id, std::vector<AtributoAsociation> attributes);
    void setInvariants(OID id, std::vector<InvariantAsociation> invariants);
    std::vector<AsociationEnd> getAsociationEnds(OID id);
    std::vector<AtributoAsociation> getAttributes(OID id);
    std::vector<InvariantAsociation> getInvariants(OID id);*/
//Now implement the methods of the class ServicioAsociacion exactly as you did for ServicioClass
OID ServicioAsociacion::createAsociation(std::string name) {
    Asociation asociation(JsonRepository::lastAsociation()+1);
    if (name.empty()) name = asociation.getId().operator std::string();
    asociation.setName(name);
    JsonRepository::save(asociation);
    return asociation.getId();
}

void ServicioAsociacion::addAsociationEnd(OID id, AsociationEnd asociationEnd) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, addAsociationEnd");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addAsociationEnd");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.addAsociationEnd(asociationEnd);
    JsonRepository::save(asociation);
}

void ServicioAsociacion::addAttribute(OID id, AtributoAsociation attribute) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, addAttribute");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addAttribute");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.addAttribute(attribute);
    JsonRepository::save(asociation);
}

void ServicioAsociacion::addInvariant(OID id, InvariantAsociation invariant) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, addInvariant");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addInvariant");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.addInvariant(invariant);
    JsonRepository::save(asociation);
}

void ServicioAsociacion::removeAsociationEnd(OID id, unsigned int position) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, removeAsociationEnd");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeAsociationEnd");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.removeAsociationEnd(position);
    JsonRepository::save(asociation);
}

void ServicioAsociacion::removeAttribute(OID id, unsigned int position) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, removeAttribute");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeAttribute");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.removeAttribute(position);
    JsonRepository::save(asociation);
}

void ServicioAsociacion::removeInvariant(OID id, unsigned int position) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, removeInvariant");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeInvariant");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.removeInvariant(position);
    JsonRepository::save(asociation);
}

void ServicioAsociacion::setAsociationEnds(OID id, std::vector<AsociationEnd> asociationEnds) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, setAsociationEnds");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setAsociationEnds");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.setAsociationEnds(asociationEnds);
    JsonRepository::save(asociation);
}

void ServicioAsociacion::setAttributes(OID id, std::vector<AtributoAsociation> attributes) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, setAttributes");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setAttributes");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.setAttributes(attributes);
    JsonRepository::save(asociation);
}

void ServicioAsociacion::setInvariants(OID id, std::vector<InvariantAsociation> invariants) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, setInvariants");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setInvariants");
    Asociation asociation = JsonRepository::loadAsociation(id);
    asociation.setInvariants(invariants);
    JsonRepository::save(asociation);
}

std::vector<AsociationEnd> ServicioAsociacion::getAsociationEnds(OID id) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, getAsociationEnds");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getAsociationEnds");
    Asociation asociation = JsonRepository::loadAsociation(id);
    return asociation.getAsociationEnds();
}

std::vector<AtributoAsociation> ServicioAsociacion::getAttributes(OID id) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, getAttributes");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getAttributes");
    Asociation asociation = JsonRepository::loadAsociation(id);
    return asociation.getAttributes();
}

std::vector<InvariantAsociation> ServicioAsociacion::getInvariants(OID id) {
    if (id.getPrefix() != Asociation::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Asociation, getInvariants");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getInvariants");
    Asociation asociation = JsonRepository::loadAsociation(id);
    return asociation.getInvariants();
}


