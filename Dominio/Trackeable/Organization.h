#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <string>
#include <iostream>
#include <set>
#include "Trackeable.h"

class Organization : public Trackeable {
private:
    std::string contactInfo;

public:

   Organization(OID id): Trackeable(std::move(id)) {}
};

#endif  // ORGANIZATION_H
