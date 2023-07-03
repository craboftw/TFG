#ifndef STAKEHOLDER_H
#define STAKEHOLDER_H

#include <string>
#include <iostream>
#include "Trackeable.h"
#include "Visitor/Visitor.h"


class Stakeholder : public Trackeable {
private:
    std::string email;
    std::string phone;
    std::string address;
    std::string stakeholderRole;
    OID worksForOrganization;
    inline static std::string prefixID = "SH";

public:
    explicit Stakeholder(unsigned id): Trackeable(prefixID,id), email(""),  phone("") , address(""), worksForOrganization(),stakeholderRole()  {}

    //Getters
    std::string getEmail() const {return email;}
    std::string getPhone() const {return phone;}
    std::string getAddress() const {return address;}
    std::string getStakeholderRole() const {return stakeholderRole;}
    OID getWorksForOrganization() const {return worksForOrganization;}

    //Setters
    void setEmail(std::string _email) {email = std::move(_email);}
    void setPhone(std::string _phone) {phone = std::move(_phone);}
    void setAddress(std::string _address) {address = std::move(_address);}
    void setStakeholderRole(std::string _stakeholderRole) {stakeholderRole = std::move(_stakeholderRole);}
    void setWorksForOrganization(OID _worksForOrganization) {worksForOrganization = std::move(_worksForOrganization);}
    void accept(Visitor* visitor) override;

    static std::string getPrefixID () {return prefixID;}
};



#endif  // STAKEHOLDER_H
