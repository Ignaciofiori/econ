#pragma once
#include "Fecha.h"
#include "Periodo.h"
class Factura {
private:
    int _idFactura;
    int _idUsuario;
    int _idSuministro;
    Periodo _periodo;
    Fecha _fecha; // Clase Fecha, debes tenerla implementada
    char _metodoPago[50];
    bool _pagoCompleto;

public:
    // Constructor
    Factura();
    Factura(int idFactura, int idUsuario, int idSuministro, Periodo& periodo, Fecha& fecha,  char* metodoPago,bool pagoCompleto);

    // Getters
    int getIdFactura() ;
    int getIdUsuario() ;
    int getIdSuministro() ;
    Periodo getPeriodo();
    Fecha getFecha() ;
    char* getMetodoPago() ;
    bool getPagoCompleto();

    // Setters
    void setIdFactura(int idFactura);
    void setIdUsuario(int idUsuario);
    void setIdSuministro(int idSuministro);
    void setPeriodo(Periodo periodo);
    void setFecha( Fecha& fecha);
    void setMetodoPago( char* metodoPago);
    void setPagoCompleto(bool pagoCompleto);
    // Método para mostrar detalles de la factura
    void mostrarFactura() ;
};
