//
// Created by Fran- on 08/07/2023.
//

#include "ServicioMatrixTraces.h"

void ServicioMatrixTraces::addPrefixFrom(OID id, std::string prefix) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addPrefixFrom");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.addPrefixFrom(prefix);
    JsonRepository::save(matrixTraces);

}

void ServicioMatrixTraces::addPrefixTo(OID id, std::string prefix) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addPrefixTo");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.addPrefixTo(prefix);
    JsonRepository::save(matrixTraces);
}

void ServicioMatrixTraces::removePrefixFrom(OID id, std::string prefix) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removePrefixFrom");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.removePrefixFrom(prefix);
    JsonRepository::save(matrixTraces);

}

void ServicioMatrixTraces::removePrefixTo(OID id, std::string prefix) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removePrefixTo");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.removePrefixTo(prefix);    JsonRepository::save(matrixTraces);

}

void ServicioMatrixTraces::addTrackeable(OID id, OID idTrackeable) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addTrackeable");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.addTrackeable(idTrackeable);    JsonRepository::save(matrixTraces);
    JsonRepository::save(matrixTraces);
}

void ServicioMatrixTraces::removeTrackeable(OID id, OID idTrackeable) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeTrackeable");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.removeTrackeable(idTrackeable);    JsonRepository::save(matrixTraces);
    JsonRepository::save(matrixTraces);

}

void ServicioMatrixTraces::setPrefixesTracesTo(OID id, std::set<std::string> prefixes) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setPrefixesTracesTo");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.setPrefixesTracesTo(prefixes);    JsonRepository::save(matrixTraces);
    JsonRepository::save(matrixTraces);

}

void ServicioMatrixTraces::setPrefixesTracesFrom(OID id, std::set<std::string> prefixes) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setPrefixesTracesFrom");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.setPrefixesTracesFrom(prefixes);    JsonRepository::save(matrixTraces);
    JsonRepository::save(matrixTraces);


}

void ServicioMatrixTraces::setTrackeables(OID id, std::set<OID> trackeables) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setTrackeables");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    matrixTraces.setTrackeables(trackeables);    JsonRepository::save(matrixTraces);
    JsonRepository::save(matrixTraces);

}

std::set<OID> ServicioMatrixTraces::getTrackeablesFrom(OID id) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getTrackeablesFrom");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    return matrixTraces.getTrackeablesFrom();
}

std::set<OID> ServicioMatrixTraces::getTrackeablesTo(OID id) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getTrackeablesTo");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    return matrixTraces.getTrackeablesTo();
}

std::vector<std::vector<bool>> ServicioMatrixTraces::getMatrix(OID id) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getMatrix");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    return matrixTraces.getMatrix();
}


std::set<std::string> ServicioMatrixTraces::getPrefixesTracesTo(OID id) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getPrefixesTracesTo");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    return matrixTraces.getPrefixesTracesTo();
}

std::set<std::string> ServicioMatrixTraces::getPrefixesTracesFrom(OID id) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getPrefixesTracesFrom");
    MatrixTraces matrixTraces = JsonRepository::loadMatrixTraces(id);
    return matrixTraces.getPrefixesTracesFrom();
}

OID ServicioMatrixTraces::createMatrixTraces(std::string name) {
/*Stakeholder stakeholder(FileJsonManager::lastStakeholder()+1);
    if (name.empty()) name = stakeholder.getId().operator std::string();
    stakeholder.setName(name);
    FileJsonManager::save(stakeholder);
    return stakeholder.getId();*/
    MatrixTraces matrixTraces(JsonRepository::lastMatrixTraces() + 1);
    if (name.empty()) name = matrixTraces.getId().operator std::string();
    matrixTraces.setName(name);
    JsonRepository::save(matrixTraces);
    return matrixTraces.getId();
}

void ServicioMatrixTraces::update() {
    auto matrices = JsonRepository::loadAllMatrixTraces();
    for (auto &matrix : matrices) {
        matrix.update();
        JsonRepository::save(matrix);
    }
}
