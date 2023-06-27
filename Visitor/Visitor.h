//
// Created by Fran- on 22/06/2023.
//

#ifndef TFG_VISITOR_H
#define TFG_VISITOR_H

#include "TFG/Dominio/UserCase.h"

class InformationRequirement;
class ActorUC;
class SystemObjective;
class RestrictionRequirement;
class FunctionalRequirement;
class NonFunctionalRequirement;
class Stakeholder;
class Rol_Stakeholder;
class UserCase;



class Visitor{
public:
    virtual void visit(InformationRequirement informationRequirement) = 0;
    virtual void visit(ActorUC actorUC) = 0;
    virtual void visit(SystemObjective systemObjective) = 0;
    virtual void visit(RestrictionRequirement restrictionRequirement) = 0;
    virtual void visit(FunctionalRequirement functionalRequirement) = 0;
    virtual void visit(NonFunctionalRequirement nonFunctionalRequirement) = 0;
    virtual void visit(Stakeholder stakeholder) = 0;
    virtual void visit(UserCase userCase) = 0;
    virtual void visit(Rol_Stakeholder rolStakeholder) = 0;
    virtual ~Visitor() = default;


};


#endif //TFG_VISITOR_H
