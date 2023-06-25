//
// Created by Fran- on 21/06/2023.
//

#ifndef TFG_GENERIC_H
#define TFG_GENERIC_H
#include "Priority/Priority.h"
#include "Trackeable/Trackeable.h"
#include "TFG/Visitor/Visitor.h"


class Stakeholder;

typedef std::string OID;


class SystemObjective : public Trackeable , public Priority {
public:
    explicit SystemObjective(OID id) : Trackeable(std::move(id)), Priority() {}
    void accept(Visitor* visitor) override ;
};

class RestrictionRequirement : public Trackeable, public Priority {
public:
    explicit RestrictionRequirement(OID id) : Trackeable(std::move(id)), Priority() {}
    void accept(Visitor* visitor) override ;
};

class FunctionalRequirement : public Trackeable, public Priority {
public:
    explicit FunctionalRequirement(OID id) : Trackeable(std::move(id)), Priority() {}
    void accept(Visitor* visitor) ;
};

class NonFunctionalRequirement : public Trackeable, public Priority {
public:
    explicit NonFunctionalRequirement(OID id) : Trackeable(std::move(id)), Priority() {}
    void accept(Visitor* visitor) override ;
};

class ActorUC : public Trackeable {
public:
    explicit ActorUC(OID id) : Trackeable(std::move(id)) {}
    void accept(Visitor* visitor) override ;
};

#endif //TFG_GENERIC_H
