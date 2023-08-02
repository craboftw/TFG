//
// Created by craboftw on 12/07/23.
//

#include "ServicioDiagramUC.h"
#include "Repository/JsonRepository.h"
void update(UserCaseDiagram obj) {
    auto list = obj.getUserCaseList();
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (!JsonRepository::exist(*it))
        obj.removeUserCase(*it);
    }
    obj.update();
    JsonRepository::save(obj);
}


void ServicioDiagramUC::addUserCase(OID id, OID userCase) {
    if (id.getPrefix() != UserCaseDiagram::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponda un UserCaseDiagram, addUserCase");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addUserCase");
    if (userCase.getPrefix() != UserCase::getPrefixID()) throw std::invalid_argument("El usercase a añadir no corresponda un UserCase, addUserCase");
    if (!JsonRepository::exist(userCase)) throw std::invalid_argument("El usercase a añadir no existe, addUserCase");
    auto diagrama = JsonRepository::loadUserCaseDiagram(id);
    diagrama.addUserCase(userCase);
    update(diagrama);
    JsonRepository::save(diagrama);
}

void ServicioDiagramUC::removeUserCase(OID id, OID userCase) {
    if (id.getPrefix() != UserCaseDiagram::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponda un UserCaseDiagram, addUserCase");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addUserCase");
    if (userCase.getPrefix() != UserCase::getPrefixID()) throw std::invalid_argument("El usercase a eliminar no corresponda un UserCase, addUserCase");
    if (!JsonRepository::exist(userCase)) throw std::invalid_argument("El usercase a eliminar no existe, addUserCase");
    auto diagrama = JsonRepository::loadUserCaseDiagram(id);
    diagrama.removeUserCase(userCase);
    update(diagrama);
    JsonRepository::save(diagrama);
}

std::set<OID> ServicioDiagramUC::getUserCaseList(OID id) {
    if (id.getPrefix() != UserCaseDiagram::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponda un UserCaseDiagram, addUserCase");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addUserCase");
    auto diagrama = JsonRepository::loadUserCaseDiagram(id);
    return diagrama.getUserCaseList();
}

std::set<OID> ServicioDiagramUC::getActorUCList(OID id) {
    if (id.getPrefix() != UserCaseDiagram::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponda un UserCaseDiagram, addUserCase");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addUserCase");
    auto diagrama = JsonRepository::loadUserCaseDiagram(id);
    return diagrama.getActorUCList();
}

OID ServicioDiagramUC::createDiagramUC(std::string name) {
    UserCaseDiagram obj(JsonRepository::lastUserCaseDiagram() +1);
    if (name.empty()) name = obj.getId().operator std::string();
    obj.setName(name);
    JsonRepository::save(obj);
    return obj.getId();
}

