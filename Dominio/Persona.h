//
// Created by Fran- on 20/07/2023.
//

#ifndef TFG_PERSONA_H
#define TFG_PERSONA_H


#include "Dominio/Trackeable/Trackeable.h"

class Persona : public Trackeable{


private:
    unsigned age;
    std::string gender;
    std::string location;
    std::string photo;    std::string occupation;
    std::string background;
    std::string goals;
    std::string challenges;
    std::string behavior;
    std::string communicationStyle;
    std::string technologyAdoption;
    std::string influences;
    std::string informationSources;
    std::string userJourney;
    std::string brandRelationship;
    inline static std::string prefix = "PS";

public:
    Persona(unsigned id): Trackeable(prefix, id),age(0){};
    Persona(): Trackeable(){};
    const std::string &getPhoto() const;
    void setPhoto(const std::string &photo);


    unsigned getAge() const;

    void setAge(unsigned age);

    const std::string &getGender() const;

    void setGender(const std::string &gender);

    const std::string &getLocation() const;

    void setLocation(const std::string &location);

    const std::string &getOccupation() const;

    void setOccupation(const std::string &occupation);

    const std::string &getBackground() const;

    void setBackground(const std::string &background);

    const std::string &getGoals() const;

    void setGoals(const std::string &goals);

    const std::string &getChallenges() const;

    void setChallenges(const std::string &challenges);

    const std::string &getBehavior() const;

    void setBehavior(const std::string &behavior);

    const std::string &getCommunicationStyle() const;

    void setCommunicationStyle(const std::string &communicationStyle);

    const std::string &getTechnologyAdoption() const;

    void setTechnologyAdoption(const std::string &technologyAdoption);

    const std::string &getInfluences() const;

    void setInfluences(const std::string &influences);

    const std::string &getInformationSources() const;

    void setInformationSources(const std::string &informationSources);

    const std::string &getUserJourney() const;

    void setUserJourney(const std::string &userJourney);

    const std::string &getBrandRelationship() const;

    void setBrandRelationship(const std::string &brandRelationship);

    inline static std::string getPrefixID() {
        return prefix;
    }
};

#endif //TFG_PERSONA_H
