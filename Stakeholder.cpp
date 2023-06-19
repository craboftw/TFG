#include "Stakeholder.h"

Rol_Stakeholder Rol_Stakeholder::nulo = Rol_Stakeholder("");

Rol_Stakeholder::Rol_Stakeholder(const std::string& roleName, const std::string& roleDescription)
        : name(roleName), description(roleDescription) {}

Stakeholder::Stakeholder(const std::string& oid, const std::string& objName, const std::string& objDescription,
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

void Stakeholder::print() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Stakeholder role: " << stakeholderRole->name << std::endl;
    std::cout << "Works for organization: ";
    worksForOrganization.print();
    Trackeable::print();
}

void Stakeholder::lineprint() const {
    std::cout << name << " " << email << " " << phone << " " << stakeholderRole->name << " ";
}
