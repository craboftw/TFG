//
// Created by Fran- on 24/07/2023.
//

#ifndef TFG_CLASS_H
#define TFG_CLASS_H


#include <vector>
#include "Dominio/Trackeable/Trackeable.h"

struct Invariant{
    std::string name;
    std::string description;
    std::string OCL;
    std::string comentario;};

enum typeOfSet{BAG, SEQUENCE, SIMPLE, SET, ORDEREDSET};
enum typeOfVariable{CONSTANT,VAR,DERIVED,QUERY};

struct Attribute{
    std::string name;
    OID componentClass;
    typeOfSet type;
    unsigned min;
    unsigned max;
    std::string defaultValue;
    std::string description;
    std::string comentario;
};

typedef Attribute Component;
enum specializationType1{DISJOINT,OVERLAPPING};
enum specializationType2{COMPLETE,INCOMPLETE};

class Class : public Trackeable{
private:
    std::vector<Attribute> attributes;
    std::vector<Invariant> invariants;
    std::vector<Component> components;
    bool abstract;
std::set<OID> superClasses;
specializationType1 specialization1;
specializationType2 specialization2;
inline static std::string prefix = "CL";

public:
    Class(unsigned id):Trackeable(prefix,id){};
    Class():Trackeable(){};
    static std::string getPrefixID() { return prefix; }
    bool getAbstract() const;
    void setAbstract(bool abstract);
    const std::set<OID> & getSuperClasses() const;
    void setSuperClasses(const std::set<OID> &superClasses);
    void addSuperClass(const OID &superClass);
    void removeSuperClass(const OID &superClass);
    specializationType1 getSpecialization1() const;
    void setSpecialization1(specializationType1 specialization1);
    specializationType2 getSpecialization2() const;
    void setSpecialization2(specializationType2 specialization2);
    const std::vector<Attribute> &getAttributes() const;
    void setAttributes(const std::vector<Attribute> &attributes);
    const std::vector<Invariant> &getInvariants() const;
    void setInvariants(const std::vector<Invariant> &invariants);
    const std::vector<Component> &getComponents() const;
    void setComponents(const std::vector<Component> &components);
    void addAttribute(const Attribute &attribute);
    void addInvariant(const Invariant &invariant);
    void addComponent(const Component &component);
    void addAtribute(const Attribute &attribute,unsigned int position);
    void addInvariant(const Invariant &invariant,unsigned int position);
    void addComponent(const Component &component,unsigned int position);
    void removeAttribute(unsigned int position);
    void removeInvariant(unsigned int position);
    void removeComponent(unsigned int position);


};

typedef Attribute AtributoAsociation;
typedef Invariant InvariantAsociation;

struct AsociationEnd{
    OID classID;
    std::string name;
    unsigned min;
    unsigned max;
    std::string description;
    std::string comentario;
};

class Asociation : public Trackeable{
private:
    std::vector<AsociationEnd> asociationEnds;
    std::vector<AtributoAsociation> attributes;
    std::vector<InvariantAsociation> invariants;
    inline static std::string prefix = "AS";

public:
    Asociation(unsigned id):Trackeable("AS",id){};
    Asociation():Trackeable(){};
    static std::string getPrefixID() { return prefix; }
    const std::vector<AsociationEnd> &getAsociationEnds() const;
    void setAsociationEnds(const std::vector<AsociationEnd> &asociationEnds);
    const std::vector<AtributoAsociation> &getAttributes() const;
    void setAttributes(const std::vector<AtributoAsociation> &attributes);
    const std::vector<InvariantAsociation> &getInvariants() const;
    void setInvariants(const std::vector<InvariantAsociation> &invariants);
    void addAsociationEnd(const AsociationEnd &asociationEnd);
    void addAttribute(const AtributoAsociation &attribute);
    void addInvariant(const InvariantAsociation &invariant);
    void addAsociationEnd(const AsociationEnd &asociationEnd,unsigned int position);
    void addAttribute(const AtributoAsociation &attribute,unsigned int position);
    void addInvariant(const InvariantAsociation &invariant,unsigned int position);
    void removeAsociationEnd(unsigned int position);
    void removeAttribute(unsigned int position);
    void removeInvariant(unsigned int position);

};


#endif //TFG_CLASS_H