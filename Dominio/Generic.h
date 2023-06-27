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
    explicit SystemObjective(OID id) : Trackeable(prefixID+id), Priority() {}
    void accept(Visitor* visitor) override ;

private:
    inline static std::string prefixID = "SO-";
};

class RestrictionRequirement : public Trackeable, public Priority {
public:
    explicit RestrictionRequirement(OID id) : Trackeable(prefixID+id), Priority() {}
    void accept(Visitor* visitor) override ;
private:
    inline static std::string prefixID = "RR-";
};

class FunctionalRequirement : public Trackeable, public Priority {
public:
    explicit FunctionalRequirement(OID id) : Trackeable(prefixID+id), Priority() {}
    void accept(Visitor* visitor) ;
private:
    inline static std::string prefixID = "FR-";
};

class NonFunctionalRequirement : public Trackeable, public Priority {
public:
    explicit NonFunctionalRequirement(OID id) : Trackeable(prefixID+id), Priority() {}
    void accept(Visitor* visitor) override ;
private:
    inline static std::string prefixID = "NF-";
};

class ActorUC : public Trackeable {
public:
    explicit ActorUC(OID id) : Trackeable(prefixID+id) {}
    void accept(Visitor* visitor) override ;
private:
    inline static std::string prefixID = "AC-";
};

#endif //TFG_GENERIC_H
