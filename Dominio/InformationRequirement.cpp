//
// Created by Fran- on 22/06/2023.
//

#include "InformationRequirement.h"


void InformationRequirement::accept(Visitor *visitor) {
    Trackeable::accept(visitor);
}

unsigned int InformationRequirement::getMaxSimultaneousOccurrence() const {
    return maxSimultaneousOccurrence;
}

unsigned int InformationRequirement::getAvgSimultaneousOccurrence() const {
    return avgSimultaneousOccurrence;
}

TimeQuantity InformationRequirement::getLifeMaxEstimate() const {
    return lifeMaxEstimate;
}

TimeQuantity InformationRequirement::getLifeAvgEstimate() const {
    return lifeAvgEstimate;
}

void InformationRequirement::setMaxSimultaneousOccurrence(unsigned int _maxSimultaneousOccurrence) {
    InformationRequirement::maxSimultaneousOccurrence = _maxSimultaneousOccurrence;
}

void InformationRequirement::setAvgSimultaneousOccurrence(unsigned int _avgSimultaneousOccurrence) {
    InformationRequirement::avgSimultaneousOccurrence = _avgSimultaneousOccurrence;
}

void InformationRequirement::setLifeMaxEstimate(const TimeQuantity &_lifeMaxEstimate) {
    InformationRequirement::lifeMaxEstimate = _lifeMaxEstimate;
}

void InformationRequirement::setLifeAvgEstimate(const TimeQuantity &_lifeAvgEstimate) {
    InformationRequirement::lifeAvgEstimate = _lifeAvgEstimate;
}
