#ifndef STAKEHOLDER_H
#define STAKEHOLDER_H

#include <string>
#include <iostream>
#include "Trackeable.h"
#include "Organization.h"

class Rol_Stakeholder {
public:
    static Rol_Stakeholder nulo;

    std::string name;
    std::string description;

    explicit Rol_Stakeholder(std::string  roleName, std::string  roleDescription = "");
};

class Stakeholder : public Trackeable {
private:
    std::string email;
    std::string phone;
    std::string address;
    const Rol_Stakeholder* stakeholderRole;
    Organization worksForOrganization;

public:
    Stakeholder(std::string oid, std::string objName, std::string objDescription,
                std::string objVersionMajor, std::string objVersionMinor,
                const Fecha& objDate, std::string objComments, std::string  objEmail,
                std::string  objPhone, std::string  objAddress,
                const Rol_Stakeholder* objStakeholderRole, Organization  objWorksForOrganization);
};

void pruebaStakeHolder();

#endif  // STAKEHOLDER_H
