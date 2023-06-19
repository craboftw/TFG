//
// Created by Fran- on 18/06/2023.
//

#ifndef TFG_FECHA_H
#define TFG_FECHA_H


#include <stdexcept>
#include <iostream>

class Fecha {
public:
    int year;
    int month;
    int day;

    Fecha(int year, int month, int day){
        //comprobar que la fecha es correcta
        comprobarFecha(year, month, day);
        this->year = year;
        this->month = month;
        this->day = day;
    }

    Fecha(const Fecha& fecha){
        this->year = fecha.year;
        this->month = fecha.month;
        this->day = fecha.day;
    }

    //Constructor vacio que ponga la fecha del dia actual
    Fecha(){
        time_t t = time(0);
        struct tm * now = localtime( & t );
        this->year = now->tm_year + 1900;
        this->month = now->tm_mon + 1;
        this->day = now->tm_mday;

    }

    Fecha& operator=(const Fecha& fecha){
        this->year = fecha.year;
        this->month = fecha.month;
        this->day = fecha.day;
        return *this;
    }

    bool operator==(const Fecha& fecha){
        return this->year == fecha.year && this->month == fecha.month && this->day == fecha.day;
    }

    Fecha(const std::string& fecha){
        //comprobar que la fecha es correcta
        int year = std::stoi(fecha.substr(0, 4));
        int month = std::stoi(fecha.substr(5, 2));
        int day = std::stoi(fecha.substr(8, 2));
        comprobarFecha(year, month, day);
        this->year = year;
        this->month = month;
        this->day = day;
    }
    void comprobarFecha(int year, int month, int day);
    void print() const {std::cout << year << "/" << month << "/" << day;}
};


#endif //TFG_FECHA_H
