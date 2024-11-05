#pragma once
#include "Reclamos.h"
#include <string>


class ArchivoReclamo{
    private:
        std::string _nombreArchivo;

    public:

        ArchivoReclamo(std::string nombreArchivo);
        bool GuardarReclamo(Reclamo reclamo);
        bool EditarReclamo(Reclamo reclamo, int posicion);
        int BuscarReclamo(int idReclamo);
        Reclamo LeerReclamo(int posicion);
        int CantidadReclamos();
        void LeerReclamos(int cantidadReclamo, Reclamo *vector);
};
