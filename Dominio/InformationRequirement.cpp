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

std::string InformationRequirement::strMaxSimultaneousOccurrence() const {
    return "WIP";
}

std::string InformationRequirement::strAvgSimultaneousOccurrence() const {
    return "WIP";
}

std::string InformationRequirement::strLifeMaxEstimate() const {
    return "WIP";
}

std::string InformationRequirement::strLifeAvgEstimate() const {
    return "WIP";
}

std::string InformationRequirement::getPrefixID(){
    return prefixID;
}

std::list<SpecificInformation> InformationRequirement::getSpecificInformation() const {
    return specificInformation;
}

void InformationRequirement::setSpecificInformation(const std::list<SpecificInformation> &specificInformation) {
    InformationRequirement::specificInformation = specificInformation;
}

void InformationRequirement::addSpecificInformation(const std::string name, const std::string description) {
    //find last id
    unsigned int id = 0;
    for(auto it = specificInformation.begin(); it != specificInformation.end(); ++it){
        if(it->id > id){
            id = it->id;
        }
    }
    specificInformation.push_back({id+1,name,description});
}

void InformationRequirement::removeSpecificInformation(const unsigned id) {
    for(auto it = specificInformation.begin(); it != specificInformation.end(); ++it){
        if(it->id == id){
            specificInformation.erase(it);
            break;
        }
    }
}

void InformationRequirement::setSpecificInformationName(const unsigned int id, const std::string &name) {
    for(auto it = specificInformation.begin(); it != specificInformation.end(); ++it){
        if(it->id == id){
            it->name = name;
            break;
        }
    }
}

void InformationRequirement::setSpecificInformationDescription(const unsigned int id, const std::string &description) {
    for(auto it = specificInformation.begin(); it != specificInformation.end(); ++it){
        if(it->id == id){
            it->description = description;
            break;
        }
    }
}

