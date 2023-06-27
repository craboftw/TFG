#ifndef TFG_USERCASE_H
#define TFG_USERCASE_H

#include <string>
#include <vector>
#include <list>
#include "Trackeable/Trackeable.h"
#include "Priority/Priority.h"

typedef std::string OID;

enum class ImportanceLevel {
    PRIMARY, SECUNDARY, OPTIONAL
};

enum class DetailQuantity {
    LOW, MEDIUM, HIGH
};

class UserCase : public Trackeable, public Priority {
    bool abstract;
    std::string precondition;
    std::string postcondition;
    TimeQuantity frequency;
    std::vector<OID> steps;
    std::list<OID> actors;
    std::list<OID> objectives;
    inline static std::string prefixID = "UC-";

public:
    UserCase(std::string id) : Trackeable(prefixID + id), abstract(false), precondition(""), postcondition(""), frequency() {}

    void setAbstract(bool _abstract);
    void setPrecondition(std::string _precondition);
    void setPostcondition(std::string _postcondition);
    void setObjectives(std::list<OID> _objectives);
    void setFrequency(TimeQuantity _frequency);
    void setSteps(std::vector<OID> _steps);
    void setActors(std::list<OID> _actors);


    void addStep(OID step);
    void addStep(OID step, int pos);
    void addActor(OID actor);

    bool isAbstract() const;
    bool getAbstract() const;
    std::string getPrecondition() const;
    std::string getPostcondition() const;
    TimeQuantity getFrequency() const;
    std::vector<OID> getSteps() const;
    std::list<OID> getActors() const;
    std::list<OID> getObjectives() const;

};

#endif // TFG_USERCASE_H
