#pragma once
#include "Fecha.h"
class Factura {
private:
    int _idFactura;
    int _idUsuario;
    int _idSuministro;
    Fecha _fecha; // Clase Fecha, debes tenerla implementada
    char _metodoPago[50];

public:
    // Constructor
    Factura();
    Factura(int idFactura, int idUsuario, int idSuministro,  Fecha& fecha,  char* metodoPago);

    // Getters
    int getIdFactura() ;
    int getIdUsuario() ;
    int getIdSuministro() ;
    Fecha getFecha() ;
    char* getMetodoPago() ;

    // Setters
    void setIdFactura(int idFactura);
    void setIdUsuario(int idUsuario);
    void setIdSuministro(int idSuministro);
    void setFecha( Fecha& fecha);
    void setMetodoPago( char* metodoPago);

    // Método para mostrar detalles de la factura
    void mostrarFactura() ;
};
