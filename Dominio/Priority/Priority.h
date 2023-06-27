//
// Created by craboftw on 20/06/23.
//

#ifndef TFG_PRIORITY_H
#define TFG_PRIORITY_H

#include <string>

class Priority{

public:
    Priority(){
        importanceLevel = NO;
        urgencyLevel = NO;
        phase = PENDDING;
        estability = NONE;
    }

    enum Importance {LOW, MEDIUM, HIGH,NO};
    enum Development_phase {VALIDATION, VERIFICATION, IMPLEMENTATION, DEVELOPMENT, DEPLOYMENT, FINISHED, PENDDING};
    enum Estability {STABLE, UNSTABLE, NONE};

    //Operador de asignacion
    Priority& operator=(const Priority& other){
        importanceLevel = other.importanceLevel;
        urgencyLevel = other.urgencyLevel;
        phase = other.phase;
        estability = other.estability;
        return *this;
    }

    void setImportanceLevel(Importance importanceLevel) {
        importanceLevel = importanceLevel;
    }

    void setUrgencyLevel(Importance urgencyLevel) {
        urgencyLevel = urgencyLevel;
    }

    void setPhase(Development_phase _phase) {
        Priority::phase = _phase;
    }

    void setEstability(Estability _estability) {
        Priority::estability = _estability;
    }

    Importance getImportanceLevel() const {
        return importanceLevel;
    }

    Importance getUrgencyLevel() const {
        return urgencyLevel;
    }

    Development_phase getPhase() const {
        return phase;
    }

    Estability getEstability() const {
        return estability;
    }

    std::string strImportanceLevel() {
        switch (importanceLevel) {
            case LOW:
                return lowLevelImportance;
            case MEDIUM:
                return mediumLevelImportance;
            case HIGH:
                return highLevelImportance;
            default:
                return "No se ha establecido la importancia";
        }
    }

    std::string strUrgencyLevel() {
        switch (urgencyLevel) {
            case LOW:
                return lowLevelUrgency;
            case MEDIUM:
                return mediumLevelUrgency;
            case HIGH:
                return highLevelUrgency;
            default:
                return "No se ha establecido la urgencia";
        }
    }

    std::string strPhase() {
        switch (phase) {
            case VALIDATION:
                return inceptionPhase;
            case VERIFICATION:
                return elaborationPhase;
            case IMPLEMENTATION:
                return constructionPhase;
            case DEVELOPMENT:
                return inDevelopmentPhase;
            case DEPLOYMENT:
                return transitionPhase;
            case FINISHED:
                return phinishedPhase;
            default:
                return "No se ha establecido la fase de desarrollo";
        }
    }

    std::string strEstability() {
        switch (estability) {
            case STABLE:
                return stableEstability;
            case UNSTABLE:
                return unstableEstability;
            default:
                return "No se ha establecido la estabilidad";
        }
    }
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








    Importance importanceLevel;
    Importance urgencyLevel;
    Development_phase phase;
    Estability estability;


};


#endif //TFG_PRIORITY_H
