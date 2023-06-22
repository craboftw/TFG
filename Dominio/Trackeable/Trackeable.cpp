#include "Trackeable.h"
#include "Stakeholder.h"


void Trackeable::setName(const std::string objName) {
    if (!name.empty() or name != objName) {
        addChange(Cambios(changeName, Fecha(), changeName + name + "->" + objName));
        this->name = objName;
    }
}

void Trackeable::setVersionMajor(std::string versionMaj) {
    if (versionMajor != defaultVersionMajor or versionMajor != versionMaj) {
        addChange(Cambios(changeVersionMajor, Fecha(), changeVersionMajor + versionMajor + "->" + versionMaj));
        this->versionMajor = versionMaj;
    }
}

void Trackeable::setVersionMinor(std::string versionMin) {
    if (versionMinor != defaultVersionMinor or versionMinor != versionMin) {
        addChange(Cambios(changeVersionMinor, Fecha(), changeVersionMinor + versionMinor + "->" + versionMin));
        this->versionMinor = versionMin;
    }

}

void Trackeable::setDate(Fecha objDate) {
    if (date_init != defaultDate or date_init != objDate) {
        addChange(Cambios(changeDate, Fecha(), changeDate + date_init.toString() + "->" + objDate.toString()));
        this->date_init = objDate;
    }
}

void Trackeable::setComments(std::string objComments) {
        this->comments = objComments;
}

void Trackeable::setAuthors(std::set<std::string>& setauthors) {
    if (authors != defaultAuthors or authors != setauthors) {
        std::string aux;
        for (auto &author : authors) {
            aux += author + ",";
        }
        aux += "->";
        for (auto &author : setauthors) {
            aux += author + ",";
        }
        addChange(Cambios(changeAuthors, Fecha(), changeAuthors + aux+"."));
        this->authors = setauthors;
    }
}

void Trackeable::addAuthor(std::string author) {
    if (authors.find(author) == authors.end()) {
        addChange(Cambios(addingAuthor, Fecha(), addingAuthor + author + "."));
        authors.insert(author);
    }
}

void Trackeable::removeAuthor(std::string author) {
    if (authors.find(author) != authors.end()) {
        addChange(Cambios(removingAuthor, Fecha(), removingAuthor + author + "."));
        authors.erase(author);
    }
}


OID Trackeable::getId() const {
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

std::set<OID> Trackeable::getAuthors() const {
    return this->authors;
}



void Trackeable::setTracesFrom(std::list<OID> &objtracesFrom) {
    tracesFrom = objtracesFrom;
}

void Trackeable::addTraceFrom(OID objtraceFrom) {
    //add a objTraceFrom to the list
    tracesFrom.push_back(objtraceFrom);

}

void Trackeable::removeTraceFrom(OID objtraceFrom) {
    //remove a objTraceFrom from the list
    tracesFrom.remove(objtraceFrom);
}

void Trackeable::setTracesTo(std::list<OID> &objtracesTo) {
    tracesTo = objtracesTo;
}

void Trackeable::addTraceTo(OID objtraceTo) {
    //add a objTraceTo to the list
    tracesTo.push_back(objtraceTo);
}

void Trackeable::removeTraceTo(OID objtraceTo) {

}

void Trackeable::setdefaultVersionMajor(std::string objversionMajor) {

}

void Trackeable::setdefaultVersionMinor(std::string objversionMinor) {

}

void Trackeable::setdefaultDate(Fecha objdate) {

}

void Trackeable::setdefaultAuthors(std::set<std::string> &objauthors) {

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




