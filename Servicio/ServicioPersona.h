//
// Created by Fran- on 20/07/2023.
//

#ifndef TFG_SERVICIOPERSONA_H
#define TFG_SERVICIOPERSONA_H


#include "ServicioTrackeable.h"

class ServicioPersona : public ServicioTrackeable{
    /*unsigned age;
    std::string gender;
    std::string location;
    std::string occupation;
    std::string background;
    std::string goals;
    std::string challenges;
    std::string behavior;
    std::string communicationStyle;
    std::string technologyAdoption;
    std::string influences;
    std::string informationSources;
    std::string userJourney;
    std::string brandRelationship*/

    public:
    OID createPersona();
    void setAge(OID id, unsigned age);
    void setGender(OID id, const std::string &gender);
    void setLocation(OID id, const std::string &location);
    void setOccupation(OID id, const std::string &occupation);
    void setBackground(OID id, const std::string &background);
    void setGoals(OID id, const std::string &goals);
    void setChallenges(OID id, const std::string &challenges);
    void setBehavior(OID id, const std::string &behavior);
    void setCommunicationStyle(OID id, const std::string &communicationStyle);
    void setTechnologyAdoption(OID id, const std::string &technologyAdoption);
    void setInfluences(OID id, const std::string &influences);
    void setInformationSources(OID id, const std::string &informationSources);
    void setUserJourney(OID id, const std::string &userJourney);
    void setBrandRelationship(OID id, const std::string &brandRelationship);

    unsigned getAge(OID id);
    std::string getGender(OID id);
    std::string getLocation(OID id);
    std::string getOccupation(OID id);
    std::string getBackground(OID id);
    std::string getGoals(OID id);
    std::string getChallenges(OID id);
    std::string getBehavior(OID id);
    std::string getCommunicationStyle(OID id);
    std::string getTechnologyAdoption(OID id);
    std::string getInfluences(OID id);
    std::string getInformationSources(OID id);
    std::string getUserJourney(OID id);
    std::string getBrandRelationship(OID id);

    std::string getPhoto(OID id);

    void setPhoto(OID id, const std::string &photo);
};


#endif //TFG_SERVICIOPERSONA_H
