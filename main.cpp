#include <iostream>
#include "Funciones.h"
#include <iomanip>

using namespace std;

int main() {
/*ArchivoSuministro sumis("suministros.dat");
ArchivoFecha fechas("fechas.dat");

int posSu = sumis.BuscarSuministro(8);
Suministro sum = sumis.LeerSuministro(posSu);


Fecha fecha(90,14,9,2024);

fechas.GuardarFecha(fecha);

sum.setFechaAlta(fecha.getId());

sumis.EditarSuministro(sum,posSu);

*/
    controlDeudaSuministros();
    menuPrincipal();

    return 0;
}


