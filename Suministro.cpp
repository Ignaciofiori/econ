#include <cstring>
#include "Suministros.h"
#include "Fecha.h"

Suministro::Suministro() {
    _suministroId = 0;
    _usuarioId = 0;
    strcpy(_tipoSuministro, "");
    _activo = false;
    strcpy(_direccion, "");
    _codigoPostal = 0;
    _fechaAlta = Fecha();  // Inicializar con un objeto Fecha vacío
    _fechaBaja = Fecha();  // Inicializar con un objeto Fecha vacío
    strcpy(_contacto, "");
    strcpy(_medidor, "");
    _consumoPorMes = 0.0f;
    _precioKwh = 0.0f;
    _deuda = false;
    _reclamo = false;
    _montoDeuda = 0.0f;
}

Suministro::Suministro(int suministroId, int usuarioId, char* tipoSuministro, char* direccion,
                       int codigoPostal, Fecha fechaAlta, Fecha fechaBaja, char* contacto,
                       char* medidor, float consumoPorMes, float precioKwh, bool deuda, bool reclamo,
                       float montoDeuda) {
    _suministroId = suministroId;
    _usuarioId = usuarioId;
    strcpy(_tipoSuministro, tipoSuministro);
    _activo = true;
    strcpy(_direccion, direccion);
    _codigoPostal = codigoPostal;
    _fechaAlta = fechaAlta;  // Asignar el objeto Fecha
    _fechaBaja = fechaBaja;  // Asignar el objeto Fecha
    strcpy(_contacto, contacto);
    strcpy(_medidor, medidor);
    _consumoPorMes = consumoPorMes;
    _precioKwh = precioKwh;
    _deuda = deuda;
    _reclamo = reclamo;
    _montoDeuda = montoDeuda;
}

// Getters
int Suministro::getSuministroId() {
    return _suministroId;
}

int Suministro::getUsuarioId() {
    return _usuarioId;
}

char* Suministro::getTipoSuministro() {
    return _tipoSuministro;
}

bool Suministro::isActivo() {
    return _activo;
}

char* Suministro::getDireccion() {
    return _direccion;
}

int Suministro::getCodigoPostal() {
    return _codigoPostal;
}

Fecha Suministro::getFechaAlta() {  // Cambiado a devolver un objeto Fecha
    return _fechaAlta;
}

Fecha Suministro::getFechaBaja() {  // Cambiado a devolver un objeto Fecha
    return _fechaBaja;
}

char* Suministro::getContacto() {
    return _contacto;
}

char* Suministro::getMedidor() {
    return _medidor;
}

float Suministro::getConsumoPorMes() {
    return _consumoPorMes;
}

float Suministro::getPrecioKwh() {
    return _precioKwh;
}

bool Suministro::hasDeuda() {
    return _deuda;
}

bool Suministro::hasReclamo() {
    return _reclamo;
}

float Suministro::getMontoDeuda() {
    return _montoDeuda;
}

// Setters
void Suministro::setSuministroId(int suministroId) {
    _suministroId = suministroId;
}

void Suministro::setUsuarioId(int usuarioId) {
    _usuarioId = usuarioId;
}

void Suministro::setTipoSuministro(char* tipoSuministro) {
    strcpy(_tipoSuministro, tipoSuministro);
}

void Suministro::setActivo(bool activo) {
    _activo = activo;
}

void Suministro::setDireccion(char* direccion) {
    strcpy(_direccion, direccion);
}

void Suministro::setCodigoPostal(int codigoPostal) {
    _codigoPostal = codigoPostal;
}

void Suministro::setFechaAlta(Fecha fechaAlta) {  // Cambiado para aceptar un objeto Fecha
    _fechaAlta = fechaAlta;
}

void Suministro::setFechaBaja(Fecha fechaBaja) {  // Cambiado para aceptar un objeto Fecha
    _fechaBaja = fechaBaja;
}

void Suministro::setContacto(char* contacto) {
    strcpy(_contacto, contacto);
}

void Suministro::setMedidor(char* medidor) {
    strcpy(_medidor, medidor);
}

void Suministro::setConsumoPorMes(float consumoPorMes) {
    _consumoPorMes = consumoPorMes;
}

void Suministro::setPrecioKwh(float precioKwh) {
    _precioKwh = precioKwh;
}

void Suministro::setDeuda(bool deuda) {
    _deuda = deuda;
}

void Suministro::setReclamo(bool reclamo) {
    _reclamo = reclamo;
}

void Suministro::setMontoDeuda(float montoDeuda) {
    _montoDeuda = montoDeuda;
}

void Suministro::mostrarSuministro() {
    std::cout << "===== INFORMACION DEL SUMINISTRO =====\n";
    std::cout << "ID de Suministro: " << getSuministroId() << std::endl;
    std::cout << "ID de Usuario: " << getUsuarioId() << std::endl;
    std::cout << "Tipo de Suministro: " << getTipoSuministro() << std::endl;
    std::cout << "Activo: " << (isActivo() ? "Si" : "No") << std::endl;
    std::cout << "Direccion: " << getDireccion() << std::endl;
    std::cout << "Codigo Postal: " << getCodigoPostal() << std::endl;
    std::cout << "Fecha de Alta: " << getFechaAlta().toString() << std::endl;  // Usar método toString de Fecha
    std::cout << "Fecha de Baja: " << (getFechaBaja().getId()!=0 ? getFechaBaja().toString() : "Sigue Activo") << std::endl;  // Usar método toString de Fecha
    std::cout << "Contacto: " << getContacto() << std::endl;
    std::cout << "Medidor: " << getMedidor() << std::endl;
    std::cout << "Consumo por Mes: " << getConsumoPorMes() << " kWh" << std::endl;
    std::cout << "Precio por kWh: $" << getPrecioKwh() << std::endl;
    std::cout << "Deuda: " << (hasDeuda() ? "Si" : "No") << std::endl;
    std::cout << "Reclamo: " << (hasReclamo() ? "Si" : "No") << std::endl;
    std::cout << "Monto de Deuda: $" << getMontoDeuda() << std::endl;
    std::cout << "======================================\n";
}
