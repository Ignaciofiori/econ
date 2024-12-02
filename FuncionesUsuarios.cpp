#include <iostream>
#include "FuncionesUsuarios.h"



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
    int dni = leerEntero(); // Usamos la función para leer y validar el DNI
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
    fechaNacimiento.setId(1);


   // Crear el nuevo usuario utilizando el constructor que recibe todos los parámetros
    Usuario nuevoUsuario(idUsuario, nombre, apellido, dni, email, contrasena, contacto, fechaNacimiento ,false);


    //system("cls");
    if (nuevoUsuario.getId() == 0) {
                    std::cout << "Error al registrarse. Inténtelo nuevamente.\n";
                }else {
    system("cls");

    std::cout << "\nRegistro exitoso!\n";
    std::cout << "Usuario registrado: " << nombre << " " << apellido << "\n";

    idUsuario++;
    acum.setIdUsuarios(idUsuario);
    archivo.EditarAcumuladorId(acum, 0);

                }


    return nuevoUsuario;
}

Usuario nuevoAdmin(){

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
    int dni = leerEntero(); // Usamos la función para leer y validar el DNI
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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


   // Crear el nuevo usuario utilizando el constructor que recibe todos los parámetros
    Usuario nuevoUsuario(idUsuario, nombre, apellido, dni, email, contrasena, contacto, fechaNacimiento,true);


    //system("cls");
    if (nuevoUsuario.getId() == 0) {
                    std::cout << "Error al registrarse. Inténtelo nuevamente.\n";
                }else {
    system("cls");

    std::cout << "\nRegistro exitoso!\n";
    std::cout << "Usuario registrado: " << nombre << " " << apellido << "\n";



    idUsuario++;
    acum.setIdUsuarios(idUsuario);
    archivo.EditarAcumuladorId(acum, 0);

                }


    return nuevoUsuario;
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

        // Verificar la contraseña
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
            std::cout << "FECHA DE NACIMIENTO: " << vectorUsuarios[i].getFechaNacimiento().toString() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}

bool confirmarContrasena(const char* contrasena1, const char* contrasena2) {

    return strcmp(contrasena1, contrasena2) == 0;
}


void listarUsuariosconReclamos(ArchivoReclamo& archivoR, ArchivoUsuario& archivoU){
    int cantidadReclamos = archivoR.CantidadReclamos();
    int totalUsuarios = archivoU.CantidadUsuarios();
    int i = 0, j = 0;

    // ------- LEO LOS RECLAMOS ---------------
    // ------- LEO LOS RECLAMOS ---------------
    Reclamo* vectReclamos = new Reclamo[cantidadReclamos];
    archivoR.LeerReclamos(cantidadReclamos, vectReclamos);

    // ---------------- CHECK DE QUE NO HAY NINGUN RECLAMO ----------------
    // ---------------- CHECK DE QUE NO HAY NINGUN RECLAMO ----------------
    if (cantidadReclamos == 0) {
        std::cout << "No hay reclamos para contar." << std::endl;
        delete[] vectReclamos;
        return;
    }




    if (totalUsuarios == 0 ){
        std::cout << "No gay usuarios registrados."<<std::endl;
        return;
    }

    Usuario* vecUsuarios = new Usuario[totalUsuarios];
    archivoU.LeerUsuarios(totalUsuarios, vecUsuarios);

    int* usuarios = new int[totalUsuarios];
    int* conteoR = new int[totalUsuarios] {};
    int usuarioId = 0,cantU = 0;
    bool encontrado = false;

    for (i = 0; i < cantidadReclamos; i++){
        usuarioId = vectReclamos[i].getUsuarioId();
        encontrado = false;
        //----------- VERIFICO SI EL USUARIO YA ESTA EN LA LISTA ----------
        //-----------       Y SI NO EXITE LO AÑADO               ----------
        for (j = 0; j < totalUsuarios; j++){
            if (usuarios[j]== usuarioId){
                conteoR[j]++;
                encontrado = true;
                break;
            }
        }

        if (!encontrado){
            usuarios[cantU] = usuarioId;
            conteoR[cantU] = 1;
            cantU++;
        }
    }

    ///----------- REVISAR MANERA PARA ORDENAR LOS USUARIOS POR CANTIDAD DE RECLAMOS ----------
    ///----------- REVISAR MANERA PARA ORDENAR LOS USUARIOS POR CANTIDAD DE RECLAMOS ----------
    ///----------- REVISAR MANERA PARA ORDENAR LOS USUARIOS POR CANTIDAD DE RECLAMOS ----------

    for(i = 0; i < cantU - 1; i++) {
        for (int j = 0; j < cantU - i - 1; j++) {
            if (conteoR[j] > conteoR[j + 1]) {
                // Intercambiar conteo de reclamos
                int aux = conteoR[j];
                conteoR[j] = conteoR[j + 1];
                conteoR[j + 1] = aux;

                // Intercambiar IDs de usuario
                aux = usuarios[j];
                usuarios[j] = usuarios[j + 1];
                usuarios[j + 1] = aux;
            }
        }
    }


    for(i = 0;i < cantU;i++){
        for(j = 0; j < totalUsuarios; j++){
          if(vecUsuarios[j].getId() == usuarios[i]){
            std::cout <<"Usuario : "<<vecUsuarios[j].getNombre()<<" "<<vecUsuarios[j].getApellido()<<"\n Cantidad de Reclamos : "<<conteoR[i]<<std::endl;
            break;
          }
        }
    }

    delete[] vectReclamos;
    delete[] vecUsuarios;
    delete[] usuarios;
    delete[] conteoR;

}


