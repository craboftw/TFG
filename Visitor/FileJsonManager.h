//
// Created by Fran- on 26/06/2023.
//

#ifndef TFG_FILEJSONMANAGER_H
#define TFG_FILEJSONMANAGER_H

#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <string>


using json = nlohmann::json;


class FileJsonManager {
public:
    static void save(json singlejson);
};


#endif //TFG_FILEJSONMANAGER_H
