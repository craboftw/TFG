//
// Created by Fran- on 18/06/2023.
//

#ifndef TFG_FECHA_H
#define TFG_FECHA_H

#include <stdexcept>
#include <iostream>
#include <string>

class Fecha {
public:
    int year;
    int month;
    int day;

    Fecha(int year, int month, int day);
    Fecha(const Fecha& fecha);
    Fecha();
    Fecha(const std::string& fecha);

    std::string toString();

private:
    void comprobarFecha(int year, int month, int day);
};

#endif //TFG_FECHA_H
