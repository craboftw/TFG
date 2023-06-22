//
// Created by Fran- on 22/06/2023.
//

#ifndef TFG_INFORMATIONREQUIREMENT_H
#define TFG_INFORMATIONREQUIREMENT_H


#include <string>
#include "Trackeable/Trackeable.h"
#include "Priority/Priority.h"


class InformationRequirement : public Trackeable, virtual public ListaCambios, public Priority {
    unsigned int maxSimultaneousOccurrence;
    unsigned int avgSimultaneousOccurrence;
    TimeQuantity lifeMaxEstimate;
    TimeQuantity lifeAvgEstimate;

public:
    explicit InformationRequirement(OID id)
            : Trackeable(std::move(id)),
              ListaCambios(),
              Priority(),
              maxSimultaneousOccurrence(0),
              avgSimultaneousOccurrence(0),
              lifeMaxEstimate(TimeQuantity()),
              lifeAvgEstimate(TimeQuantity()) {}
};




#endif //TFG_INFORMATIONREQUIREMENT_H
