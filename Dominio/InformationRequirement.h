//
// Created by Fran- on 22/06/2023.
//

#ifndef TFG_INFORMATION_REQUIREMENT_H
#define TFG_INFORMATION_REQUIREMENT_H

#include "Dominio/Trackeable/Trackeable.h"
#include "Dominio/Priority/Priority.h"
#include <string>

struct SpecificInformation
{
    unsigned int id;
    std::string name;
    std::string description;
};

class InformationRequirement : virtual public Trackeable , public Priority {
    unsigned int maxSimultaneousOccurrence;
    unsigned int avgSimultaneousOccurrence;
    TimeQuantity lifeMaxEstimate;
    TimeQuantity lifeAvgEstimate;
    std::list<SpecificInformation> specificInformation;

public:
    explicit InformationRequirement(unsigned id)
            : Trackeable(prefixID,id),
              Priority(),
              maxSimultaneousOccurrence(0),
              avgSimultaneousOccurrence(0),
              lifeMaxEstimate(TimeQuantity()),
              lifeAvgEstimate(TimeQuantity()) {}
    InformationRequirement() : Trackeable(OID()),
                               Priority(),
                               maxSimultaneousOccurrence(0),
                               avgSimultaneousOccurrence(0),
                               lifeMaxEstimate(TimeQuantity()),
                               lifeAvgEstimate(TimeQuantity()) {}

              static std::string getPrefixID();

    unsigned int getMaxSimultaneousOccurrence() const;
    unsigned int getAvgSimultaneousOccurrence() const;
    TimeQuantity getLifeMaxEstimate() const;
    TimeQuantity getLifeAvgEstimate() const;
    std::list<SpecificInformation> getSpecificInformation() const;

    std::string strMaxSimultaneousOccurrence() const;
    std::string strAvgSimultaneousOccurrence() const;
    std::string strLifeMaxEstimate() const;
    std::string strLifeAvgEstimate() const;

    void setMaxSimultaneousOccurrence(unsigned int maxSimultaneousOccurrence);
    void setAvgSimultaneousOccurrence(unsigned int avgSimultaneousOccurrence);
    void setLifeMaxEstimate(const TimeQuantity &lifeMaxEstimate);
    void setLifeAvgEstimate(const TimeQuantity &lifeAvgEstimate);
    void setSpecificInformation(const std::list<SpecificInformation> &specificInformation);
    void addSpecificInformation(const std::string name, const std::string description);

    void removeSpecificInformation(const unsigned id);
    void setSpecificInformationName(const unsigned id, const std::string &name);
    void setSpecificInformationDescription(const unsigned id, const std::string &description);
    void accept(Visitor* visitor) override ;


private:
    inline static std::string prefixID = "IR";

};




#endif //TFG_INFORMATION_REQUIREMENT_H
