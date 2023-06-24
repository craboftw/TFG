//
// Created by Fran- on 22/06/2023.
//

#include "InformationRequirement.h"


void InformationRequirement::accept(Visitor *visitor) {
    Trackeable::accept(visitor);
}
