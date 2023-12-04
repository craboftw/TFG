//
// Created by Fran- on 03/07/2023.
//

#ifndef TFG_SERVICIOORGANIZATION_H
#define TFG_SERVICIOORGANIZATION_H


#include <string>
#include "Repository/JsonRepository.h"
#include "ServicioTrackeable.h"
#include "OID.h"

class ServicioOrganization : public ServicioTrackeable{
public:
    OID createOrganization(std::string name="");
    void setContactInfo(OID id, std::string _contactInfo);
    std::string getContactInfo(OID id);

private:
    JsonRepository fileJsonManager;

};


#endif //TFG_SERVICIOORGANIZATION_H
