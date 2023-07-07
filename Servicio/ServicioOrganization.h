//
// Created by Fran- on 03/07/2023.
//

#ifndef TFG_SERVICIOORGANIZATION_H
#define TFG_SERVICIOORGANIZATION_H


#include <string>
#include "Dominio/Trackeable/Trackeable.h"
#include "Visitor/FileJsonManager.h"
#include "ServicioTrackeable.h"

class ServicioOrganization : public ServicioTrackeable{
public:
    OID createOrganization(std::string name="");
    void setContactInfo(OID id, std::string _contactInfo);
    std::string getContactInfo(OID id);

private:
    FileJsonManager fileJsonManager;

};


#endif //TFG_SERVICIOORGANIZATION_H
