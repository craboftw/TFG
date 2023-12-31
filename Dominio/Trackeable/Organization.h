#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <string>
#include <set>
#include "Trackeable.h"

class Organization : public Trackeable {
private:
    std::string contactInfo;
    inline static std::string prefixID = "OR";

public:

   explicit Organization(unsigned id): Trackeable(prefixID,id) {}
    Organization() : Trackeable(OID()) {}

        //Getters
        std::string getContactInfo() const;

        //Setters
        void setContactInfo(std::string _contactInfo);
        static std::string getPrefixID () {return prefixID;}
        void accept(Visitor* visitor) override;

};

#endif  // ORGANIZATION_H
