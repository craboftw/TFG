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

    void comprobarFecha(int year, int month, int day);
    void print() const;
};

#endif //TFG_FECHA_H
