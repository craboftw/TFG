#ifndef TFG_TRACKEABLE_H
#define TFG_TRACKEABLE_H

#include <string>
#include <set>
#include <utility>
#include <iostream>
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

    void print() const {
        std::cout << "Version: " << version << std::endl;
        std::cout << "Date: ";
        date.print();
        std::cout << "Comments: " << comments << std::endl;
    }
};

class Trackeable {
private:
    std::string changeName = "Nombre modificado.";
    std::string changeDescription = "Descripción modificada.";
    std::string changeVersionMajor = "Versión mayor modificada.";
    std::string changeVersionMinor = "Versión menor modificada.";
    std::string changeDate = "Fecha modificada.";
    std::string changeComments = "Comentarios modificados.";
    std::string changeAuthors = "Autores modificados.";
    std::string changeChanges = "Cambios modificados.";

protected:
    std::string id;
    std::string name;
    std::string description;
    std::string versionMajor;
    std::string versionMinor;
    Fecha date_init;
    std::string comments;
    std::set<Stakeholder*> authors;
    std::set<Cambios*> changes;

public:
    Trackeable(std::string oid, std::string objName, std::string objDescription,
               std::string versionMaj, std::string versionMin, const Fecha& objDate,
               std::string objComments);

    void setName(const std::string& objName);
    void setDescription(const std::string& objDescription);
    void setVersionMajor(const std::string& versionMaj);
    void setVersionMinor(const std::string& versionMin);
    void setDate(const Fecha& objDate);
    void setComments(const std::string& objComments);
    void setAuthors(std::set<Stakeholder*>& setauthors);
    void addAuthor(Stakeholder* author);
    void removeAuthor(Stakeholder* author);
    void setChanges(std::set<Cambios*>& changes);
    void addChange(Cambios* change);
    void removeChange(Cambios* change);

    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;
    std::string getVersionMajor() const;
    std::string getVersionMinor() const;
    Fecha getDate() const;
    std::string getComments() const;
    std::set<Stakeholder*> getAuthors() const;
    std::set<Cambios*> getChanges() const;

    virtual void print() const;
};

#endif // TFG_TRACKEABLE_H
