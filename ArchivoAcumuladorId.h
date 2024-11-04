#pragma once
#include "AcumuladorId.h"
#include <string>
class ArchivoAcumuladorId{
    private:
        std::string _nombreArchivo;

    public:

        ArchivoAcumuladorId(std::string nombreArchivo);
        bool GuardarAcumuladorId(AcumuladorId acumulador);
        bool EditarAcumuladorId(AcumuladorId acumulador, int posicion);
        AcumuladorId LeerAcumuladorId(int posicion);
        int CantidadAcumuladorId();
        void LeerAcumuladorId(int cantidad, AcumuladorId *vector);

