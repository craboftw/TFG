//
// Created by Fran- on 06/07/2023.
//

#include "MatrixTraces.h"
#include "Servicio/ServicioTrackeable.h"

void MatrixTraces::update()
{
    ServicioTrackeable servicioTrackeable;
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

    update();
    }

    void MatrixTraces::setTrackeables(std::set<OID> trackeables) {
        this->trackeables = trackeables;
        OIDTracesFrom.clear();
        OIDTracesTo.clear();
        for (auto it = trackeables.begin(); it != trackeables.end(); ++it) {
            if (prefixesTracesFrom.find(it->getPrefix()) != prefixesTracesFrom.end()) {
                OIDTracesFrom.insert(*it);
                mapTracesFrom.clear();
                unsigned i = 0;
                for (auto it = OIDTracesFrom.begin(); it != OIDTracesFrom.end(); ++it) {
                    mapTracesFrom.insert(std::pair<unsigned, OID>(i, *it));
                    ++i;
                }
            }
            if (prefixesTracesTo.find(it->getPrefix()) != prefixesTracesTo.end()) {
                OIDTracesTo.insert(*it);
                mapTracesTo.clear();
                unsigned i = 0;
                for (auto it = OIDTracesTo.begin(); it != OIDTracesTo.end(); ++it) {
                    mapTracesTo.insert(std::pair<unsigned, OID>(i, *it));
                    ++i;
                }
            }
        }
        update();
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

    update();
}

void MatrixTraces::addPrefixTo(std::string prefix) {
    prefixesTracesTo.insert(prefix);
    for (auto it = trackeables.begin(); it != trackeables.end(); ++it) {
        if (it->getPrefix() == prefix)
            OIDTracesTo.insert(*it);
            mapTracesTo.clear();
            unsigned i = 0;
            for (auto it = OIDTracesTo.begin(); it != OIDTracesTo.end(); ++it) {
                mapTracesTo.insert(std::pair<unsigned ,OID>(i,*it));
                ++i;
            }
        }

    update();
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

std::set<std::string> MatrixTraces::getPrefixesTracesTo() {
    return prefixesTracesTo;
}

std::set<std::string> MatrixTraces::getPrefixesTracesFrom() {
    return prefixesTracesFrom;
}

void MatrixTraces::setPrefixesTracesTo(std::set<std::string> prefixes) {
    prefixesTracesTo = prefixes;
    OIDTracesTo.clear();
    for (auto it = prefixes.begin(); it != prefixes.end(); ++it) {
        for (auto it2 = trackeables.begin(); it2 != trackeables.end(); ++it2) {
            if (it2->getPrefix() == *it)
                OIDTracesTo.insert(*it2);
            mapTracesTo.clear();
            unsigned i = 0;
            for (auto it = OIDTracesTo.begin(); it != OIDTracesTo.end(); ++it) {
                mapTracesTo.insert(std::pair<unsigned ,OID>(i,*it));
                ++i;
            }
        }
    }

    update();
}

void MatrixTraces::setPrefixesTracesFrom(std::set<std::string> prefixes) {
    prefixesTracesFrom = prefixes;
    OIDTracesFrom.clear();
    for (auto it = prefixes.begin(); it != prefixes.end(); ++it) {
        for (auto it2 = trackeables.begin(); it2 != trackeables.end(); ++it2) {
            if (it2->getPrefix() == *it)
                OIDTracesFrom.insert(*it2);
            mapTracesFrom.clear();
            unsigned i = 0;
            for (auto it = OIDTracesFrom.begin(); it != OIDTracesFrom.end(); ++it) {
                mapTracesFrom.insert(std::pair<unsigned ,OID>(i,*it));
                ++i;
            }
        }
    }

    update();
}

void MatrixTraces::removePrefixFrom(std::string prefix) {
    prefixesTracesFrom.erase(prefix);
    OIDTracesFrom.clear();
    for (auto it = prefixesTracesFrom.begin(); it != prefixesTracesFrom.end(); ++it) {
        for (auto it2 = trackeables.begin(); it2 != trackeables.end(); ++it2) {
            if (it2->getPrefix() == *it)
                OIDTracesFrom.insert(*it2);
            mapTracesFrom.clear();
            unsigned i = 0;
            for (auto it = OIDTracesFrom.begin(); it != OIDTracesFrom.end(); ++it) {
                mapTracesFrom.insert(std::pair<unsigned ,OID>(i,*it));
                ++i;
            }
        }
    }

    update();
}

void MatrixTraces::removePrefixTo(std::string prefix) {
    prefixesTracesTo.erase(prefix);
    OIDTracesTo.clear();
    for (auto it = prefixesTracesTo.begin(); it != prefixesTracesTo.end(); ++it) {
        for (auto it2 = trackeables.begin(); it2 != trackeables.end(); ++it2) {
            if (it2->getPrefix() == *it)
                OIDTracesTo.insert(*it2);
            mapTracesTo.clear();
            unsigned i = 0;
            for (auto it = OIDTracesTo.begin(); it != OIDTracesTo.end(); ++it) {
                mapTracesTo.insert(std::pair<unsigned ,OID>(i,*it));
                ++i;
            }
        }
    }

    update();
}

void MatrixTraces::removeTrackeable(OID id) {
    trackeables.erase(id);
    OIDTracesFrom.erase(id);
    OIDTracesTo.erase(id);
    mapTracesFrom.clear();
    mapTracesTo.clear();
    unsigned i = 0;
    for (auto it = OIDTracesFrom.begin(); it != OIDTracesFrom.end(); ++it) {
        mapTracesFrom.insert(std::pair<unsigned ,OID>(i,*it));
        ++i;
    }
    i = 0;
    for (auto it = OIDTracesTo.begin(); it != OIDTracesTo.end(); ++it) {
        mapTracesTo.insert(std::pair<unsigned ,OID>(i,*it));
        ++i;
    }

    update();
}
