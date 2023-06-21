#include "Trackeable.h"
#include "Stakeholder.h"

Trackeable::Trackeable(std::string oid, std::string objName = "",
                       std::string versionMaj = "", std::string versionMin = "",
                       Fecha objDate = Fecha(),
                       std::string objComments = "")
        : id(std::move(oid)),
          name(std::move(objName)),
          versionMajor(std::move(versionMaj)),
          versionMinor(std::move(versionMin)),
          date_init(objDate),
          comments(std::move(objComments)) {}

void Trackeable::setName(const std::string objName) {
    changes.emplace_back(changeName, date_init, changeName + name + " -> " + objName); // Añadimos el cambio a la lista de cambios
    this->name = objName;
}

void Trackeable::setVersionMajor(std::string versionMaj) {
    changes.emplace_back(changeVersionMajor, date_init, changeVersionMajor + versionMajor + " -> " + versionMaj); // Añadimos el cambio a la lista de cambios
    this->versionMajor = versionMaj;
}

void Trackeable::setVersionMinor(std::string versionMin) {
    changes.emplace_back(changeVersionMinor, date_init, changeVersionMinor + versionMinor + " -> " + versionMin); // Añadimos el cambio a la lista de cambios
    this->versionMinor = versionMin;

}

void Trackeable::setDate(Fecha objDate) {
    changes.emplace_back(changeDate, date_init, changeDate + date_init.toString() + " -> " + objDate.toString()); // Añadimos el cambio a la lista de cambios
    this->date_init = objDate;
}

void Trackeable::setComments(std::string objComments) {
    changes.emplace_back(changeComments, date_init, changeComments + comments + " -> " + objComments); // Añadimos el cambio a la lista de cambios
    this->comments = objComments;
}

void Trackeable::setAuthors(std::set<std::string>& setauthors) {
    changes.emplace_back(changeAuthors, date_init, changeAuthors + " -> " + std::to_string(setauthors.size()) + " autores"); // Añadimos el cambio a la lista de cambios
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

std::list<Cambios> Trackeable::getChanges() const {
    return this->changes;
}

void Trackeable::addAuthor(std::string author) {
    authors.insert(author);

}

void Trackeable::removeAuthor(std::string author) {
    authors.erase(author);

}

void Trackeable::setChanges(std::list<Cambios> changes) {
    this->changes = changes;

}

void Trackeable::addChange(Cambios change) {
    changes.emplace_back(change);
}
