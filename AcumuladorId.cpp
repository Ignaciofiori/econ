#include "AcumuladorId.h"

AcumuladorId::AcumuladorId(){
_idSuministro = 0; // Acumulador para el ID de suministros
_idUsuarios = 0;   // Acumulador para el ID de usuarios
_idReclamos = 0;   // Acumulador para el ID de reclamos
_idFacturas = 0; // Acumulador para el ID de suministros
_idRespuestas = 0;

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

int AcumuladorId::getIdFacturas()  {
    return _idFacturas;
}

int AcumuladorId::getIdRespuestas(){
    return _idRespuestas;
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
void AcumuladorId::setIdFacturas(int id) {
    _idFacturas= id;
}
void AcumuladorId::setIdRespuestas(int id){
    _idRespuestas = id;
}
