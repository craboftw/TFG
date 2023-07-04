//
// Created by Fran- on 29/06/2023.
//

#ifndef TFG_DIAGRAMMANAGER_H
#define TFG_DIAGRAMMANAGER_H


#include "Visitor.h"
#include "Servicio/ServicioActorUC.h"
#include "Servicio/ServicioUserCase.h"

class DiagramManager {

public:

    void visit(std::list<OID> userCaseList, std::list<OID> actorUCList);

private:
    ServicioActorUC servicioActorUC;
    ServicioUserCase servicioUserCase;
};



#endif //TFG_DIAGRAMMANAGER_H
