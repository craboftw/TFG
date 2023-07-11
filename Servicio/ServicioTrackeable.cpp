//
// Created by Fran- on 02/07/2023.
//

#include "ServicioTrackeable.h"

void ServicioTrackeable::setName(OID id, std::string objName) {
    if(objName.empty()) throw std::invalid_argument("Nombre vacio, setName");
    if(objName.size() > 50) throw std::invalid_argument("Nombre demasiado largo, setName");
    if(!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setName");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    obj.setName(objName);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::setDescription(OID id, std::string objDescription) {
    if(objDescription.empty()) throw std::invalid_argument("Descripcion vacia, setDescription");
    if(!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setDescription");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    obj.setDescription(objDescription);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::setVersionMajor(OID id, std::string versionMaj) {
    if(versionMaj.empty()) throw std::invalid_argument("Version vacia, setVersionMajor");
    if(!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setVersionMajor");
    if(versionMaj.size() > 50) throw std::invalid_argument("Version demasiado larga, setVersionMajor" );
    auto obj =  FileJsonManager::loadTrackeable(id);
    obj.setVersionMajor(versionMaj);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::setVersionMinor(OID id, std::string versionMin) {
    if(versionMin.empty()) throw std::invalid_argument("Version vacia, setVersionMinor");
    if(!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setVersionMinor");
    if(versionMin.size() > 50) throw std::invalid_argument("Version demasiado larga, setVersionMinor" );
    auto obj =  FileJsonManager::loadTrackeable(id);
    obj.setVersionMinor(versionMin);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::setDate(OID id, Fecha objDate) {
    if(!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setDate");
    if(objDate > Fecha()) throw std::invalid_argument("Fecha invalida, setDate");
    auto obj =  FileJsonManager::loadTrackeable(id);
    obj.setDate(objDate);
    FileJsonManager::save(&obj);

}

void ServicioTrackeable::setComments(OID id, std::string objComments) {
    if(objComments.empty()) throw std::invalid_argument("Comentario vacio, setComments");
    if(!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setComments");
    auto obj =  FileJsonManager::loadTrackeable(id);
    obj.setComments(objComments);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::setAuthors(OID id, std::set<OID> &setauthors) {
    if(!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setComments");
    for(auto it = setauthors.begin(); it != setauthors.end(); ++it){
        if(!FileJsonManager::exist(*it)) throw std::invalid_argument("Uno de los id de autor no existe, setComments");
        if(it->getPrefix() != "SH") throw std::invalid_argument("Uno de los id de autor no es de tipo Stakeholder, setComments"     );
    }
    auto obj =  FileJsonManager::loadTrackeable(id);
    obj.setAuthors(setauthors);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::addAuthor(OID id, OID author) {
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, addAuthor");
    if (!FileJsonManager::exist(author)) throw std::invalid_argument("El id de autor no existe, addAuthor");
    if (author.getPrefix() != "SH") throw std::invalid_argument("El id de autor no es de tipo Stakeholder, addAuthor");
    auto obj = FileJsonManager::loadTrackeable(id);
    obj.addAuthor(author);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::removeAuthor(OID id, OID author) {
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeAuthor");
    if (!FileJsonManager::exist(author)) throw std::invalid_argument("El id de autor no existe, removeAuthor");
    if (author.getPrefix() != "SH") throw std::invalid_argument("El id de autor no es de tipo Stakeholder, removeAuthor");
    auto obj = FileJsonManager::loadTrackeable(id);
    obj.removeAuthor(author);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::setTracesFrom(OID id, std::set<OID> &tracesFrom) {
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setTracesFrom");
    for(auto it = tracesFrom.begin(); it != tracesFrom.end(); ++it){
        if(!FileJsonManager::exist(*it)) throw std::invalid_argument("Uno de los id de tracesFrom no existe, setTracesFrom");
    }
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    obj.setTracesFrom(tracesFrom);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::addTraceFrom(OID id, OID traceFrom) {
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, addTraceFrom");
    if (!FileJsonManager::exist(traceFrom)) throw std::invalid_argument("El id de traceFrom no existe, addTraceFrom");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    Trackeable objTraceFrom = FileJsonManager::loadTrackeable(traceFrom);
    obj.addTraceFrom(traceFrom);
    objTraceFrom.addTraceTo(id);

    FileJsonManager::save(&obj);
    FileJsonManager::save(&objTraceFrom);
}

void ServicioTrackeable::removeTraceFrom(OID id, OID traceFrom) {
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeTraceFrom");
    if (!FileJsonManager::exist(traceFrom)) throw std::invalid_argument("El id de traceFrom no existe, removeTraceFrom");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    Trackeable objTraceFrom = FileJsonManager::loadTrackeable(traceFrom);


    obj.removeTraceFrom(traceFrom);
    objTraceFrom.removeTraceTo(id);
    FileJsonManager::save(&obj);
    FileJsonManager::save(&objTraceFrom);
}

void ServicioTrackeable::setTracesTo(OID id, std::set<OID> &tracesTo) {
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setTracesTo");
    for(auto it = tracesTo.begin(); it != tracesTo.end(); ++it){
        if(!FileJsonManager::exist(*it)) throw std::invalid_argument("Uno de los id de tracesTo no existe, setTracesTo");
    }
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    //clear tracesTo from obj
    auto traces = obj.getTracesTo();
    for(auto it = traces.begin(); it != traces.end(); ++it){
        Trackeable objTraceTo = FileJsonManager::loadTrackeable(*it);
        objTraceTo.removeTraceFrom(id);
        FileJsonManager::save(&objTraceTo);
    }
    obj.setTracesTo(tracesTo);
    for (auto it = tracesTo.begin(); it != tracesTo.end(); ++it) {
        Trackeable objTraceTo = FileJsonManager::loadTrackeable(*it);
        objTraceTo.addTraceFrom(id);
        FileJsonManager::save(&objTraceTo);
    }
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::addTraceTo(OID id, OID traceTo) {
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, addTraceTo");
    if (!FileJsonManager::exist(traceTo)) throw std::invalid_argument("El id de traceTo no existe, addTraceTo");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    Trackeable objTraceTo = FileJsonManager::loadTrackeable(traceTo);
    obj.addTraceTo(traceTo);
    objTraceTo.addTraceFrom(id);
    FileJsonManager::save(&obj);
    FileJsonManager::save(&objTraceTo);
}

void ServicioTrackeable::removeTraceTo(OID id, OID traceTo) {
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeTraceTo");
    if (!FileJsonManager::exist(traceTo)) throw std::invalid_argument("El id de traceTo no existe, removeTraceTo");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    Trackeable objTraceTo = FileJsonManager::loadTrackeable(traceTo);
    obj.removeTraceTo(traceTo);
    objTraceTo.removeTraceFrom(id);
    FileJsonManager::save(&obj);
    FileJsonManager::save(&objTraceTo);
}

void ServicioTrackeable::setChanges(OID id, std::list<Change> changes)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, setChanges");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    obj.setChanges(changes);
    FileJsonManager::save(&obj);
}

void ServicioTrackeable::addChange(OID id, Change change)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, addChange");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    obj.addChange(change);
    FileJsonManager::save(&obj);
}

std::string ServicioTrackeable::getName(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getName");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    return obj.getName();

}

std::string ServicioTrackeable::getDescription(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getDescription");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    return obj.getDescription();
}

std::string ServicioTrackeable::getVersionMajor(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getVersionMajor");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    return obj.getVersionMajor();
}

std::string ServicioTrackeable::getVersionMinor(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getVersionMinor");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    return obj.getVersionMinor();
}

Fecha ServicioTrackeable::getDate(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getDate");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    return obj.getDate();
}

std::string ServicioTrackeable::getComments(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getComments");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    return obj.getComments();
}

std::set<OID> ServicioTrackeable::getAuthors(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getAuthors");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    //test if every author exists
    std::set<OID> authors = obj.getAuthors();
    std::set<OID> authorsToReturn;
    for(auto it = authors.begin(); it != authors.end(); ++it){
        if(FileJsonManager::exist(*it)) authorsToReturn.insert(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(authors.size() != authorsToReturn.size())
    {
        obj.setAuthors(authorsToReturn);
        FileJsonManager::save(&obj);
    }

    return authorsToReturn;
}

std::set<OID> ServicioTrackeable::getTracesFrom(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getTracesFrom");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    //test if every traceFrom exists
    std::set<OID> tracesFrom = obj.getTracesFrom();
    std::set<OID> tracesFromToReturn;
    for(auto it = tracesFrom.begin(); it != tracesFrom.end(); ++it){
        if(!FileJsonManager::exist(*it)) tracesFromToReturn.insert(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(tracesFrom.size() != tracesFromToReturn.size())
    {
        obj.setTracesFrom(tracesFromToReturn);
        FileJsonManager::save(&obj);
    }
    return tracesFromToReturn;
}

std::set<OID> ServicioTrackeable::getTracesTo(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getTracesTo");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    //test if every traceTo exists
    std::set<OID> tracesTo = obj.getTracesTo();
    std::set<OID> tracesToToReturn;
    for(auto it = tracesTo.begin(); it != tracesTo.end(); ++it){
        if(FileJsonManager::exist(*it)) tracesToToReturn.insert(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(tracesTo.size() != tracesToToReturn.size())
    {
        obj.setTracesTo(tracesToToReturn);
        FileJsonManager::save(&obj);
    }
    return tracesToToReturn;
}

std::list<Change> ServicioTrackeable::getChanges(OID id)
{
    if (!FileJsonManager::exist(id)) throw std::invalid_argument("El id a modificar no existe, getChanges");
    Trackeable obj = FileJsonManager::loadTrackeable(id);
    return obj.getChanges();
}


