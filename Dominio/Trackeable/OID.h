//
// Created by Fran- on 05/09/2023.
//

#ifndef TFG_OID_H
#define TFG_OID_H

#include "./Fecha.h"
#include <list>
#include <iostream>
#include <utility>
#include <set>
#include <string>

class OID {
private:
    std::string prefixID;
    unsigned id;

public:
    OID(std::string prefixID, unsigned id): prefixID(std::move(prefixID)), id(id) {}

    OID(): prefixID("XX"), id(0) {}

    std::string getPrefix() const;
    unsigned getId() const;
    bool operator<(const OID& rhs) const;
    bool operator>(const OID& rhs) const;
    bool operator<=(const OID& rhs) const;
    bool operator>=(const OID& rhs) const;
    bool operator==(const OID rhs) const;
    bool operator!=(const OID& rhs) const;
    operator std::string () const {
        return prefixID + std::to_string(id);
    }
    OID operator = (const OID& rhs) {
        prefixID = rhs.prefixID;
        id = rhs.id;
        return *this;
    }




};


#endif //TFG_OID_H
