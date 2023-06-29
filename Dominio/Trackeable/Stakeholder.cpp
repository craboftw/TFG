#include "Stakeholder.h"

void Stakeholder::accept(Visitor* visitor) {
    visitor->visit(*this);
}

