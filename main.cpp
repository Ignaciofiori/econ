#include <iostream>
#include "Funciones.h"
#include <iomanip>

using namespace std;

int main() {






        controlDeudaSuministros();


     ArchivoSuministro archivo("suministros.dat");
    ArchivoFecha archivoF("fechas.dat");
    int cantSums = archivo.CantidadSuministros();
    Suministro *vectorSuministros;
    vectorSuministros = new Suministro[cantSums];
    archivo.LeerSuministros(cantSums,vectorSuministros);
    mostrarSuministros(vectorSuministros,cantSums);


    delete []vectorSuministros;
    return 0;
}


