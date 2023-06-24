//
// Created by Fran- on 22/06/2023.
//

#ifndef TFG_INFORMATION_REQUIREMENT_H
#define TFG_INFORMATION_REQUIREMENT_H

#include "./Trackeable/Trackeable.h"
#include "Priority/Priority.h"
#include <string>
class TimeQuantity;
class Visitor;
class Priority;


typedef std::string OID;

//En la siguiente linea se haya un error: "expected class-name before ',' token"
//La solucion es incluir la clase Priority.h en este archivo
class InformationRequirement : public Trackeable , public Priority {
    unsigned int maxSimultaneousOccurrence;
    unsigned int avgSimultaneousOccurrence;
    TimeQuantity lifeMaxEstimate;
    TimeQuantity lifeAvgEstimate;

public:
    explicit InformationRequirement(OID id)
            : Trackeable(std::move(id)),
              Priority(),
              maxSimultaneousOccurrence(0),
              avgSimultaneousOccurrence(0),
              lifeMaxEstimate(TimeQuantity()),
              lifeAvgEstimate(TimeQuantity()) {}
    void accept(Visitor* visitor) override ;
};




#endif //TFG_INFORMATION_REQUIREMENT_H
