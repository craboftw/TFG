#include "Stakeholder.h"

#include <utility>

void Stakeholder::accept(Visitor visitor) {
    visitor.visitStakeholder(this);
}

