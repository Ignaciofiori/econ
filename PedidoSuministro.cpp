#include "PedidoSuministro.h"
#include <iostream>
#include <cstring>

// Constructor por defecto
PedidoSuministro::PedidoSuministro() {
    _pedidoId = 0;
    _usuarioId = 0;
    _codigoPostal = 0;
    _fechaPedido = Fecha(); // Inicialización con un objeto Fecha por defecto
    strcpy(_contacto, "");  // Inicialización como cadena vacía
    strcpy(_tipoSuministro, "");
    strcpy(_direccion, "");
    strcpy(_medidor, "");
    strcpy(_comentarios, "");
    _activo = false;
}

// Constructor con parámetros
PedidoSuministro::PedidoSuministro(int pedidoId, int usuarioId, char* tipoSuministro, char* direccion,
                                   int codigoPostal, Fecha fechaPedido, char* contacto,
                                   char* medidor, char* comentarios) {
    _pedidoId = pedidoId;
    _usuarioId = usuarioId;
    _codigoPostal = codigoPostal;
    _fechaPedido = fechaPedido; // Asignación del objeto Fecha
    strcpy(_contacto, contacto);
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

char* PedidoSuministro::getTipoSuministro() {
    return _tipoSuministro;
}

char* PedidoSuministro::getDireccion() {
    return _direccion;
}

int PedidoSuministro::getCodigoPostal() {
    return _codigoPostal;
}

Fecha PedidoSuministro::getFechaPedido() {
    return _fechaPedido;
}

char* PedidoSuministro::getContacto() {
    return _contacto;
}

char* PedidoSuministro::getMedidor() {
    return _medidor;
}

char* PedidoSuministro::getComentarios() {
    return _comentarios;
}

bool PedidoSuministro::isActivo() {
    return _activo;
}

// Setters
void PedidoSuministro::setPedidoId(int pedidoId) {
    _pedidoId = pedidoId;
}

void PedidoSuministro::setUsuarioId(int usuarioId) {
    _usuarioId = usuarioId;
}

void PedidoSuministro::setTipoSuministro(char* tipoSuministro) {
    strcpy(_tipoSuministro, tipoSuministro);
}

void PedidoSuministro::setDireccion(char* direccion) {
    strcpy(_direccion, direccion);
}

void PedidoSuministro::setCodigoPostal(int codigoPostal) {
    _codigoPostal = codigoPostal;
}

void PedidoSuministro::setFechaPedido(Fecha fechaPedido) {
    _fechaPedido = fechaPedido; // Asignación del objeto Fecha
}

void PedidoSuministro::setContacto(char* contacto) {
    strcpy(_contacto, contacto);
}

void PedidoSuministro::setMedidor(char* medidor) {
    strcpy(_medidor, medidor);
}

void PedidoSuministro::setComentarios(char* comentarios) {
    strcpy(_comentarios, comentarios);
}

void PedidoSuministro::setActivo(bool activo) {
    _activo = activo;
}

// Mostrar información del pedido
void PedidoSuministro::mostrarPedido() {
    std::cout << "===== INFORMACION DEL PEDIDO DE SUMINISTRO =====\n";
    std::cout << "ID del Pedido: " << getPedidoId() << std::endl;
    std::cout << "ID del Usuario: " << getUsuarioId() << std::endl;
    std::cout << "Tipo de Suministro: " << getTipoSuministro() << std::endl;
    std::cout << "Direccion: " << getDireccion() << std::endl;
    std::cout << "Codigo Postal: " << getCodigoPostal() << std::endl;
    std::cout << "Fecha del Pedido: " << getFechaPedido().toString() << std::endl; // Uso del método toString de Fecha
    std::cout << "Contacto: " << getContacto() << std::endl;
    std::cout << "Medidor: " << getMedidor() << std::endl;
    std::cout << "Comentarios: " << getComentarios() << std::endl;
    std::cout << "Activo: " << (isActivo() ? "Si" : "No") << std::endl;
    std::cout << "===============================================\n";
}
