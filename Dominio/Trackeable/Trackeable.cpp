#include "Trackeable.h"
#include "Stakeholder.h"


void Trackeable::setName(const std::string objName) {
    this->name = objName;
}

void Trackeable::setVersionMajor(std::string versionMaj) {
    this->versionMajor = versionMaj;
}

void Trackeable::setVersionMinor(std::string versionMin) {
    this->versionMinor = versionMin;

}

void Trackeable::setDate(Fecha objDate) {
    this->date_init = objDate;
}

void Trackeable::setComments(std::string objComments) {
    this->comments = objComments;
}

void Trackeable::setAuthors(std::set<std::string>& setauthors) {
    this->authors = setauthors;
}

std::string Trackeable::getId() const {
    return this->id;
}

std::string Trackeable::getName() const {
    return this->name;
}


std::string Trackeable::getVersionMajor() const {
    return this->versionMajor;
}

std::string Trackeable::getVersionMinor() const {
    return this->versionMinor;
}

Fecha Trackeable::getDate() const {
    return this->date_init;
}

std::string Trackeable::getComments() const {
    return this->comments;
}

std::set<std::string> Trackeable::getAuthors() const {
    return this->authors;
}

void Trackeable::addAuthor(std::string author) {
    authors.insert(author);

}

void Trackeable::removeAuthor(std::string author) {
    authors.erase(author);

}


//    void setChanges(std::list<Cambios> changes);
//    void addChange(Cambios change);
//    std::list<Cambios> getChanges() const;

void ListaCambios::setChanges(std::list<Cambios> changes) {
    this->cambios = changes;
}

void ListaCambios::addChange(Cambios change) {
    cambios.emplace_back(change);
}

std::list<Cambios> ListaCambios::getChanges() const {
    return this->cambios;
}
