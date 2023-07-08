//
// Created by Fran- on 08/07/2023.
//

#ifndef TFG_SERVICIOUSERSTORIES_H
#define TFG_SERVICIOUSERSTORIES_H


#include <string>
#include "Dominio/Trackeable/Trackeable.h"
#include "Visitor/FileJsonManager.h"
#include "ServicioTrackeable.h"
#include "ServicioPriority.h"

class ServicioUserStories : public ServicioTrackeable, public ServicioPriority{
public:
    OID createUserStories(std::string name);
    void setRole(OID id, std::string role);
    void setGoal(OID id, std::string goal);
    void setBenefit(OID id, std::string benefit);
    void setPriorityPoints(OID id, unsigned int priorityPoints);
    void setDevTimePoints(OID id, unsigned int DevTimePoints);

    std::string getRole(OID id);
    std::string getGoal(OID id);
    std::string getBenefit(OID id);
    unsigned getPriorityPoints(OID id);
    unsigned getDevTimePoints(OID id);

private:
    FileJsonManager filejsonManager;
};


#endif //TFG_SERVICIOUSERSTORIES_H
