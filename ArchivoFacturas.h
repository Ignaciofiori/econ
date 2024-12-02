#pragma once
#include "Factura.h"
#include <string>

class ArchivoFactura {
private:
    std::string _nombreArchivo;

public:
    ArchivoFactura(std::string nombreArchivo);
    bool GuardarFactura(Factura factura);
    bool EditarFactura(Factura factura, int posicion);
    int BuscarFactura(int idFactura);
    Factura LeerFactura(int posicion);
    int CantidadFacturas();
    void LeerFacturas(int cantidadFacturas, Factura *vector);
};
