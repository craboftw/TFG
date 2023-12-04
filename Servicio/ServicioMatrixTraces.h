//
// Created by Fran- on 08/07/2023.
//

#ifndef TFG_SERVICIOMATRIXTRACES_H
#define TFG_SERVICIOMATRIXTRACES_H


#include <vector>
#include "ServicioTrackeable.h"
#include "Dominio/Trackeable/MatrixTraces.h"
#include "OID.h"


class ServicioMatrixTraces {

    /*void addPrefixFrom(std::string prefix);
    void addPrefixTo(std::string prefix);
    void removePrefixFrom(std::string prefix);
    void removePrefixTo(std::string prefix);

    void addTrackeable(OID id);
    void removeTrackeable(OID id);
    void setPrefixesTracesTo(std::set<std::string> prefixes);
    void setPrefixesTracesFrom(std::set<std::string> prefixes);
    void setTrackeables(std::set<OID> trackeables);

    std::set<OID> getTrackeablesFrom();
    std::set<OID> getTrackeablesTo();
    std::vector<std::vector<bool>> getMatrix();
    static std::string getPrefixID();
    std::set<std::string> getPrefixesTracesTo();
    std::set<std::string> getPrefixesTracesFrom();*/
public:
    OID createMatrixTraces(std::string name);
    void addPrefixFrom(OID id,std::string prefix);
    void addPrefixTo(OID id,std::string prefix);
    void removePrefixFrom(OID id,std::string prefix);
    void removePrefixTo(OID id,std::string prefix);
    static void update();

    void addTrackeable(OID id,OID idTrackeable);
    void removeTrackeable(OID id,OID idTrackeable);
    void setPrefixesTracesTo(OID id,std::set<std::string> prefixes);
    void setPrefixesTracesFrom(OID id,std::set<std::string> prefixes);
    void setTrackeables(OID id,std::set<OID> trackeables);

    std::set<OID> getTrackeablesFrom(OID id);
    std::set<OID> getTrackeablesTo(OID id);
    std::vector<std::vector<bool>> getMatrix(OID id);
    static std::string getPrefixID();
    std::set<std::string> getPrefixesTracesTo(OID id);
    std::set<std::string> getPrefixesTracesFrom(OID id);

private:
    static JsonRepository fileJsonManager;

};


#endif //TFG_SERVICIOMATRIXTRACES_H
