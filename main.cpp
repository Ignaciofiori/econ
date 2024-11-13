#include <iostream>
#include "Funciones.h"
using namespace std ;

int main() {


/*menuPrincipal();*/

ArchivoReclamo archivo("reclamos.dat");  // Archivo donde se almacenan los reclamos
int cantidad = archivo.CantidadReclamos();  // Obtiene la cantidad de reclamos

Reclamo *vectorReclamos;  // Puntero para almacenar los reclamos

vectorReclamos = new Reclamo[cantidad];  // Reserva memoria para los reclamos

archivo.LeerReclamos(cantidad, vectorReclamos);  // Lee los reclamos desde el archivo

mostrarReclamos(vectorReclamos, cantidad);  // Muestra los reclamos


    return 0;
}
