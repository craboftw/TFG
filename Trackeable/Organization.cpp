#include "Organization.h"


Organization::Organization(std::string oid1, std::string objName1, std::string objDescription1,
                           std::string versionMaj1, std::string versionMin1, const Fecha &objDate1,
                           std::string objComments1, std::string oid, std::string objName,
                           std::string objDescription, std::string versionMaj, std::string versionMin,
                           const Fecha &objDate, std::string objComments, std::string objContactInfo)
                           :Trackeable(oid1, objName1, versionMaj1, versionMin1, objDate1, objComments1),
                           contactInfo(std::move(objContactInfo)) {}


