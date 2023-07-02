//
// Created by Fran- on 18/06/2023.
//

#include "Fecha.h"
//definimos los metodos de la clase Fecha

    void Fecha::comprobarFecha(int year, int month, int day)
    {
        if (year < 0 || month < 0 || day < 0){
            throw std::invalid_argument("Fecha no valida");
        }
        if (month > 12){
            throw std::invalid_argument("Fecha no valida");
        }
        //comprobar que el dia es correcto
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            || month == 10 || month == 12) {
            if (day > 31) {
                throw std::invalid_argument("Fecha no valida");
            }
        }
        else
        {
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (day > 30) {
                    throw std::invalid_argument("Fecha no valida");
                }
            }
            else
            {
                if (month == 2) {
                    if (year % 4 == 0) {
                        if (day > 29) {
                            throw std::invalid_argument("Fecha no valida");
                        }
                    }
                    else
                    {
                        if (day > 28) {
                            throw std::invalid_argument("Fecha no valida");
                        }
                    }
                }
            }
        }
    }

Fecha::Fecha(const Fecha &fecha) {
    this->year = fecha.year;
    this->month = fecha.month;
    this->day = fecha.day;
}

Fecha::Fecha(int year, int month, int day) {
    comprobarFecha(year, month, day);
    this->year = year;
    this->month = month;
    this->day = day;
}

Fecha::Fecha() {
    //fecha actual con mktime
    time_t t = time(0);
    struct tm * now = localtime( & t );
    this->year = now->tm_year + 1900;
    this->month = now->tm_mon + 1;
    this->day = now->tm_mday;
    //std::string fechaformal = "19:12:2013T16:30:00.000"
}

Fecha::Fecha(const std::string &fecha) {
    int parseyear = std::stoi(fecha.substr(0, 4));
    int parsemonth = std::stoi(fecha.substr(5,2));
    int parseday = std::stoi(fecha.substr(8,2));
    comprobarFecha(parseyear, parsemonth, parseday);
    this->year = parseyear;
    this->month = parsemonth;
    this->day = parseday;
}

std::string Fecha::toString() {
    if (month < 10)
        return std::to_string(this->year) + "-0" + std::to_string(this->month) + "-" + std::to_string(this->day);
    else
        return std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
}


bool Fecha::operator==(const Fecha &fecha) {
    return this->year == fecha.year && this->month == fecha.month && this->day == fecha.day;
}

bool Fecha::operator!=(const Fecha &fecha) {
    return this->year != fecha.year || this->month != fecha.month || this->day != fecha.day;
}

bool Fecha::operator<(const Fecha &fecha) {
    if (this->year < fecha.year)
        return true;
    else if (this->year == fecha.year)
    {
        if (this->month < fecha.month)
            return true;
        else if (this->month == fecha.month)
        {
            if (this->day < fecha.day)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Fecha::operator>(const Fecha &fecha) {
    if (this->year > fecha.year)
        return true;
    else if (this->year == fecha.year)
    {
        if (this->month > fecha.month)
            return true;
        else if (this->month == fecha.month)
        {
            if (this->day > fecha.day)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Fecha::operator<=(const Fecha &fecha) {
    if (this->year < fecha.year)
        return true;
    else if (this->year == fecha.year)
    {
        if (this->month < fecha.month)
            return true;
        else if (this->month == fecha.month)
        {
            if (this->day <= fecha.day)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Fecha::operator>=(const Fecha &fecha) {
    if (this->year > fecha.year)
        return true;
    else if (this->year == fecha.year)
    {
        if (this->month > fecha.month)
            return true;
        else if (this->month == fecha.month)
        {
            if (this->day >= fecha.day)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

int Fecha::getYear() const {
    return 0;
}

int Fecha::getMonth() const {
    return 0;
}

int Fecha::getDay() const {
    return 0;
}

