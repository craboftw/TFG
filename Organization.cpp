#include "Organization.h"

Organization::Organization(const std::string& company, const std::string& contactInfo,
                           const std::string& description, const std::string& comments)
        : Trackeable("", company, description, "", "", Fecha(), comments),
          contactInfo(contactInfo) {}

void Organization::print() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Contact info: " << contactInfo << std::endl;
}
