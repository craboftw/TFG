//
// Created by Fran- on 21/06/2023.
//

#include "Generic.h"

/*
${workspaceFolder}/**
${workspaceFolder}/Repository
${workspaceFolder}/Dominio/Trackeable
${workspaceFolder}/Dominio/Priority
${workspaceFolder}/Dominio/
*/

void FunctionalRequirement::accept(Visitor* visitor)
{

}

void ActorUC::accept(Visitor* visitor)
{
    return;
}

void NonFunctionalRequirement::accept(Visitor* visitor)
{
    
}

void RestrictionRequirement::accept(Visitor* visitor) {

}

void SystemObjective::accept(Visitor* visitor) {
    visitor->visit(*this);
}
