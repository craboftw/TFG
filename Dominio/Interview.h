//
// Created by Fran- on 21/07/2023.
//

#ifndef TFG_INTERVIEW_H
#define TFG_INTERVIEW_H

#include <string>
#include <vector>
#include "Dominio/Trackeable/Trackeable.h"

struct Question{
    std::string question;
    std::string answer;
};

class Interview  : public Trackeable{
public:
    Interview(unsigned id) : Trackeable(prefix,id) {};
    Interview() : Trackeable() {};
    void addQuestion(std::string question, std::string answer);
    void addQuestion(std::string question, std::string answer, unsigned position);
    void setQuestions(std::vector<Question> questions);
    void removeQuestion(unsigned position);
    void setPlace(std::string place);
    std::string getPlace();
    void addStakeholderAsking(OID stakeholder);
    void setStakeholdersAsking(std::set<OID> stakeholders);
    void addStakeholderInterviewed(OID stakeholder);
    void setStakeholdersInterviewed(std::set<OID> stakeholders);
    void removeStakeholderAsking(OID stakeholder);
    void removeStakeholderInterviewed(OID stakeholder);
    std::set<OID> getStakeholdersAsking();
    std::set<OID> getStakeholdersInterviewed();


    Question getQuestion(unsigned position);
    static std::string getPrefixID();

    std::vector<Question> getQuestions();

private:
    std::vector<Question> questions;
    std::set<OID> stakeholdersAsking;
    std::set<OID> stakeholdersInterviewed;
    std::string place;
inline static std::string prefix = "IN";

};


#endif //TFG_INTERVIEW_H
