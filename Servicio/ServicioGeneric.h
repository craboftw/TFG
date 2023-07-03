//
// Created by Fran- on 03/07/2023.
//

#ifndef TFG_SERVICIOGENERIC_H
#define TFG_SERVICIOGENERIC_H


#include "Dominio/Trackeable/Trackeable.h"
#include "Visitor/FileJsonManager.h"
#include "ServicioPriority.h"
#include "ServicioTrackeable.h"

class ServicioGeneric : public ServicioTrackeable{
public:
    OID createActorUC(std::string name="");

    std::string getPackage(OID id);
    OID getGeneralization(OID id);

    void setPackage(OID id,std::string _package);
    void setGeneralization(OID id,OID _generalization);
    std::list<std::pair<OID,std::string>> getActorsUC();

private:
    FileJsonManager fileJsonManager;
};

class ServicioNonFunctionalRequirement : virtual public Trackeable, public Priority {
public:
    OID createNonFunctionalRequirement(std::string name="");
    std::list<std::pair<OID,std::string>> getNonFunctionalRequirements();
private:
    FileJsonManager fileJsonManager;
};

class ServicioFunctionalRequirement : virtual public Trackeable, public Priority {
public:
    OID createFunctionalRequirement(std::string name="");
    std::list<std::pair<OID,std::string>> getFunctionalRequirements();
private:
    FileJsonManager fileJsonManager;
};

class ServicioRestrictionRequirement : virtual public Trackeable, public Priority {
public:
    OID createRestrictionRequirement(std::string name="");
    std::list<std::pair<OID,std::string>> getRestrictionRequirements();
private:
    FileJsonManager fileJsonManager;
};

class ServicioSystemObjective : virtual public Trackeable, public Priority {
public:
    OID createSystemObjective(std::string name="");
    std::list<std::pair<OID,std::string>> getSystemObjectives();
private:
    FileJsonManager fileJsonManager;
};


#endif //TFG_SERVICIOGENERIC_H
