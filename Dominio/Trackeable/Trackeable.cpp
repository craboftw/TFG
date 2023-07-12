#include "Trackeable.h"

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
        this->description = objDescription;
}

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

void Trackeable::setAuthors(std::set<OID> setauthors) {
        this->authors = setauthors;
}

void Trackeable::addAuthor(OID author) {
        this->authors.insert(author);

}

void Trackeable::removeAuthor(OID author) {
    this->authors.erase(author);

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

std::set<OID> Trackeable::getTracesFrom() const {
    return this->tracesFrom;
}

std::set<OID> Trackeable::getTracesTo() const {
    return this->tracesTo;
}



void Trackeable::setTracesFrom(std::set<OID> objtracesFrom) {
    tracesFrom = objtracesFrom;
}

void Trackeable::addTraceFrom(OID objtraceFrom) {
    //add a objTraceFrom to the list
    tracesFrom.insert(objtraceFrom);

}

void Trackeable::removeTraceFrom(OID objtraceFrom) {
    //remove a objTraceFrom from the list
    tracesFrom.erase(objtraceFrom);
}

void Trackeable::setTracesTo(std::set<OID> objtracesTo) {
    tracesTo = objtracesTo;
}

void Trackeable::addTraceTo(OID objtraceTo) {
    //add a objTraceTo to the list
    tracesTo.insert(objtraceTo);
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

void Trackeable::setTrackeablePart(TrackeableDTO trackeable) {
    /* std::string name;
    std::string description;
    std::string versionMajor;
    std::string versionMinor;
    Fecha date_init;
    std::string comments;
    std::set<OID> authors;
    std::set<OID> tracesFrom;
    std::set<OID> tracesTo;
    std::list<Change> changes;*/
    this->name = trackeable.name;
    this->description = trackeable.description;
    this->versionMajor = trackeable.versionMajor;
    this->versionMinor = trackeable.versionMinor;
    this->date_init = trackeable.date_init;
    this->comments = trackeable.comments;
    this->authors = trackeable.authors;
    this->tracesFrom = trackeable.tracesFrom;
    this->tracesTo = trackeable.tracesTo;
    this->changes = trackeable.changes;

}

void Trackeable::setTrackeableDTO(TrackeableDTO trackeableDto)
{
    this->name = trackeableDto.name;
    this->description = trackeableDto.description;
    this->versionMajor = trackeableDto.versionMajor;
    this->versionMinor = trackeableDto.versionMinor;
    this->date_init = trackeableDto.date_init;
    this->comments = trackeableDto.comments;
    this->authors = trackeableDto.authors;
    this->tracesFrom = trackeableDto.tracesFrom;
    this->tracesTo = trackeableDto.tracesTo;
    this->changes = trackeableDto.changes;
}

void Trackeable::setTrackeablePart(Trackeable *trackeable) {
    this->name = trackeable->name;
    this->description = trackeable->description;
    this->versionMajor = trackeable->versionMajor;
    this->versionMinor = trackeable->versionMinor;
    this->date_init = trackeable->date_init;
    this->comments = trackeable->comments;
    this->authors = trackeable->authors;
    this->tracesFrom = trackeable->tracesFrom;
    this->tracesTo = trackeable->tracesTo;
    this->changes = trackeable->changes;
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

unsigned Change::getId() const {
    return id;
}


std::string OID::getPrefix() const {
    return this->prefixID;
}

unsigned OID::getId() const {
    return this->id;
}

bool OID::operator<(const OID& rhs) const {
    return this->operator std::string() < rhs.operator std::string();
}

bool OID::operator>(const OID& rhs) const {
    return this->operator std::string() > rhs.operator std::string();
}

bool OID::operator==(const OID& rhs) const {
    return this->operator std::string() == rhs.operator std::string();
}

bool OID::operator!=(const OID& rhs) const {
    return this->operator std::string() != rhs.operator std::string();
}

bool OID::operator<=(const OID& rhs) const {
    return this->operator std::string() <= rhs.operator std::string();
}

bool OID::operator>=(const OID& rhs) const {
    return this->operator std::string() >= rhs.operator std::string();
}





