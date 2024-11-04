#pragma once
#include "Fecha.h"
#include <string>


class ArchivoFecha{
    private:
        std::string _nombreArchivo;

    public:

        ArchivoFecha(std::string nombreArchivo);
        bool GuardarFecha(Fecha fecha);
        bool EditarFecha(Fecha fecha, int posicion);
        int BuscarFecha(int idFecha);
        Fecha LeerFecha(int posicion);
        int CantidadFechas();
        void LeerFechas(int cantidadFechas, Fecha *vector);
};
