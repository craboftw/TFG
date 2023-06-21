#ifndef TFG_TRACKEABLE_H
#define TFG_TRACKEABLE_H

#include <string>
#include <set>
#include <utility>
#include <iostream>
#include <list>
#include "Fecha.h"

typedef std::string OID;


class Stakeholder; // Declaración adelantada para evitar problemas de dependencia circular


class Cambios {
private:
    std::string version;
    Fecha date;
    std::string comments;

public:
    Cambios(std::string version, const Fecha& date, std::string comments)
            : version(std::move(version)), date(date), comments(std::move(comments)) {}

};

class ListaCambios {

protected:
    std::list<Cambios> cambios;
public:
    explicit ListaCambios(std::list<Cambios> cambios = std::list<Cambios>()) : cambios(std::move(cambios)) {}

    void setChanges(std::list<Cambios> changes);
    void addChange(Cambios change);
    std::list<Cambios> getChanges() const;
};

class Trackeable {
private:
    // Constantes para los mensajes de cambio
    std::string changeName = "Nombre modificado.";
    std::string changeVersionMajor = "Versión mayor modificada.";
    std::string changeVersionMinor = "Versión menor modificada.";
    std::string changeDate = "Fecha modificada.";
    std::string changeComments = "Comentarios modificados.";
    std::string changeAuthors = "Autores modificados.";
    std::string changeChanges = "Cambios modificados.";

protected:
    OID id;
    std::string name;
    std::string versionMajor;
    std::string versionMinor;
    Fecha date_init;
    std::string comments;
    std::set<OID> authors;
    std::list<OID> tracesFrom;
    std::list<OID> tracesTo;

public:
    explicit Trackeable(std::string id):
            id(std::move(id)), name(""), versionMajor(""), versionMinor(""), date_init(Fecha()), comments(""), authors(std::set<std::string>()), tracesFrom(std::list<std::string>()), tracesTo(std::list<std::string>()) {}


    void setName(std::string objName);
    void setVersionMajor(std::string versionMaj);
    void setVersionMinor(std::string versionMin);
    void setDate(Fecha objDate);
    void setComments(std::string objComments);
    void setAuthors(std::set<std::string>& setauthors);
    void addAuthor(std::string author);
    void removeAuthor(std::string author);
    void setTracesFrom(std::list<std::string>& tracesFrom);
    void addTraceFrom(std::string traceFrom);
    void removeTraceFrom(std::string traceFrom);
    void setTracesTo(std::list<std::string>& tracesTo);
    void addTraceTo(std::string traceTo);
    void removeTraceTo(std::string traceTo);



    std::string getId() const;
    std::string getName() const;
    std::string getVersionMajor() const;
    std::string getVersionMinor() const;
    Fecha getDate() const;
    std::string getComments() const;
    std::set<std::string> getAuthors() const;
    std::list<std::string> getTracesFrom() const;
    std::list<std::string> getTracesTo() const;


};

#endif // TFG_TRACKEABLE_H
