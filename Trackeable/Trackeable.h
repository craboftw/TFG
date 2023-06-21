#ifndef TFG_TRACKEABLE_H
#define TFG_TRACKEABLE_H

#include <string>
#include <set>
#include <utility>
#include <iostream>
#include <list>
#include "Fecha.h"

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
    std::string id;
    std::string name;
    std::string versionMajor;
    std::string versionMinor;
    Fecha date_init;
    std::string comments;
    std::set<std::string> authors;
    std::list<Cambios> changes;
    std::list<std::string> tracesFrom;
    std::list<std::string> tracesTo;

public:
    Trackeable(std::string oid, std::string objName,
               std::string versionMaj, std::string versionMin, Fecha objDate,
               std::string objComments);


    void setName(std::string objName);
    void setVersionMajor(std::string versionMaj);
    void setVersionMinor(std::string versionMin);
    void setDate(Fecha objDate);
    void setComments(std::string objComments);
    void setAuthors(std::set<std::string>& setauthors);
    void addAuthor(std::string author);
    void removeAuthor(std::string author);
    void setChanges(std::list<Cambios> changes);
    void addChange(Cambios change);

    std::string getId() const;
    std::string getName() const;
    std::string getVersionMajor() const;
    std::string getVersionMinor() const;
    Fecha getDate() const;
    std::string getComments() const;
    std::set<std::string> getAuthors() const;
    std::list<Cambios> getChanges() const;

};

#endif // TFG_TRACKEABLE_H
