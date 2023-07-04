//
// Created by craboftw on 4/07/23.
//

#ifndef TFG_SERVICIOACTORUC_H
#define TFG_SERVICIOACTORUC_H
#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Generic.h"
#include "Visitor/FileJsonManager.h"

class ServicioActorUC {

public:
    std::string getName(OID oid);

    std::string getPackage(OID &oid);

    OID getGeneralization(OID oid);

private:
    FileJsonManager fileJsonManager;
};


#endif //TFG_SERVICIOACTORUC_H
