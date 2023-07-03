//
// Created by Fran- on 03/07/2023.
//

#ifndef TFG_SERVICIOORGANIZATION_H
#define TFG_SERVICIOORGANIZATION_H


#include <string>
#include "Dominio/Trackeable/Trackeable.h"
#include "Visitor/FileJsonManager.h"

class ServicioOrganization {
public:
    OID createOrganization(std::string name="");

    std::list<std::pair<OID,std::string>> getOrganizations();

private:
    FileJsonManager fileJsonManager;

    void setContactInfo(OID id, std::string _contactInfo);

    std::string getContactInfo(OID id);
};


#endif //TFG_SERVICIOORGANIZATION_H
