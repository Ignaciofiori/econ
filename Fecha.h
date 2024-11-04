#pragma once
#include <iostream>
#include "ArchivoAcumulador.h"
#include "AcumuladorId.h"
#include <cstring>
#include <ctime>

class Fecha{

private:
    int _id;
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha ();
    Fecha(int id, int d, int m, int a);

// Getters
    int getId();
    int getDia() ;
    int getMes() ;
    int getAnio() ;

    // Setters
    void setId(int id);
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    void Mostrar();
    bool esBisiesto(int a);
    void FechaActual();
    std::string toString();

};
