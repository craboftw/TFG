//
// Created by Fran- on 18/06/2023.
//

#ifndef TFG_FECHA_H
#define TFG_FECHA_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <ctime>

class Fecha {
public:


    Fecha(int year, int month, int day);
    Fecha(const Fecha& fecha);
    Fecha();
    bool operator==(const Fecha& fecha);
    bool operator!=(const Fecha& fecha);
    bool operator<(const Fecha& fecha);
    bool operator>(const Fecha& fecha);
    bool operator<=(const Fecha& fecha);
    bool operator>=(const Fecha& fecha);
    Fecha(const std::string& fecha);
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    std::string toString();

private:
    void comprobarFecha(int year, int month, int day);
    int year;
    int month;
    int day;
};


class TimeQuantity{
public:
    enum Unit {YEAR, MONTH, WEEK, DAY, HOUR, MINUTE, SECOND, MILLISECOND};

private:
    unsigned quantity;
    Unit unit;

public: TimeQuantity() : quantity(0), unit(MONTH) {}
    TimeQuantity(unsigned _quantity, Unit _unit) : quantity(_quantity), unit(_unit) {}

    unsigned getQuantity() const {return quantity;}
    Unit getUnit() const {return unit;}

    void setQuantity(unsigned _quantity) {quantity = _quantity;}
    void setUnit(Unit _unit) {unit = _unit;}
};

#endif //TFG_FECHA_H
