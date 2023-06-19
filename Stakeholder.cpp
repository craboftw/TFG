#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "Fecha.h"
#include "Trackeable.h"
#include "Stakeholder.h"


class Stakeholder;

class Cambios {
private:
    std::string version;
    Fecha date;
    std::string comments;

public:
    Cambios(const std::string& version, const Fecha& date, const std::string& comments)
            : version(version), date(date), comments(comments) {}

};


class Organization :public Trackeable {
private:
    std::string contactInfo;
    std::set<Stakeholder*> stakeholders;

public:
    Organization(const std::string& company, const std::string& contactInfo,
                 const std::string& description, const std::string& comments = "")
            : Trackeable("", company, description, "", "", Fecha(), comments),
              contactInfo(contactInfo) {}

    void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Contact info: " << contactInfo << std::endl;
    }
};

class Rol_Stakeholder {
public:
    static Rol_Stakeholder nulo;

    std::string name;
    std::string description;

    Rol_Stakeholder(const std::string& roleName, const std::string& roleDescription = "")
            : name(roleName), description(roleDescription) {}
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
                const Rol_Stakeholder* objStakeholderRole, const Organization& objWorksForOrganization)
            : Trackeable(oid, objName, objDescription, objVersionMajor, objVersionMinor, objDate, objComments),
              email(objEmail),
              phone(objPhone),
              address(objAddress),
              stakeholderRole(objStakeholderRole),
              worksForOrganization(objWorksForOrganization) {}


    void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Phone: " << phone << std::endl;
        std::cout << "Stakeholder role: " << stakeholderRole->name << std::endl;
        std::cout << "Works for organization: ";
        worksForOrganization.print();
    }
};

void pruebaStakeHolder() {
    // PRUEBA DE ORGANIZACION Y STAKEHOLDER
    std::cout << "PRUEBA DE ORGANIZACION" << std::endl;
    Organization org("Org", "Contact info", "Description", "Comments");
    org.print();

    std::cout << "\nPRUEBA DE STAKEHOLDER" << std::endl;
    Rol_Stakeholder stakeholderRole("Stakeholder role");
     Stakeholder stakeholder("Stakeholder", "Stakeholder", "Description", "", "", Fecha(), "Comments",
                            "Email", "Phone", "Address", &stakeholderRole, org);
    stakeholder.print();
}

int main() {
    pruebaStakeHolder();
    return 0;
}