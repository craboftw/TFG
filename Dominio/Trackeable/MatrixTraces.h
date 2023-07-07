//
// Created by Fran- on 06/07/2023.
//

#ifndef TFG_MATRIXTRACES_H
#define TFG_MATRIXTRACES_H


#include <string>
#include <list>
#include <vector>
#include <map>
#include "Trackeable.h"
#include "Servicio/ServicioTrackeable.h"

class MatrixTraces : public Trackeable {
public:
    MatrixTraces(unsigned id): Trackeable(prefixID,id), servicioTrackeable() {
        matrix.resize(0);
    }
    void addPrefixFrom(std::string prefix);
    void addPrefixTo(std::string prefix);
    void removePrefixFrom(std::string prefix);
    void removePrefixTo(std::string prefix);

    void addTrackeable(OID id);
    void removeTrackeable(OID id);
    std::set<OID> getTrackeablesFrom();
    std::set<OID> getTrackeablesTo();
    std::vector<std::vector<bool>> getMatrix();
    static std::string getPrefixID();
    void visit(Visitor* visitor);
    void print();


private:
    OID id;
    std::set<std::string> prefixesTracesTo;
    std::set<std::string> prefixesTracesFrom;
    std::set<OID> OIDTracesTo;
    std::set<OID> OIDTracesFrom;
    std::set<OID> trackeables;
    std::vector<std::vector<bool>> matrix;
    std::map<unsigned ,OID > mapTracesTo;
    std::map<unsigned ,OID > mapTracesFrom;
    ServicioTrackeable servicioTrackeable;

    inline static std::string prefixID = "MT";
};


#endif //TFG_MATRIXTRACES_H
