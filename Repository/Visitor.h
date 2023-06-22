//
// Created by Fran- on 22/06/2023.
//

#ifndef TFG_REPOSITORYVISITOR_H
#define TFG_REPOSITORYVISITOR_H


#include "../Dominio/Generic.h"
#include "../Dominio/InformationRequirement.h"
#include "../Dominio/Trackeable/Trackeable.h"

class Visitor {
public:
    virtual void visit(InformationRequirement* informationRequirement) = 0;
    virtual void visit(ActorUC* actorUC) = 0;
    virtual void visit(SystemObjective* systemObjective) = 0;
    virtual void visit(RestrictionRequirement* restrictionRequirement) = 0;
    virtual void visit(FunctionalRequirement* functionalRequirement) = 0;
    virtual void visit(NonFunctionalRequirement* nonFunctionalRequirement) = 0;

};


#endif //TFG_REPOSITORYVISITOR_H
