#include "Factura.h"
#include <iostream>
#include <cstring>

// Constructor por defecto
Factura::Factura() {
    _idFactura = 0;
    _idUsuario = 0;
    _idSuministro = 0;
    _monto = 0;
    _periodo = Periodo();
    _fecha = Fecha(); // Inicialización con un objeto Fecha por defecto
    strcpy(_metodoPago, "");
    _pagada = false; // Inicialización como cadena vacía
}

// Constructor con parámetros
Factura::Factura(int idFactura, int idUsuario, int idSuministro,float monto,Periodo& periodo ,Fecha& fecha, char* metodoPago,bool pagada) {
    _idFactura = idFactura;
    _idUsuario = idUsuario;
    _idSuministro = idSuministro;
    _monto = monto;
    _periodo = periodo;
    _fecha = fecha; // Asignación del objeto Fecha
    strcpy(_metodoPago, metodoPago);
    _pagada = pagada;

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

float Factura::getMonto() {
    return _monto;
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
bool Factura::isPagada(){
    return _pagada;
}
// Setters
void Factura::setIdFactura(int idFactura) {
    _idFactura = idFactura;
}

void Factura::setIdUsuario(int idUsuario) {
    _idUsuario = idUsuario;
}

void Factura::setMonto(float monto) {
    _monto = monto;
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
void Factura::setIsPagada(bool pagoCompleto) {
   _pagada = pagoCompleto;

}

// Mostrar información de la factura
void Factura::mostrarFactura() {
    std::cout << "===== INFORMACION DE LA FACTURA =====\n";
    std::cout << "ID de la Factura: " << getIdFactura() << std::endl;
    std::cout << "ID del Usuario: " << getIdUsuario() << std::endl;
    std::cout << "ID de Suministro: " << getIdSuministro() << std::endl;
     std::cout << "Monto: " << getMonto() <<"$." <<std::endl;
    std::cout << "Periodo Correspondiente: " << getPeriodo()    .toString() << std::endl;
    std::cout << "Fecha de la Factura: " << getFecha().toString() << std::endl; // Uso del método toString de Fecha
    std::cout << "Metodo de Pago: " << getMetodoPago() << std::endl;
    std::cout << "La Factura esta Pagada? : " << (isPagada()?"Si":"No") << std::endl;
    std::cout << "===================================\n";
}
