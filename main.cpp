#include <iostream>
#include "Funciones.h"
using namespace std;

int main() {

/*menuPrincipal();*/
ArchivoSuministro archivo("suministros.dat");
int cantidad = archivo.CantidadSuministros();
Suministro *vectorSuministros;

vectorSuministros = new Suministro[cantidad];

archivo.LeerSuministros(cantidad,vectorSuministros);

mostrarSuministros(vectorSuministros,cantidad);

    return 0;
}
