#include <iostream>
#include "Funciones.h"
#include "FuncionesPagos.h"
#include "FuncionesPrecios.h"

using namespace std;

int main() {

/*
Fecha fecha(1,3,10,2024);

ArchivoSuministro archivo("suministros.dat");

int pos = archivo.BuscarSuministro(7);
Suministro sumi = archivo.LeerSuministro(pos);

sumi.setFechaAlta(fecha);

archivo.EditarSuministro(sumi,pos);
*/
   ArchivoPreciosMed archivoPreciosMed("precios-medidores.dat");
PreciosMedidores precios = archivoPreciosMed.LeerPreciosMed(0);
precios.mostrarPrecios();

    controlarPrecios();
    controlDeudaSuministros();
    menuPrincipal();

    return 0;
}


