//
// Created by Fran- on 22/06/2023.
//

#ifndef TFG_VISITOR_H
#define TFG_VISITOR_H

#include "Dominio/UserCase.h"
#include "Dominio/Trackeable/Organization.h"
#include "Dominio/InformationRequirement.h"
#include "Dominio/Generic.h"
#include "Dominio/Trackeable/Stakeholder.h"
#include "Dominio/UserStories.h"
#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Priority/Priority.h"


class ActorUC;
class RestrictionRequirement;
class SystemObjective;
class NonFunctionalRequirement;
class FunctionalRequirement;
class UserCaseDiagram;


class Text;

class Visitor{
public:
    virtual void visit(InformationRequirement informationRequirement) = 0;
    virtual void visit(ActorUC actorUC) = 0;
    virtual void visit(SystemObjective systemObjective) = 0;
    virtual void visit(RestrictionRequirement restrictionRequirement) = 0;
    virtual void visit(FunctionalRequirement functionalRequirement) = 0;
    virtual void visit(NonFunctionalRequirement nonFunctionalRequirement) = 0;
    virtual void visit(Stakeholder stakeholder) = 0;
    virtual void visit(UserCase& userCase) = 0;
    virtual void visit(Organization organization) = 0;
    virtual void visit(Text text) = 0;
    virtual void visit(UserStories userStories) = 0;
    virtual void visit(Trackeable* trackeable) = 0;
    virtual void visit(Priority* priority) = 0;
    virtual ~Visitor() = default;


};


#endif //TFG_VISITOR_H
