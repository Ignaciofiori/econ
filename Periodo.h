#pragma once
#include <string>

class Periodo {
private:
    int _mes;
    int _anio;

public:
    Periodo();
    Periodo(int mes, int anio);


    int getMes();
    int getAnio();


    void setMes(int mes);
    void setAnio(int anio);


    std::string toString();
};
