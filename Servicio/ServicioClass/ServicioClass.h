//
// Created by Fran- on 01/08/2023.
//

#ifndef TFG_SERVICIOCLASS_H
#define TFG_SERVICIOCLASS_H


#include <string>
#include "Servicio/ServicioTrackeable.h"
#include "OID.h"

class ServicioClass : public ServicioTrackeable{
    public:
    OID createClass(std::string name);
    void setAbstract(OID id, bool abstract);
    void addSuperClass(OID id, OID superClass);
    void removeSuperClass(OID id, OID superClass);
    void setSpecialization1(OID id, specializationType1 specialization1);
    void setSpecialization2(OID id, specializationType2 specialization2);
    void removeAttribute(OID id, unsigned int position);
    void removeInvariant(OID id, unsigned int position);
    void removeComponent(OID id, unsigned int position);
    void addAttribute(OID id, Attribute attribute);
    void addInvariant(OID id, Invariant invariant);
    void addComponent(OID id, Component component);                                              
    bool getAbstract(OID id);
    std::set<OID> getSuperClasses(OID id);
    specializationType1 getSpecialization1(OID id);
    specializationType2 getSpecialization2(OID id);
    std::vector<Attribute> getAttributes(OID id);
    std::vector<Invariant> getInvariants(OID id);
    std::vector<Component> getComponents(OID id);
    void setAttributes(OID id, std::vector<Attribute> attributes);
    void setInvariants(OID id, std::vector<Invariant> invariants);
    void setComponents(OID id, std::vector<Component> components);
    void addAttribute(OID id, Attribute attribute, unsigned int position);
    void addInvariant(OID id, Invariant invariant, unsigned int position);
    void addComponent(OID id, Component component, unsigned int position);
    void setSuperClasses(OID id, std::set<OID> superClasses);

};

class ServicioAsociacion : public ServicioTrackeable
{
public:
    OID createAsociation(std::string name);
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
    std::vector<InvariantAsociation> getInvariants(OID id);

};


#endif //TFG_SERVICIOCLASS_H
