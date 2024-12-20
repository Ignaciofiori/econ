#include <iostream>
#include "funcionesMenus.h"
#include "Funciones.h"
#include "FuncionesPagos.h"
#include "FuncionesPrecios.h"
#include "FuncionesEstadisticas.h"

#include <cstdlib>
#include <limits> // Para std::numeric_limits
#include <iomanip> // Para std::setw
#include <string>
#include <iostream>
//login y registro
void menuPrincipal(){
    bool logueado = false;

    int opcion = -1;
    while(opcion != 0){

    bannerBienvenida();
    std::cout << "===== MENU PRINCIPAL =====\n";
    std::cout << "1. Registrarse\n";
    std::cout << "2. Login\n";
    std::cout << "0. Salir del Programa\n";
    std::cout << "==========================\n";
    std::cout << "Seleccione una opcion: ";


    std::cin >> opcion;

    system("cls");

    switch(opcion) {
            case 1: {
                std::cout << "Opcion seleccionada: Registrarse\n";
                Usuario usuarioLogueado = registrarse();

                if(usuarioLogueado.getId() != 0){
                //guardo Usuario
                ArchivoUsuario archivo("usuarios.dat");
                logueado =  archivo.GuardarUsuario(usuarioLogueado);
                }

                if(logueado){
                    menuSecundario(usuarioLogueado);                }

                break;
            }
            case 2: {
                std::cout << "Opcion seleccionada: Login\n";

                Usuario usuarioLogueado = login();

                if(usuarioLogueado.getId() != 0){

                menuSecundario(usuarioLogueado);
                }
                break;
            }
            case 0:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
        }
    }
}
//menu segun usario (admin o cliente)
void menuSecundario(Usuario usu) {
    int idUsuario = usu.getId();
    int opcion = -1;
    PedidoSuministro pedido;
    Suministro sumAPagar;
    int cantidadPedidos;
    //MENU USUARIOS ADMIN
    if(usu.isAdmin()){
               while (opcion != 0) {
        std::cout << "\n===== MENU Admin =====\n";
        std::cout << "1. Ver Perfil\n";
        std::cout << "2. Ver Pedidos de Suministros\n";
        std::cout << "3. Ver Registros\n";
        std::cout << "4. Ver Reclamos \n";
        std::cout << "5. Crear Usuario Admin \n";
        //std::cout << "6. Ver Cantidad Totales \n";
        std::cout << "6. Actualizar Precios Medidores \n";;
        std::cout << "7. Realizar Control de Precios y Deudas \n";
        std::cout << "0. Cerrar Sesion (Desloguearse)\n";
        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        std::cin >> opcion;
        system("cls"); // Limpiar pantalla después de cada selección

        switch (opcion) {
            case 1:
                std::cout << "Perfil de "<<usu.getNombre() <<":\n";
                usu.mostrarUsuario(); // Método para mostrar el perfil del usuario
                break;
            case 2:
                std::cout << "Pedidos de Suministros Solicitados:\n";
                cantidadPedidos = listaPedidos();

                if(cantidadPedidos !=0){
                PedidoSuministro pedido = seleccionarPedido();

                if(pedido.getPedidoId() == 0){
                system("cls");
                std::cout << "No se encontro un Pedido con el Id Ingresado. \n";

                }else{

                    creacionSuministro(pedido);
                     break;
                }
                }

                break;
            case 3:
                std::cout << "Menu de Estadisticas :\n";
                menuRegistros();
               //menuEstadisticas();
                 break;
            case 4:
                 system ("cls");
                menuReclamos(usu);
                break;
            case 5:{
                std::cout << "Agregar Usuario ADMIN :\n";
                Usuario adminNuevo = nuevoAdmin();
                if(adminNuevo.getId() != 0){
                //guardo Usuario
                    ArchivoUsuario archivo("usuarios.dat");
                    archivo.GuardarUsuario(adminNuevo);
                }
                break;
                }
            case 6:
                actualizarPrecios();
                system("pause");
                 system("cls");
                break;
            case 7:
                controlarPrecios();
                controlDeudaSuministros();
                 std::cout << "Control Realizado  Exitosamente...\n";
                break;
            case 0:
                std::cout << "Sesion Cerrada Exitosamente...\n";
                break;

            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }}
    }else{
    //MENU USUARIOS CLIENTES
    ArchivoPedido archivoP("pedidos.dat");
    ArchivoSuministro archivoS("suministros.dat");
    PedidoSuministro pedido;
    Reclamo reclamo;
    int contador = 0;
    int pago;
    int nuevoMontoDeuda;
    int posSum;
    bool cargado;
    int opcFacturas = -1;
    int contadorFacturasPagadas;
    int contadorFacturasNoPagas;
    Factura facturaAPagar;
       while (opcion != 0) {
            opcFacturas = -1;
        std::cout << "\n===== MENU Cliente =====\n";
        std::cout << "1. Ver Perfil\n";
        std::cout << "2. Pedir Suministro\n";
        std::cout << "3. Ver Suministros Asociados\n";
        std::cout << "4. Ver Respuestas a tu pedidos\n";
        std::cout << "5. Generar Reclamo\n";
        std::cout << "6. Ver Reclamos\n";
        std::cout << "7. Facturas\n";
        std::cout << "0. Cerrar Sesion (Desloguearse)\n";
        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        std::cin >> opcion;
        system("cls"); // Limpiar pantalla después de cada selección

       switch (opcion) {
    case 1:
        std::cout << "Perfil de " << usu.getNombre() << ":\n";
        usu.mostrarUsuario(); // Método para mostrar el perfil del usuario
        break;

    case 2:
        pedido = cargarPedidoSuministro(idUsuario);
        cargado = archivoP.GuardarPedido(pedido);
        if (!cargado) {
            std::cout << "Error al Crear el Pedido de Suministro.";
        }
        break;

    case 3:
       mostrarSuministrosAsociados(usu);

        break;

    case 4:
        // Código para ver respuestas a los pedidos
        mostrarRespuestas(usu);
        break;
    case 5:

    reclamo = cargarReclamo(usu);
    if(reclamo.getReclamoId()!=0){
        system("cls");
       std::cout << "Tu reclamo fue realizado exitosamente. Se estara revisando y un administrador te respondera lo antes posible.\n";
    }else{
    std::cout << "Hubo un error al cargar tu reclamo, intentalo nuevamente. \n";
    }
        break;
    case 6:
        std::cout << "Reclamos de " << usu.getNombre() << "\n"<< std::endl;
        mostrarReclamosCliente(usu.getId());
        break;
    case 0:
        std::cout << "Sesion Cerrada Exitosamente...\n";
        break;
 case 7:
    while (opcFacturas!=0) {  // Bucle infinito, se saldrá solo con opcFacturas == 0
        std::cout << "Menu de Facturas:" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "1- Ver Tus Facturas Pagadas" << std::endl;
        std::cout << "2- Pagar Facturas" << std::endl;
        std::cout << "0- Volver al Menu Principal" << std::endl;
        std::cout << "(Selecciona una Opcion): ";
        opcFacturas = leerEntero();
        std::cin.ignore();

        switch (opcFacturas) {
            case 1:
                system("cls");
                contadorFacturasPagadas = mostrarFacturasPagadasPorUsuario(usu);
                if (contadorFacturasPagadas == 0) {
                    std::cout << "No Tienes Facturas Pagadas :( " << std::endl;
                }
                break;

            case 2:
                system("cls");
                contadorFacturasNoPagas = mostrarFacturasDeudaUsuario(usu);
                if (contadorFacturasNoPagas == 0) {
                    std::cout << "No Tienes Facturas No Pagas :) " << std::endl;
                    break;  // Sale solo del switch, no del bucle
                }
                facturaAPagar = seleccionarFactura(usu);

                if (facturaAPagar.getIdFactura() == 0) {
                    system("cls");
                    std::cout << "No Tienes una Factura con ese Id.. " << std::endl;
                    break;
                } else {
                    system("cls");
                    pagarFactura(facturaAPagar);
                    break;
                }
                break;

            case 0:
                system("cls");
                std::cout << "Volviendo al menu..." << std::endl;
                  // Salir del bucle y del caso 7
                break;

            default:
                std::cout << "Opción no valida. Por favor, seleccione 1, 2 o 0." << std::endl;
                break;
        }
    }
    break;  // Salir de case 7

    default:
        std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
        break;
       }
}

    }
        }

void menuRegistros(){
     int opc = -1;
    while (opc != 0) {
            int opc = -1;
        std::cout << "\n===== MENU REGISTROS =====\n";
        std::cout << "1. Menu Estadisticas\n";
        std::cout << "2. Menu Listados\n";
        std::cout << "3. Menu Totales\n";
        std::cout << "0. Volver al menu anterior\n";
        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        opc = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
        system("cls"); // Limpiar pantalla después de cada selección
        switch (opc) {
            case 1:
            menuEstadisticas();
                break;
            case 2:
                menuListado();
                break;
            case 3:
                Totales();
                //menuTotales();
                break;
            case 0:
                std::cout << "Volviendo al Menu Anterior...\n";
                opc = 0;
                return;
            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }

        system("PAUSE");
        system("cls");
    }

}

void menuEstadisticas() {
    Usuario usuariosMasDeudas[5];
    float mayoresDeudas[5];
    int opc = -1;
    while (opc != 0) {
            int opc = -1;
        std::cout << "\n===== MENU ESTADISTICAS =====\n";
        std::cout << "1. Usuarios con Mas Deudas\n";
        std::cout << "2. Recaudacion de Suministros\n";
        std::cout << "3. Consumo de KWHS de Suministros\n";
        std::cout << "4. Rendimientos de Metodos de Pago\n";
        std::cout << "5. Analisis de Motivos de Reclamos\n";


        std::cout << "0. Volver al menu anterior\n";
        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        opc = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
        system("cls"); // Limpiar pantalla después de cada selección
        switch (opc) {
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
               // menuUsuariosEstadisticas();
                break;
            case 2:
                recaudacionSuministros();

             break;
            case 3:
                consumoPorTipoSuministro();
              //  menuSuministrosEstadisticas();
                break;
            case 4:
                recaudacionMetodoPago();

                break;
            case 5:
                analisisReclamosPorTipo();
                break;
            case 0:
                std::cout << "Volviendo al Menu Anterior...\n";
                opc = 0;
                return;
            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }
        system("PAUSE");
        system("cls");
    }
}

void menuSecEstadisticas(){
    ArchivoSuministro archivoSumi("suministros.dat");
    ArchivoUsuario archivoUsu("usuarios.dat");

    int opc = -1;
    bool flag = false;


    while (opc!= 0){
        std::cout << "\t======== MENU Sec. Estadisticas ========\n";
        std::cout <<"\t1. Consultar Usuarios con Deudas\n";
        std::cout <<"\t2. Consultar Mayor Consumista Mensual\n";

        std::cout <<"\t0. Regresar\n";
        std::cout << "\t========================================\n";
        std::cout << "Digite una opcion : ";

        opc = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer

        switch (opc){
        case 1 :
            system ("cls");
            usuariosConDeudas(archivoSumi,archivoUsu);
            break;
        case 2 :
            system("cls");

            system("pause");
            break;

        case 0 :
            system ("cls");
            std::cout << "\nSaliendo del Menu Secuendario de Estadisticas ...\n";
            break;
        default :

            std::cout <<"\nOpcion Invalida, Digite nuevamente\n";
            break;
        }
    }
}

void menuReclamos(Usuario &usu){

    ArchivoReclamo archivo("reclamos.dat");
    int cantidad = archivo.CantidadReclamos();
    Reclamo *vectorReclamos;
    vectorReclamos = new Reclamo[cantidad];
    archivo.LeerReclamos(cantidad, vectorReclamos);

    int opc = -1;
    bool salida = false;
     Reclamo reclamo;
     int cantidadReclamos;
    while (opc!= 0){
            system("cls");
        std::cout << "\t====== MENU Reclamos ======\n";
        std::cout <<"\t1. Reclamos PENDIENTES\n";
        std::cout <<"\t2. Reclamos REALIZADOS\n";
        std::cout <<"\t0. Regresar\n";
        std::cout << "\t===========================\n";
        std::cout << "Digite una opcion : ";

        opc = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer

        switch (opc){
        case 1 :
            system ("cls");
            std::cout << "\nListando Reclamos PENDIENTES:\n";
                listarReclamosEstado(false);
                cantidadReclamos = listarReclamosEstado(false);
                if(cantidadReclamos == 0){
                    return;
                }
                reclamo = seleccionarReclamo(false);
             if(reclamo.getReclamoId() == 0){
                    system ("cls");
               std::cout << "No se encontro ningun reclamo con el id ingresado. \n";
               system("pause");
             }else{
                    accionesReclamos(reclamo,usu,usu);
             }

            break;
        case 2 :

            std::cout << "\nListando Reclamos REALIZADOS:\n";
             cantidadReclamos = listarReclamosEstado(true);
                    system("pause");
                if(cantidadReclamos == 0){
                        system("cls");
                      "No Hay reclamos en estado Realizado. \n";

                    break;
                }


            break;
        case 0 :
            system ("cls");
            std::cout << "\nSaliendo del menu de Reclamos...\n";
            salida = true;
            break;
        default :

            std::cout <<"\nOpcion Invalida, Digite nuevamente\n";
            break;
        }
    }

    delete[] vectorReclamos;

    ArchivoSuministro archivoSumi("suministros.dat");
    ArchivoUsuario archivoUsu("usuarios.dat");

    opc = -1;
    bool flag = false;
}

void menuListado(){
    int opc = -1;
    while (opc != 0) {
            int opc = -1;
        std::cout << "\n===== MENU LISTADO =====\n";
        std::cout << "1. Listado Usuarios\n";
        std::cout << "2. Listado Suministros\n";
        std::cout << "3. Listado Facturas\n";
        std::cout << "4. Listado Reclamos\n";
        std::cout << "5. Busquedas por Id\n";
        std::cout << "0. Volver al menu anterior\n";
        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        opc = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
        system("cls"); // Limpiar pantalla después de cada selección
        switch (opc) {
            case 1:
                listadoUsuarios();
                break;
            case 2:
                listadoSuministros();
                break;
            case 3:
                listadoFacturas();
                break;
            case 4:
                listadoReclamos();
                break;
            case 5:
                menuBusquedaPorId();
                break;
            case 0:
                std::cout << "Volviendo al Menu Anterior...\n";
                opc = 0;
                return;
            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }
        system("PAUSE");
        system("cls");
    }

}

void menuTotales(){
    int opc = -1;
    while (opc != 0) {
            int opc = -1;
        std::cout << "\n===== MENU TOTALES =====\n";
        std::cout << "1. Total Clientes\n";
        std::cout << "2. Total Suministros\n";
        std::cout << "3. Total Facturas\n";
        std::cout << "4. Total Pedidos\n";
        std::cout << "5. Total Reclamos\n";

        std::cout << "0. Volver al menu anterior\n";
        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        opc = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
        system("cls"); // Limpiar pantalla después de cada selección
        switch (opc) {
            case 1:
               // totalUsuarios();
                break;
            case 2:
              //  totalSuministros();
                break;
            case 3:
              //  totalFacturas();
                break;
            case 4:
             //   totalPedidos();
                break;
            case 5:
             //   totalReclamos();
                break;
            case 0:
                std::cout << "Volviendo al Menu Anterior...\n";
                opc = 0;
                return;
            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }
        system("PAUSE");
        system("cls");
    }
}

void menuUsuariosEstadisticas(){

}
void menuSuministrosEstadisticas(){

}
void menuFacturasEstadisticas(){

}
void menuReclamosEstadisticas(){

}
void menuPedidosEstadisticas(){

}

void menuBusquedaPorId() {
    int opc = -1;
    while (opc != 0) {
        std::cout << "\n===== MENU BUSQUEDA POR ID =====\n";
        std::cout << "1. Buscar Suministro por ID\n";
        std::cout << "2. Buscar Factura por ID\n";
        std::cout << "3. Buscar Usuario por ID\n";
        std::cout << "4. Buscar Reclamo por ID\n";
        std::cout << "0. Volver al menu anterior\n";
        std::cout << "===============================\n";
        std::cout << "Seleccione una opcion: ";

        opc = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
        system("cls"); // Limpiar pantalla después de cada selección
        switch (opc) {
            case 1:
                buscarSuministroPorId();
                break;
            case 2:
                buscarFacturaPorId();
                break;
            case 3:
                buscarUsuarioPorId();
                break;
            case 4:
                buscarReclamoPorId();
                break;
            case 0:
                std::cout << "Volviendo al Menu Anterior...\n";
                opc = 0;
                return;
            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }
        system("PAUSE");
        system("cls");
    }
}


void buscarSuministroPorId(){
ArchivoSuministro archivo("suministros.dat");
Suministro SuministroEncontrado;
bool encontrado = false;
int cantSuministros = archivo.CantidadSuministros();
Suministro *vectorSuministros = new Suministro[cantSuministros];
archivo.LeerSuministros(cantSuministros,vectorSuministros);
int idSuministro;
    std::cout << "Ingrese el ID de Suministro: ";
   idSuministro = leerEntero();
   std::cin.ignore();

for(int i = 0; i< cantSuministros; i++){
    if(vectorSuministros[i].getSuministroId() == idSuministro){

        SuministroEncontrado = vectorSuministros[i];
        encontrado = true;
    }

}
if(encontrado){
    SuministroEncontrado.mostrarSuministro();
}else{
     std::cout << "No se encontro ningun Suministro con el Id Ingresado : " << idSuministro << std::endl;
}


   delete []vectorSuministros;

}

void buscarFacturaPorId() {
    ArchivoFactura archivo("facturas.dat");
    Factura facturaEncontrada;
    bool encontrado = false;
    int cantFacturas = archivo.CantidadFacturas();
    Factura *vectorFacturas = new Factura[cantFacturas];
    archivo.LeerFacturas(cantFacturas, vectorFacturas);

    int idFactura;
    std::cout << "Ingrese el ID de Factura: ";
    idFactura = leerEntero();
    std::cin.ignore();

    for (int i = 0; i < cantFacturas; i++) {
        if (vectorFacturas[i].getIdFactura() == idFactura) {
            facturaEncontrada = vectorFacturas[i];
            encontrado = true;
        }
    }

    if (encontrado) {
        facturaEncontrada.mostrarFactura();
    } else {
        std::cout << "No se encontro ninguna Factura con el Id Ingresado: " << idFactura << std::endl;
    }

    delete[] vectorFacturas;
}

void buscarUsuarioPorId() {
    ArchivoUsuario archivo("usuarios.dat");
    Usuario usuarioEncontrado;
    bool encontrado = false;
    int cantUsuarios = archivo.CantidadUsuarios();
    Usuario *vectorUsuarios = new Usuario[cantUsuarios];
    archivo.LeerUsuarios(cantUsuarios, vectorUsuarios);

    int idUsuario;
    std::cout << "Ingrese el ID de Usuario: ";
    idUsuario = leerEntero();
    std::cin.ignore();

    for (int i = 0; i < cantUsuarios; i++) {
        if (vectorUsuarios[i].getId() == idUsuario) {
            usuarioEncontrado = vectorUsuarios[i];
            encontrado = true;
        }
    }

    if (encontrado) {
        usuarioEncontrado.mostrarUsuario();
    } else {
        std::cout << "No se encontro ningun Usuario con el Id Ingresado: " << idUsuario << std::endl;
    }

    delete[] vectorUsuarios;
}

void buscarReclamoPorId() {
    ArchivoReclamo archivo("reclamos.dat");
    Reclamo reclamoEncontrado;
    bool encontrado = false;
    int cantReclamos = archivo.CantidadReclamos();
    Reclamo *vectorReclamos = new Reclamo[cantReclamos];
    archivo.LeerReclamos(cantReclamos, vectorReclamos);

    int idReclamo;
    std::cout << "Ingrese el ID de Reclamo: ";
    idReclamo = leerEntero();
    std::cin.ignore();

    for (int i = 0; i < cantReclamos; i++) {
        if (vectorReclamos[i].getReclamoId() == idReclamo) {
            reclamoEncontrado = vectorReclamos[i];
            encontrado = true;
        }
    }

    if (encontrado) {
        reclamoEncontrado.mostrarReclamo();
    } else {
        std::cout << "No se encontro ningun Reclamo con el Id Ingresado: " << idReclamo << std::endl;
    }

    delete[] vectorReclamos;
}
