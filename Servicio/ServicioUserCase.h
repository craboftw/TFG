//
// Created by Fran- on 30/06/2023.
//

#ifndef TFG_SERVICIOUSERCASE_H
#define TFG_SERVICIOUSERCASE_H


#include "Dominio/Trackeable/Trackeable.h"
#include "Visitor/FileJsonManager.h"
#include "ServicioTrackeable.h"
#include "ServicioPriority.h"

class ServicioUserCase : public ServicioTrackeable, public ServicioPriority{
public:
    OID createUserCase(std::string name="");
    void setAbstract(OID id,bool _abstract);
    void setPrecondition(OID id,std::string _precondition);
    void setPostcondition(OID id,std::string _postcondition);
    void setObjectives(OID id,std::list<OID> _objectives);
    void addObjective(OID id,OID objective);
    void removeObjective(OID id,OID objective);
    void setFrequency(OID id,TimeQuantity _frequency);
    void setSteps(OID id,std::vector<Step> _steps);
    void setActors(OID id,std::list<OID> _actors);
    void setPackage(OID id,std::string _package);
    void setGeneralization(OID id,OID _generalization);
    void addStep(OID id,Step step);
    void addStep(OID id,Step step,int pos);
    void addActor(OID id,OID actor);
    void removeStep(OID id,int pos);

    bool getAbstract(OID id);
    std::string getPrecondition(OID id);
    std::string getPostcondition(OID id);
    TimeQuantity getFrequency(OID id);
    std::vector<Step> getSteps(OID id);
    std::list<OID> getActors(OID id);
    std::list<OID> getObjectives(OID id);
    std::string getPackage(OID id);
    OID getGeneralization(OID id);

    bool getAbstract(OID id,unsigned pos);
    std::string getDescription(OID id,unsigned pos);
    std::string getCondition(OID id,unsigned pos);
    std::string getComments(OID id,unsigned pos);
    Step::type getType(OID id,unsigned pos);
    OID getReference(OID id,unsigned pos);

    void setAbstract(OID id,unsigned pos,bool _abstract);
    void setCondition(OID id,unsigned pos,std::string _condition);
    void setComments(OID id,unsigned pos,std::string _comments);
    void setDescription(OID id,unsigned pos,std::string _description);
    void setType(OID id,unsigned pos,Step::type _type);
    void setReference(OID id,unsigned pos,OID _reference);

    std::list<std::pair<OID, std::string>> getUseCases();

private:
    FileJsonManager fileJsonManager;



};
#endif //TFG_SERVICIOUSERCASE_H
