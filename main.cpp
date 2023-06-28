#include <iostream>
#include <fstream>
#include "TFG/Dominio/Generic.h"
#include "TFG/Visitor/Jsoneitor.h"
#include "TFG/Dominio/Trackeable/Stakeholder.h"
#include "TFG/nlohmann/json.hpp"

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
    stakeholder.setEmail("cambioforzado")   ;00

    return stakeholder;
}

int main() {
auto stakeholder = crearStakeholder();
Jsoneitor jsoneitor;
jsoneitor.visit(stakeholder);

//input por teclado para mantener la consola abierta
std::string input;
std::cin >> input;
    return 0;

}
