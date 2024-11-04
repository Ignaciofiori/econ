#pragma once
#include <string>
#include "AcumuladorId.h"

class ArchivoAcumuladorId{
private:
        std::string _nombreArchivo;
public:
        ArchivoAcumuladorId(std::string nombreArchivo);
        bool GuardarAcumuladorId(AcumuladorId acum);
        bool EditarAcumuladorId(AcumuladorId acum, int posicion);
        AcumuladorId LeerAcumuladorId(int posicion);
        int CantidadAcumuladorId();
        void LeerAcumuladorId(int cantidad, AcumuladorId *vector);

};

