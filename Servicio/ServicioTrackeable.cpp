//
// Created by Fran- on 02/07/2023.
//

#include "ServicioTrackeable.h"
#include "ServicioMatrixTraces.h"

void ServicioTrackeable::setName(OID id, std::string objName) {
    if(objName.empty()) throw std::invalid_argument("Nombre vacio, setName");
    if(objName.size() > 50) throw std::invalid_argument("Nombre demasiado largo, setName");
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setName");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    obj.setName(objName);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::setDescription(OID id, std::string objDescription) {
    if(objDescription.empty()) throw std::invalid_argument("Descripcion vacia, setDescription");
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setDescription");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    obj.setDescription(objDescription);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::setVersionMajor(OID id, std::string versionMaj) {
    if(versionMaj.empty()) throw std::invalid_argument("Version vacia, setVersionMajor");
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setVersionMajor");
    if(versionMaj.size() > 50) throw std::invalid_argument("Version demasiado larga, setVersionMajor" );
    auto obj =  JsonRepository::loadTrackeable(id);
    obj.setVersionMajor(versionMaj);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::setVersionMinor(OID id, std::string versionMin) {
    if(versionMin.empty()) throw std::invalid_argument("Version vacia, setVersionMinor");
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setVersionMinor");
    if(versionMin.size() > 50) throw std::invalid_argument("Version demasiado larga, setVersionMinor" );
    auto obj =  JsonRepository::loadTrackeable(id);
    obj.setVersionMinor(versionMin);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::setDate(OID id, Fecha objDate) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setDate");
    if(objDate > Fecha()) throw std::invalid_argument("Fecha invalida, setDate");
    auto obj =  JsonRepository::loadTrackeable(id);
    obj.setDate(objDate);
    JsonRepository::save(&obj);

}

void ServicioTrackeable::setComments(OID id, std::string objComments) {
    if(objComments.empty()) throw std::invalid_argument("Comentario vacio, setComments");
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setComments");
    auto obj =  JsonRepository::loadTrackeable(id);
    obj.setComments(objComments);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::setAuthors(OID id, std::set<OID> &setauthors) {
    if(!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setComments");
    for(auto it = setauthors.begin(); it != setauthors.end(); ++it){
        if(!JsonRepository::exist(*it)) throw std::invalid_argument("Uno de los id de autor no existe, setComments");
        if(it->getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("Uno de los id de autor no es de tipo Stakeholder, setComments"     );
    }
    auto obj =  JsonRepository::loadTrackeable(id);
    obj.setAuthors(setauthors);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::addAuthor(OID id, OID author) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addAuthor");
    if (!JsonRepository::exist(author)) throw std::invalid_argument("El id de autor no existe, addAuthor");
    if (author.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id de autor no es de tipo Stakeholder, addAuthor");
    auto obj = JsonRepository::loadTrackeable(id);
    obj.addAuthor(author);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::removeAuthor(OID id, OID author) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeAuthor");
    if (!JsonRepository::exist(author)) throw std::invalid_argument("El id de autor no existe, removeAuthor");
    if (author.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id de autor no es de tipo Stakeholder, removeAuthor");
    auto obj = JsonRepository::loadTrackeable(id);
    obj.removeAuthor(author);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::setTracesFrom(OID id, std::set<OID> &tracesFrom) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setTracesFrom");
    for(auto it = tracesFrom.begin(); it != tracesFrom.end(); ++it){
        if(!JsonRepository::exist(*it)) throw std::invalid_argument("Uno de los id de tracesFrom no existe, setTracesFrom");
    }
    Trackeable obj = JsonRepository::loadTrackeable(id);
    obj.setTracesFrom(tracesFrom);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::addTraceFrom(OID id, OID traceFrom) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addTraceFrom");
    if (!JsonRepository::exist(traceFrom)) throw std::invalid_argument("El id de traceFrom no existe, addTraceFrom");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    Trackeable objTraceFrom = JsonRepository::loadTrackeable(traceFrom);
    obj.addTraceFrom(traceFrom);
    objTraceFrom.addTraceTo(id);

    JsonRepository::save(&obj);
    JsonRepository::save(&objTraceFrom);
    ServicioMatrixTraces::update();
}

void ServicioTrackeable::removeTraceFrom(OID id, OID traceFrom) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeTraceFrom");
    if (!JsonRepository::exist(traceFrom)) throw std::invalid_argument("El id de traceFrom no existe, removeTraceFrom");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    Trackeable objTraceFrom = JsonRepository::loadTrackeable(traceFrom);


    obj.removeTraceFrom(traceFrom);
    objTraceFrom.removeTraceTo(id);
    JsonRepository::save(&obj);
    JsonRepository::save(&objTraceFrom);
}

void ServicioTrackeable::setTracesTo(OID id, std::set<OID> &tracesTo) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setTracesTo");
    for(auto it = tracesTo.begin(); it != tracesTo.end(); ++it){
        if(!JsonRepository::exist(*it)) throw std::invalid_argument("Uno de los id de tracesTo no existe, setTracesTo");
    }
    Trackeable obj = JsonRepository::loadTrackeable(id);
    //clear tracesTo from obj
    auto traces = obj.getTracesTo();
    for(auto it = traces.begin(); it != traces.end(); ++it){
        Trackeable objTraceTo = JsonRepository::loadTrackeable(*it);
        objTraceTo.removeTraceFrom(id);
        JsonRepository::save(&objTraceTo);
    }
    obj.setTracesTo(tracesTo);
    for (auto it = tracesTo.begin(); it != tracesTo.end(); ++it) {
        Trackeable objTraceTo = JsonRepository::loadTrackeable(*it);
        objTraceTo.addTraceFrom(id);
        JsonRepository::save(&objTraceTo);
    }
    JsonRepository::save(&obj);
}

void ServicioTrackeable::addTraceTo(OID id, OID traceTo) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addTraceTo");
    if (!JsonRepository::exist(traceTo)) throw std::invalid_argument("El id de traceTo no existe, addTraceTo");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    Trackeable objTraceTo = JsonRepository::loadTrackeable(traceTo);
    obj.addTraceTo(traceTo);
    objTraceTo.addTraceFrom(id);
    JsonRepository::save(&obj);
    JsonRepository::save(&objTraceTo);
    ServicioMatrixTraces::update();

}

void ServicioTrackeable::removeTraceTo(OID id, OID traceTo) {
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeTraceTo");
    if (!JsonRepository::exist(traceTo)) throw std::invalid_argument("El id de traceTo no existe, removeTraceTo");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    Trackeable objTraceTo = JsonRepository::loadTrackeable(traceTo);
    obj.removeTraceTo(traceTo);
    objTraceTo.removeTraceFrom(id);
    JsonRepository::save(&obj);
    JsonRepository::save(&objTraceTo);
}

void ServicioTrackeable::setChanges(OID id, std::list<Change> changes)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setChanges");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    obj.setChanges(changes);
    JsonRepository::save(&obj);
}

void ServicioTrackeable::addChange(OID id, Change change)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addChange");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    obj.addChange(change);
    JsonRepository::save(&obj);
}

std::string ServicioTrackeable::getName(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getName");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    return obj.getName();

}

std::string ServicioTrackeable::getDescription(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getDescription");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    return obj.getDescription();
}

std::string ServicioTrackeable::getVersionMajor(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getVersionMajor");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    return obj.getVersionMajor();
}

std::string ServicioTrackeable::getVersionMinor(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getVersionMinor");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    return obj.getVersionMinor();
}

Fecha ServicioTrackeable::getDate(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getDate");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    return obj.getDate();
}

std::string ServicioTrackeable::getComments(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getComments");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    return obj.getComments();
}

std::set<OID> ServicioTrackeable::getAuthors(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getAuthors");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    //test if every author exists
    std::set<OID> authors = obj.getAuthors();
    std::set<OID> authorsToReturn;
    for(auto it = authors.begin(); it != authors.end(); ++it){
        if(JsonRepository::exist(*it)) authorsToReturn.insert(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(authors.size() != authorsToReturn.size())
    {
        obj.setAuthors(authorsToReturn);
        JsonRepository::save(&obj);
    }

    return authorsToReturn;
}

std::set<OID> ServicioTrackeable::getTracesFrom(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getTracesFrom");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    //test if every traceFrom exists
    std::set<OID> tracesFrom = obj.getTracesFrom();
    std::set<OID> tracesFromToReturn;
    for(auto it = tracesFrom.begin(); it != tracesFrom.end(); ++it){
        if(!JsonRepository::exist(*it)) tracesFromToReturn.insert(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(tracesFrom.size() != tracesFromToReturn.size())
    {
        obj.setTracesFrom(tracesFromToReturn);
        JsonRepository::save(&obj);
    }
    return tracesFromToReturn;
}

std::set<OID> ServicioTrackeable::getTracesTo(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getTracesTo");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    //test if every traceTo exists
    std::set<OID> tracesTo = obj.getTracesTo();
    std::set<OID> tracesToToReturn;
    for(auto it = tracesTo.begin(); it != tracesTo.end(); ++it){
        if(JsonRepository::exist(*it)) tracesToToReturn.insert(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(tracesTo.size() != tracesToToReturn.size())
    {
        obj.setTracesTo(tracesToToReturn);
        JsonRepository::save(&obj);
    }
    return tracesToToReturn;
}

std::list<Change> ServicioTrackeable::getChanges(OID id)
{
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getChanges");
    Trackeable obj = JsonRepository::loadTrackeable(id);
    return obj.getChanges();
}


