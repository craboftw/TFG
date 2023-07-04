#ifndef TFG_USERCASE_H
#define TFG_USERCASE_H

#include <string>
#include <vector>
#include <list>
#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Priority/Priority.h"


enum class ImportanceLevel {
    PRIMARY, SECUNDARY, OPTIONAL
};

enum class DetailQuantity {
    LOW, MEDIUM, HIGH
};

enum type {SYSTEM, ACTOR, INCLUDE, EXTEND};


struct Exception{
    unsigned id;
    unsigned step;
    type stepType;
    std::string description;
    std::string condition;
    std::string comments;
    OID reference;
};



class Step{
private:

    bool abstract;
    std::string description;
    std::string condition;
    std::string comments;
    type stepType;
    OID reference;



public:
    Step(bool abstract = false, std::string condition ="", std::string comments ="") : abstract(abstract), condition(std::move(condition)), comments(std::move(comments)) {}
    bool getAbstract() const;
    std::string getDescription() const;
    std::string getCondition() const;
    std::string getComments() const;
    type getType() const;
    OID getReference() const;

    void setAbstract(bool _abstract);
    void setCondition(std::string _condition);
    void setComments(std::string _comments);
    void setDescription(std::string _description);
    void setType(type _type);
    void setReference(OID _reference);


};



class UserCase : virtual public Trackeable, public Priority {
    bool abstract;
    std::string precondition;
    std::string postcondition;
    std::string package;
    TimeQuantity frequency;
    std::vector<Step> steps;
    std::list<OID> actors;
    std::list<OID> objectives;
    std::list<Exception> exceptions;
    OID generalization; //OID of the UserCase that this UserCase generalizes

    inline static std::string prefixID = "UC";



public:
    UserCase(unsigned id) : Trackeable(prefixID , id), abstract(false), precondition(""), postcondition(""), frequency(),package(""),generalization(){}

    void setAbstract(bool _abstract);
    void setPrecondition(std::string _precondition);
    void setPostcondition(std::string _postcondition);
    void setObjectives(std::list<OID> _objectives);
    void addObjective(OID objective);
    void removeObjective(OID objective);
    void setFrequency(TimeQuantity _frequency);
    void setSteps(std::vector<Step> _steps);
    void setActors(std::list<OID> _actors);
    void setPackage(std::string _package);
    void setGeneralization(OID _generalization);
    void setExceptions(std::list<Exception> _exceptions);


    void addStep(Step step);
    void addStep(Step step, int pos);
    void removeStep(int pos);
    void addActor(OID actor);

    void addException(Exception exception);
    void setException(Exception exception) ;
    void removeException(unsigned id);

    bool isAbstract() const;
    bool getAbstract() const;
    std::string getPrecondition() const;
    std::string getPostcondition() const;
    TimeQuantity getFrequency() const;
    std::vector<Step> getSteps() const;
    std::list<OID> getActors() const;
    std::list<OID> getObjectives() const;
    std::string getPackage() const;
    OID getGeneralization() const;
    static std::string getPrefixID();

    std::list<Exception> getExceptions() const;
};




#endif // TFG_USERCASE_H
