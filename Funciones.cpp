#include <iostream>
#include "Funciones.h"
#include <cstdlib>
#include <limits> // Para std::numeric_limits
#include <cstring>

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
 std::cout << "\n\n";
    std::cout << "======== BIENVENIDO A LA OFICINA VIRTUAL DE ECON ========\n\n";

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

            // Ignorar los caracteres no válidos en el buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora hasta el siguiente salto de línea
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar el salto de línea restante
            return valor; // Retorna el valor válido
        }
    }
}

Usuario registrarse() {

    int id;

    std::cout << "===== REGISTRO =====\n";

    std::cout << "Ingrese su ID (numero entero): ";
    std::cin >> id;


    char nombre[50];
    std::cout << "Ingrese su nombre: ";
    std::cin.ignore(); // Limpiar el buffer de entrada
    std::cin.getline(nombre, 50);


    char apellido[50];
    std::cout << "Ingrese su apellido: ";
    std::cin.getline(apellido, 50);



    std::cout << "Ingrese su DNI (numero entero): ";
    int dni = leerEntero(); // Usamos la función para leer y validar el DNI


    char email[50];
    std::cout << "Ingrese su correo electronico: ";
     // Limpiar el buffer de entrada
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


    char fechaNacimiento[50];
    std::cout << "Ingrese su fecha de nacimiento (DD/MM/AAAA): ";
    std::cin.getline(fechaNacimiento, 50);


   // Crear el nuevo usuario utilizando el constructor que recibe todos los parámetros
    Usuario nuevoUsuario(id, nombre, apellido, dni, email, contrasena, contacto, fechaNacimiento, false);

    system("cls");
    if (nuevoUsuario.getId() == 0) {
                    std::cout << "Error al registrarse. Inténtelo nuevamente.\n";
                }else {

    std::cout << "\nRegistro exitoso!\n";
    std::cout << "Usuario registrado: " << nombre << " " << apellido << "\n";
                }
    return nuevoUsuario;
}


void menuSecundario(Usuario usu) {
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n===== MENU SECUNDARIO =====\n";
        std::cout << "1. Ver Perfil\n";
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

            case 0:
                std::cout << "Sesion Cerrada Exitosamente...\n";
                break;

            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;
        }
    }
}
Usuario busquedaUsuarioPorEmail(const char *email) {
    ArchivoUsuario archivo("usuarios.dat");

    int cantidad = archivo.CantidadUsuarios();

    Usuario *vectorUsuarios = new Usuario[cantidad];
    if (vectorUsuarios == NULL) {
        std::cout << "ERROR AL ASIGNAR MEMORIA DINAMICA\n";
        return Usuario(); // Retorna un objeto Usuario por defecto
    }

    archivo.LeerUsuarios(cantidad, vectorUsuarios);

    for (int i = 0; i < cantidad; ++i) {
        // Verificar si el usuario está activo y el email coincide
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
    char contrasena[50];

    std::cout << "===== LOGIN =====\n";

    // Solicitar el email al usuario
    std::cout << "Ingrese su correo electronico: ";
    std::cin.ignore(); // Limpiar el buffer de entrada
    std::cin.getline(email, 50);

    Usuario usuarioALoguear = busquedaUsuarioPorEmail(email);

    if (usuarioALoguear.getId() != 0) {
        std::cout << "Ingrese su Contrasena: ";

        std::cin.getline(contrasena, 50);
        system("cls");

        // Verificar la contraseña
        if (confirmarContrasena(contrasena, usuarioALoguear.getContrasena())) {
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
                system("cls");
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
