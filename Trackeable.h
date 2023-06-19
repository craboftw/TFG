//
// Created by craboftw on 19/06/23.
//

#ifndef TFG_TRACKEABLE_H
#define TFG_TRACKEABLE_H

#include <string>
#include <set>
#include <utility>
#include "Fecha.h"
#include "Stakeholder.h"


class Cambios {
private:
    std::string version;
    Fecha date;
    std::string comments;

public:
    Cambios(std::string  version, const Fecha& date, std::string  comments)
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
    std::set<Stakeholder *> authors;
    std::set <Cambios *> changes;

public:
    Trackeable (std::string oid, std::string objName, std::string objDescription,
                std::string versionMaj, std::string versionMin, const Fecha &objDate,
                std::string objComments)
            : id(std::move(oid)),
              name(std::move(objName)),
              description(std::move(objDescription)),
              versionMajor(std::move(versionMaj)),
              versionMinor(std::move(versionMin)),
              date_init(objDate),
              comments(std::move(objComments)) {}

    //༺♥༻❀SETTERS❀༺♥༻

    void setName (const std::string &objName) {changes.insert(new Cambios(changeName + this->name + "->" + objName , Fecha(), objName));this->name = objName; }
    void setDescription (const std::string &objDescription) {this->description = objDescription; }
    void setVersionMajor (const std::string &versionMaj) {this->versionMajor = versionMaj; }
    void setVersionMinor (const std::string &versionMin) {this->versionMinor = versionMin; }
    void setDate (const Fecha &objDate) {this->date_init = objDate;}
    void setComments (const std::string &objComments) {this->comments = objComments;}
    //Authors
    void setAuthors (std::set<Stakeholder *> &authors) {this->authors = authors;}
    void addAuthor (Stakeholder *author) {this->authors.insert(author);}
    void removeAuthor (Stakeholder *author) {this->authors.erase(author);}
    //Changes
    void setChanges (std::set<Cambios*> &changes) { this->changes = changes; }
    void addChange (Cambios* change) {this->changes.insert(change); }
    void removeChange (Cambios* change) { this->changes.erase(change);}

    //༺♥༻❀GETTERS❀༺♥༻
    std::string getId () const { return this->id;}
    std::string getName () const { return this->name;}
    std::string getDescription () const { return this->description;}
    std::string getVersionMajor () const { return this->versionMajor;}
    std::string getVersionMinor () const { return this->versionMinor;}
    Fecha getDate () const { return this->date_init;}
    std::string getComments () const { return this->comments; }
    std::set<Stakeholder *> getAuthors () const { return this->authors;}
    std::set <Cambios*> getChanges () const { return this->changes;}

    //༺♥༻❀OTHERS❀༺♥༻
    void print () const;
};

#endif //TFG_TRACKEABLE_H
