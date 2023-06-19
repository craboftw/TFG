#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <string>
#include <iostream>
#include <set>
#include "Trackeable.h"

class Organization : public Trackeable {
private:
    std::string contactInfo;
    std::set<Stakeholder*> stakeholders;

public:
    Organization(const std::string& company, const std::string& contactInfo,
                 const std::string& description, const std::string& comments = "");

    void print() const;
};

#endif  // ORGANIZATION_H
