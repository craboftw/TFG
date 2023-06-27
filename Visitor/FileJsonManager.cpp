//
// Created by Fran- on 26/06/2023.
//

#include "FileJsonManager.h"

/*guardar un objeto trackeable derivado en un fichero json:
1. crear un objeto json
2. añadirle los atributos del objeto trackeable derivado
 3. cargar una lista del objeto trackeable derivado del fichero json
    4. añadir o modificar el stakeholder en la lista
    5. guardar la lista en el fichero json
*/

/* cargar un objeto stakeholder de un fichero json:
1. cargar una lista de stakeholders del fichero json
2. buscar el stakeholder en la lista
3. devolver el stakeholder
*/

// for convenience

void FileJsonManager::save(json singlejson) {

    std::string typeOfTrackeable = singlejson["id"].get<std::string>().substr(0, 2);
    std::string path = "TFG/Jsons/" + typeOfTrackeable + ".json";
// Open the file in input mode to check if it exists
    std::ifstream i(path);
    json listaj;

// Check if the file exists and load its contents into listaj if it does
    if (i.good()) {
        i >> listaj;
    }
    else
    {
        //create the file if it doesn't exist
        std::ofstream o(path);
    }

    std::string fullPath = std::filesystem::absolute(path).string();
    std::cout << "File path: " << fullPath << std::endl;

// Add the new json object to the listaj
    listaj[singlejson["id"]] = singlejson;

// Open the file in output mode to save the updated json
    std::ofstream o(path);
    o << std::setw(4) << listaj << std::endl;

}