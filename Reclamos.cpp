#include <cstring>
#include "Reclamos.h"

Reclamo::Reclamo() {
    _reclamoId = 0;
    _usuarioId = 0;
    _suministroId = 0;
    strcpy(_descripcion, "");
    _fechaReclamo = 0;
    strcpy(_estado, "");
    strcpy(_tipoDeReclamo, "");
    _responsableDeAtencion = 0;
    strcpy(_respuesta, "");
    strcpy(_prioridad, "");
    _activo = false;
}

Reclamo::Reclamo(int reclamoId,int usuarioId,int suministroId, const char* descripcion,
            int fechaReclamo, const char* estado, const char* tipoDeReclamo,int responsableDeAtencion,
            const char* respuesta, const char* prioridad){

    _reclamoId = reclamoId;
    _usuarioId = usuarioId;
    _suministroId = suministroId;
    strcpy(_descripcion, descripcion);
    _fechaReclamo = fechaReclamo ;
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

const char* Reclamo::getDescripcion() {
    return _descripcion;
}

int Reclamo::getFechaReclamo() {
    return _fechaReclamo;
}

const char* Reclamo::getEstado() {
    return _estado;
}

const char* Reclamo::getTipoDeReclamo() {
    return _tipoDeReclamo;
}

int Reclamo::getResponsableDeAtencion() {
    return _responsableDeAtencion;
}

const char* Reclamo::getRespuesta() {
    return _respuesta;
}

const char* Reclamo::getPrioridad() {
    return _prioridad;
}

bool Reclamo::isActivo(){
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

void Reclamo::setDescripcion(const char* descripcion) {
    strcpy(_descripcion, descripcion);
}

void Reclamo::setFechaReclamo(int fechaDeReclamo) {
    _fechaReclamo = fechaDeReclamo;
}

void Reclamo::setEstado(const char* estado) {
    strcpy(_estado, estado);
}

void Reclamo::setTipoDeReclamo(const char* tipoDeReclamo) {
    strcpy(_tipoDeReclamo, tipoDeReclamo);
}

void Reclamo::setResponsableDeAtencion(int responsableDeAtencion) {
    _responsableDeAtencion = responsableDeAtencion;
}

void Reclamo::setRespuesta(const char* respuesta) {
    strcpy(_respuesta, respuesta);
}

void Reclamo::setPrioridad(const char* prioridad) {
    strcpy(_prioridad, prioridad);
}
void Reclamo::setActivo(bool activo){
    _activo = activo;
}


