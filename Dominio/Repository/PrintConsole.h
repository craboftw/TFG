//
// Created by Fran- on 24/06/2023.
//

#ifndef TFG_PRINTCONSOLE_H
#define TFG_PRINTCONSOLE_H


#include "Visitor.h"

class PrintConsole : public Visitor {
    virtual void visit(InformationRequirement informationRequirement) override;
    virtual void visit(ActorUC actorUC) override;
    virtual void visit(SystemObjective systemObjective) override;
    virtual void visit(RestrictionRequirement restrictionRequirement) override;
    virtual void visit(FunctionalRequirement functionalRequirement) override;
    virtual void visit(NonFunctionalRequirement nonFunctionalRequirement) override;
    virtual void visit(Stakeholder stakeholder) override;


};


#endif //TFG_PRINTCONSOLE_H
