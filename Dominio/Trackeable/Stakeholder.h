#ifndef STAKEHOLDER_H
#define STAKEHOLDER_H

#include <string>
#include <iostream>
#include "Trackeable.h"
#include "TFG/Visitor/Visitor.h"

class Rol_Stakeholder : public Trackeable {
public:

    std::string description;

    explicit Rol_Stakeholder(std::string id) : Trackeable(std::move(id)), description("") {};
};

class Stakeholder : public Trackeable {
private:
    std::string email;
    std::string phone;
    std::string address;
    OID stakeholderRole;
    OID worksForOrganization;

public:
    Stakeholder(std::string id): Trackeable(std::move(id)), email(""),  phone("") , address(""), worksForOrganization("")  {}

    //Getters
    std::string getEmail() const {return email;}
    std::string getPhone() const {return phone;}
    std::string getAddress() const {return address;}
    OID getStakeholderRole() const {return stakeholderRole;}
    OID getWorksForOrganization() const {return worksForOrganization;}

    //Setters
    void setEmail(std::string _email) {email = std::move(_email);}
    void setPhone(std::string _phone) {phone = std::move(_phone);}
    void setAddress(std::string _address) {address = std::move(_address);}
    void setStakeholderRole(OID _stakeholderRole) {stakeholderRole = std::move(_stakeholderRole);}
    void setWorksForOrganization(OID _worksForOrganization) {worksForOrganization = std::move(_worksForOrganization);}
    void accept(Visitor* visitor) override;
};



#endif  // STAKEHOLDER_H
