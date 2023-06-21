//
// Created by craboftw on 20/06/23.
//

#ifndef TFG_SYSTEMOBJETIVE_H
#define TFG_SYSTEMOBJETIVE_H

#include "../Trackeable/Trackeable.h"


class SystemObjetive : public Trackeable{

private:
    // Constantes para los mensajes de importancia
    std::string highLevelImportance = "Importancia vital";
    std::string mediumLevelImportance = "Importancia considerable";
    std::string lowLevelImportance = "Importancia baja";
    // Constantes para los mensajes de urgencia
    std::string highLevelUrgency = "Urgencia alta";
    std::string mediumLevelUrgency = "Urgencia media";
    std::string lowLevelUrgency = "Urgencia baja";

    // Constantes para los mensajes de fase de desarrollo
    std::string inceptionPhase = "Pendiente de validacion";
    std::string elaborationPhase = "Pendiente de verificacion";
    std::string constructionPhase = "Pendiente de implementacion";
    std::string inDevelopmentPhase = "En desarrollo";
    std::string transitionPhase = "Pendiente de despliegue";
    std::string phinishedPhase = "Finalizado";

    // Constantes para los mensajes de estabilidad
    std::string stableEstability = "Alta estabilidad";
    std::string mediumEstability = "Baja estabilidad";
    std::string unstableEstability = "No estable";




    enum Importance {LOW, MEDIUM, HIGH};
    enum Development_phase {VALIDATION, VERIFICATION, IMPLEMENTATION, DEVELOPMENT, DEPLOYMENT, FINISHED};
    enum Estability {STABLE, UNSTABLE, NO};



    Importance ImportanceLevel;
    Importance UrgencyLevel;
    Development_phase phase;
    Estability estability;

public:
    //Trackeable(std::move(oid), std::move(objName), std::move(objDescription), std::move(objVersionMajor), std::move(objVersionMinor), objDate, std::move(objComments)),
    //          email(std::move(objEmail)),
    //          phone(std::move(objPhone)),
    //          address(std::move(objAddress))

    SystemObjetive(std::string oid, std::string objName, std::string objDescription,
                   std::string objVersionMajor, std::string objVersionMinor,
                   const Fecha& objDate, std::string objComments, std::string  objEmail,
                   std::string  objPhone, std::string  objAddress,
                   std::set<std::string> objTracesFrom, std::set<std::string> objTracesTo,
                   Importance objImportanceLevel, Importance objUrgencyLevel,
                   Development_phase objPhase, Estability objEstability);

};


#endif //TFG_SYSTEMOBJETIVE_H
