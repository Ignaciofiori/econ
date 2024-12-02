#include "FuncionesEstadisticas.h"
#include "Funciones.h"
#include "FuncionesUsuarios.h"

void EstadisticaReclamos() {
    ArchivoReclamo archivoR("reclamos.dat");
    ArchivoUsuario archivoU("usuarios.dat");

    int opc = -1;
    bool flag = false;


    while (opc!= 0){
        std::cout << "\t====== MENU Estadisticas Reclamos ======\n";
        std::cout <<"\t1. Listar Usuarios con Reclamos\n";
        std::cout <<"\t2. Visualizar Mes con mas Reclamos\n";
        std::cout <<"\t3. Visualizar Mes con menos Reclamos\n";
        std::cout <<"\t0. Regresar\n";
        std::cout << "\t========================================\n";
        std::cout << "Digite una opcion : ";

        opc = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer

        switch (opc){
        case 1 :
            system ("cls");
            listarUsuariosconReclamos(archivoR,archivoU);
            system("pause");
            break;
        case 2 :
            system("cls");
            flag = true;            //------------- Bandera TRUE = Mes con MAS reclamos
            mesDeudas(flag,archivoR,archivoU);
            system("pause");
            break;
        case 3 :
            system ("cls");
            flag = false;           //------------- Bandera FALSE = Mes con MENOS reclamos
            mesDeudas(flag,archivoR,archivoU);
            system("pause");
            break;
        case 0 :
            system ("cls");
            std::cout << "\nSaliendo del menu de Estadisticas Reclamos...\n";
            break;
        default :

            std::cout <<"\nOpcion Invalida, Digite nuevamente\n";
            break;
        }
    }









    ///---------------- CODIGO ANTERIOR A REVISION FINAL -----------------------
    ///---------------- CODIGO ANTERIOR A REVISION FINAL -----------------------
    ///---------------- CODIGO ANTERIOR A REVISION FINAL -----------------------
    ///---------------- CODIGO ANTERIOR A REVISION FINAL -----------------------
    /*
    int* usuarios = new int[cantidadReclamos];
    int* conteoReclamos = new int[cantidadReclamos]{0};
    int cantidadUsuarios = 0;

    // Contar reclamos por usuario
    for (int i = 0; i < cantidadReclamos; ++i) {
        int usuarioId = vectorReclamos[i].getUsuarioId();
        bool usuarioExistente = false;

        for (int j = 0; j < cantidadUsuarios; ++j) {
            if (usuarios[j] == usuarioId) {
                conteoReclamos[j]++;
                usuarioExistente = true;
                break;
            }
        }

        if (!usuarioExistente) {
            usuarios[cantidadUsuarios] = usuarioId;
            conteoReclamos[cantidadUsuarios] = 1;
            cantidadUsuarios++;
        }
    }

    if (cantidadUsuarios == 0) {
        std::cout << "No se encontraron reclamos." << std::endl;
        delete[] vectorReclamos;
        delete[] usuarios;
        delete[] conteoReclamos;
        return;
    }
    */


    /*
    //----------------------------- ENCONTRAR USUARIO CON MAS RECLAMOS -----------------------------
    //----------------------------- ENCONTRAR USUARIO CON MAS RECLAMOS -----------------------------
    //----------------------------- ENCONTRAR USUARIO CON MAS RECLAMOS -----------------------------
    int maxReclamos = 0;
    int usuarioConMasReclamosId = -1;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (conteoReclamos[i] > maxReclamos) {
            maxReclamos = conteoReclamos[i];
            usuarioConMasReclamosId = usuarios[i];
        }
    }


    // Leer todos los usuarios
    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    // Obtener información del usuario con más reclamos
    char nombreUsuarioConMasReclamos[50];
    char apellidoUsuarioConMasReclamos[50];
    Usuario usuarioConMasReclamos;
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (vectorUsuarios[i].getId() == usuarioConMasReclamosId) {
            usuarioConMasReclamos = vectorUsuarios[i];
            strcpy(nombreUsuarioConMasReclamos, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMasReclamos, vectorUsuarios[i].getApellido());
            break;
        }
    }

    // Mostrar información del usuario con más reclamos
    usuarioConMasReclamos.mostrarUsuario();

    // Mostrar todos los reclamos del usuario con más reclamos
    std::cout << "EL Usuario con más reclamos (" << nombreUsuarioConMasReclamos << " " << apellidoUsuarioConMasReclamos << "):\n";
    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].getUsuarioId() == usuarioConMasReclamosId) {
            std::cout << "===== INFORMACION DEL RECLAMO =====\n";
            std::cout << "ID del Reclamo: " << vectorReclamos[i].getReclamoId() << std::endl;
            std::cout << "ID del Usuario: " << vectorReclamos[i].getUsuarioId() << std::endl;
            std::cout << "ID del Suministro: " << vectorReclamos[i].getSuministroId() << std::endl;
            std::cout << "Descripcion: " << vectorReclamos[i].getDescripcion() << std::endl;
            std::cout << "Fecha del Reclamo: " << vectorReclamos[i].getFechaReclamo() << std::endl;
            std::cout << "Estado: " << vectorReclamos[i].getEstado() << std::endl;
            std::cout << "Tipo de Reclamo: " << vectorReclamos[i].getTipoDeReclamo() << std::endl;
            std::cout << "Responsable de Atencion: " << vectorReclamos[i].getResponsableDeAtencion() << std::endl;
            std::cout << "Respuesta: " << vectorReclamos[i].getRespuesta() << std::endl;
            std::cout << "Prioridad: " << vectorReclamos[i].getPrioridad() << std::endl;
            std::cout << "Activo: " << (vectorReclamos[i].isActivo() ? "Si" : "No") << std::endl; std::cout << "===================================\n";
             }
            }
            delete[] vectorReclamos;
            delete[] vectorUsuarios;
            delete[] usuarios;
            delete[] conteoReclamos;
    */
}

void EstadisticaSuministros() {
    ArchivoSuministro archivoS("suministros.dat");
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadSuministros = archivoS.CantidadSuministros();
    if (cantidadSuministros == 0) {
        std::cout << "No hay suministros para contar." << std::endl;
        return;
    }

    Suministro* vectorSuministros = new Suministro[cantidadSuministros];
    archivoS.LeerSuministros(cantidadSuministros, vectorSuministros);

    int* usuarios = new int[cantidadSuministros];  // Usamos cantidadSuministros como tamaño inicial, ya que no sabemos cuántos usuarios únicos hay
    int* conteoSuministros = new int[cantidadSuministros]{0};  // Inicializamos el array de conteos a 0
    int cantidadUsuarios = 0;

    // Contar suministros por usuario
    for (int i = 0; i < cantidadSuministros; ++i) {
        int usuarioId = vectorSuministros[i].getUsuarioId();
        bool usuarioExistente = false;

        for (int j = 0; j < cantidadUsuarios; ++j) {
            if (usuarios[j] == usuarioId) {
                conteoSuministros[j]++;
                usuarioExistente = true;
                break;
            }
        }

        if (!usuarioExistente) {
            usuarios[cantidadUsuarios] = usuarioId;
            conteoSuministros[cantidadUsuarios] = 1;
            cantidadUsuarios++;
        }
    }

    delete[] vectorSuministros;

    if (cantidadUsuarios == 0) {
        std::cout << "No se encontraron suministros." << std::endl;
        delete[] usuarios;
        delete[] conteoSuministros;
        return;
    }

    // Encontrar el usuario con más suministros
    int maxSuministros = 0;
    int usuarioConMasSuministrosId = -1;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (conteoSuministros[i] > maxSuministros) {
            maxSuministros = conteoSuministros[i];
            usuarioConMasSuministrosId = usuarios[i];
        }
    }

    // Leer todos los usuarios
    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    // Obtener información del usuario con más suministros
    char nombreUsuarioConMasSuministros[50];
    char apellidoUsuarioConMasSuministros[50];
    Usuario usuarioConMasSuministros;
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (vectorUsuarios[i].getId() == usuarioConMasSuministrosId) {
            usuarioConMasSuministros = vectorUsuarios[i];
            strcpy(nombreUsuarioConMasSuministros, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMasSuministros, vectorUsuarios[i].getApellido());
            break;
        }
    }

    // Mostrar información del usuario con más suministros
    usuarioConMasSuministros.mostrarUsuario();

    // Mostrar todos los suministros del usuario con más suministros
    std::cout << "El Usuario con más suministros (" << nombreUsuarioConMasSuministros << " " << apellidoUsuarioConMasSuministros << "):\n";
    for (int i = 0; i < cantidadSuministros; ++i) {
        if (vectorSuministros[i].getUsuarioId() == usuarioConMasSuministrosId) {
            std::cout << "ID del Suministro: " << vectorSuministros[i].getSuministroId() << std::endl;
            std::cout << "Tipo de Suministro: " << vectorSuministros[i].getTipoSuministro() << std::endl;
            std::cout << "Direccion: " << vectorSuministros[i].getDireccion() << std::endl;
            std::cout << "Codigo Postal: " << vectorSuministros[i].getCodigoPostal() << std::endl;
            std::cout << "Fecha de Alta: " << vectorSuministros[i].getFechaAlta().toString() << std::endl;
            std::cout << "Fecha de Baja: " << vectorSuministros[i].getFechaBaja().toString() << std::endl;
            std::cout << "Contacto: " << vectorSuministros[i].getContacto() << std::endl;
            std::cout << "Medidor: " << vectorSuministros[i].getMedidor() << std::endl;
            std::cout << "Consumo por Mes: " << vectorSuministros[i].getConsumoPorMes() << std::endl;
            std::cout << "Precio por Kwh: " << vectorSuministros[i].getPrecioKwh() << std::endl;
            std::cout << "Deuda: " << (vectorSuministros[i].hasDeuda() ? "Si" : "No") << std::endl;
            std::cout << "Reclamo: " << (vectorSuministros[i].hasReclamo() ? "Si" : "No") << std::endl;
            std::cout << "Monto Deuda: " << vectorSuministros[i].getMontoDeuda() << std::endl;
            std::cout << "===================================\n";
        }
    }

    delete[] vectorUsuarios;
    delete[] usuarios;
    delete[] conteoSuministros;
}

void EstadisticaPedidos() {
    ArchivoPedido archivoP("pedidos.dat");
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadPedidos = archivoP.CantidadPedidos();
    if (cantidadPedidos == 0) {
        std::cout << "No hay pedidos para contar." << std::endl;
        return;
    }

    PedidoSuministro* vectorPedidos = new PedidoSuministro[cantidadPedidos];
    archivoP.LeerPedidos(cantidadPedidos, vectorPedidos);

    int* usuarios = new int[cantidadPedidos];  // Usamos cantidadPedidos como tamaño inicial, ya que no sabemos cuántos usuarios únicos hay
    int* conteoPedidos = new int[cantidadPedidos]{0};  // Inicializamos el array de conteos a 0
    int cantidadUsuarios = 0;

    // Contar pedidos por usuario
    for (int i = 0; i < cantidadPedidos; ++i) {
        int usuarioId = vectorPedidos[i].getUsuarioId();
        bool usuarioExistente = false;

        for (int j = 0; j < cantidadUsuarios; ++j) {
            if (usuarios[j] == usuarioId) {
                conteoPedidos[j]++;
                usuarioExistente = true;
                break;
            }
        }

        if (!usuarioExistente) {
            usuarios[cantidadUsuarios] = usuarioId;
            conteoPedidos[cantidadUsuarios] = 1;
            cantidadUsuarios++;
        }
    }

    if (cantidadUsuarios == 0) {
        std::cout << "No se encontraron pedidos." << std::endl;
        delete[] vectorPedidos;
        delete[] usuarios;
        delete[] conteoPedidos;
        return;
    }

    // Encontrar el usuario con más pedidos
    int maxPedidos = 0;
    int usuarioConMasPedidosId = -1;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (conteoPedidos[i] > maxPedidos) {
            maxPedidos = conteoPedidos[i];
            usuarioConMasPedidosId = usuarios[i];
        }
    }

    // Leer todos los usuarios
    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    // Obtener información del usuario con más pedidos
    char nombreUsuarioConMasPedidos[50] = "";
    char apellidoUsuarioConMasPedidos[50] = "";
    Usuario usuarioConMasPedidos;
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (vectorUsuarios[i].getId() == usuarioConMasPedidosId) {
            usuarioConMasPedidos = vectorUsuarios[i];
            strcpy(nombreUsuarioConMasPedidos, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMasPedidos, vectorUsuarios[i].getApellido());
            break;
        }
    }

    // Mostrar información del usuario con más pedidos
    usuarioConMasPedidos.mostrarUsuario();

    // Mostrar todos los pedidos del usuario con más pedidos
    std::cout << "El Usuario con más pedidos (" << nombreUsuarioConMasPedidos << " " << apellidoUsuarioConMasPedidos << "):\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadPedidos; ++i) {
        if (vectorPedidos[i].getUsuarioId() == usuarioConMasPedidosId) {
            std::cout << "ID del Pedido: " << vectorPedidos[i].getPedidoId() << std::endl;
            std::cout << "Tipo de Suministro: " << vectorPedidos[i].getTipoSuministro() << std::endl;
            std::cout << "Direccion: " << vectorPedidos[i].getDireccion() << std::endl;
            std::cout << "Codigo Postal: " << vectorPedidos[i].getCodigoPostal() << std::endl;
            std::cout << "Fecha del Pedido: " << vectorPedidos[i].getFechaPedido().toString() << std::endl;
            std::cout << "Contacto: " << vectorPedidos[i].getContacto() << std::endl;
            std::cout << "Medidor: " << vectorPedidos[i].getMedidor() << std::endl;
            std::cout << "Comentarios: " << vectorPedidos[i].getComentarios() << std::endl;
            std::cout << "Activo: " << (vectorPedidos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===============================================\n";
        }
    }

    delete[] vectorPedidos;
    delete[] vectorUsuarios;
    delete[] usuarios;
    delete[] conteoPedidos;
}

void MenuEstadisticas1(){
    int opcion;
    std::cout << "\n===== MENU ESTADISTICAS =====\n";
    std::cout << "1. Estadisticas de Reclamos\n";
    std::cout << "2. Estadisticas de Suministros\n";
    std::cout << "3. Estadisticas de Pedidos\n";

    std::cout << "0. Volver al menu anterior\n";
    std::cout << "===========================\n";
    std::cout << "Seleccione una opcion: ";

    std::cin >> opcion;
    system("cls"); // Limpiar pantalla después de cada selección

     switch (opcion) {


            case 1:
                EstadisticaReclamos1();
                break;
            case 2:
                EstadisticaSuministros1();
                break;
            case 3:
                EstadisticaPedidos1();
                 break;

            case 0:
                std::cout << "Volviendo al menu anterior\n";
                break;

            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;

    }
}

void EstadisticaReclamos1() {
    EstadisticaReclamosGrafico();/*
    ArchivoReclamo archivoR("reclamos.dat");
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadReclamos = archivoR.CantidadReclamos();
    if (cantidadReclamos == 0) {
        std::cout << "No hay reclamos para contar." << std::endl;
        return;
    }

    Reclamo* vectorReclamos = new Reclamo[cantidadReclamos];
    archivoR.LeerReclamos(cantidadReclamos, vectorReclamos);

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    int* usuarios = new int[cantidadUsuariosTotales];
    int* conteoReclamos = new int[cantidadUsuariosTotales]{0};
    int cantidadUsuarios = 0;

    // Contar reclamos por usuario
    for (int i = 0; i < cantidadReclamos; ++i) {
        int usuarioId = vectorReclamos[i].getUsuarioId();
        bool usuarioExistente = false;

        for (int j = 0; j < cantidadUsuariosTotales; ++j) {
            if (vectorUsuarios[j].getId() == usuarioId && !vectorUsuarios[j].isAdmin()) {
                for (int k = 0; k < cantidadUsuarios; ++k) {
                    if (usuarios[k] == usuarioId) {
                        conteoReclamos[k]++;
                        usuarioExistente = true;
                        break;
                    }
                }

                if (!usuarioExistente) {
                    usuarios[cantidadUsuarios] = usuarioId;
                    conteoReclamos[cantidadUsuarios] = 1;
                    cantidadUsuarios++;
                }
                break;
            }
        }
    }

    if (cantidadUsuarios == 0) {
        std::cout << "No se encontraron reclamos de clientes." << std::endl;
        delete[] vectorReclamos;
        delete[] usuarios;
        delete[] conteoReclamos;
        delete[] vectorUsuarios;
        return;
    }

    // Encontrar el usuario con más y menos reclamos
    int maxReclamos = 0;
    int minReclamos = INT_MAX;
    int usuarioConMasReclamosId = -1;
    int usuarioConMenosReclamosId = -1;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (conteoReclamos[i] > maxReclamos) {
            maxReclamos = conteoReclamos[i];
            usuarioConMasReclamosId = usuarios[i];
        }
        if (conteoReclamos[i] < minReclamos) {
            minReclamos = conteoReclamos[i];
            usuarioConMenosReclamosId = usuarios[i];
        }
    }
    // Obtener información de los usuarios con más y menos reclamos
    char nombreUsuarioConMasReclamos[50] = "";
    char apellidoUsuarioConMasReclamos[50] = "";
    char nombreUsuarioConMenosReclamos[50] = "";
    char apellidoUsuarioConMenosReclamos[50] = "";

    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (vectorUsuarios[i].getId() == usuarioConMasReclamosId) {
            strcpy(nombreUsuarioConMasReclamos, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMasReclamos, vectorUsuarios[i].getApellido());
        }
        if (vectorUsuarios[i].getId() == usuarioConMenosReclamosId) {
            strcpy(nombreUsuarioConMenosReclamos, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMenosReclamos, vectorUsuarios[i].getApellido());
        }
    }

    // Mostrar información del usuario con más reclamos
    std::cout << "El Usuario con más reclamos (" << nombreUsuarioConMasReclamos << " " << apellidoUsuarioConMasReclamos << ") tiene " << maxReclamos << " reclamos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].getUsuarioId() == usuarioConMasReclamosId) {
            std::cout << "===== INFORMACION DEL RECLAMO =====\n";
            std::cout << "ID del Reclamo: " << vectorReclamos[i].getReclamoId() << std::endl;
            std::cout << "ID del Usuario: " << vectorReclamos[i].getUsuarioId() << std::endl;
            std::cout << "ID del Suministro: " << vectorReclamos[i].getSuministroId() << std::endl;
            std::cout << "Descripcion: " << vectorReclamos[i].getDescripcion() << std::endl;
            std::cout << "Fecha del Reclamo: " << vectorReclamos[i].getFechaReclamo() << std::endl;
            std::cout << "Estado: " << vectorReclamos[i].getEstado() << std::endl;
            std::cout << "Tipo de Reclamo: " << vectorReclamos[i].getTipoDeReclamo() << std::endl;
            std::cout << "Responsable de Atencion: " << vectorReclamos[i].getResponsableDeAtencion() << std::endl;
            std::cout << "Respuesta: " << vectorReclamos[i].getRespuesta() << std::endl;
            std::cout << "Prioridad: " << vectorReclamos[i].getPrioridad() << std::endl;
            std::cout << "Activo: " << (vectorReclamos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===================================\n";
        }
    }

    // Mostrar información del usuario con menos reclamos
    std::cout << "El Usuario con menos reclamos (" << nombreUsuarioConMenosReclamos << " " << apellidoUsuarioConMenosReclamos << ") tiene " << minReclamos << " reclamos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].getUsuarioId() == usuarioConMenosReclamosId) {
            std::cout << "===== INFORMACION DEL RECLAMO =====\n";
            std::cout << "ID del Reclamo: " << vectorReclamos[i].getReclamoId() << std::endl;
            std::cout << "ID del Usuario: " << vectorReclamos[i].getUsuarioId() << std::endl;
            std::cout << "ID del Suministro: " << vectorReclamos[i].getSuministroId() << std::endl;
            std::cout << "Descripcion: " << vectorReclamos[i].getDescripcion() << std::endl;
            std::cout << "Fecha del Reclamo: " << vectorReclamos[i].getFechaReclamo() << std::endl;
            std::cout << "Estado: " << vectorReclamos[i].getEstado() << std::endl;
            std::cout << "Tipo de Reclamo: " << vectorReclamos[i].getTipoDeReclamo() << std::endl;
            std::cout << "Responsable de Atencion: " << vectorReclamos[i].getResponsableDeAtencion() << std::endl;
            std::cout << "Respuesta: " << vectorReclamos[i].getRespuesta() << std::endl;
            std::cout << "Prioridad: " << vectorReclamos[i].getPrioridad() << std::endl;
            std::cout << "Activo: " << (vectorReclamos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===================================\n";
        }
    }

    // Mostrar clientes que no tienen reclamos
    bool hayClientesSinReclamos = false;
    std::cout << "Clientes sin reclamos:\n";
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        bool tieneReclamo = false;
        if (!vectorUsuarios[i].isAdmin()) {
            for (int j = 0; j < cantidadUsuarios; ++j) {
                if (vectorUsuarios[i].getId() == usuarios[j]) {
                    tieneReclamo = true;
                    break;
                }
            }
            if (!tieneReclamo) {
                std::cout << "ID del Usuario: " << vectorUsuarios[i].getId() << std::endl;
                std::cout << "Nombre: " << vectorUsuarios[i].getNombre() << std::endl;
                std::cout << "Apellido: " << vectorUsuarios[i].getApellido() << std::endl;
                std::cout << "===============================================\n";
                hayClientesSinReclamos = true;
            }
        }
    }

    if (!hayClientesSinReclamos) {
        std::cout << "No hay clientes sin reclamos." << std::endl;
    }

    delete[] vectorReclamos;
    delete[] vectorUsuarios;
    delete[] usuarios;
    delete[] conteoReclamos;*/
}

//VARIOS CLIENTES
void imprimirGraficoBarras1(int maxSuministros, const char* nombreMax, int minSuministros, const char* nombreMin, bool variosMax, bool variosMin) {
    const int maxAnchoBarra = 50;

    // Calcular el ancho de las barras
    int anchoBarraMax = static_cast<int>((static_cast<double>(maxSuministros) / maxSuministros) * maxAnchoBarra);
    int anchoBarraMin = static_cast<int>((static_cast<double>(minSuministros) / maxSuministros) * maxAnchoBarra);

    // Imprimir barras
    std::cout << std::setw(30) << (variosMax ? "Varios clientes" : nombreMax) << " | ";
    for (int i = 0; i < anchoBarraMax; ++i) {
        std::cout << "#";
    }
    std::cout << " " << maxSuministros << std::endl;

    std::cout << std::setw(30) << (variosMin ? "Varios clientes" : nombreMin) << " | ";
    for (int i = 0; i < anchoBarraMin; ++i) {
        std::cout << "#";
    }
    std::cout << " " << minSuministros << std::endl;
}

void EstadisticaSuministros1() {
    ArchivoSuministro archivoS("suministros.dat");
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadSuministros = archivoS.CantidadSuministros();
    if (cantidadSuministros == 0) {
        std::cout << "No hay suministros para contar." << std::endl;
        return;
    }

    Suministro* vectorSuministros = new Suministro[cantidadSuministros];
    archivoS.LeerSuministros(cantidadSuministros, vectorSuministros);

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    int* usuarios = new int[cantidadUsuariosTotales];
    int* conteoSuministros = new int[cantidadUsuariosTotales]{0};
    int cantidadUsuarios = 0;
    // Contar suministros por usuario, excluyendo administradores
        // Contar suministros por usuario, excluyendo administradores
    for (int i = 0; i < cantidadSuministros; ++i) {
        int usuarioId = vectorSuministros[i].getUsuarioId();
        bool usuarioExistente = false;

        for (int j = 0; j < cantidadUsuariosTotales; ++j) {
            if (vectorUsuarios[j].getId() == usuarioId && !vectorUsuarios[j].isAdmin()) {
                for (int k = 0; k < cantidadUsuarios; ++k) {
                    if (usuarios[k] == usuarioId) {
                        conteoSuministros[k]++;
                        usuarioExistente = true;
                        break;
                    }
                }

                if (!usuarioExistente) {
                    usuarios[cantidadUsuarios] = usuarioId;
                    conteoSuministros[cantidadUsuarios] = 1;
                    cantidadUsuarios++;
                }
                break;
            }
        }
    }

    if (cantidadUsuarios == 0) {
        std::cout << "No se encontraron suministros de clientes." << std::endl;
        delete[] vectorSuministros;
        delete[] usuarios;
        delete[] conteoSuministros;
        delete[] vectorUsuarios;
        return;
    }

    // Encontrar el usuario con más y menos suministros
    int maxSuministros = 0;
    int minSuministros = INT_MAX;
    int* usuariosConMaxSuministros = new int[cantidadUsuarios];
    int* usuariosConMinSuministros = new int[cantidadUsuarios];
    int cantidadUsuariosConMaxSuministros = 0;
    int cantidadUsuariosConMinSuministros = 0;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (conteoSuministros[i] > maxSuministros) {
            maxSuministros = conteoSuministros[i];
            cantidadUsuariosConMaxSuministros = 0;
            usuariosConMaxSuministros[cantidadUsuariosConMaxSuministros++] = usuarios[i];
        } else if (conteoSuministros[i] == maxSuministros) {
            usuariosConMaxSuministros[cantidadUsuariosConMaxSuministros++] = usuarios[i];
        }
        if (conteoSuministros[i] < minSuministros) {
            minSuministros = conteoSuministros[i];
            cantidadUsuariosConMinSuministros = 0;
            usuariosConMinSuministros[cantidadUsuariosConMinSuministros++] = usuarios[i];
        } else if (conteoSuministros[i] == minSuministros) {
            usuariosConMinSuministros[cantidadUsuariosConMinSuministros++] = usuarios[i];
        }
    }
    // Obtener información de los usuarios con más y menos suministros
    char** nombresUsuariosConMasSuministros = new char*[cantidadUsuariosConMaxSuministros];
    char** apellidosUsuariosConMasSuministros = new char*[cantidadUsuariosConMaxSuministros];
    char** nombresUsuariosConMenosSuministros = new char*[cantidadUsuariosConMinSuministros];
    char** apellidosUsuariosConMenosSuministros = new char*[cantidadUsuariosConMinSuministros];
    int* idsUsuariosConMasSuministros = new int[cantidadUsuariosConMaxSuministros];
    int* idsUsuariosConMenosSuministros = new int[cantidadUsuariosConMinSuministros];

    for (int i = 0; i < cantidadUsuariosConMaxSuministros; ++i) {
        nombresUsuariosConMasSuministros[i] = new char[50];
        apellidosUsuariosConMasSuministros[i] = new char[50];
    }

    for (int i = 0; i < cantidadUsuariosConMinSuministros; ++i) {
        nombresUsuariosConMenosSuministros[i] = new char[50];
        apellidosUsuariosConMenosSuministros[i] = new char[50];
    }

    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        for (int j = 0; j < cantidadUsuariosConMaxSuministros; ++j) {
            if (vectorUsuarios[i].getId() == usuariosConMaxSuministros[j]) {
                idsUsuariosConMasSuministros[j] = vectorUsuarios[i].getId();
                strcpy(nombresUsuariosConMasSuministros[j], vectorUsuarios[i].getNombre());
                strcpy(apellidosUsuariosConMasSuministros[j], vectorUsuarios[i].getApellido());
            }
        }
        for (int j = 0; j < cantidadUsuariosConMinSuministros; ++j) {
            if (vectorUsuarios[i].getId() == usuariosConMinSuministros[j]) {
                idsUsuariosConMenosSuministros[j] = vectorUsuarios[i].getId();
                strcpy(nombresUsuariosConMenosSuministros[j], vectorUsuarios[i].getNombre());
                strcpy(apellidosUsuariosConMenosSuministros[j], vectorUsuarios[i].getApellido());
            }
        }
    }

    // Mostrar información de los usuarios con más suministros
    std::cout << "Usuarios con más suministros (" << maxSuministros << " suministros):\n";
    for (int i = 0; i < cantidadUsuariosConMaxSuministros; ++i) {
        std::cout << "ID del Usuario: " << idsUsuariosConMasSuministros[i] << "\n";
        std::cout << nombresUsuariosConMasSuministros[i] << " " << apellidosUsuariosConMasSuministros[i] << std::endl;
    }
    std::cout << "===============================================\n";

    // Mostrar información de los usuarios con menos suministros
    std::cout << "Usuarios con menos suministros (" << minSuministros << " suministros):\n";
    for (int i = 0; i < cantidadUsuariosConMinSuministros; ++i) {
        std::cout << "ID del Usuario: " << idsUsuariosConMenosSuministros[i] << "\n";
        std::cout << nombresUsuariosConMenosSuministros[i] << " " << apellidosUsuariosConMenosSuministros[i] << std::endl;
    }
    std::cout << "===============================================\n";
    // Mostrar clientes que no tienen suministros
    bool hayClientesSinSuministros = false;
    int cantidadClientesSinSuministros = 0;
    std::cout << "Clientes sin suministros:\n";
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        bool tieneSuministro = false;
        for (int j = 0; j < cantidadUsuarios; ++j) {
            if (vectorUsuarios[i].getId() == usuarios[j]) {
                tieneSuministro = true;
                break;
            }
        }
        if (!tieneSuministro && !vectorUsuarios[i].isAdmin()) {
            std::cout << "ID del Usuario: " << vectorUsuarios[i].getId() << std::endl;
            std::cout << "Nombre: " << vectorUsuarios[i].getNombre() << std::endl;
            std::cout << "Apellido: " << vectorUsuarios[i].getApellido() << std::endl;
            std::cout << "===============================================\n";
            hayClientesSinSuministros = true;
            cantidadClientesSinSuministros++;
        }
    }

    if (!hayClientesSinSuministros) {
        std::cout << "No hay clientes sin suministros." << std::endl;
    } else if (cantidadClientesSinSuministros > 1) {
        std::cout << "Cantidad de clientes sin suministros: " << cantidadClientesSinSuministros << std::endl;
    }

    // Imprimir gráfico de barras
    bool variosMax = (cantidadUsuariosConMaxSuministros > 1);
    bool variosMin = (cantidadUsuariosConMinSuministros > 1);
    if (cantidadUsuariosConMaxSuministros > 0 && cantidadUsuariosConMinSuministros > 0) {
        imprimirGraficoBarras1(maxSuministros, nombresUsuariosConMasSuministros[0], minSuministros, nombresUsuariosConMenosSuministros[0], variosMax, variosMin);
    }

    delete[] vectorSuministros;
    delete[] vectorUsuarios;
    delete[] usuarios;
    delete[] conteoSuministros;
    delete[] usuariosConMaxSuministros;
    delete[] usuariosConMinSuministros;
    for (int i = 0; i < cantidadUsuariosConMaxSuministros; ++i) {
        delete[] nombresUsuariosConMasSuministros[i];
        delete[] apellidosUsuariosConMasSuministros[i];
    }
    for (int i = 0; i < cantidadUsuariosConMinSuministros; ++i) {
        delete[] nombresUsuariosConMenosSuministros[i];
        delete[] apellidosUsuariosConMenosSuministros[i];
    }
    delete[] nombresUsuariosConMasSuministros;
    delete[] apellidosUsuariosConMasSuministros;
    delete[] nombresUsuariosConMenosSuministros;
    delete[] apellidosUsuariosConMenosSuministros;
}

//MODIFICAR
void EstadisticaPedidos1() {

    EstadisticaPedidosGrafico();
    ArchivoPedido archivoP("pedidos.dat");
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadPedidos = archivoP.CantidadPedidos();
    if (cantidadPedidos == 0) {
        std::cout << "No hay pedidos para contar." << std::endl;
        return;
    }

    PedidoSuministro* vectorPedidos = new PedidoSuministro[cantidadPedidos];
    archivoP.LeerPedidos(cantidadPedidos, vectorPedidos);

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    int* usuarios = new int[cantidadUsuariosTotales];  // Usamos la cantidad de usuarios totales como tamaño inicial
    int* conteoPedidos = new int[cantidadUsuariosTotales]{0};  // Inicializamos el array de conteos a 0
    int cantidadUsuarios = 0;

    // Contar pedidos por usuario
    for (int i = 0; i < cantidadPedidos; ++i) {
        int usuarioId = vectorPedidos[i].getUsuarioId();
        bool usuarioExistente = false;

        for (int j = 0; j < cantidadUsuariosTotales; ++j) {
            if (vectorUsuarios[j].getId() == usuarioId && !vectorUsuarios[j].isAdmin()) {  // Verificar que no sea administrador
                for (int k = 0; k < cantidadUsuarios; ++k) {
                    if (usuarios[k] == usuarioId) {
                        conteoPedidos[k]++;
                        usuarioExistente = true;
                        break;
                    }
                }

                if (!usuarioExistente) {
                    usuarios[cantidadUsuarios] = usuarioId;
                    conteoPedidos[cantidadUsuarios] = 1;
                    cantidadUsuarios++;
                }

                break;
            }
        }
    }

    if (cantidadUsuarios == 0) {
        std::cout << "No se encontraron pedidos de clientes." << std::endl;
        delete[] vectorPedidos;
        delete[] usuarios;
        delete[] conteoPedidos;
        delete[] vectorUsuarios;
        return;
    }

    // Encontrar el usuario con más y menos pedidos
    int maxPedidos = 0;
    int minPedidos = INT_MAX;
    int usuarioConMasPedidosId = -1;
    int usuarioConMenosPedidosId = -1;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (conteoPedidos[i] > maxPedidos) {
            maxPedidos = conteoPedidos[i];
            usuarioConMasPedidosId = usuarios[i];
        }
        if (conteoPedidos[i] < minPedidos) {
            minPedidos = conteoPedidos[i];
            usuarioConMenosPedidosId = usuarios[i];
        }
    }

    // Obtener información de los usuarios con más y menos pedidos
    char nombreUsuarioConMasPedidos[50] = "";
    char apellidoUsuarioConMasPedidos[50] = "";
    char nombreUsuarioConMenosPedidos[50] = "";
    char apellidoUsuarioConMenosPedidos[50] = "";

    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (vectorUsuarios[i].getId() == usuarioConMasPedidosId) {
            strcpy(nombreUsuarioConMasPedidos, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMasPedidos, vectorUsuarios[i].getApellido());
        }
        if (vectorUsuarios[i].getId() == usuarioConMenosPedidosId) {
            strcpy(nombreUsuarioConMenosPedidos, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMenosPedidos, vectorUsuarios[i].getApellido());
        }
    }

    // Mostrar información del usuario con más pedidos
    std::cout << "El Usuario con más pedidos (" << nombreUsuarioConMasPedidos << " " << apellidoUsuarioConMasPedidos << ") tiene " << maxPedidos << " pedidos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadPedidos; ++i) {
        if (vectorPedidos[i].getUsuarioId() == usuarioConMasPedidosId) {
            std::cout << "ID del Pedido: " << vectorPedidos[i].getPedidoId() << std::endl;
            std::cout << "Tipo de Suministro: " << vectorPedidos[i].getTipoSuministro() << std::endl;
            std::cout << "Direccion: " << vectorPedidos[i].getDireccion() << std::endl;
            std::cout << "Codigo Postal: " << vectorPedidos[i].getCodigoPostal() << std::endl;
            std::cout << "Fecha del Pedido: " << vectorPedidos[i].getFechaPedido().toString() << std::endl;
            std::cout << "Contacto: " << vectorPedidos[i].getContacto() << std::endl;
            std::cout << "Medidor: " << vectorPedidos[i].getMedidor() << std::endl;
            std::cout << "Comentarios: " << vectorPedidos[i].getComentarios() << std::endl;
            std::cout << "Activo: " << (vectorPedidos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===============================================\n";
        }
    }

    // Mostrar información del usuario con menos pedidos
    std::cout << "El Usuario con menos pedidos (" << nombreUsuarioConMenosPedidos << " " << apellidoUsuarioConMenosPedidos << ") tiene " << minPedidos << " pedidos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadPedidos; ++i) {
        if (vectorPedidos[i].getUsuarioId() == usuarioConMenosPedidosId) {
            std::cout << "ID del Pedido: " << vectorPedidos[i].getPedidoId() << std::endl;
            std::cout << "Tipo de Suministro: " << vectorPedidos[i].getTipoSuministro() << std::endl;
            std::cout << "Direccion: " << vectorPedidos[i].getDireccion() << std::endl;
            std::cout << "Codigo Postal: " << vectorPedidos[i].getCodigoPostal() << std::endl;
            std::cout << "Fecha del Pedido: " << vectorPedidos[i].getFechaPedido().toString() << std::endl;
            std::cout << "Contacto: " << vectorPedidos[i].getContacto() << std::endl;
            std::cout << "Medidor: " << vectorPedidos[i].getMedidor() << std::endl;
            std::cout << "Comentarios: " << vectorPedidos[i].getComentarios() << std::endl;
            std::cout << "Activo: " << (vectorPedidos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===============================================\n";
        }
    }

    // Mostrar clientes que no tienen pedidos
    bool hayClientesSinPedidos = false;
    std::cout << "Clientes sin pedidos:\n";
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        bool tienePedido = false;
        if (!vectorUsuarios[i].isAdmin()) {  // Verificar que no sea administrador
            for (int j = 0; j < cantidadUsuarios; ++j) {
                if (vectorUsuarios[i].getId() == usuarios[j]) {
                    tienePedido = true;
                    break;
                }
            }
            if (!tienePedido) {
                std::cout << "ID del Usuario: " << vectorUsuarios[i].getId() << std::endl;
                std::cout << "Nombre: " << vectorUsuarios[i].getNombre() << std::endl;
                std::cout << "Apellido: " << vectorUsuarios[i].getApellido() << std::endl;
                std::cout << "===============================================\n";
                hayClientesSinPedidos = true;
            }
        }
    }

    if (!hayClientesSinPedidos) {
        std::cout << "No hay clientes sin pedidos." << std::endl;
    }

    delete[] vectorPedidos;
    delete[] vectorUsuarios;
    delete[] usuarios;
    delete[] conteoPedidos;
}

//UN SOLO CLIENTE
void imprimirGraficoBarras(int maxPedidos, const char* nombreMax, int minPedidos, const char* nombreMin) {
    const int maxAnchoBarra = 50;

    // Calcular el ancho de las barras
    int anchoBarraMax = static_cast<int>(static_cast<double>(maxPedidos) / maxPedidos * maxAnchoBarra);
    int anchoBarraMin = static_cast<int>(static_cast<double>(minPedidos) / maxPedidos * maxAnchoBarra);

    // Imprimir barras
    std::cout << std::setw(15) << nombreMax << " | ";
    for (int i = 0; i < anchoBarraMax; ++i) {
        std::cout << "#";
    }
    std::cout << " " << maxPedidos << std::endl;

    std::cout << std::setw(15) << nombreMin << " | ";
    for (int i = 0; i < anchoBarraMin; ++i) {
        std::cout << "#";
    }
    std::cout << " " << minPedidos << std::endl;
}
//MODIFICAR
void EstadisticaPedidosGrafico() {
    ArchivoPedido archivoP("pedidos.dat");
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadPedidos = archivoP.CantidadPedidos();
    if (cantidadPedidos == 0) {
        std::cout << "No hay pedidos para contar." << std::endl;
        return;
    }

    PedidoSuministro* vectorPedidos = new PedidoSuministro[cantidadPedidos];
    archivoP.LeerPedidos(cantidadPedidos, vectorPedidos);

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    int* usuarios = new int[cantidadUsuariosTotales];
    int* conteoPedidos = new int[cantidadUsuariosTotales]{0};
    int cantidadUsuarios = 0;

    // Contar pedidos por usuario
    for (int i = 0; i < cantidadPedidos; ++i) {
        int usuarioId = vectorPedidos[i].getUsuarioId();
        bool usuarioExistente = false;

        for (int j = 0; j < cantidadUsuariosTotales; ++j) {
            if (vectorUsuarios[j].getId() == usuarioId && !vectorUsuarios[j].isAdmin()) {
                for (int k = 0; k < cantidadUsuarios; ++k) {
                    if (usuarios[k] == usuarioId) {
                        conteoPedidos[k]++;
                        usuarioExistente = true;
                        break;
                    }
                }

                if (!usuarioExistente) {
                    usuarios[cantidadUsuarios] = usuarioId;
                    conteoPedidos[cantidadUsuarios] = 1;
                    cantidadUsuarios++;
                }
                break;
            }
        }
    }

    if (cantidadUsuarios == 0) {
        std::cout << "No se encontraron pedidos de clientes." << std::endl;
        delete[] vectorPedidos;
        delete[] usuarios;
        delete[] conteoPedidos;
        delete[] vectorUsuarios;
        return;
    }

    int maxPedidos = 0;
    int minPedidos = INT_MAX;
    int usuarioConMasPedidosId = -1;
    int usuarioConMenosPedidosId = -1;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (conteoPedidos[i] > maxPedidos) {
            maxPedidos = conteoPedidos[i];
            usuarioConMasPedidosId = usuarios[i];
        }
        if (conteoPedidos[i] < minPedidos) {
            minPedidos = conteoPedidos[i];
            usuarioConMenosPedidosId = usuarios[i];
        }
    }

    char nombreUsuarioConMasPedidos[50] = "";
    char nombreUsuarioConMenosPedidos[50] = "";

    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (vectorUsuarios[i].getId() == usuarioConMasPedidosId) {
            strcpy(nombreUsuarioConMasPedidos, vectorUsuarios[i].getNombre());
        }
        if (vectorUsuarios[i].getId() == usuarioConMenosPedidosId) {
            strcpy(nombreUsuarioConMenosPedidos, vectorUsuarios[i].getNombre());
        }
    }

    std::cout << "Gráfico de barras del cliente con mas pedidos y cliente con menos pedidos:\n";
    imprimirGraficoBarras(maxPedidos, nombreUsuarioConMasPedidos, minPedidos, nombreUsuarioConMenosPedidos);

    delete[] vectorPedidos;
    delete[] vectorUsuarios;
    delete[] usuarios;
    delete[] conteoPedidos;
}
//MODIFICAR
void EstadisticaReclamosGrafico() {
    ArchivoReclamo archivoR("reclamos.dat");
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadReclamos = archivoR.CantidadReclamos();
    if (cantidadReclamos == 0) {
        std::cout << "No hay reclamos para contar." << std::endl;
        return;
    }

    Reclamo* vectorReclamos = new Reclamo[cantidadReclamos];
    archivoR.LeerReclamos(cantidadReclamos, vectorReclamos);

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    int* usuarios = new int[cantidadUsuariosTotales];
    int* conteoReclamos = new int[cantidadUsuariosTotales]{0};
    int cantidadUsuarios = 0;

    // Contar reclamos por usuario
    for (int i = 0; i < cantidadReclamos; ++i) {
        int usuarioId = vectorReclamos[i].getUsuarioId();
        bool usuarioExistente = false;

        for (int j = 0; j < cantidadUsuariosTotales; ++j) {
            if (vectorUsuarios[j].getId() == usuarioId && !vectorUsuarios[j].isAdmin()) {
                for (int k = 0; k < cantidadUsuarios; ++k) {
                    if (usuarios[k] == usuarioId) {
                        conteoReclamos[k]++;
                        usuarioExistente = true;
                        break;
                    }
                }

                if (!usuarioExistente) {
                    usuarios[cantidadUsuarios] = usuarioId;
                    conteoReclamos[cantidadUsuarios] = 1;
                    cantidadUsuarios++;
                }
                break;
            }
        }
    }

    if (cantidadUsuarios == 0) {
        std::cout << "No se encontraron reclamos de clientes." << std::endl;
        delete[] vectorReclamos;
        delete[] usuarios;
        delete[] conteoReclamos;
        delete[] vectorUsuarios;
        return;
    }

    // Encontrar el usuario con más y menos reclamos
    int maxReclamos = 0;
    int minReclamos = INT_MAX;
    int usuarioConMasReclamosId = -1;
    int usuarioConMenosReclamosId = -1;

    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (conteoReclamos[i] > maxReclamos) {
            maxReclamos = conteoReclamos[i];
            usuarioConMasReclamosId = usuarios[i];
        }
        if (conteoReclamos[i] < minReclamos) {
            minReclamos = conteoReclamos[i];
            usuarioConMenosReclamosId = usuarios[i];
        }
    }
     // Obtener información de los usuarios con más y menos reclamos
    char nombreUsuarioConMasReclamos[50] = "";
    char apellidoUsuarioConMasReclamos[50] = "";
    char nombreUsuarioConMenosReclamos[50] = "";
    char apellidoUsuarioConMenosReclamos[50] = "";

    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (vectorUsuarios[i].getId() == usuarioConMasReclamosId) {
            strcpy(nombreUsuarioConMasReclamos, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMasReclamos, vectorUsuarios[i].getApellido());
        }
        if (vectorUsuarios[i].getId() == usuarioConMenosReclamosId) {
            strcpy(nombreUsuarioConMenosReclamos, vectorUsuarios[i].getNombre());
            strcpy(apellidoUsuarioConMenosReclamos, vectorUsuarios[i].getApellido());
        }
    }

    // Mostrar información del usuario con más reclamos
    std::cout << "El Usuario con más reclamos (" << nombreUsuarioConMasReclamos << " " << apellidoUsuarioConMasReclamos << ") tiene " << maxReclamos << " reclamos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].getUsuarioId() == usuarioConMasReclamosId) {
            std::cout << "===== INFORMACION DEL RECLAMO =====\n";
            std::cout << "ID del Reclamo: " << vectorReclamos[i].getReclamoId() << std::endl;
            std::cout << "ID del Usuario: " << vectorReclamos[i].getUsuarioId() << std::endl;
            std::cout << "ID del Suministro: " << vectorReclamos[i].getSuministroId() << std::endl;
            std::cout << "Descripcion: " << vectorReclamos[i].getDescripcion() << std::endl;
            std::cout << "Fecha del Reclamo: " << vectorReclamos[i].getFechaReclamo().toString() << std::endl;
            std::cout << "Estado: " << vectorReclamos[i].getEstado() << std::endl;
            std::cout << "Tipo de Reclamo: " << vectorReclamos[i].getTipoDeReclamo() << std::endl;
            std::cout << "Responsable de Atencion: " << vectorReclamos[i].getResponsableDeAtencion() << std::endl;
            std::cout << "Respuesta: " << vectorReclamos[i].getRespuesta() << std::endl;
            std::cout << "Prioridad: " << vectorReclamos[i].getPrioridad() << std::endl;
            std::cout << "Activo: " << (vectorReclamos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===================================\n";
        }
    }

    // Mostrar información del usuario con menos reclamos
    std::cout << "El Usuario con menos reclamos (" << nombreUsuarioConMenosReclamos << " " << apellidoUsuarioConMenosReclamos << ") tiene " << minReclamos << " reclamos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].getUsuarioId() == usuarioConMenosReclamosId) {
            std::cout << "===== INFORMACION DEL RECLAMO =====\n";
            std::cout << "ID del Reclamo: " << vectorReclamos[i].getReclamoId() << std::endl;
            std::cout << "ID del Usuario: " << vectorReclamos[i].getUsuarioId() << std::endl;
            std::cout << "ID del Suministro: " << vectorReclamos[i].getSuministroId() << std::endl;
            std::cout << "Descripcion: " << vectorReclamos[i].getDescripcion() << std::endl;
            std::cout << "Fecha del Reclamo: " << vectorReclamos[i].getFechaReclamo().toString() << std::endl;
            std::cout << "Estado: " << vectorReclamos[i].getEstado() << std::endl;
            std::cout << "Tipo de Reclamo: " << vectorReclamos[i].getTipoDeReclamo() << std::endl;
            std::cout << "Responsable de Atencion: " << vectorReclamos[i].getResponsableDeAtencion() << std::endl;
            std::cout << "Respuesta: " << vectorReclamos[i].getRespuesta() << std::endl;
            std::cout << "Prioridad: " << vectorReclamos[i].getPrioridad() << std::endl;
            std::cout << "Activo: " << (vectorReclamos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===================================\n";
        }
    }

    // Mostrar clientes que no tienen reclamos
    bool hayClientesSinReclamos = false;
    std::cout << "Clientes sin reclamos:\n";
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        bool tieneReclamo = false;
        if (!vectorUsuarios[i].isAdmin()) {
            for (int j = 0; j < cantidadUsuarios; ++j) {
                if (vectorUsuarios[i].getId() == usuarios[j]) {
                    tieneReclamo = true;
                    break;
                }
            }
            if (!tieneReclamo) {
                std::cout << "ID del Usuario: " << vectorUsuarios[i].getId() << std::endl;
                std::cout << "Nombre: " << vectorUsuarios[i].getNombre() << std::endl;
                std::cout << "Apellido: " << vectorUsuarios[i].getApellido() << std::endl;
                std::cout << "===============================================\n";
                hayClientesSinReclamos = true;
            }
        }
    }

    if (!hayClientesSinReclamos) {
        std::cout << "No hay clientes sin reclamos." << std::endl;
    }

    // Imprimir gráfico de barras
    std::cout << "Grafico con cliente con mas reclamos y cliente con menos reclamos." << std::endl;
    imprimirGraficoBarras(maxReclamos, nombreUsuarioConMasReclamos, minReclamos, nombreUsuarioConMenosReclamos);

    delete[] vectorReclamos;
    delete[] vectorUsuarios;
    delete[] usuarios;
    delete[] conteoReclamos;
}

void Totales(){
    int cli = 0, sum = 0, ped=0, rec=0;
    float con = 0.0f;
    double promedio = 0;
    cli = TotalClientes();
    sum = TotalSuministros();
    ped = TotalPedidos();
    rec = TotalReclamos();
    con = TotalConsumo();
    TotalDeuda();
    //TotalSuministrosPorTipo();
    TotalSuministrosConsumoPorTipo();


    std::cout << "\nPromedios: \n" <<std::endl;
    promedio = static_cast<double>(sum) / cli;
    std::cout << "\tEl promedio de suministros por cliente es: " << promedio <<" Suministro/Cliente" << std::endl;
    promedio = static_cast<double>(rec) / cli;
    std::cout << "\n\tEl promedio de reclamos por cliente es: " << promedio <<" Reclamo/Cliente" << std::endl;
    promedio = static_cast<double>(ped) / cli;
    std::cout << "\n\tEl promedio de pedidos por cliente es: " << promedio << " Pedidos/Cliente" << std::endl;
    promedio = static_cast<double>(rec) / sum;
    std::cout << "\n\tEl promedio de reclamos por suministro es: " << promedio <<" Reclamos/Suministro" << std::endl;
    promedio = static_cast<double>(con) / sum;
    std::cout << "\n\tEl promedio de consumo por suministro es: " << promedio << " kWh/Cliente" << std::endl;

}

int TotalClientes() {
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    if (cantidadUsuariosTotales == 0) {
        std::cout << "No hay usuarios registrados." << std::endl;
        return 0;
    }

    Usuario* vectorUsuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, vectorUsuarios);

    int totalClientes = 0;

    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (!vectorUsuarios[i].isAdmin()) {
            totalClientes++;
        }
    }

    std::cout << "\n\tCantidad total de clientes: " << totalClientes << std::endl;

    delete[] vectorUsuarios;

    return totalClientes;
}

int TotalSuministros() {
    ArchivoSuministro archivoS("suministros.dat");

    int cantidadSuministrosTotales = archivoS.CantidadSuministros();
    if (cantidadSuministrosTotales == 0) {
        std::cout << "No hay suministros registrados." << std::endl;
        return 0;
    }

    std::cout << "\n\tCantidad total de suministros: " << cantidadSuministrosTotales << std::endl;
    return cantidadSuministrosTotales;
}

int TotalPedidos() {
    ArchivoPedido archivoP("pedidos.dat");

    int cantidadPedidosTotales = archivoP.CantidadPedidos();
    if (cantidadPedidosTotales == 0) {
        std::cout << "No hay pedidos registrados." << std::endl;
        return 0;
    }

    std::cout << "\n\tCantidad total de pedidos: " << cantidadPedidosTotales << std::endl;
    return cantidadPedidosTotales;
}

int TotalReclamos() {
    ArchivoReclamo archivoR("reclamos.dat");

    int cantidadReclamosTotales = archivoR.CantidadReclamos();
    if (cantidadReclamosTotales == 0) {
        std::cout << "No hay reclamos registrados." << std::endl;
        return 0;
    }

    std::cout << "\n\tCantidad total de reclamos: " << cantidadReclamosTotales << std::endl;
    return cantidadReclamosTotales;
}

float TotalConsumo() {
    ArchivoSuministro archivoS("suministros.dat");

    int cantidadSuministrosTotales = archivoS.CantidadSuministros();
    if (cantidadSuministrosTotales == 0) {
        std::cout << "\nNo hay suministros registrados." << std::endl;
        return 0.0f;
    }

    Suministro* vectorSuministros = new Suministro[cantidadSuministrosTotales];
    archivoS.LeerSuministros(cantidadSuministrosTotales, vectorSuministros);

    float totalConsumo = 0.0f;

    for (int i = 0; i < cantidadSuministrosTotales; ++i) {
        totalConsumo += vectorSuministros[i].getConsumoPorMes();
    }

    std::cout << "\n\tCantidad total del consumo de suministros: " << totalConsumo << " kWh"<<std::endl;

    delete[] vectorSuministros;
    return totalConsumo;
}

void TotalSuministrosPorTipo() {
    ArchivoSuministro archivoS("suministros.dat");

    int cantidadSuministrosTotales = archivoS.CantidadSuministros();
    if (cantidadSuministrosTotales == 0) {
        std::cout << "No hay suministros registrados." << std::endl;
        return;
    }

    const int NUM_TIPOS = 4; // Número de tipos diferentes de suministros
    const char* TIPOS_SUMINISTROS[NUM_TIPOS] = {"Comercial", "Industrial", "Agricola", "Residencial"}; // Los tipos de suministros

    Suministro* vectorSuministros = new Suministro[cantidadSuministrosTotales];
    archivoS.LeerSuministros(cantidadSuministrosTotales, vectorSuministros);

    int suministrosPorTipo[NUM_TIPOS] = {0}; // Array para contar los suministros por tipo
    for (int i = 0; i < cantidadSuministrosTotales; ++i) {
        const char* tipo = vectorSuministros[i].getTipoSuministro();
        for (int j = 0; j < NUM_TIPOS; ++j) {
            if (strcmp(tipo, TIPOS_SUMINISTROS[j]) == 0) {
                suministrosPorTipo[j]++;
                break;
            }
        }
    }

    std::cout << "\nCantidad total de suministros por tipo:\n";
    for (int j = 0; j < NUM_TIPOS; ++j) {
        std::cout << TIPOS_SUMINISTROS[j] << "\n\t - Cantidad: " << suministrosPorTipo[j] << "\n"<< std::endl;
    }

    delete[] vectorSuministros;
}

void TotalSuministrosConsumoPorTipo() {
    ArchivoSuministro archivoS("suministros.dat");

    int cantidadSuministrosTotales = archivoS.CantidadSuministros();
    if (cantidadSuministrosTotales == 0) {
        std::cout << "No hay suministros registrados." << std::endl;
        return;
    }

    const int NUM_TIPOS = 4; // Número de tipos diferentes de suministros
    const char* TIPOS_SUMINISTROS[NUM_TIPOS] = {"Comercial", "Industrial", "Agricola", "Residencial"}; // Los tipos de suministros

    Suministro* vectorSuministros = new Suministro[cantidadSuministrosTotales];
    archivoS.LeerSuministros(cantidadSuministrosTotales, vectorSuministros);

    int suministrosPorTipo[NUM_TIPOS] = {0}; // Array para contar los suministros por tipo
    float consumoPorTipo[NUM_TIPOS] = {0.0f}; // Array para acumular el consumo total por tipo de suministro
    float deudaPorTipo[NUM_TIPOS] = {0.0f}; // Array para acumular la deuda total por tipo de suministro
    for (int i = 0; i < cantidadSuministrosTotales; ++i) {
        const char* tipo = vectorSuministros[i].getTipoSuministro();
        float consumo = vectorSuministros[i].getConsumoPorMes();
        float montoDeuda = vectorSuministros[i].getMontoDeuda();

        for (int j = 0; j < NUM_TIPOS; ++j) {
            if (strcmp(tipo, TIPOS_SUMINISTROS[j]) == 0) {
                suministrosPorTipo[j]++;
                consumoPorTipo[j] += consumo;
                deudaPorTipo[j] += montoDeuda;
                break;
            }
        }
    }

    std::cout << "\nCantidad, consumo y deuda total de suministros por tipo:\n";
    for (int j = 0; j < NUM_TIPOS; ++j) {
        std::cout << "\n\t-" << TIPOS_SUMINISTROS[j] << " - Cantidad: " << suministrosPorTipo[j]
                  << " - Consumo Total: " << consumoPorTipo[j] << " kWh"
                  << " - Deuda Total: $" << deudaPorTipo[j] << std::endl;
    }

    delete[] vectorSuministros;
}

void TotalDeuda() {
    ArchivoSuministro archivoS("suministros.dat");

    int cantidadSuministrosTotales = archivoS.CantidadSuministros();
    if (cantidadSuministrosTotales == 0) {
        std::cout << "\nNo hay suministros registrados." << std::endl;
        return;
    }

    Suministro* vectorSuministros = new Suministro[cantidadSuministrosTotales];
    archivoS.LeerSuministros(cantidadSuministrosTotales, vectorSuministros);

    float totalDeuda = 0.0f;

    for (int i = 0; i < cantidadSuministrosTotales; ++i) {
        totalDeuda += vectorSuministros[i].getMontoDeuda();
    }

    std::cout << "\n\tCantidad total de deuda de suministros es: $" << totalDeuda << std::endl;

    delete[] vectorSuministros;
}
