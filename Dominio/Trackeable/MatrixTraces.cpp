//
// Created by Fran- on 06/07/2023.
//

#include "MatrixTraces.h"

void MatrixTraces::addTrackeable(OID id) {
    trackeables.insert(id);
    if (prefixesTracesFrom.find(id.getPrefix()) != prefixesTracesFrom.end()) {
        OIDTracesFrom.insert(id);
        mapTracesFrom.clear();
        unsigned i = 0;
        for (auto it = OIDTracesFrom.begin(); it != OIDTracesFrom.end(); ++it) {
            mapTracesFrom.insert(std::pair<unsigned, OID>(i, *it));
            ++i;
        }
    }
    if (prefixesTracesTo.find(id.getPrefix()) != prefixesTracesTo.end()) {
        OIDTracesTo.insert(id);
        mapTracesTo.clear();
        unsigned i = 0;
        for (auto it = OIDTracesTo.begin(); it != OIDTracesTo.end(); ++it) {
            mapTracesTo.insert(std::pair<unsigned, OID>(i, *it));
            ++i;
        }
    }
    matrix.resize(OIDTracesFrom.size());
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        it->resize(OIDTracesTo.size());
    }
    //set to false all the matrix
    for (unsigned i = 0; i < matrix.size(); ++i) {
        for (unsigned j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = false;
        }
    }
        for (unsigned i = 0; i < matrix.size(); ++i) {
            OID trackeableFrom = mapTracesFrom[i];
            for (unsigned j = 0; j < matrix[i].size(); ++j) {
                OID trackeableTo = mapTracesTo[j];
                auto set= servicioTrackeable.getTracesTo(trackeableFrom);
                matrix[i][j] = std::find(set.begin(), set.end(), trackeableTo) != set.end();
            }
        }
    }


void MatrixTraces::addPrefixFrom(std::string prefix) {
    prefixesTracesFrom.insert(prefix);
    for (auto it = trackeables.begin(); it != trackeables.end(); ++it) {
        if (it->getPrefix() == prefix) {
            OIDTracesFrom.insert(*it);
            mapTracesFrom.clear();
            unsigned i = 0;
            for (auto it = OIDTracesFrom.begin(); it != OIDTracesFrom.end(); ++it) {
                mapTracesFrom.insert(std::pair<unsigned ,OID>(i,*it));
                ++i;
            }
        }
    }
    matrix.resize(OIDTracesFrom.size());
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        it->resize(OIDTracesTo.size());
    }
    for (unsigned i = 0; i < matrix.size(); ++i) {
        for (unsigned j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = std::find(servicioTrackeable.getTracesTo(mapTracesFrom[i]).begin(),
                                     servicioTrackeable.getTracesTo(mapTracesFrom[i]).end(), mapTracesTo[j]) != servicioTrackeable.getTracesTo(mapTracesFrom[i]).end();
        }
    }
}

void MatrixTraces::addPrefixTo(std::string prefix) {
    prefixesTracesTo.insert(prefix);
    for (auto it = trackeables.begin(); it != trackeables.end(); ++it) {
        if (it->getPrefix() == prefix) {
            OIDTracesTo.insert(*it);
            mapTracesTo.clear();
            unsigned i = 0;
            for (auto it = OIDTracesTo.begin(); it != OIDTracesTo.end(); ++it) {
                mapTracesTo.insert(std::pair<unsigned ,OID>(i,*it));
                ++i;
            }
        }
    }
    matrix.resize(OIDTracesFrom.size());
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        it->resize(OIDTracesTo.size());
    }
    for (unsigned i = 0; i < matrix.size(); ++i) {
        for (unsigned j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = std::find(servicioTrackeable.getTracesTo(mapTracesFrom[i]).begin(),
                                     servicioTrackeable.getTracesTo(mapTracesFrom[i]).end(), mapTracesTo[j]) != servicioTrackeable.getTracesTo(mapTracesFrom[i]).end();
        }
    }
}

void MatrixTraces::print() {
    std::cout << "    ";
    for (auto it = mapTracesTo.begin(); it != mapTracesTo.end(); ++it) {
        std::cout << it->second.operator std::string() << " ";
    }
    std::cout << std::endl;
    for (unsigned i = 0; i < matrix.size(); ++i) {
        std::cout << mapTracesFrom[i].operator std::string() << " ";
        for (unsigned j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j]) {
                std::cout << "(X) ";
            } else {
                std::cout << "(_) ";
            }
        }
        std::cout << std::endl;
    }
}

std::set<OID> MatrixTraces::getTrackeablesFrom() {
    return OIDTracesFrom;
}

std::set<OID> MatrixTraces::getTrackeablesTo() {
    return OIDTracesTo;
}

std::vector<std::vector<bool>> MatrixTraces::getMatrix() {
    return matrix;
}

std::string MatrixTraces::getPrefixID() {
    return prefixID;
}

void MatrixTraces::visit(Visitor *visitor) {
    visitor->visit(this);
}
