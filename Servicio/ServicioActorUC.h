//
// Created by craboftw on 4/07/23.
//

#ifndef TFG_SERVICIOACTORUC_H
#define TFG_SERVICIOACTORUC_H
#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Generic.h"
#include "Visitor/FileJsonManager.h"
#include "ServicioTrackeable.h"

class ServicioActorUC : public ServicioTrackeable{

public:
    OID createActorUC(std::string name="");
    std::string getName(OID oid);

    std::string getPackage(OID &oid);

    OID getGeneralization(OID oid);

    void setGeneralization(OID oid, OID generalization);
    void setPackage(OID oid, std::string package);
    void setName(OID oid, std::string name);


private:
    FileJsonManager fileJsonManager;
};


#endif //TFG_SERVICIOACTORUC_H
