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
   //El constructor recibira los parametros de la clase padre y los de la clase hija
   //Trackeable(std::string oid, std::string objName, std::string objDescription,
    //                       std::string versionMaj, std::string versionMin, const Fecha& objDate,
    //                       std::string objComments)
   Organization(std::string oid1, std::string objName1, std::string objDescription1,
                std::string versionMaj1, std::string versionMin1, const Fecha &objDate1,
                std::string objComments1, std::string oid, std::string objName,
                std::string objDescription, std::string versionMaj, std::string versionMin,
                const Fecha &objDate, std::string objComments, std::string objContactInfo);
};

#endif  // ORGANIZATION_H
