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
