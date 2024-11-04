#include "Fecha.h"

 Fecha::Fecha(){
            _id = 0;
            _dia = 0;
            _mes = 0;
            _anio = 0;
         }

 Fecha::Fecha(int id, int d, int m, int a) {
    if (a <= 0 || m < 1 || m > 12) {
        _id = 0;
        _dia = 0;
        _mes = 0;
        _anio = 0;
        return;
    }

    int diasxMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (esBisiesto(a)) {
        diasxMes[1]++;
    }

    if (d < 1 || d > diasxMes[m - 1]) {
        _id = 0;
        _dia = 0;
        _mes = 0;
        _anio = 0;
        return;
    }

    _id = id;
    _dia = d;
    _mes = m;
    _anio = a;
}


int Fecha::getId()  { return _id; }
int Fecha::getDia()  { return _dia; }
int Fecha::getMes()  { return _mes; }
int Fecha::getAnio()  { return _anio; }

// Setters
void Fecha::setId(int id) {
    if (id >= 0) {
        _id = id;
    } else {
        _id = 0;
    }
}
void Fecha::setDia(int d) {
    if (d >= 1 && d <= 31) {
        _dia = d;
    } else {
        _dia = 0;
    }
}

void Fecha::setMes(int m) {
    if (m >= 1 && m <= 12) {
        _mes = m;
    } else {
        _mes = 0;
    }
}

void Fecha::setAnio(int a) {
    if (a > 0) {
        _anio = a;
    } else {
        _anio = 0;
    }
}

bool Fecha::esBisiesto(int a){

    return (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
};


void Fecha::FechaActual(){
        time_t timestamp = time(0);
        tm *diaactual = localtime(&timestamp);
        _dia = diaactual->tm_mday;
        _mes = diaactual->tm_mon+1;
        _anio = diaactual->tm_year+1900;
    }


std::string Fecha::toString(){
    std::string fechaADevolver;
    fechaADevolver = std::to_string(_dia) + "/";
    fechaADevolver += std::to_string(_mes) + "/";
    fechaADevolver += std::to_string(_anio);
    return fechaADevolver;

}

