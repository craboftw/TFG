//
// Created by Fran- on 21/06/2023.
//

#ifndef TFG_GENERIC_H
#define TFG_GENERIC_H

#include "Dominio/Priority/Priority.h"
#include "Dominio/Trackeable/Trackeable.h"
#include "Visitor/Visitor.h"


class Stakeholder;


class SystemObjective : virtual public Trackeable , public Priority {
public:
    explicit SystemObjective(unsigned id) : Trackeable(prefixID,id), Priority() {}
    void accept(Visitor* visitor) override ;
    static std::string getPrefixID();

private:
    inline static std::string prefixID = "SO";
};

class RestrictionRequirement : virtual public Trackeable, public Priority {
public:
    explicit RestrictionRequirement(unsigned id) : Trackeable(prefixID,id), Priority() {}
    void accept(Visitor* visitor) override ;
    static std::string getPrefixID();

private:
    inline static std::string prefixID = "RR";
};

class FunctionalRequirement : virtual public Trackeable, public Priority {
public:
    explicit FunctionalRequirement(unsigned id) : Trackeable(prefixID,id), Priority() {}
    void accept(Visitor* visitor) ;
    static std::string getPrefixID();

private:
    inline static std::string prefixID = "FR";
};

class NonFunctionalRequirement : virtual public Trackeable, public Priority {
public:
    explicit NonFunctionalRequirement(unsigned id) : Trackeable(prefixID,id), Priority() {}
    void accept(Visitor* visitor) override ;
    static std::string getPrefixID();

private:
    inline static std::string prefixID = "NF";
};

class Text : virtual public Trackeable {
    public:
    explicit Text(unsigned id) : Trackeable(prefixID,id) {}
    void accept(Visitor* visitor) override ;
    static std::string getPrefixID() {return prefixID;}

private:
    inline static std::string prefixID = "TX";
};

class ActorUC : public Trackeable {
public:
    explicit ActorUC(unsigned id) : Trackeable(prefixID,id), package("") {}
    void accept(Visitor* visitor) override ;

    std::string getPackage();
    OID getGeneralization() const;
    static std::string getPrefixID();

    void setPackage(std::string reference);
    void setGeneralization(OID generalization);


private:
    inline static std::string prefixID = "AC";
    OID generalization;
    std::string package;
};

#endif //TFG_GENERIC_H
