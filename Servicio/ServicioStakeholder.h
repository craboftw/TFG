//
// Created by Fran- on 03/07/2023.
//

#ifndef TFG_SERVICIOSTAKEHOLDER_H
#define TFG_SERVICIOSTAKEHOLDER_H


#include "Visitor/FileJsonManager.h"
#include "ServicioTrackeable.h"

class ServicioStakeholder : public ServicioTrackeable{
public:
    OID createStakeholder(std::string name="");
    void setEmail(OID id,std::string _email);
    void setPhone(OID id,std::string _phone);
    void setAddress(OID id,std::string _address);
    void setStakeholderRole(OID id,std::string _stakeholderRole);
    void setWorksForOrganization(OID id,OID _worksForOrganization);

    std::string getEmail(OID id);
    std::string getPhone(OID id);
    std::string getAddress(OID id);
    std::string getStakeholderRole(OID id);
    OID getWorksForOrganization(OID id);

std::list<std::pair<OID,std::string>> getStakeholders();
private:
FileJsonManager fileJsonManager;
};


#endif //TFG_SERVICIOSTAKEHOLDER_H
