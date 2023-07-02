//
// Created by Fran- on 02/07/2023.
//

#ifndef TFG_SERVICIOINFORMATIONREQUIREMENT_H
#define TFG_SERVICIOINFORMATIONREQUIREMENT_H


#include "ServicioPriority.h"
#include "ServicioTrackeable.h"

class ServicioInformationRequirement : public ServicioTrackeable, public ServicioPriority {
public:
    OID createInformationRequirement(std::string nombre);

    void setMaxSimultaneousOccurrence(OID id, unsigned int maxSimultaneousOccurrence);
    void setAvgSimultaneousOccurrence(OID id, unsigned int avgSimultaneousOccurrence);
    void setLifeMaxEstimate(OID id, const TimeQuantity &lifeMaxEstimate);
    void setLifeAvgEstimate(OID id, const TimeQuantity &lifeAvgEstimate);

    unsigned int getMaxSimultaneousOccurrence(OID id) ;
    unsigned int getAvgSimultaneousOccurrence(OID id) ;
    TimeQuantity getLifeMaxEstimate(OID id) ;
    TimeQuantity getLifeAvgEstimate(OID id) ;

    std::string strMaxSimultaneousOccurrence(OID id) ;
    std::string strAvgSimultaneousOccurrence(OID id) ;
    std::string strLifeMaxEstimate(OID id) ;
    std::string strLifeAvgEstimate(OID id) ;




private:
    FileJsonManager fileJsonManager;
/*    void setMaxSimultaneousOccurrence(unsigned int maxSimultaneousOccurrence);
    void setAvgSimultaneousOccurrence(unsigned int avgSimultaneousOccurrence);
    void setLifeMaxEstimate(const TimeQuantity &lifeMaxEstimate);
    void setLifeAvgEstimate(const TimeQuantity &lifeAvgEstimate);

    unsigned int getMaxSimultaneousOccurrence() const;
    unsigned int getAvgSimultaneousOccurrence() const;
    TimeQuantity getLifeMaxEstimate() const;
    TimeQuantity getLifeAvgEstimate() const;.

    std::string strMaxSimultaneousOccurrence() const;
    std::string strAvgSimultaneousOccurrence() const;
    std::string strLifeMaxEstimate() const;
    std::string strLifeAvgEstimate() const;
    */

};


#endif //TFG_SERVICIOINFORMATIONREQUIREMENT_H
