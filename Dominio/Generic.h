//
// Created by Fran- on 21/06/2023.
//

#ifndef TFG_GENERIC_H
#define TFG_GENERIC_H


#include <utility>

#include "Priority/Priority.h"
#include "Trackeable/Trackeable.h"

class Generic : public Trackeable, public Priority, public ListaCambios{
private:
    std::string description;

public:

    Generic(OID id): Trackeable(std::move(id)), Priority(), ListaCambios() {}

    void setDescription(std::string description);



};

typedef Generic SystemObjective;
typedef Generic RestrictionRequirement;
typedef Generic FunctionalRequirement;
typedef Generic NonFunctionalRequirement;

class GenericTC : public Trackeable, public ListaCambios {
private:
    std::string description;

public:
    GenericTC (OID id): Trackeable(std::move(id)), ListaCambios() {}

    void setDescription(std::string _description) {description = std::move(_description);}
    std::string getDescription() const {return description;}
};

typedef GenericTC ActorUC;


#endif //TFG_SYSTEMOBJETIVE_H
