#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <string>
#include <iostream>
#include <set>
#include "Trackeable.h"

class Organization : public Trackeable {
private:
    std::string contactInfo;
    inline static std::string prefixID = "OR-";

public:

   explicit Organization(OID id): Trackeable(prefixID+id) {}

        //Getters
        std::string getContactInfo() const;

        //Setters
        void setContactInfo(std::string _contactInfo);
        void accept(Visitor* visitor) override;
};

#endif  // ORGANIZATION_H
