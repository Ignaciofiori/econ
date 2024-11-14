#include <cstring>
#include "Reclamos.h"
#include "ArchivoFecha.h"
#include "ArchivoUsuario.h"
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

void Reclamo::mostrarReclamo() {
    ArchivoFecha archivoF("fechas.dat");
    ArchivoUsuario archivoU("usuarios.dat");
    int posU = archivoU.BuscarUsuario(getResponsableDeAtencion());
    Usuario usu = archivoU.LeerUsuario(posU);
    int pos = archivoF.BuscarFecha(getFechaReclamo());
    Fecha fecha = archivoF.LeerFecha(pos);

    std::cout << "===== INFORMACION DEL RECLAMO =====\n";
    std::cout << "ID Reclamo: " << getReclamoId() << std::endl;
    std::cout << "ID Usuario: " << getUsuarioId() << std::endl;
    std::cout << "ID Suministro: " << getSuministroId() << std::endl;
    std::cout << "Descripcion: " << getDescripcion() << std::endl;
    std::cout << "Fecha de Reclamo: " << fecha.toString() << std::endl;
    std::cout << "Estado: " << getEstado() << std::endl;
    std::cout << "Tipo de Reclamo: " << getTipoDeReclamo() << std::endl;
    std::cout << "Responsable de Atencion: " << usu.getNombre() <<" " <<usu.getApellido() << std::endl;
    std::cout << "Respuesta: " << getRespuesta() << std::endl;
    std::cout << "Prioridad: " << getPrioridad() << std::endl;
    std::cout << "Activo: " << (isActivo() ? "Si" : "No") << std::endl;
    std::cout << "===================================\n";
}

