#include "Periodo.h"
#include <iostream>

// Constructor por defecto
Periodo::Periodo() {
    _mes = 0;  // Mes por defecto: enero
    _anio = 0;  // Año por defecto: 2000
}

// Constructor con parámetros
Periodo::Periodo(int mes, int anio) {
    _mes = (mes >= 1 && mes <= 12) ? mes : 0;  // Validar mes
    _anio = anio;
}

// Getters
int Periodo::getMes() {
    return _mes;
}

int Periodo::getAnio() {
    return _anio;
}

// Setters
void Periodo::setMes(int mes) {
   _mes = (mes >= 1 && mes <= 12) ? mes : 0;  // Validar mes
}

void Periodo::setAnio(int anio) {
   _anio = anio;
}

// Método para mostrar el periodo en formato "mes-anio"
std::string Periodo::toString() {
    std::string periodoADevolver;
    periodoADevolver = std::to_string(_mes) + "-";
    periodoADevolver += std::to_string(_anio);
    return periodoADevolver;
}
