#include "Trackeable.h"
#include "Stakeholder.h"

Trackeable::Trackeable(std::string oid, std::string objName, std::string objDescription,
                       std::string versionMaj, std::string versionMin, const Fecha& objDate,
                       std::string objComments)
        : id(std::move(oid)),
          name(std::move(objName)),
          description(std::move(objDescription)),
          versionMajor(std::move(versionMaj)),
          versionMinor(std::move(versionMin)),
          date_init(objDate),
          comments(std::move(objComments)) {}

void Trackeable::setName(const std::string& objName) {
    changes.insert(new Cambios(changeName + this->name + "->" + objName, Fecha(), objName));
    this->name = objName;
}

void Trackeable::setDescription(const std::string& objDescription) {
    this->description = objDescription;
}

void Trackeable::setVersionMajor(const std::string& versionMaj) {
    this->versionMajor = versionMaj;
}

void Trackeable::setVersionMinor(const std::string& versionMin) {
    this->versionMinor = versionMin;
}

void Trackeable::setDate(const Fecha& objDate) {
    this->date_init = objDate;
}

void Trackeable::setComments(const std::string& objComments) {
    this->comments = objComments;
}

void Trackeable::setAuthors(std::set<Stakeholder*>& setauthors) {
    this->authors = setauthors;
}

void Trackeable::addAuthor(Stakeholder* author) {
    this->authors.insert(author);
}

void Trackeable::removeAuthor(Stakeholder* author) {
    this->authors.erase(author);
}

void Trackeable::setChanges(std::set<Cambios*>& changes) {
    this->changes = changes;
}

void Trackeable::addChange(Cambios* change) {
    this->changes.insert(change);
}

void Trackeable::removeChange(Cambios* change) {
    this->changes.erase(change);
}

std::string Trackeable::getId() const {
    return this->id;
}

std::string Trackeable::getName() const {
    return this->name;
}

std::string Trackeable::getDescription() const {
    return this->description;
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

std::set<Stakeholder*> Trackeable::getAuthors() const {
    return this->authors;
}

std::set<Cambios*> Trackeable::getChanges() const {
    return this->changes;
}

void Trackeable::print() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Version: " << versionMajor << "  -  " << versionMinor << std::endl;
    std::cout << "Date: ";
    date_init.print();
    std::cout << "Comments: " << comments << std::endl;
    std::cout << "Authors: " << std::endl;
    int i=1;
    for (auto author : authors) {
        std::cout<<i<<": ";author->lineprint();i++;
        std::cout << "\n";
    }
    std::cout << "Changes: " << std::endl;
    for (auto& change : changes) {
        std::cout << "\t";
        change->print();
        std::cout << std::endl;
    }
}

void pruebaStakeHolder() {
    // PRUEBA DE ORGANIZACION Y STAKEHOLDER
    std::cout << "PRUEBA DE ORGANIZACION" << std::endl;
    Organization org("Org", "Contact info", "Description", "Comments");
    org.print();

    std::cout << "\nPRUEBA DE STAKEHOLDER" << std::endl;
    Rol_Stakeholder stakeholderRole("Stakeholder role");
    Stakeholder stakeholder("Stakeholder", "Stakeholder", "Description", "0.0.1", "2.0.0", Fecha(), "Comments",
                            "Email", "Phone", "Address", &stakeholderRole, org);
    stakeholder.print();

    std::cout << "\nPRUEBA DE CAMBIOS" << std::endl;
    stakeholder.setName("Miriam");
    stakeholder.setName("Pakito");
    stakeholder.addAuthor(&stakeholder);
    stakeholder.print();
}

int main() {
    pruebaStakeHolder();
    return 0;
}
