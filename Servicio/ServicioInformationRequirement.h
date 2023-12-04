//
// Created by Fran- on 02/07/2023.
//

#ifndef TFG_SERVICIOINFORMATIONREQUIREMENT_H
#define TFG_SERVICIOINFORMATIONREQUIREMENT_H


#include "Dominio/Generic.h"
#include "Servicio/ServicioTrackeable.h"
#include "Servicio/ServicioPriority.h"
#include "OID.h"

class ServicioInformationRequirement : public ServicioTrackeable, public ServicioPriority {
public:
    OID createInformationRequirement(std::string nombre);

    void setMaxSimultaneousOccurrence(OID id, unsigned int maxSimultaneousOccurrence);
    void setAvgSimultaneousOccurrence(OID id, unsigned int avgSimultaneousOccurrence);
    void setLifeMaxEstimate(OID id, const TimeQuantity &lifeMaxEstimate);
    void setLifeAvgEstimate(OID id, const TimeQuantity &lifeAvgEstimate);
    void setSpecificInformation(OID id,const std::list<SpecificInformation> &specificInformation);
    void addSpecificInformation(OID idconst ,const std::string name, const std::string description);
    void removeSpecificInformation(OID id,const unsigned idSpecificInformation);
    void setSpecificInformationName(OID id,const unsigned idSpecificInformation, const std::string &name);
    void setSpecificInformationDescription(OID id,const unsigned idSpecificInformation, const std::string &description);

    unsigned int getMaxSimultaneousOccurrence(OID id) ;
    unsigned int getAvgSimultaneousOccurrence(OID id) ;
    TimeQuantity getLifeMaxEstimate(OID id) ;
    TimeQuantity getLifeAvgEstimate(OID id) ;
    std::list<SpecificInformation> getSpecificInformation(OID id) ;

    std::string strMaxSimultaneousOccurrence(OID id) ;
    std::string strAvgSimultaneousOccurrence(OID id) ;
    std::string strLifeMaxEstimate(OID id) ;
    std::string strLifeAvgEstimate(OID id) ;

    std::list<std::pair<OID,std::string>> getInformationRequirements();



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
