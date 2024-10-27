#include <cstring>
#include "Suministros.h"

Suministro::Suministro() {
    _suministroId = 0;
    _usuarioId = 0;
    strcpy(_tipoSuministro, "");
    _activo = false;
    strcpy(_direccion, "");
    _codigoPostal = 0;
    strcpy(_fechaAlta, "");
    strcpy(_fechaBaja, "");
    strcpy(_contacto, "");
    strcpy(_medidor, "");
    _consumoPorMes = 0.0f;
    _precioKwh = 0.0f;
    _deuda = false;
    _reclamo = false;
    _montoDeuda = 0.0f;
}

Suministro::Suministro(int suministroId, int usuarioId, const char* tipoSuministro, bool activo, const char* direccion,
                       int codigoPostal, const char* fechaAlta, const char* fechaBaja, const char* contacto,
                       const char* medidor, float consumoPorMes, float precioKwh, bool deuda, bool reclamo,
                       float montoDeuda) {
    _suministroId = suministroId;
    _usuarioId = usuarioId;
    strcpy(_tipoSuministro, tipoSuministro);
    _activo = activo;
    strcpy(_direccion, direccion);
    _codigoPostal = codigoPostal;
    strcpy(_fechaAlta, fechaAlta);
    strcpy(_fechaBaja, fechaBaja);
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

const char* Suministro::getTipoSuministro() {
    return _tipoSuministro;
}

bool Suministro::isActivo() {
    return _activo;
}

const char* Suministro::getDireccion() {
    return _direccion;
}

int Suministro::getCodigoPostal() {
    return _codigoPostal;
}

const char* Suministro::getFechaAlta() {
    return _fechaAlta;
}

const char* Suministro::getFechaBaja() {
    return _fechaBaja;
}

const char* Suministro::getContacto() {
    return _contacto;
}

const char* Suministro::getMedidor() {
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

void Suministro::setTipoSuministro(const char* tipoSuministro) {
    strcpy(_tipoSuministro, tipoSuministro);
}

void Suministro::setActivo(bool activo) {
    _activo = activo;
}

void Suministro::setDireccion(const char* direccion) {
    strcpy(_direccion, direccion);
}

void Suministro::setCodigoPostal(int codigoPostal) {
    _codigoPostal = codigoPostal;
}

void Suministro::setFechaAlta(const char* fechaAlta) {
    strcpy(_fechaAlta, fechaAlta);
}

void Suministro::setFechaBaja(const char* fechaBaja) {
    strcpy(_fechaBaja, fechaBaja);
}

void Suministro::setContacto(const char* contacto) {
    strcpy(_contacto, contacto);
}

void Suministro::setMedidor(const char* medidor) {
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
