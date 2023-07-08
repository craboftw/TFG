//
// Created by Fran- on 08/07/2023.
//

#include "ServicioMatrixTraces.h"

void ServicioMatrixTraces::addPrefixFrom(OID id, std::string prefix) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addPrefixFrom");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.addPrefixFrom(prefix);
    fileJsonManager.save(matrixTraces);

}

void ServicioMatrixTraces::addPrefixTo(OID id, std::string prefix) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addPrefixTo");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.addPrefixTo(prefix);
    fileJsonManager.save(matrixTraces);
}

void ServicioMatrixTraces::removePrefixFrom(OID id, std::string prefix) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removePrefixFrom");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.removePrefixFrom(prefix);
    fileJsonManager.save(matrixTraces);

}

void ServicioMatrixTraces::removePrefixTo(OID id, std::string prefix) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removePrefixTo");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.removePrefixTo(prefix);    fileJsonManager.save(matrixTraces);

}

void ServicioMatrixTraces::addTrackeable(OID id, OID idTrackeable) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addTrackeable");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.addTrackeable(idTrackeable);    fileJsonManager.save(matrixTraces);

}

void ServicioMatrixTraces::removeTrackeable(OID id, OID idTrackeable) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removeTrackeable");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.removeTrackeable(idTrackeable);    fileJsonManager.save(matrixTraces);

}

void ServicioMatrixTraces::setPrefixesTracesTo(OID id, std::set<std::string> prefixes) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setPrefixesTracesTo");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.setPrefixesTracesTo(prefixes);    fileJsonManager.save(matrixTraces);

}

void ServicioMatrixTraces::setPrefixesTracesFrom(OID id, std::set<std::string> prefixes) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setPrefixesTracesFrom");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.setPrefixesTracesFrom(prefixes);    fileJsonManager.save(matrixTraces);


}

void ServicioMatrixTraces::setTrackeables(OID id, std::set<OID> trackeables) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setTrackeables");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    matrixTraces.setTrackeables(trackeables);    fileJsonManager.save(matrixTraces);

}

std::set<OID> ServicioMatrixTraces::getTrackeablesFrom(OID id) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getTrackeablesFrom");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    return matrixTraces.getTrackeablesFrom();
}

std::set<OID> ServicioMatrixTraces::getTrackeablesTo(OID id) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getTrackeablesTo");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    return matrixTraces.getTrackeablesTo();
}

std::vector<std::vector<bool>> ServicioMatrixTraces::getMatrix(OID id) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getMatrix");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    return matrixTraces.getMatrix();
}


std::set<std::string> ServicioMatrixTraces::getPrefixesTracesTo(OID id) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getPrefixesTracesTo");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    return matrixTraces.getPrefixesTracesTo();
}

std::set<std::string> ServicioMatrixTraces::getPrefixesTracesFrom(OID id) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getPrefixesTracesFrom");
    MatrixTraces matrixTraces = fileJsonManager.loadMatrixTraces(id);
    return matrixTraces.getPrefixesTracesFrom();
}

OID ServicioMatrixTraces::createMatrixTraces(std::string name) {
/*Stakeholder stakeholder(fileJsonManager.lastStakeholder()+1);
    if (name.empty()) name = stakeholder.getId().operator std::string();
    stakeholder.setName(name);
    fileJsonManager.save(stakeholder);
    return stakeholder.getId();*/
    MatrixTraces matrixTraces(fileJsonManager.lastMatrixTraces()+1);
    if (name.empty()) name = matrixTraces.getId().operator std::string();
    matrixTraces.setName(name);
    fileJsonManager.save(matrixTraces);
    return matrixTraces.getId();
}
