//
// Created by Fran- on 02/07/2023.
//

#include "ServicioTrackeable.h"

void ServicioTrackeable::setName(OID id, std::string objName) {
    if(objName.empty()) throw std::invalid_argument("Nombre vacio, setName");
    if(objName.size() > 50) throw std::invalid_argument("Nombre demasiado largo, setName");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setName");
    Trackeable* obj = fileJsonManager.loadTrackeable(id);
    obj->setName(objName);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setDescription(OID id, std::string objDescription) {
    if(objDescription.empty()) throw std::invalid_argument("Descripcion vacia, setDescription");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setDescription");
    Trackeable* obj = fileJsonManager.loadTrackeable(id);
    obj->setDescription(objDescription);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setVersionMajor(OID id, std::string versionMaj) {
    if(versionMaj.empty()) throw std::invalid_argument("Version vacia, setVersionMajor");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setVersionMajor");
    if(versionMaj.size() > 50) throw std::invalid_argument("Version demasiado larga, setVersionMajor" );
    Trackeable* obj = fileJsonManager.loadTrackeable(id);
    obj->setVersionMajor(versionMaj);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setVersionMinor(OID id, std::string versionMin) {
    if(versionMin.empty()) throw std::invalid_argument("Version vacia, setVersionMinor");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setVersionMinor");
    if(versionMin.size() > 50) throw std::invalid_argument("Version demasiado larga, setVersionMinor" );
    Trackeable* obj = fileJsonManager.loadTrackeable(id);
    obj->setVersionMinor(versionMin);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setDate(OID id, Fecha objDate) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setDate");
    if(objDate > Fecha()) throw std::invalid_argument("Fecha invalida, setDate");
    Trackeable* obj = fileJsonManager.loadTrackeable(id);
    obj->setDate(objDate);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setComments(OID id, std::string objComments) {
    if(objComments.empty()) throw std::invalid_argument("Comentario vacio, setComments");
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setComments");
    Trackeable* obj = fileJsonManager.loadTrackeable(id);
    obj->setComments(objComments);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setAuthors(OID id, std::set<OID> &setauthors) {
    if(!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setComments");
    for(auto it = setauthors.begin(); it != setauthors.end(); ++it){
        if(!fileJsonManager.exist(*it)) throw std::invalid_argument("Uno de los id de autor no existe, setComments");
        if(it->getPrefix() != "SH") throw std::invalid_argument("Uno de los id de autor no es de tipo Stakeholder, setComments"     );
    }
    Trackeable* obj = fileJsonManager.loadTrackeable(id);
    obj->setAuthors(setauthors);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::addAuthor(OID id, OID author) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addAuthor");
    if (!fileJsonManager.exist(author)) throw std::invalid_argument("El id de autor no existe, addAuthor");
    if (author.getPrefix() != "SH") throw std::invalid_argument("El id de autor no es de tipo Stakeholder, addAuthor");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->addAuthor(author);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::removeAuthor(OID id, OID author) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removeAuthor");
    if (!fileJsonManager.exist(author)) throw std::invalid_argument("El id de autor no existe, removeAuthor");
    if (author.getPrefix() != "SH") throw std::invalid_argument("El id de autor no es de tipo Stakeholder, removeAuthor");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->removeAuthor(author);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setTracesFrom(OID id, std::list<OID> &tracesFrom) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setTracesFrom");
    for(auto it = tracesFrom.begin(); it != tracesFrom.end(); ++it){
        if(!fileJsonManager.exist(*it)) throw std::invalid_argument("Uno de los id de tracesFrom no existe, setTracesFrom");
    }
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->setTracesFrom(tracesFrom);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::addTraceFrom(OID id, OID traceFrom) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addTraceFrom");
    if (!fileJsonManager.exist(traceFrom)) throw std::invalid_argument("El id de traceFrom no existe, addTraceFrom");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->addTraceFrom(traceFrom);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::removeTraceFrom(OID id, OID traceFrom) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removeTraceFrom");
    if (!fileJsonManager.exist(traceFrom)) throw std::invalid_argument("El id de traceFrom no existe, removeTraceFrom");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->removeTraceFrom(traceFrom);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setTracesTo(OID id, std::list<OID> &tracesTo) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setTracesTo");
    for(auto it = tracesTo.begin(); it != tracesTo.end(); ++it){
        if(!fileJsonManager.exist(*it)) throw std::invalid_argument("Uno de los id de tracesTo no existe, setTracesTo");
    }
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->setTracesTo(tracesTo);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::addTraceTo(OID id, OID traceTo) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addTraceTo");
    if (!fileJsonManager.exist(traceTo)) throw std::invalid_argument("El id de traceTo no existe, addTraceTo");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->addTraceTo(traceTo);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::removeTraceTo(OID id, OID traceTo) {
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removeTraceTo");
    if (!fileJsonManager.exist(traceTo)) throw std::invalid_argument("El id de traceTo no existe, removeTraceTo");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->removeTraceTo(traceTo);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::setChanges(OID id, std::list<Change> changes)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setChanges");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->setChanges(changes);
    fileJsonManager.save(obj);
}

void ServicioTrackeable::addChange(OID id, Change change)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addChange");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    obj->addChange(change);
    fileJsonManager.save(obj);
}

std::string ServicioTrackeable::getName(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getName");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    return obj->getName();

}

std::string ServicioTrackeable::getDescription(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getDescription");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    return obj->getDescription();
}

std::string ServicioTrackeable::getVersionMajor(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getVersionMajor");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    return obj->getVersionMajor();
}

std::string ServicioTrackeable::getVersionMinor(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getVersionMinor");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    return obj->getVersionMinor();
}

Fecha ServicioTrackeable::getDate(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getDate");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    return obj->getDate();
}

std::string ServicioTrackeable::getComments(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getComments");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    return obj->getComments();
}

std::set<OID> ServicioTrackeable::getAuthors(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getAuthors");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    //test if every author exists
    std::set<OID> authors = obj->getAuthors();
    std::set<OID> authorsToReturn;
    for(auto it = authors.begin(); it != authors.end(); ++it){
        if(!fileJsonManager.exist(*it)) authorsToReturn.insert(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(authors.size() != authorsToReturn.size())
    {
        obj->setAuthors(authorsToReturn);
        fileJsonManager.save(obj);
    }
    return authorsToReturn;
}

std::list<OID> ServicioTrackeable::getTracesFrom(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getTracesFrom");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    //test if every traceFrom exists
    std::list<OID> tracesFrom = obj->getTracesFrom();
    std::list<OID> tracesFromToReturn;
    for(auto it = tracesFrom.begin(); it != tracesFrom.end(); ++it){
        if(!fileJsonManager.exist(*it)) tracesFromToReturn.push_back(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(tracesFrom.size() != tracesFromToReturn.size())
    {
        obj->setTracesFrom(tracesFromToReturn);
        fileJsonManager.save(obj);
    }
    return tracesFromToReturn;
}

std::list<OID> ServicioTrackeable::getTracesTo(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getTracesTo");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    //test if every traceTo exists
    std::list<OID> tracesTo = obj->getTracesTo();
    std::list<OID> tracesToToReturn;
    for(auto it = tracesTo.begin(); it != tracesTo.end(); ++it){
        if(!fileJsonManager.exist(*it)) tracesToToReturn.push_back(*it);
    }
    //si tienen distinto tamaño es porque alguno no existe
    if(tracesTo.size() != tracesToToReturn.size())
    {
        obj->setTracesTo(tracesToToReturn);
        fileJsonManager.save(obj);
    }
    return tracesToToReturn;
}

std::list<Change> ServicioTrackeable::getChanges(OID id)
{
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getChanges");
    Trackeable *obj = fileJsonManager.loadTrackeable(id);
    return obj->getChanges();
}


