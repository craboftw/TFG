#include "Stakeholder.h"

#include <utility>

Rol_Stakeholder Rol_Stakeholder::nulo = Rol_Stakeholder("");

Rol_Stakeholder::Rol_Stakeholder(std::string  roleName, std::string  roleDescription)
        : name(std::move(roleName)), description(std::move(roleDescription)) {}

Stakeholder::Stakeholder(std::string oid, std::string objName, std::string objDescription,
                         std::string objVersionMajor, std::string objVersionMinor,
                         const Fecha& objDate, std::string objComments, std::string  objEmail,
                         std::string  objPhone, std::string  objAddress,
                         const Rol_Stakeholder* objStakeholderRole, Organization  objWorksForOrganization)
        : Trackeable(std::move(oid), std::move(objName), std::move(objVersionMajor), std::move(objVersionMinor), objDate, std::move(objComments)),
          email(std::move(objEmail)),
          phone(std::move(objPhone)),
          address(std::move(objAddress)),
          stakeholderRole(objStakeholderRole),
          worksForOrganization(std::move(objWorksForOrganization)) {}

int main() {
    return 0;
}