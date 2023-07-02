#ifndef TFG_PRIORITY_H
#define TFG_PRIORITY_H

#include <string>
#include "Dominio/Trackeable/Trackeable.h"

class Priority : virtual public Trackeable{
public:
    Priority();

    enum Importance {LOW, MEDIUM, HIGH, NO};
    enum Development_phase {VALIDATION, VERIFICATION, IMPLEMENTATION, DEVELOPMENT, DEPLOYMENT, FINISHED, PENDDING};
    enum Estability {STABLE, UNSTABLE, NONE};

    Priority& operator=(const Priority& other);

    void setImportanceLevel(Importance importanceLevel);
    void setUrgencyLevel(Importance urgencyLevel);
    void setPhase(Development_phase _phase);
    void setEstability(Estability _estability);
    
    std::string strImportanceLevel();
    std::string strUrgencyLevel();
    std::string strPhase();
    std::string strEstability();

    Importance getImportanceLevel() const;
    Importance getUrgencyLevel() const;
    Development_phase getPhase() const;
    Estability getEstability() const;

    void setID(OID id){this->id = id;}




private:
    std::string highLevelImportance;
    std::string mediumLevelImportance;
    std::string lowLevelImportance;
    std::string highLevelUrgency;
    std::string mediumLevelUrgency;
    std::string lowLevelUrgency;
    std::string inceptionPhase;
    std::string elaborationPhase;
    std::string constructionPhase;
    std::string inDevelopmentPhase;
    std::string transitionPhase;
    std::string finishedPhase;
    std::string stableEstability;
    std::string mediumEstability;
    std::string unstableEstability;

    Importance importanceLevel;
    Importance urgencyLevel;
    Development_phase phase;
    Estability estability;
};

#endif //TFG_PRIORITY_H
