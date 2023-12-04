//
// Created by Fran- on 21/07/2023.
//

#ifndef TFG_SERVICIOINTERVIEW_H
#define TFG_SERVICIOINTERVIEW_H


#include "ServicioTrackeable.h"
#include "Dominio/Interview.h"
#include "OID.h"

class ServicioInterview : public ServicioTrackeable{


public:
    OID createInterview(std::string name);
    void addQuestion(OID interview, std::string question, std::string answer);
    void addQuestion(OID interview, std::string question, std::string answer, unsigned position);
    void removeQuestion(OID interview, unsigned position);
    Question getQuestion(OID interview, unsigned position);
    void addStakeholderAsking(OID interview, OID stakeholder);
    void addStakeholderInterviewed(OID interview, OID stakeholder);
    void removeStakeholderAsking(OID interview, OID stakeholder);
    void removeStakeholderInterviewed(OID interview, OID stakeholder);
    std::set<OID> getStakeholdersAsking(OID interview);
    std::set<OID> getStakeholdersInterviewed(OID interview);
    std::vector<Question> getQuestions(OID oid);
    std::string getPlace(OID oid);
    void setPlace(OID oid, std::string place);
};


#endif //TFG_SERVICIOINTERVIEW_H
