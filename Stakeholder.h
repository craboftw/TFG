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

    Rol_Stakeholder(const std::string& roleName, const std::string& roleDescription = "");
};

class Stakeholder : public Trackeable {
private:
    std::string email;
    std::string phone;
    std::string address;
    const Rol_Stakeholder* stakeholderRole;
    Organization worksForOrganization;

public:
    Stakeholder(const std::string& oid, const std::string& objName, const std::string& objDescription,
                const std::string& objVersionMajor, const std::string& objVersionMinor,
                const Fecha& objDate, const std::string& objComments, const std::string& objEmail,
                const std::string& objPhone, const std::string& objAddress,
                const Rol_Stakeholder* objStakeholderRole, const Organization& objWorksForOrganization);

    void print() const;
    void lineprint() const;
};

void pruebaStakeHolder();

#endif  // STAKEHOLDER_H
