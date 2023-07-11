#include "Organization.h"


std::string Organization::getContactInfo() const {
    return contactInfo;
}

void Organization::setContactInfo(std::string _contactInfo) {
    contactInfo = _contactInfo;
}

void Organization::accept(Visitor *visitor) {
    Trackeable::accept(visitor);
}


