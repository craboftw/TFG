//
// Created by craboftw on 19/06/23.
//

#ifndef TFG_TRACKEABLE_H
#define TFG_TRACKEABLE_H

class Trackeable {
protected:
    std::string id;
    std::string name;
    std::string description;
    std::string versionMajor;
    std::string versionMinor;
    Fecha date_init;
    std::string comments;
    std::set<Stakeholder *> authors;
    std::set <Cambios*> changes;

public:
    Trackeable (const std::string &oid, const std::string &objName, const std::string &objDescription,
                const std::string &versionMaj, const std::string &versionMin, const Fecha &objDate,
                const std::string &objComments)
            : id(oid),
              name(objName),
              description(objDescription),
              versionMajor(versionMaj),
              versionMinor(versionMin),
              date_init(objDate),
              comments(objComments) {}

    //༺♥༻❀SETTERS❀༺♥༻

    void setName (const std::string &objName) {this->name = objName;}
    void setDescription (const std::string &objDescription) { this->description = objDescription; }
    void setVersionMajor (const std::string &versionMaj) {this->versionMajor = versionMaj; }
    void setVersionMinor (const std::string &versionMin) {this->versionMinor = versionMin; }
    void setDate (const Fecha &objDate) {this->date_init = objDate;}
    void setComments (const std::string &objComments) {this->comments = objComments;}
    //Authors
    void setAuthors (const std::set<Stakeholder *> &authors) {this->authors = authors;}
    void addAuthor (Stakeholder *author) {this->authors.insert(author);}
    void removeAuthor (Stakeholder *author) {this->authors.erase(author);}
    //Changes
    void setChanges (const std::set <Cambios> &changes) { this->changes = changes; }
    void addChange (const Cambios &change) {this->changes.insert(change); }
    void removeChange (const Cambios &change) { this->changes.erase(change);}

    //༺♥༻❀GETTERS❀༺♥༻
    std::string getId () const { return this->id;}
    std::string getName () const { return this->name;}
    std::string getDescription () const { return this->description;}
    std::string getVersionMajor () const { return this->versionMajor;}
    std::string getVersionMinor () const { return this->versionMinor;}
    Fecha getDate () const { return this->date_init;}
    std::string getComments () const { return this->comments; }
    std::set<Stakeholder *> getAuthors () const { return this->authors;}
    std::set <Cambios> getChanges () const { return this->changes;}


};

#endif //TFG_TRACKEABLE_H
