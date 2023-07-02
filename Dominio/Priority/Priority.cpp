//
// Created by craboftw on 20/06/23.
//

#include "Priority.h"

Priority::Priority() {
    importanceLevel = NO;
    urgencyLevel = NO;
    phase = PENDDING;
    estability = NONE;

    // Initialize constant strings
    highLevelImportance = "Importancia vital";
    mediumLevelImportance = "Importancia considerable";
    lowLevelImportance = "Importancia baja";
    highLevelUrgency = "Urgencia alta";
    mediumLevelUrgency = "Urgencia media";
    lowLevelUrgency = "Urgencia baja";
    inceptionPhase = "Pendiente de validacion";
    elaborationPhase = "Pendiente de verificacion";
    constructionPhase = "Pendiente de implementacion";
    inDevelopmentPhase = "En desarrollo";
    transitionPhase = "Pendiente de despliegue";
    finishedPhase = "Finalizado";
    stableEstability = "Alta estabilidad";
    mediumEstability = "Baja estabilidad";
    unstableEstability = "No estable";
}

Priority& Priority::operator=(const Priority& other) {
    importanceLevel = other.importanceLevel;
    urgencyLevel = other.urgencyLevel;
    phase = other.phase;
    estability = other.estability;
    return *this;
}

void Priority::setImportanceLevel(Importance importanceLevel) {
    this->importanceLevel = importanceLevel;
}

void Priority::setUrgencyLevel(Importance urgencyLevel) {
    this->urgencyLevel = urgencyLevel;
}

void Priority::setPhase(Development_phase _phase) {
    phase = _phase;
}

void Priority::setEstability(Estability _estability) {
    estability = _estability;
}

Priority::Importance Priority::getImportanceLevel() const {
    return importanceLevel;
}

Priority::Importance Priority::getUrgencyLevel() const {
    return urgencyLevel;
}

Priority::Development_phase Priority::getPhase() const {
    return phase;
}

Priority::Estability Priority::getEstability() const {
    return estability;
}

std::string Priority::strImportanceLevel() {
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

std::string Priority::strUrgencyLevel() {
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

std::string Priority::strPhase() {
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
            return finishedPhase;
        default:
            return "No se ha establecido la fase de desarrollo";
    }
}

std::string Priority::strEstability() {
    switch (estability) {
        case STABLE:
            return stableEstability;
        case UNSTABLE:
            return unstableEstability;
        default:
            return "No se ha establecido la estabilidad";
    }
}
