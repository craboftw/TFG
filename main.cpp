#include <iostream>
#include <fstream>
#include "Dominio/Generic.h"
#include "Visitor/Jsoneitor.h"
#include "Dominio/Trackeable/Stakeholder.h"
#include "nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;


Stakeholder crearStakeholder(){
    std::string id;
    std::string email;
    std::string phone;
    std::string address;
    std::string stakeholderRole;
    std::string worksForOrganization;

    std::cout << "Introduce el id del stakeholder: ";
    std::cin >> id;
    std::cout << "Introduce el email del stakeholder: ";
    std::cin >> email;
    std::cout << "Introduce el telefono del stakeholder: ";
    std::cin >> phone;
    std::cout << "Introduce la direccion del stakeholder: ";
    std::cin >> address;
    std::cout << "Introduce el rol del stakeholder: ";
    std::cin >> stakeholderRole;
    std::cout << "Introduce la organizacion del stakeholder: ";
    std::cin >> worksForOrganization;

    Stakeholder stakeholder(id);
    stakeholder.setEmail(email);
    stakeholder.setPhone(phone);
    stakeholder.setAddress(address);
    stakeholder.setStakeholderRole(stakeholderRole);
    stakeholder.setWorksForOrganization(worksForOrganization);
    stakeholder.setEmail("cambioforzado")   ;
    return stakeholder;
}

int main() {
auto stakeholder = crearStakeholder();
stakeholder.addChange(Change("0",Fecha(),"Que locura"));
stakeholder.addChange(Change("0",Fecha(),"Dos locuras"));
Jsoneitor jsoneitor;
jsoneitor.visit(stakeholder);

//input por teclado para mantener la consola abierta
std::string input;
std::cin >> input;
    return 0;

}
