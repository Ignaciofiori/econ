#pragma once
#include "Fecha.h"
#include "Periodo.h"
class Factura {
private:
    int _idFactura;
    int _idUsuario;
    int _idSuministro;
    float _monto;
    Periodo _periodo;
    Fecha _fecha; // Clase Fecha, debes tenerla implementada
    char _metodoPago[50];
    bool _pagada;

public:
    // Constructor
    Factura();
    Factura(int idFactura, int idUsuario, int idSuministro,float monto ,Periodo& periodo, Fecha& fecha,  char* metodoPago,bool pagada);

    // Getters
    int getIdFactura() ;
    int getIdUsuario() ;
    int getIdSuministro() ;
    float getMonto();
    Periodo getPeriodo();
    Fecha getFecha() ;
    char* getMetodoPago() ;
    bool isPagada();

    // Setters
    void setIdFactura(int idFactura);
    void setIdUsuario(int idUsuario);
    void setIdSuministro(int idSuministro);
    void setMonto (float monto);
    void setPeriodo(Periodo periodo);
    void setFecha( Fecha& fecha);
    void setMetodoPago( char* metodoPago);
    void setIsPagada(bool pagada);
    // Método para mostrar detalles de la factura
    void mostrarFactura() ;
};
