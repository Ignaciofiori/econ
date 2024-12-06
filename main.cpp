#include <iostream>
#include "Funciones.h"
#include "FuncionesPagos.h"
#include "FuncionesPrecios.h"

using namespace std;


int main() {




/*
Fecha fecha(1,3,10,2024);

ArchivoSuministro archivo("suministros.dat");

int pos = archivo.BuscarSuministro(8);
Suministro sumi = archivo.LeerSuministro(pos);

sumi.setFechaAlta(fecha);

archivo.EditarSuministro(sumi,pos);
*/
    controlarPrecios();
    controlDeudaSuministros();
    menuPrincipal();

    return 0;
}


