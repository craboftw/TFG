//
// Created by Fran- on 02/07/2023.
//

#ifndef TFG_SERVICIOPRIORITY_H
#define TFG_SERVICIOPRIORITY_H


#include "Dominio/Priority/Priority.h"
#include "OID.h"

class ServicioPriority {
public:
    void setImportanceLevel(OID id,Priority::Importance importanceLevel);
    void setUrgencyLevel(OID id,Priority::Importance urgencyLevel);
    void setPhase(OID id,Priority::Development_phase _phase);
    void setEstability(OID id,Priority::Estability _estability);

    std::string strImportanceLevel(OID id);
    std::string strUrgencyLevel(OID id);
    std::string strPhase(OID id);
    std::string strEstability(OID id);

    Priority::Importance getImportanceLevel(OID id) ;
    Priority::Importance getUrgencyLevel(OID id) ;
    Priority::Development_phase getPhase(OID id) ;
    Priority::Estability getEstability(OID id) ;



};


#endif //TFG_SERVICIOPRIORITY_H
