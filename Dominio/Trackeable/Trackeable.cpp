#include "Trackeable.h"
#include "Stakeholder.h"


void Change::setVersion(std::string _version){
    version = _version;
}

void Change::setDate(Fecha _date){
    date = _date;
}

void Change::setComments(std::string _comments){
    comments = _comments;
}

void Trackeable::setDescription(std::string objDescription) {
    if (description != objDescription and !description.empty()) {
        addChange(Change(changeDescription, Fecha(), changeDescription + description + "->" + objDescription));
        this->description = objDescription;
    }
}

void Trackeable::setName(const std::string objName) {
    if (!name.empty() and name != objName) {
        addChange(Change(changeName, Fecha(), changeName + name + "->" + objName));
        this->name = objName;
    }
    else
        this->name = objName;
}

void Trackeable::setVersionMajor(std::string versionMaj) {
    if (versionMajor != defaultVersionMajor and versionMajor != versionMaj) {
        addChange(Change(changeVersionMajor, Fecha(), changeVersionMajor + versionMajor + "->" + versionMaj));
        this->versionMajor = versionMaj;
    }
    else
        this->versionMajor = versionMaj;
}

void Trackeable::setVersionMinor(std::string versionMin) {
    if (versionMinor != defaultVersionMinor and versionMinor != versionMin) {
        addChange(Change(changeVersionMinor, Fecha(), changeVersionMinor + versionMinor + "->" + versionMin));
        this->versionMinor = versionMin;
    }
    else
        this->versionMinor = versionMin;

}

void Trackeable::setDate(Fecha objDate) {
    if (date_init != defaultDate or date_init != objDate) {
        addChange(Change(changeDate, Fecha(), changeDate + date_init.toString() + "->" + objDate.toString()));
        this->date_init = objDate;
    }
    else
        this->date_init = objDate;
}

void Trackeable::setComments(std::string objComments) {
        this->comments = objComments;
}

void Trackeable::setAuthors(std::set<OID>& setauthors) {
    if (authors != setauthors) {
        std::string aux;
        for (auto author : authors) {
            aux += author.operator std::string() + ",";
        }
        aux += "->";
        for (auto author : setauthors) {
            aux += author.operator std::string() + ",";
        }
        addChange(Change(changeAuthors, Fecha(), changeAuthors + aux + "."));
        this->authors = setauthors;
    }
}

void Trackeable::addAuthor(OID author) {
    if (authors.find(author) == authors.end()) {
        addChange(Change(addingAuthor, Fecha(), addingAuthor + author.operator std::string() + "."));
        authors.insert(author);
    }
}

void Trackeable::removeAuthor(OID author) {
    if (authors.find(author) != authors.end()) {
        addChange(Change(removingAuthor, Fecha(), removingAuthor + author.operator std::string() + "."));
        authors.erase(author);
    }
}


OID Trackeable::getId() const {
    return this->id;
}

std::string Trackeable::getDescription() const {
    return this->description;
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

std::list<OID> Trackeable::getTracesFrom() const {
    return this->tracesFrom;
}

std::list<OID> Trackeable::getTracesTo() const {
    return this->tracesTo;
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
    defaultVersionMajor = objversionMajor;
}

void Trackeable::setdefaultVersionMinor(std::string objversionMinor) {
    defaultVersionMinor = objversionMinor;
}

void Trackeable::setdefaultDate(Fecha objdate) {
    defaultDate = objdate;
}

void Trackeable::setdefaultAuthors(std::set<OID> &objauthors) {
    defaultAuthors = objauthors;
}

void Trackeable::accept(Visitor* visitor) {

}





//    void setChanges(std::list<Change> changes);
//    void addChange(Change change);
//    std::list<Change> getChanges() const;

void Trackeable::setChanges(std::list<Change> changes) {
    this->changes = changes;
}

void Trackeable::addChange(Change change) {
    changes.emplace_back(change);
}

std::list<Change> Trackeable::getChanges() const {
    return this->changes;
}


std::string Change::getVersion() const {
    return version;
}

Fecha Change::getDate() const {
    return Fecha();
}

std::string Change::getComments() const {
    return comments;
}


std::string OID::getPrefix() const {
    return this->prefixID;
}

unsigned OID::getId() const {
    return this->id;
}

bool OID::operator<(const OID& rhs) const {
    return this->id < rhs.id;
}

bool OID::operator>(const OID& rhs) const {
    return this->id > rhs.id;
}

bool OID::operator==(const OID& rhs) const {
    return this->id == rhs.id;
}

bool OID::operator!=(const OID& rhs) const {
    return this->id != rhs.id;
}

bool OID::operator<=(const OID& rhs) const {
    return this->id <= rhs.id;
}

bool OID::operator>=(const OID& rhs) const {
    return this->id >= rhs.id;
}





