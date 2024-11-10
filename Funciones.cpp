#include <iostream>
#include "Funciones.h"
#include <cstdlib>
#include <limits> // Para std::numeric_limits
#include <string>

void mostrarPedidos(PedidoSuministro* pedidos, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "ID de Pedido: " << pedidos[i].getPedidoId() << "\n";
        std::cout << "ID de Usuario: " << pedidos[i].getUsuarioId() << "\n";
        std::cout << "Tipo de Suministro: " << pedidos[i].getTipoSuministro() << "\n";
        std::cout << "Direccion: " << pedidos[i].getDireccion() << "\n";
        std::cout << "Codigo Postal: " << pedidos[i].getCodigoPostal() << "\n";
        std::cout << "Fecha de Pedido: " << pedidos[i].getFechaPedido() << "\n";
        std::cout << "Contacto: " << pedidos[i].getContacto() << "\n";
        std::cout << "Medidor: " << pedidos[i].getMedidor() << "\n";
        std::cout << "Comentarios: " << pedidos[i].getComentarios() << "\n";
        std::cout << "-----------------------------\n";
    }
}


void mostrarReclamos(Reclamo* reclamos, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Reclamo #" << (i + 1) << ":\n";
        std::cout << "ID de Reclamo: " << reclamos[i].getReclamoId() << "\n";
        std::cout << "ID de Usuario: " << reclamos[i].getUsuarioId() << "\n";
        std::cout << "ID de Suministro: " << reclamos[i].getSuministroId() << "\n";
        std::cout << "Descripcion: " << reclamos[i].getDescripcion() << "\n";
        std::cout << "Fecha de Reclamo: " << reclamos[i].getFechaReclamo() << "\n";
        std::cout << "Estado: " << reclamos[i].getEstado() << "\n";
        std::cout << "Tipo de Reclamo: " << reclamos[i].getTipoDeReclamo() << "\n";
        std::cout << "Responsable de Atencion: " << reclamos[i].getResponsableDeAtencion() << "\n";
        std::cout << "Respuesta: " << reclamos[i].getRespuesta() << "\n";
        std::cout << "Prioridad: " << reclamos[i].getPrioridad() << "\n";
        std::cout << "-----------------------------\n";
    }
}

void mostrarFechas(Fecha *vectorFechas, int cantidadFechas) {
    for (int i = 0; i < cantidadFechas; i++) {
        std::cout << "FECHA ID: " << vectorFechas[i].getId() << std::endl;
        std::cout << "D�A: " << vectorFechas[i].getDia() << std::endl;
        std::cout << "MES: " << vectorFechas[i].getMes() << std::endl;
        std::cout << "A�O: " << vectorFechas[i].getAnio() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
void seleccionarTipoSuministro(char* tipoSuministro) {
    int opcion;
    bool opcionValida = false;

    while (!opcionValida) {
        std::cout << "Seleccione el tipo de suministro que desea:\n";
        std::cout << "1. Comercial\n";
        std::cout << "2. Industrial\n";
        std::cout << "3. Agricola\n";
        std::cout << "4. Residencial\n";
        std::cout << "Seleccione una opcion (1-4): ";
        std::cin >> opcion;

        // Validar la opcion seleccionada y asignar el tipo correspondiente
        switch (opcion) {
            case 1:
                strcpy(tipoSuministro, "Comercial");
                opcionValida = true;
                break;
            case 2:
                strcpy(tipoSuministro, "Industrial");
                opcionValida = true;
                break;
            case 3:
                strcpy(tipoSuministro, "Agricola");
                opcionValida = true;
                break;
            case 4:
                strcpy(tipoSuministro, "Residencial");
                opcionValida = true;
                break;
            default:
                system("cls");
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }
    }
}
void seleccionarTipoMedidor(char* tipoMedidor) {
    int opcion;
    bool opcionValida = false;

    while (!opcionValida) {
        std::cout << "Seleccione el tipo de medidor de energia electrica que desea:\n";
        std::cout << "1. Medidor Electromec�nico\n";
        std::cout << "2. Medidor Digital\n";
        std::cout << "3. Medidor Inteligente\n";
        std::cout << "4. Medidor Bidireccional\n";
        std::cout << "5. Medidor Trif�sico\n";
        std::cout << "6. Medidor Monof�sico\n";
        std::cout << "7. Medidor de Prepago\n";
        std::cout << "Seleccione una opcion (1-7): ";

        if (!(std::cin >> opcion)) {
            std::cin.clear(); // Clear error flag
            system("cls");
            std::cout << "Entrada invalida. Por favor, intente nuevamente.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

            switch (opcion) {
                case 1:
                    strcpy(tipoMedidor, "Medidor Electromec�nico");
                    opcionValida = true;
                    break;
                case 2:
                    strcpy(tipoMedidor, "Medidor Digital");
                    opcionValida = true;
                    break;
                case 3:
                    strcpy(tipoMedidor, "Medidor Inteligente");
                    opcionValida = true;
                    break;
                case 4:
                    strcpy(tipoMedidor, "Medidor Bidireccional");
                    opcionValida = true;
                    break;
                case 5:
                    strcpy(tipoMedidor, "Medidor Trif�sico");
                    opcionValida = true;
                    break;
                case 6:
                    strcpy(tipoMedidor, "Medidor Monof�sico");
                    opcionValida = true;
                    break;
                case 7:
                    strcpy(tipoMedidor, "Medidor de Prepago");
                    opcionValida = true;
                    break;
                default:
                    std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                    break;
            }
        }

        if (!opcionValida) {
            std::cin.clear();
            system("cls");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void cargarFecha(Fecha &fecha) {
    int dia, mes, anio;
    ArchivoAcumuladorId archivo("acumulador.dat");
    AcumuladorId acum = archivo.LeerAcumuladorId(0);
    int id = acum.getIdFechas(); // Lee el ID inicial

    bool fechaValida = false;

    while (!fechaValida) {
        std::cout << "Ingrese el dia de nacimiento: ";
        std::cin >> dia;
        // Verificar si la entrada es v�lida
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, ingrese numeros validos." << std::endl;
            continue;
        }

        std::cout << "Ingrese el mes de nacimiento: ";
        std::cin >> mes;

        // Verificar si la entrada es v�lida
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, ingrese numeros validos." << std::endl;
            continue;
        }


        std::cout << "Ingrese el a�o de nacimiento: ";
        std::cin >> anio;

            // Verificar si la entrada es v�lida
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, ingrese numeros validos." << std::endl;
            continue;
        }

        Fecha fechaTemp(id, dia, mes, anio);

        // Verifica si la fecha es v�lida
        if (fechaTemp.getId() == 0) {
            std::cout << "La fecha ingresada es inv�lida. Por favor, intente nuevamente." << std::endl;
        } else {
            fecha.setId(id); // Asigna el ID a la fecha
            fecha.setDia(dia);
            fecha.setMes(mes);
            fecha.setAnio(anio);
            std::cout << "Fecha ingresada correctamente: "
                      << dia << "/" << mes << "/" << anio << std::endl;
            fechaValida = true; // La fecha es v�lida, salimos del bucle
        }
    }


}

void mostrarUsuarios(Usuario *vectorUsuarios, int cantidadUsuarios) {
    for (int i = 0; i < cantidadUsuarios; i++) {
        if (vectorUsuarios[i].isActivo()) {  // Solo muestra usuarios activos
            std::cout << "USUARIO ID: " << vectorUsuarios[i].getId() << std::endl;
            std::cout << "NOMBRE: " << vectorUsuarios[i].getNombre() << std::endl;
            std::cout << "APELLIDO: " << vectorUsuarios[i].getApellido() << std::endl;
            std::cout << "DNI: " << vectorUsuarios[i].getDni() << std::endl;
            std::cout << "EMAIL: " << vectorUsuarios[i].getEmail() << std::endl;
            std::cout << "CONTRASENIA: " << vectorUsuarios[i].getContrasena() << std::endl;
            std::cout << "CONTACTO: " << vectorUsuarios[i].getContacto() << std::endl;
            std::cout << "FECHA DE NACIMIENTO: " << vectorUsuarios[i].getFechaNacimiento() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}

void mostrarSuministros(Suministro *vectorSuministros, int cantidadSuministros) {
    for (int i = 0; i < cantidadSuministros; i++) {
        if (vectorSuministros[i].isActivo()) {  // Solo muestra suministros activos
            std::cout << "SUMINISTRO ID: " << vectorSuministros[i].getSuministroId() << std::endl;
            std::cout << "USUARIO ID: " << vectorSuministros[i].getUsuarioId() << std::endl;
            std::cout << "TIPO DE SUMINISTRO: " << vectorSuministros[i].getTipoSuministro() << std::endl;
            std::cout << "DIRECCION: " << vectorSuministros[i].getDireccion() << std::endl;
            std::cout << "CODIGO POSTAL: " << vectorSuministros[i].getCodigoPostal() << std::endl;
            std::cout << "FECHA DE ALTA: " << vectorSuministros[i].getFechaAlta() << std::endl;
            std::cout << "FECHA DE BAJA: " << vectorSuministros[i].getFechaBaja() << std::endl;
            std::cout << "CONTACTO: " << vectorSuministros[i].getContacto() << std::endl;
            std::cout << "MEDIDOR: " << vectorSuministros[i].getMedidor() << std::endl;
            std::cout << "CONSUMO POR MES: " << vectorSuministros[i].getConsumoPorMes() << " kWh" << std::endl;
            std::cout << "PRECIO POR KWH: $" << vectorSuministros[i].getPrecioKwh() << std::endl;
            std::cout << "DEUDA PENDIENTE: " << (vectorSuministros[i].hasDeuda() ? "Si" : "No") << std::endl;
            if (vectorSuministros[i].hasDeuda()) {
                std::cout << "MONTO DE DEUDA: $" << vectorSuministros[i].getMontoDeuda() << std::endl;
            }
            std::cout << "RECLAMOS PENDIENTES: " << (vectorSuministros[i].hasReclamo() ? "Si" : "No") << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}

void bannerBienvenida(){

    Fecha fecha;
    fecha.FechaActual();

 std::cout << "\n\n";
    std::cout << "====================== "<< fecha.toString() <<" ======================\n";
    std::cout << "======== BIENVENIDO A LA OFICINA VIRTUAL DE ECON =======\n\n";

    std::cout << "EEEEEEEEEE      CCCCCCCCC     OOOOOOOOO     NNN     NNN\n";
    std::cout << "EEE             CCC           OOO   OOO     NNNN    NNN\n";
    std::cout << "EEE             CCC           OOO   OOO     NNNNN   NNN\n";
    std::cout << "EEE             CCC           OOO   OOO     NNN NN  NNN\n";
    std::cout << "EEEEEEEE        CCC           OOO   OOO     NNN  NN NNN\n";
    std::cout << "EEE             CCC           OOO   OOO     NNN   NNNNN\n";
    std::cout << "EEE             CCC           OOO   OOO     NNN    NNNN\n";
    std::cout << "EEEEEEEEEE      CCCCCCCCC     OOOOOOOOO     NNN     NNN\n";

    std::cout << "\n========================================================\n\n";

}

bool confirmarContrasena(const char* contrasena1, const char* contrasena2) {

    return strcmp(contrasena1, contrasena2) == 0;
}

int leerEntero() {
    int valor;
    while (true) {
        std::cin >> valor;


        if (std::cin.fail()) {
            std::cout << "Error: Entrada invalida. Por favor, ingrese un numero entero: ";


            std::cin.clear(); // Limpia el estado de error

            // Ignorar los caracteres no v�lidos en el buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora hasta el siguiente salto de l�nea
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar el salto de l�nea restante
            return valor; // Retorna el valor v�lido
        }
    }
}

Usuario registrarse() {

    ArchivoAcumuladorId archivo("acumulador.dat");
    AcumuladorId acum = archivo.LeerAcumuladorId(0);
    int idUsuario = acum.getIdUsuarios();

    std::cout << "===== REGISTRO =====\n";

    char nombre[50];
    std::cout << "Ingrese su nombre: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
    std::cin.getline(nombre, 50);


    char apellido[50];
    std::cout << "Ingrese su apellido: ";
    std::cin.getline(apellido, 50);



    std::cout << "Ingrese su DNI (numero entero): ";
    int dni = leerEntero(); // Usamos la funci�n para leer y validar el DNI


    char email[50];
    std::cout << "Ingrese su correo electronico: ";
    std::cin.getline(email, 50);

    bool contrasenaValida = false;
      char contrasena[50];
    while(!contrasenaValida){

            std::cout << "Ingrese una contrasena: ";
            std::cin.getline(contrasena, 50);


                char contrasenaConfirmacion[50];
            std::cout << "Repita la contrasena: ";
            std::cin.getline(contrasenaConfirmacion, 50);

            if (confirmarContrasena(contrasena, contrasenaConfirmacion)) {
                    contrasenaValida = true;
                } else {
                    std::cout << "Las contrasenas no coinciden. Intente nuevamente.\n";
                }

    }


    char contacto[50];
    std::cout << "Ingrese su numero de contacto: ";
    std::cin.getline(contacto, 50);


    Fecha fechaNacimiento ;
    cargarFecha(fechaNacimiento);
    int fechaId = fechaNacimiento.getId();


   // Crear el nuevo usuario utilizando el constructor que recibe todos los par�metros
    Usuario nuevoUsuario(idUsuario, nombre, apellido, dni, email, contrasena, contacto, fechaId,false);


    //system("cls");
    if (nuevoUsuario.getId() == 0) {
                    std::cout << "Error al registrarse. Int�ntelo nuevamente.\n";
                }else {

    system("cls");

    std::cout << "\nRegistro exitoso!\n";
    std::cout << "Usuario registrado: " << nombre << " " << apellido << "\n";


    int nuevoFechaId = fechaNacimiento.getId() + 1 ;

    idUsuario++;
    acum.setIdFechas(nuevoFechaId);
    acum.setIdUsuarios(idUsuario);
    archivo.EditarAcumuladorId(acum, 0);

                }


    return nuevoUsuario;
}


PedidoSuministro cargarPedidoSuministro(int idUsuario) {
    ArchivoAcumuladorId archivo("acumulador.dat");
    AcumuladorId acum = archivo.LeerAcumuladorId(0);


    int pedidoId, codigoPostal, fechaPedidoid, contacto, fechaId;
    char tipoSuministro[50], direccion[50], medidor[50], comentarios[100];

    pedidoId = acum.getIdSuministro();
    fechaId = acum.getIdFechas();

    seleccionarTipoSuministro(tipoSuministro);

    std::cout << "Ingrese la direccion: ";
    std::cin.ignore(); // Limpiar el buffer antes de getline
    std::cin.getline(direccion, 50);

    std::cout << "Ingrese el codigo postal: ";
    std::cin >> codigoPostal;
    std::cin.ignore(); // Limpiar el buffer despu�s de la entrada num�rica

    std::cout << "Ingrese numero de contacto del domicilio: ";
    std::cin >> contacto;
    std::cin.ignore(); // Limpiar el buffer despu�s de la entrada num�rica

    seleccionarTipoMedidor(medidor);

    std::cout << "Ingrese comentarios adicionales: ";
    std::cin.getline(comentarios, 100);

    Fecha fechaPedido;
    fechaPedido.FechaActual();
    fechaPedido.setId(fechaId);
    // Crear el objeto PedidoSuministro con los datos ingresados
    PedidoSuministro pedido(pedidoId, idUsuario, tipoSuministro, direccion, codigoPostal, fechaPedido.getId(), contacto, medidor, comentarios);

        if(pedido.getPedidoId() == 0){
                system("cls");
            std::cout << "Error al realizar el pedido de suministro. Intentelo nuevamente.\n";
    }else{
         system("cls");
        std::cout << "\Pedido Enviado al Administrador Exitosamente!\n";
        std::cout << " Se estara revisando la peticion y se brindara el servicio lo antes posible.\n";


    ArchivoFecha archiF("fechas.dat");
    archiF.GuardarFecha(fechaPedido);

    int nuevoFechaId = fechaPedido.getId() + 1 ;
    pedidoId = pedidoId + 1;
    acum.setIdFechas(nuevoFechaId);
    acum.setIdSuministros(pedidoId);
    archivo.EditarAcumuladorId(acum, 0);
    }
    return pedido;
}

void listaPedidos(){

ArchivoPedido archivoP("pedidos.dat");

int cant = archivoP.CantidadPedidos();
a
PedidoSuministro *vectorPedidos;

vectorPedidos = new PedidoSuministro[cant];

archivoP.LeerPedidos(cant,vectorPedidos);

mostrarPedidos(vectorPedidos,cant);

delete []vectorPedidos;
}

void menuSecundario(Usuario usu) {
    int idUsuario = usu.getId();
    int opcion = -1;
    //MENU USUARIOS ADMIN
    if(usu.isAdmin()){
               while (opcion != 0) {
        std::cout << "\n===== MENU Admin =====\n";
        std::cout << "1. Ver Perfil\n";
        std::cout << "2. Ver Pedidos de Suministros\n";
        std::cout << "0. Cerrar Sesion (Desloguearse)\n";

        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        std::cin >> opcion;
        system("cls"); // Limpiar pantalla despu�s de cada selecci�n

        switch (opcion) {
            case 1:
                std::cout << "Perfil de "<<usu.getNombre() <<":\n";
                usu.mostrarUsuario(); // M�todo para mostrar el perfil del usuario
                break;
            case 2:
                std::cout << "Pedidos de Suministros Solicitados:\n";
                listaPedidos();

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
    PedidoSuministro pedido;
    bool cargado;
       while (opcion != 0) {
        std::cout << "\n===== MENU Cliente =====\n";
        std::cout << "1. Ver Perfil\n";
        std::cout << "2. Pedir Suministro\n";
        std::cout << "0. Cerrar Sesion (Desloguearse)\n";
        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        std::cin >> opcion;
        system("cls"); // Limpiar pantalla despu�s de cada selecci�n

        switch (opcion) {
            case 1:
                std::cout << "Perfil de "<<usu.getNombre() <<":\n";
                usu.mostrarUsuario(); // M�todo para mostrar el perfil del usuario
                break;
            case 2:
                std::cout << "Perfil de "<<usu.getNombre() <<":\n";
                pedido = cargarPedidoSuministro(idUsuario);
                cargado = archivoP.GuardarPedido(pedido);
                if(!cargado){
                    std::cout << "Error al Crear el Pedido de Suministro.";
                }
                break;
            case 0:
                std::cout << "Sesion Cerrada Exitosamente...\n";
                break;

            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }
    }
        }
        }

Usuario busquedaUsuarioPorEmail( char *email) {
    ArchivoUsuario archivo("usuarios.dat");

    int cantidad = archivo.CantidadUsuarios();

    Usuario *vectorUsuarios = new Usuario[cantidad];
    if (vectorUsuarios == NULL) {
        std::cout << "ERROR AL ASIGNAR MEMORIA DINAMICA\n";
        return Usuario(); // Retorna un objeto Usuario por defecto
    }

    archivo.LeerUsuarios(cantidad, vectorUsuarios);

    for (int i = 0; i < cantidad; ++i) {
        // Verificar si el usuario est� activo y el email coincide
        if (vectorUsuarios[i].isActivo() && strcmp(vectorUsuarios[i].getEmail(), email) == 0) {
            Usuario encontrado = vectorUsuarios[i];
            delete[] vectorUsuarios;
            return encontrado;
        }
    }

    delete[] vectorUsuarios;
    return Usuario(); // Retorna un objeto Usuario por defecto
}


Usuario login() {
    char email[50];
    char contrasenaIngresada[50];
    char contrasena[50];
    std::cout << "===== LOGIN =====\n";

    // Solicitar el email al usuario
    std::cout << "Ingrese su correo electronico: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
    std::cin.getline(email, 50);


    Usuario usuarioALoguear = busquedaUsuarioPorEmail(email);

    if (usuarioALoguear.getId() != 0) {
        std::cout << "Ingrese su Contrasena: ";
        std::cin.getline(contrasenaIngresada, 50);
        system("cls");

        strcpy(contrasena,usuarioALoguear.getContrasena());

        // Verificar la contrase�a
        if (confirmarContrasena(contrasenaIngresada,contrasena)) {
            std::cout << "Bienvenido, " << usuarioALoguear.getNombre() << "!\n";

            return usuarioALoguear; // Retorna el usuario autenticado
        } else {
            std::cout << "Las Credenciales Son Invalidas.\n";
            return Usuario(); // Retorna un objeto Usuario por defecto
        }

    } else {
        system("cls");
        std::cout << "No se Encontro un Usuario con Ese Correo Electronico.\n";
        return Usuario(); // Retorna un objeto Usuario por defecto
    }
}


void menuPrincipal(){
    bool logueado = false;

    int opcion = -1;
    while(opcion != 0){


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
