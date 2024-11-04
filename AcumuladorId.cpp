#include "AcumuladorId.h"

AcumuladorId::AcumuladorId(){
_idSuministro = 0; // Acumulador para el ID de suministros
_idUsuarios = 0;   // Acumulador para el ID de usuarios
_idReclamos = 0;   // Acumulador para el ID de reclamos
_idFechas = 0; // Acumulador para el ID de suministros


}

// Getters
int AcumuladorId::getIdSuministro()  {
    return _idSuministro;
}

int AcumuladorId::getIdUsuarios()  {
    return _idUsuarios;
}

int AcumuladorId::getIdReclamos()  {
    return _idReclamos;
}

int AcumuladorId::getIdFechas()  {
    return _idFechas;
}
// Setters
void AcumuladorId::setIdSuministros(int id) {
    _idSuministro = id;
}

void AcumuladorId::setIdUsuarios(int id) {
    _idUsuarios = id;
}

void AcumuladorId::setIdReclamos(int id) {
    _idReclamos = id;
}
void AcumuladorId::setIdFechas(int id) {
    _idFechas = id;
}

