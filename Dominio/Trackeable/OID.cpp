//
// Created by Fran- on 05/09/2023.
//
#include "OID.h"
std::string OID::getPrefix() const {
    return this->prefixID;
}

unsigned OID::getId() const {
    return this->id;
}

bool OID::operator<(const OID& rhs) const {
    return this->operator std::string() < rhs.operator std::string();
}

bool OID::operator>(const OID& rhs) const {
    return this->operator std::string() > rhs.operator std::string();
}

bool OID::operator==(const OID rhs) const {
    return this->operator std::string() == rhs.operator std::string();
}

bool OID::operator!=(const OID& rhs) const {
    return this->operator std::string() != rhs.operator std::string();
}

bool OID::operator<=(const OID& rhs) const {
    return this->operator std::string() <= rhs.operator std::string();
}

bool OID::operator>=(const OID& rhs) const {
    return this->operator std::string() >= rhs.operator std::string();
}