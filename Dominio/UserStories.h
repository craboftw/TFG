//
// Created by Fran- on 08/07/2023.
//

#ifndef TFG_USERSTORIES_H
#define TFG_USERSTORIES_H


#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Priority/Priority.h"

class UserStories : virtual public Trackeable, public Priority{
public:
   UserStories(unsigned id) : Trackeable(prefixID,id) {}
   void setRole(std::string role);
    void setGoal(std::string goal);
    void setBenefit(std::string benefit);
    void setPriorityPoints(unsigned int priorityPoints);
    void setDevTimePoints(unsigned int DevTimePoints);

    std::string getRole();
    std::string getGoal();
    std::string getBenefit();
    unsigned getPriorityPoints();
    unsigned getDevTimePoints();
    static std::string getPrefixID() {return prefixID;}

    void accept(Visitor* visitor) override ;

private:
    std::string role ;
    std::string goal ;
    std::string benefit ;
    unsigned int priorityPoints;
    unsigned int DevTimePoints;

    inline static std::string prefixID = "US";
};


#endif //TFG_USERSTORIES_H
