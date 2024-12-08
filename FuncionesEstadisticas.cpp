#include "FuncionesEstadisticas.h"
#include "Funciones.h"
#include "ArchivoFacturas.h"
#include "ArchivoUsuario.h"
#include <iostream>
#include <iomanip>

void MenuUsuariosEstadisticas() {
        Usuario usuariosMasDeudas[5];
        float mayoresDeudas[5];
        int opcion=  -1;
    while (opcion !=0) {
            int opcion = -1;
        // Mostrar el men�
        std::cout << "\n----- Menu de Usuarios y Estadisticas -----" << std::endl;
        std::cout << "1. Mostrar Clientes Con Mas Deuda" << std::endl;
        std::cout << "2. Mostrar Clientes de mayor Recaudacion " << std::endl;
        std::cout << "3. Buscar usuario por ID" << std::endl;
        std::cout << "4. Estadisticas avanzadas" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "\n------------------------------------------" << std::endl;
        std::cout << "Seleccione una opcion: ";
        opcion = leerEntero();
        std::cin.ignore();

        // Manejar las opciones del men� con un switch
        switch (opcion) {
            case 1:
                system("cls");
                usuariosConMasDeudas(usuariosMasDeudas,mayoresDeudas);
                // Agregar funcionalidad aqu�
                 for (int i = 0; i < 5; i++) {
            if (mayoresDeudas[i] != -1 && mayoresDeudas[i] != 0) {  // Verifica si la deuda es v�lida
                std::cout << "Usuario con mas deuda (puesto " << i + 1 << "): " << std::endl;
                std::cout << "Nombre y Apellido: " << usuariosMasDeudas[i].getNombre() << " " << usuariosMasDeudas[i].getApellido() << std::endl;
                std::cout << "Deuda: " << std::fixed << std::setprecision(2) << mayoresDeudas[i]<<"$" << std::endl;

                // Mostrar m�s detalles del usuario
                usuariosMasDeudas[i].mostrarUsuario();  // Asumiendo que 'mostrar' es un m�todo de la clase Usuario
                std::cout << "--------------------------------------" << std::endl;
            }
        }
                break;

            case 2:
                 system("cls");
                std::cout << "Opcion 2: Mostrar estadisticas generales." << std::endl;
                // Agregar funcionalidad aqu�
                break;

            case 3:
                 system("cls");
                std::cout << "Opcion 3: Buscar usuario por ID." << std::endl;
                // Agregar funcionalidad aqu�
                break;

            case 4:
                 system("cls");
                std::cout << "Opcion 4: Estadisticas avanzadas." << std::endl;
                // Agregar funcionalidad aqu�
                break;

            case 0:
                 system("cls");
                std::cout << "Saliendo del Menu..." << std::endl;
                    opcion = 0;
                    return;

            default:
                std::cout << "Opci�n inv�lida. Por favor, intente nuevamente." << std::endl;
                break;
        }
    }
}


void usuariosConMasDeudas(Usuario* vectorUsuarioFinal, float* vectorMontosFinal){
ArchivoFactura archivoFacturas("facturas.dat");
int cantFacturas = archivoFacturas.CantidadFacturas();
ArchivoUsuario archivoUsus("usuarios.dat");
int cantidadUsuarios = archivoUsus.CantidadUsuarios();
//INT DE USUARIOS ID MAS DEUDA

//Vector de Facturas
Factura *vectorFacturas = new Factura[cantFacturas];
archivoFacturas.LeerFacturas(cantFacturas,vectorFacturas);
//vector Usuarios
Usuario *vectorUsuarios = new Usuario[cantidadUsuarios];
float *vectorMontosDeudas = new float[cantidadUsuarios]();

//llenamos vector de montos
for(int i = 0; i<cantFacturas; i++){
   if(vectorFacturas[i].isPagada()== false){
    int idUsuario =  vectorFacturas[i].getIdUsuario();
    int posUsuario = archivoUsus.BuscarUsuario(idUsuario);

    vectorMontosDeudas[posUsuario] += vectorFacturas[i].getMonto();
   }
}
float montoMaximo1 = -1, montoMaximo2 = -1, montoMaximo3 = -1, montoMaximo4 = -1, montoMaximo5 = -1;
int posMax1 = -1, posMax2 = -1, posMax3 = -1, posMax4 = -1, posMax5 = -1;

for (int j = 0; j < 5; j++) {
    float maxDeuda = -1;  // Valor inicial mas bajo
    int posMax = -1;

    for (int x = 0; x < cantidadUsuarios; x++) {
        if (vectorMontosDeudas[x] > maxDeuda) {
            maxDeuda = vectorMontosDeudas[x];
            posMax = x;
        }
    }

    // Guardar el resultado seg�n la iteraci�n
    if (j == 0) {
        montoMaximo1 = maxDeuda;
        posMax1 = posMax;
    } else if (j == 1) {
        montoMaximo2 = maxDeuda;
        posMax2 = posMax;
    } else if (j == 2) {
        montoMaximo3 = maxDeuda;
        posMax3 = posMax;
    } else if (j == 3) {
        montoMaximo4 = maxDeuda;
        posMax4 = posMax;
    } else if (j == 4) {
        montoMaximo5 = maxDeuda;
        posMax5 = posMax;
    }

    // Marcar el maximo encontrado como procesado
    if (posMax != -1) {
        vectorMontosDeudas[posMax] = -1;  // Valor invaido para evitar que sea considerado de nuevo
    }
}
// Cargar los valores en los vectores de salida
    vectorMontosFinal[0] = montoMaximo1;
    vectorMontosFinal[1] = montoMaximo2;
    vectorMontosFinal[2] = montoMaximo3;
    vectorMontosFinal[3] = montoMaximo4;
    vectorMontosFinal[4] = montoMaximo5;

    // Obtener los usuarios correspondientes a los m�ximos
    Usuario usu1 = archivoUsus.LeerUsuario(posMax1);
    Usuario usu2 = archivoUsus.LeerUsuario(posMax2);
    Usuario usu3 = archivoUsus.LeerUsuario(posMax3);
    Usuario usu4 = archivoUsus.LeerUsuario(posMax4);
    Usuario usu5 = archivoUsus.LeerUsuario(posMax5);

    vectorUsuarioFinal[0] = usu1;
    vectorUsuarioFinal[1] = usu2;
    vectorUsuarioFinal[2] = usu3;
    vectorUsuarioFinal[3] = usu4;
    vectorUsuarioFinal[4] = usu5;

delete []vectorFacturas;
delete []vectorUsuarios;
delete []vectorMontosDeudas;
}


