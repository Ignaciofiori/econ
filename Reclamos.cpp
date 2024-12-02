#include <cstring>
#include <iostream>
#include "Reclamos.h"

Reclamo::Reclamo() {
    _reclamoId = 0;
    _usuarioId = 0;
    _suministroId = 0;
    strcpy(_descripcion, "");
    _fechaReclamo = Fecha(); // Inicializa un objeto Fecha vacío
    strcpy(_estado, "");
    strcpy(_tipoDeReclamo, "");
    _responsableDeAtencion = 0;
    strcpy(_respuesta, "");
    strcpy(_prioridad, "");
    _activo = false;
}

Reclamo::Reclamo(int reclamoId, int usuarioId, int suministroId, char* descripcion,
                 Fecha fechaDeReclamo, char* estado, char* tipoDeReclamo, int responsableDeAtencion,
                 char* respuesta, char* prioridad) {
    _reclamoId = reclamoId;
    _usuarioId = usuarioId;
    _suministroId = suministroId;
    strcpy(_descripcion, descripcion);
    _fechaReclamo = fechaDeReclamo; // Asigna el objeto Fecha
    strcpy(_estado, estado);
    strcpy(_tipoDeReclamo, tipoDeReclamo);
    _responsableDeAtencion = responsableDeAtencion;
    strcpy(_respuesta, respuesta);
    strcpy(_prioridad, prioridad);
    _activo = true;
}

// Getters
int Reclamo::getReclamoId() {
    return _reclamoId;
}

int Reclamo::getUsuarioId() {
    return _usuarioId;
}

int Reclamo::getSuministroId() {
    return _suministroId;
}

char* Reclamo::getDescripcion() {
    return _descripcion;
}

Fecha Reclamo::getFechaReclamo() {
    return _fechaReclamo;
}

char* Reclamo::getEstado() {
    return _estado;
}

char* Reclamo::getTipoDeReclamo() {
    return _tipoDeReclamo;
}

int Reclamo::getResponsableDeAtencion() {
    return _responsableDeAtencion;
}

char* Reclamo::getRespuesta() {
    return _respuesta;
}

char* Reclamo::getPrioridad() {
    return _prioridad;
}

bool Reclamo::isActivo() {
    return _activo;
}

// Setters
void Reclamo::setReclamoId(int reclamoId) {
    _reclamoId = reclamoId;
}

void Reclamo::setUsuarioId(int usuarioId) {
    _usuarioId = usuarioId;
}

void Reclamo::setSuministroId(int suministroId) {
    _suministroId = suministroId;
}

void Reclamo::setDescripcion(char* descripcion) {
    strcpy(_descripcion, descripcion);
}

void Reclamo::setFechaReclamo(Fecha fechaDeReclamo) {
    _fechaReclamo = fechaDeReclamo;
}

void Reclamo::setEstado(char* estado) {
    strcpy(_estado, estado);
}

void Reclamo::setTipoDeReclamo(char* tipoDeReclamo) {
    strcpy(_tipoDeReclamo, tipoDeReclamo);
}

void Reclamo::setResponsableDeAtencion(int responsableDeAtencion) {
    _responsableDeAtencion = responsableDeAtencion;
}

void Reclamo::setRespuesta(char* respuesta) {
    strcpy(_respuesta, respuesta);
}

void Reclamo::setPrioridad(char* prioridad) {
    strcpy(_prioridad, prioridad);
}

void Reclamo::setActivo(bool activo) {
    _activo = activo;
}

void Reclamo::mostrarReclamo() {
    ArchivoUsuario archivoU("usuarios.dat");
    int posU = archivoU.BuscarUsuario(getResponsableDeAtencion());
    Usuario usuResponsable = archivoU.LeerUsuario(posU);

    std::cout << "===== INFORMACION DEL RECLAMO =====\n";
    std::cout << "ID Reclamo: " << getReclamoId() << std::endl;
    std::cout << "ID Usuario: " << getUsuarioId() << std::endl;
    std::cout << "ID Suministro: " << getSuministroId() << std::endl;
    std::cout << "Descripcion: " << getDescripcion() << std::endl;
    std::cout << "Fecha de Reclamo: " << getFechaReclamo().toString() << std::endl; // Usa el método de Fecha
    std::cout << "Estado: " << getEstado() << std::endl;
    std::cout << "Tipo de Reclamo: " << getTipoDeReclamo() << std::endl;
    std::cout << "Responsable de Atencion: " << usuResponsable.getNombre() << " " << usuResponsable.getApellido() << std::endl;
    std::cout << "Respuesta: " << getRespuesta() << std::endl;
    std::cout << "Prioridad: " << getPrioridad() << std::endl;
    std::cout << "Activo: " << (isActivo() ? "Si" : "No") << std::endl;
    std::cout << "===================================\n";
}
