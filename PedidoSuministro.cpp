#include "PedidoSuministro.h"
#include <cstring>

// Constructor por defecto
PedidoSuministro::PedidoSuministro() {
    _pedidoId = 0;
    _usuarioId = 0;
    _codigoPostal = 0;
    _fechaPedido = 0;
    _contacto = 0;
    strcpy(_tipoSuministro, "");
    strcpy(_direccion, "");
    strcpy(_medidor, "");
    strcpy(_comentarios, "");
    _activo = false;
}

// Constructor con parámetros
PedidoSuministro::PedidoSuministro(int pedidoId, int usuarioId, const char* tipoSuministro, const char* direccion,
                                   int codigoPostal, int fechaPedido, int contacto, const char* medidor, const char* comentarios) {
    _pedidoId = pedidoId;
    _usuarioId = usuarioId;
    _codigoPostal = codigoPostal;
    _fechaPedido = fechaPedido;
    _contacto = contacto;
    strcpy(_tipoSuministro, tipoSuministro);
    strcpy(_direccion, direccion);
    strcpy(_medidor, medidor);
    strcpy(_comentarios, comentarios);
    _activo = true;
}

// Getters
int PedidoSuministro::getPedidoId() {
    return _pedidoId;
}

int PedidoSuministro::getUsuarioId() {
    return _usuarioId;
}

const char* PedidoSuministro::getTipoSuministro() {
    return _tipoSuministro;
}

const char* PedidoSuministro::getDireccion() {
    return _direccion;
}

int PedidoSuministro::getCodigoPostal() {
    return _codigoPostal;
}

int PedidoSuministro::getFechaPedido() {
    return _fechaPedido;
}

int PedidoSuministro::getContacto() {
    return _contacto;
}

const char* PedidoSuministro::getMedidor() {
    return _medidor;
}

const char* PedidoSuministro::getComentarios() {
    return _comentarios;
}

bool PedidoSuministro::isActivo(){
    return _activo;
}
// Setters
void PedidoSuministro::setPedidoId(int pedidoId) {
    _pedidoId = pedidoId;
}

void PedidoSuministro::setUsuarioId(int usuarioId) {
    _usuarioId = usuarioId;
}

void PedidoSuministro::setTipoSuministro(const char* tipoSuministro) {
    strcpy(_tipoSuministro, tipoSuministro);
}

void PedidoSuministro::setDireccion(const char* direccion) {
    strcpy(_direccion, direccion);
}

void PedidoSuministro::setCodigoPostal(int codigoPostal) {
    _codigoPostal = codigoPostal;
}

void PedidoSuministro::setFechaPedido(int fechaPedido) {
    _fechaPedido = fechaPedido;
}

void PedidoSuministro::setContacto(int contacto) {
    _contacto = contacto;
}

void PedidoSuministro::setMedidor(const char* medidor) {
    strcpy(_medidor, medidor);
}

void PedidoSuministro::setComentarios(const char* comentarios) {
    strcpy(_comentarios, comentarios);
}
void PedidoSuministro::setActivo(bool activo){
    _activo = activo;
}
