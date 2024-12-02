#include "Factura.h"
#include <iostream>
#include <cstring>

// Constructor por defecto
Factura::Factura() {
    _idFactura = 0;
    _idUsuario = 0;
    _idSuministro = 0;
    _periodo = Periodo();
    _fecha = Fecha(); // Inicializaci�n con un objeto Fecha por defecto
    strcpy(_metodoPago, "");
    _pagoCompleto = false; // Inicializaci�n como cadena vac�a
}

// Constructor con par�metros
Factura::Factura(int idFactura, int idUsuario, int idSuministro,Periodo& periodo ,Fecha& fecha, char* metodoPago,bool pagoCompleto) {
    _idFactura = idFactura;
    _idUsuario = idUsuario;
    _idSuministro = idSuministro;
    _periodo = periodo;
    _fecha = fecha; // Asignaci�n del objeto Fecha
    strcpy(_metodoPago, metodoPago);
    _pagoCompleto = pagoCompleto;

}

// Getters
int Factura::getIdFactura() {
    return _idFactura;
}

int Factura::getIdUsuario() {
    return _idUsuario;
}

int Factura::getIdSuministro() {
    return _idSuministro;
}

Periodo Factura::getPeriodo() {
    return _periodo;
}

Fecha Factura::getFecha() {
    return _fecha;
}

char* Factura::getMetodoPago() {
    return _metodoPago;
}
bool Factura::getPagoCompleto(){
    return _pagoCompleto;
}
// Setters
void Factura::setIdFactura(int idFactura) {
    _idFactura = idFactura;
}

void Factura::setIdUsuario(int idUsuario) {
    _idUsuario = idUsuario;
}

void Factura::setPeriodo(Periodo periodo) {
    _periodo = periodo;
}

void Factura::setIdSuministro(int idSuministro) {
    _idSuministro = idSuministro;
}

void Factura::setFecha(Fecha& fecha) {
    _fecha = fecha;
}

void Factura::setMetodoPago(char* metodoPago) {
   strcpy(_metodoPago, metodoPago);

}
void Factura::setPagoCompleto(bool pagoCompleto) {
   _pagoCompleto = pagoCompleto;

}

// Mostrar informaci�n de la factura
void Factura::mostrarFactura() {
    std::cout << "===== INFORMACION DE LA FACTURA =====\n";
    std::cout << "ID de la Factura: " << getIdFactura() << std::endl;
    std::cout << "ID del Usuario: " << getIdUsuario() << std::endl;
    std::cout << "ID de Suministro: " << getIdSuministro() << std::endl;
    std::cout << "Periodo Correspondiente: " << getPeriodo().toString() << std::endl;
    std::cout << "Fecha de la Factura: " << getFecha().toString() << std::endl; // Uso del m�todo toString de Fecha
    std::cout << "Metodo de Pago: " << getMetodoPago() << std::endl;
    std::cout << "Se Pago Totalidad de Deuda : " << (getPagoCompleto()?"Si":"No") << std::endl;
    std::cout << "===================================\n";
}
