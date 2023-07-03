//
// Created by Fran- on 02/07/2023.
//

#ifndef TFG_SERVICIOTRACKEABLE_H
#define TFG_SERVICIOTRACKEABLE_H


#include "Dominio/Trackeable/Trackeable.h"
#include "Visitor/FileJsonManager.h"

class ServicioTrackeable {
public:
    void setName(OID id, std::string objName);
    void setDescription(OID id, std::string objDescription);
    void setVersionMajor(OID id, std::string versionMaj);
    void setVersionMinor(OID id, std::string versionMin);
    void setDate(OID id, Fecha objDate);
    void setComments(OID id, std::string objComments);
    void setAuthors(OID id, std::set<OID>& setauthors);
    void addAuthor(OID id, OID author);
    void removeAuthor(OID id, OID author);
    void setTracesFrom(OID id, std::list<OID>& tracesFrom);
    void addTraceFrom(OID id, OID traceFrom);
    void removeTraceFrom(OID id, OID traceFrom);
    void setTracesTo(OID id, std::list<OID>& tracesTo);
    void addTraceTo(OID id, OID traceTo);
    void removeTraceTo(OID id, OID traceTo);
    void setChanges(OID id, std::list<Change> changes);
    void addChange(OID id, Change change);

    std::string getName(OID id);
    std::string getDescription(OID id);
    std::list<Change> getChanges(OID id);
    std::list<OID> getTracesFrom(OID id);
    std::list<OID> getTracesTo(OID id);
    std::set<OID> getAuthors(OID id);
    std::string getComments(OID id);
    Fecha getDate(OID id);
    std::string getVersionMinor(OID id);
    std::string getVersionMajor(OID id);



protected:
    FileJsonManager fileJsonManager;


};


#endif //TFG_SERVICIOTRACKEABLE_H
