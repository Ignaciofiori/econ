#include <iostream>
#include "Funciones.h"
#include "funcionesMenus.h"
#include "FuncionesPagos.h"
#include "FuncionesPrecios.h"


using namespace std;


int main() {



/*
Fecha fecha(1,8,12,2023);

ArchivoSuministro archivo("suministros.dat");

int pos = archivo.BuscarSuministro(12);
Suministro sumi = archivo.LeerSuministro(pos);

sumi.setFechaAlta(fecha);

archivo.EditarSuministro(sumi,pos);
*/

    controlarPrecios();
    controlDeudaSuministros();
    menuPrincipal();

    return 0;
}


