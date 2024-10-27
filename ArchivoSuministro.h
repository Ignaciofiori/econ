#pragma once
#include <string>
#include "Suministros.h"

class ArchivoSuministro{
    private:
        std::string _nombreArchivo;

    public:

        ArchivoSuministro(std::string nombreArchivo);
        bool GuardarSuministro(Suministro suministro);
        bool EditarSuministro(Suministro suministro, int posicion);
        int BuscarSuministro(int idSuministro);
        Suministro LeerSuministro(int posicion);
        int CantidadSuministros();
        void LeerSuministros(int cantidadSuministro, Suministro *vector);
};
