//
// Created by Fran- on 03/07/2023.
//

#ifndef TFG_SERVICIOGENERIC_H
#define TFG_SERVICIOGENERIC_H


#include "Dominio/Trackeable/Trackeable.h"
#include "Repository/JsonRepository.h"
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
    JsonRepository fileJsonManager;
};

class ServicioNonFunctionalRequirement : virtual public ServicioTrackeable, public ServicioPriority {
public:
    OID createNonFunctionalRequirement(std::string name="");
    std::list<std::pair<OID,std::string>> getNonFunctionalRequirements();
private:
    JsonRepository fileJsonManager;
};

class ServicioFunctionalRequirement : virtual public ServicioTrackeable, public ServicioPriority {
public:
    OID createFunctionalRequirement(std::string name="");
    std::list<std::pair<OID,std::string>> getFunctionalRequirements();
private:
    JsonRepository fileJsonManager;
};

class ServicioRestrictionRequirement : virtual public ServicioTrackeable, public ServicioPriority {
public:
    OID createRestrictionRequirement(std::string name="");
    std::list<std::pair<OID,std::string>> getRestrictionRequirements();
private:
    JsonRepository fileJsonManager;
};

class ServicioSystemObjective : virtual public ServicioTrackeable, public ServicioPriority {
public:
    OID createSystemObjective(std::string name="");
    std::list<std::pair<OID,std::string>> getSystemObjectives();
private:
    JsonRepository fileJsonManager;
};

class ServicioText : virtual public ServicioTrackeable {
public:
    OID createText(std::string name="");
    bool getIndexable(OID id);
    void setIndexable(OID id,bool indexable);
    std::list<std::pair<OID,std::string>> getTexts();
private:
    JsonRepository fileJsonManager;
};


#endif //TFG_SERVICIOGENERIC_H
