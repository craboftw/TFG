//
// Created by Fran- on 22/06/2023.
//

#ifndef TFG_INFORMATIONREQUIREMENT_H
#define TFG_INFORMATIONREQUIREMENT_H


#include <string>
#include "Trackeable/Trackeable.h"
#include "Priority/Priority.h"

class InformationRequirement : public Trackeable , public ListaCambios , public Priority{
    std::string description;
    unsigned int maxSimultaneousOccurrence;
    unsigned int avgSimultaneousOccurrence;

public:
    InformationRequirement(OID id): Trackeable(std::move(id)), ListaCambios(), Priority(), description(""), maxSimultaneousOccurrence(0), avgSimultaneousOccurrence(0) {}

};




#endif //TFG_INFORMATIONREQUIREMENT_H
