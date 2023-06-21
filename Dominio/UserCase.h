//
// Created by Fran- on 21/06/2023.
//

#ifndef TFG_USERCASE_H
#define TFG_USERCASE_H


#include <string>
#include <vector>
#include "Trackeable/Trackeable.h"
#include "Priority/Priority.h"

class TimeQuantity{
    enum Unit {MONTH, YEAR};

    unsigned quantity;
    Unit unit;

public: TimeQuantity() : quantity(0), unit(MONTH) {}
    TimeQuantity(unsigned _quantity, Unit _unit) : quantity(_quantity), unit(_unit) {}

    unsigned getQuantity() const {return quantity;}
    Unit getUnit() const {return unit;}

    void setQuantity(unsigned _quantity) {quantity = _quantity;}
    void setUnit(Unit _unit) {unit = _unit;}
};



class UserCase : public Trackeable , public ListaCambios , public Priority{
    bool abstract;
    std::string description;
    std::string precondition;
    std::string postcondition;
    TimeQuantity estimatedTime;
    std::vector<OID> steps;
    std::list<OID> actors;

public:
    UserCase(std::string id): Trackeable(std::move(id)), abstract(false), description(""), precondition(""), postcondition("") , estimatedTime() {}


void setAbstract(bool _abstract) {abstract = _abstract;}

void setDescription(std::string _description) {description = std::move(_description);}

void setName(std::string _name) {name = std::move(_name);}

void setPrecondition(std::string _precondition) {precondition = std::move(_precondition);}

void setPostcondition(std::string _postcondition) {postcondition = std::move(_postcondition);}

void addStep(OID step) {steps.push_back(step);}

void addStep(OID step, int pos) {steps.insert(steps.begin()+pos, step);}

void addActor(OID actor) {actors.push_back(actor);}

bool isAbstract() const {return abstract;}

std::string getDescription() const {return description;}

std::string getName() const {return name;}

std::string getPrecondition() const {return precondition;}

std::string getPostcondition() const {return postcondition;}

std::vector<OID> getSteps() const {return steps;}

std::list<OID> getActors() const {return actors;}
};


class Step : public Trackeable , public ListaCambios , public Priority{
    std::string description;
    std::string comments;
};

class IncludeExtend : public Step{
    OID useCase;
};



#endif //TFG_USERCASE_H
