#include <iostream>
#include "Funciones.h"
using namespace std;

int main() {

ArchivoPedido archivoP("pedidos.dat");

int cantidad = archivoP.CantidadPedidos();

PedidoSuministro *vectorPedidos = NULL;
vectorPedidos = new PedidoSuministro[cantidad];

archivoP.LeerPedidos(cantidad,vectorPedidos);

mostrarPedidos(vectorPedidos,cantidad);

/*bannerBienvenida();
menuPrincipal();
*/
delete []vectorPedidos ;
    return 0;
}
