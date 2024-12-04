#pragma once
#include <string>
#include "PreciosMedidores.h"

class ArchivoPreciosMed {
private:
    std::string _nombreArchivo;

public:
    ArchivoPreciosMed(std::string nombreArchivo);

    bool GuardarPreciosMed(PreciosMedidores preciosMed);
    bool EditarPreciosMed(PreciosMedidores preciosMed, int posicion);
    int BuscarPreciosMed(int idMedidor); // Si deseas buscar por un atributo, reemplaza por uno existente
    PreciosMedidores LeerPreciosMed(int posicion);
    int CantidadPreciosMed();
    void LeerPreciosMed(int cantidadRegistros, PreciosMedidores* vector);
};


