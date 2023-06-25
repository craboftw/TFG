//
// Created by Fran- on 21/06/2023.
//

#ifndef TFG_USERCASE_H
#define TFG_USERCASE_H


#include <string>
#include <vector>
#include "Trackeable/Trackeable.h"
#include "Priority/Priority.h"

typedef std::string OID;

enum class ImportanceLevel {
    PRIMARY, SECUNDARY, OPTIONAL
};

enum class DetailQuantity {
    LOW, MEDIUM, HIGH
};


class UserCase : public Trackeable , public Priority {
    bool abstract;
    std::string objective;

    std::string description;
    std::string precondition;
    std::string postcondition;
    TimeQuantity frequency;
    std::vector<OID> steps;
    std::list<OID> actors;
    std::list <OID> objectives;


public:
    UserCase(std::string id): Trackeable(std::move(id)), abstract(false), description(""), precondition(""), postcondition("") , frequency() {}


void setAbstract(bool _abstract) {abstract = _abstract;}

void setDescription(std::string _description) {description = std::move(_description);}

void setPrecondition(std::string _precondition) {precondition = std::move(_precondition);}

void setPostcondition(std::string _postcondition) {postcondition = std::move(_postcondition);}

void addStep(OID step) {steps.push_back(step);}

void addStep(OID step, int pos) {steps.insert(steps.begin()+pos, step);}

void addActor(OID actor) {actors.push_back(actor);}

bool isAbstract() const {return abstract;}

std::string getPrecondition() const {return precondition;}

std::string getPostcondition() const {return postcondition;}

std::vector<OID> getSteps() const {return steps;}

std::list<OID> getActors() const {return actors;}
};


class Step {
    bool abstract;
    std::string description;
    std::string comments;
    TimeQuantity estimatedTime;

public:
    Step(): abstract(false), description(""), comments("") {}

    void setComments(std::string _comments) {comments = std::move(_comments);}

    std::string getComments() const {return comments;}
};

class IncludeExtend : public Step {
    OID useCase;
};



#endif //TFG_USERCASE_H
