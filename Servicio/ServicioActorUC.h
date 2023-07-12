//
// Created by craboftw on 4/07/23.
//

#ifndef TFG_SERVICIOACTORUC_H
#define TFG_SERVICIOACTORUC_H
#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Generic.h"
#include "ServicioTrackeable.h"
#include "Repository/JsonRepository.h"

class ServicioActorUC : public ServicioTrackeable{

public:
    OID createActorUC(std::string name="");

    std::string getPackage(OID oid);

    OID getGeneralization(OID oid);

    void setGeneralization(OID oid, OID generalization);
    void setPackage(OID oid, std::string package);


};


#endif //TFG_SERVICIOACTORUC_H
