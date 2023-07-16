//
// Created by craboftw on 12/07/23.
//

#ifndef TFG_SERVICIODIAGRAMUC_H
#define TFG_SERVICIODIAGRAMUC_H
#include "Dominio/UserCaseDiagram.h"

class ServicioDiagramUC {
public:
    OID createDiagramUC(std::string name);
    void setElements(OID id,std::set<OID> userCaseList, std::set<OID> actorUCList);
    std::set<OID> getUserCaseList(OID id);
    std::set<OID> getActorUCList(OID id);
    void addUserCase(OID id,OID userCase);
    void removeUserCase(OID id,OID userCase);
private:

};


#endif //TFG_SERVICIODIAGRAMUC_H
