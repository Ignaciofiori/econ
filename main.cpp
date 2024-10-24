#include <iostream>
#include "Usuario.h"
#include "ArchivoUsuario.h"
using namespace std;

int main()
{
    ArchivoUsuario archivo("usuarios.dat");


/*Usuario usu2 = Usuario(2,"Juan", "Alberto","aknaldikas", "12345", "1243525", "dfsdfsdf", true);

archivo.GuardarUsuario(usu2);*/

int cantidad = archivo.CantidadUsuarios();

int posicionUsu = archivo.BuscarUsuario(2);

Usuario* vectorUsuario= NULL;

vectorUsuario = new Usuario[cantidad];
if(vectorUsuario == NULL){return 0;}

archivo.LeerUsuarios(cantidad,vectorUsuario);





     cout <<vectorUsuario[1].getApellido() << endl;



    return 0;
}
