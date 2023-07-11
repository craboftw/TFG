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
    void removeActor(OID id,OID actor);
    void setException(OID id,unsigned pos, Exception exception);
    void setExceptions(OID id,std::vector<Exception> exceptions);
    void addException(OID id,Exception exception);



    bool getAbstract(OID id);
    std::string getPrecondition(OID id);
    std::string getPostcondition(OID id);
    TimeQuantity getFrequency(OID id);
    std::string strFrequency(OID id);
    std::vector<Step> getSteps(OID id);
    std::list<OID> getActors(OID id);
    std::list<OID> getObjectives(OID id);
    std::string getPackage(OID id);
    OID getGeneralization(OID id);
    std::vector<Exception> getExceptions(OID oid);

    bool getAbstractStep(OID id,unsigned pos);
    std::string getDescriptionStep(OID id,unsigned pos);
    std::string getConditionStep(OID id,unsigned pos);
    std::string getCommentsStep(OID id,unsigned pos);
    type getTypeStep(OID id,unsigned pos);
    OID getReferenceStep(OID id,unsigned pos);

    void setAbstractStep(OID id,unsigned pos,bool _abstract);
    void setConditionStep(OID id,unsigned pos,std::string _condition);
    void setCommentsStep(OID id,unsigned pos,std::string _comments);
    void setDescriptionStep(OID id,unsigned pos,std::string _description);
    void setTypeStep(OID id,unsigned pos,type _type);
    void setReferenceStep(OID id,unsigned pos,OID _reference);


    std::list<std::pair<OID, std::string>> getUseCases();


private:
    FileJsonManager fileJsonManager;


};
#endif //TFG_SERVICIOUSERCASE_H
