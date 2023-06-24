
#ifndef TFG_TRACKEABLE_H
#define TFG_TRACKEABLE_H

#include <string>
#include <set>
#include <utility>
#include <iostream>
#include <list>
#include "./Fecha.h"

class Visitor;

typedef std::string OID;

class Cambios {
private:
    std::string version;
    Fecha date;
    std::string comments;

public:
    Cambios(std::string version, const Fecha& date, std::string comments)
            : version(std::move(version)), date(date), comments(std::move(comments)) {}

};

class ListaCambios  {

protected:
    std::list<Cambios> cambios;
public:
    explicit ListaCambios(std::list<Cambios> cambios = std::list<Cambios>()) : cambios(std::move(cambios)) {}

    void setChanges(std::list<Cambios> changes);
    void addChange(Cambios change);
    std::list<Cambios> getChanges() const;
};

/*
std::string defaultVersionMajor = "";
std::string defaultVersionMinor = "";
Fecha defaultDate = Fecha();
std::string defaultComments = "";
std::set<OID> defaultAuthors = std::set<OID>();
*/

class Trackeable : public ListaCambios {
private:



    // Constantes para los mensajes de cambio
    std::string changeName = "Nombre modificado.";
    std::string changeVersionMajor = "Versión mayor modificada.";
    std::string changeVersionMinor = "Versión menor modificada.";
    std::string changeDate = "Fecha modificada.";
    std::string changeComments = "Comentarios modificados.";
    std::string addingAuthor = "Autor añadido.";
    std::string removingAuthor = "Autor eliminado.";
    std::string changeAuthors = "Autores modificados.";

protected:
    OID id;
    std::string name;
    std::string description;
    std::string versionMajor;
    std::string versionMinor;
    Fecha date_init;
    std::string comments;
    std::set<OID> authors;
    std::list<OID> tracesFrom;
    std::list<OID> tracesTo;

public:
    explicit Trackeable(std::string id):
            id(std::move(id)), name(""), versionMajor(""), versionMinor(""), date_init(Fecha()), comments(""), authors(std::set<std::string>()), tracesFrom(std::list<std::string>()), tracesTo(std::list<std::string>()),ListaCambios() {}


    void setName(std::string objName);
    void setDescription(std::string objDescription);
    void setVersionMajor(std::string versionMaj);
    void setVersionMinor(std::string versionMin);
    void setDate(Fecha objDate);
    void setComments(std::string objComments);
    void setAuthors(std::set<OID>& setauthors);
    void addAuthor(OID author);
    void removeAuthor(OID author);
    void setTracesFrom(std::list<OID>& tracesFrom);
    void addTraceFrom(OID traceFrom);
    void removeTraceFrom(OID traceFrom);
    void setTracesTo(std::list<OID>& tracesTo);
    void addTraceTo(OID traceTo);
    void removeTraceTo(OID traceTo);

     void setdefaultVersionMajor(std::string versionMajor);
     void setdefaultVersionMinor(std::string versionMinor);
     void setdefaultDate(Fecha date);
     void setdefaultAuthors(std::set<std::string>& authors);

    virtual void accept(Visitor* visitor);

    virtual ~Trackeable() = default;


     std::string defaultVersionMajor = "1";
     std::string defaultVersionMinor = "0";
     Fecha defaultDate = Fecha();
     std::set<OID> defaultAuthors = std::set<std::string>();



    OID getId() const;
    std::string getName() const;
    std::string getDescription() const;
    std::string getVersionMajor() const;
    std::string getVersionMinor() const;
    Fecha getDate() const;
    std::string getComments() const;
    std::set<OID> getAuthors() const;
    std::list<OID> getTracesFrom() const;
    std::list<OID> getTracesTo() const;


};

#endif // TFG_TRACKEABLE_H
