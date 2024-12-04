#include "PreciosMedidores.h"

// Constructor por defecto
PreciosMedidores::PreciosMedidores() {
    _precioElectromecanico = 0.0f;
    _precioDigital = 0.0f;
    _precioInteligente = 0.0f;
    _precioBidireccional = 0.0f;
    _precioTrifasico = 0.0f;
    _precioMonofasico = 0.0f;
    _precioPrepago = 0.0f;
}

// Constructor por parametros
PreciosMedidores::PreciosMedidores(float electromecanico, float digital, float inteligente,
                                   float bidireccional, float trifasico, float monofasico, float prepago) {
    _precioElectromecanico = electromecanico;
    _precioDigital = digital;
    _precioInteligente = inteligente;
    _precioBidireccional = bidireccional;
    _precioTrifasico = trifasico;
    _precioMonofasico = monofasico;
    _precioPrepago = prepago;
}

// Getters
float PreciosMedidores::getPrecioElectromecanico() {
    return _precioElectromecanico;
}
float PreciosMedidores::getPrecioDigital() {
    return _precioDigital;
}
float PreciosMedidores::getPrecioInteligente() {
    return _precioInteligente;
}
float PreciosMedidores::getPrecioBidireccional() {
    return _precioBidireccional;
}
float PreciosMedidores::getPrecioTrifasico() {
    return _precioTrifasico;
}
float PreciosMedidores::getPrecioMonofasico() {
    return _precioMonofasico;
}
float PreciosMedidores::getPrecioPrepago() {
    return _precioPrepago;
}

// Setters
void PreciosMedidores::setPrecioElectromecanico(float precio) {
    _precioElectromecanico = precio;
}
void PreciosMedidores::setPrecioDigital(float precio) {
    _precioDigital = precio;
}
void PreciosMedidores::setPrecioInteligente(float precio) {
    _precioInteligente = precio;
}
void PreciosMedidores::setPrecioBidireccional(float precio) {
    _precioBidireccional = precio;
}
void PreciosMedidores::setPrecioTrifasico(float precio) {
    _precioTrifasico = precio;
}
void PreciosMedidores::setPrecioMonofasico(float precio) {
    _precioMonofasico = precio;
}
void PreciosMedidores::setPrecioPrepago(float precio) {
    _precioPrepago = precio;
}

// Metodo para mostrar precios
void PreciosMedidores::mostrarPrecios() {
    cout << "Precios de los medidores:" <<endl;
    cout << "-------------------------" <<endl;
    cout << "1-Medidor Electromecanico: " << _precioElectromecanico <<"$" << endl;
    cout << "2-Medidor Digital: " << _precioDigital  <<"$" << endl;
    cout << "3-Medidor Inteligente: " << _precioInteligente <<"$"  << endl;
    cout << "4-Medidor Bidireccional: " << _precioBidireccional <<"$"  << endl;
    cout << "5-Medidor Trifasico: " << _precioTrifasico <<"$"  << endl;
    cout << "6-Medidor Monofasico: " << _precioMonofasico  <<"$" << endl;
    cout << "7-Medidor de Prepago: " << _precioPrepago  <<"$" << endl;
}
