#include <iostream>
#include "Funciones.h"
#include "FuncionesPagos.h"

using namespace std;

int main() {
/*
Fecha fecha(1,3,10,2024);

ArchivoSuministro archivo("suministros.dat");

int pos = archivo.BuscarSuministro(2);
Suministro sumi = archivo.LeerSuministro(pos);

sumi.setFechaAlta(fecha);

archivo.EditarSuministro(sumi,pos);
*/
    controlDeudaSuministros();
    menuPrincipal();

    return 0;
}


