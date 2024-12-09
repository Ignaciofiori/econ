#include <iostream>
#include "Funciones.h"
#include "FuncionesPagos.h"
#include "FuncionesPrecios.h"
#include "FuncionesEstadisticas.h"
#include "funcionesMostrar.h"
#include <cstdlib>
#include <limits> // Para std::numeric_limits
#include <iomanip> // Para std::setw
#include <string>
#include <iostream>

int contarPedidosActivos(PedidoSuministro* pedidos, int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; ++i) {
        if (pedidos[i].isActivo()) {
            ++contador;
        }
    }
    return contador;
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

        opcion = leerEntero();

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
        std::cout << "1. Medidor Electromecanico\n";
        std::cout << "2. Medidor Digital\n";
        std::cout << "3. Medidor Inteligente\n";
        std::cout << "4. Medidor Bidireccional\n";
        std::cout << "5. Medidor Trifasico\n";
        std::cout << "6. Medidor Monofasico\n";
        std::cout << "7. Medidor de Prepago\n";
        std::cout << "Seleccione una opcion (1-7): ";

        if (!(std::cin >> opcion)) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
            std::cout << "Entrada invalida. Por favor, intente nuevamente.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

            switch (opcion) {
                case 1:
                    strcpy(tipoMedidor, "Medidor Electromecanico");
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
                    strcpy(tipoMedidor, "Medidor Trifasico");
                    opcionValida = true;
                    break;
                case 6:
                    strcpy(tipoMedidor, "Medidor Monofasico");
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

float determinarConsumoPorMes(char* tipoSuministro) {
    if (strcmp(tipoSuministro, "Comercial") == 0) {
        return 200.0f; // Consumo medio-bajo
    } else if (strcmp(tipoSuministro, "Industrial") == 0) {
        return 400.0f; // Mayor consumo
    } else if (strcmp(tipoSuministro, "Agricola") == 0) {
        return 300.0f; // Consumo medio-alto
    } else if (strcmp(tipoSuministro, "Residencial") == 0) {
        return 100.0f; // Menor consumo
    } else {
        return 0.0f;
    }
}

bool esFechaPasada( Fecha& fecha) {
    Fecha fechaActual;
    fechaActual.FechaActual(); // Establece la fecha actual en el objeto

    // Comparaci�n de a�os
    if (fecha.getAnio() > fechaActual.getAnio()) {
        return false; // La fecha est� en el futuro
    }
    if (fecha.getAnio() == fechaActual.getAnio()) {
        // Comparaci�n de meses
        if (fecha.getMes() > fechaActual.getMes()) {
            return false; // La fecha est� en el futuro
        }
        if (fecha.getMes() == fechaActual.getMes()) {
            // Comparaci�n de d�as
            if (fecha.getDia() > fechaActual.getDia()) {
                return false; // La fecha est� en el futuro
            }
        }
    }
    return true; // La fecha es v�lida (ha sucedido o es la actual)
}

void cargarFecha(Fecha& fecha) {
    int dia, mes, anio;
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

        std::cout << "Ingrese el anio de nacimiento: ";
        std::cin >> anio;
        // Verificar si la entrada es v�lida
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, ingrese numeros validos." << std::endl;
            continue;
        }

        Fecha fechaTemp(1, dia, mes, anio);

        // Verifica si la fecha es v�lida
        if (fechaTemp.getId() == 0) {
            std::cout << "La fecha ingresada es inv�lida. Por favor, intente nuevamente." << std::endl;
            continue;
        }

        // Verifica si la fecha ya sucedi�
        if (!esFechaPasada(fechaTemp)) {
            std::cout << "Vienes del Futuro?, No lo creo... Por favor, ingrese una fecha valida." << std::endl;
            continue;
        }

        // Si la fecha es v�lida y ya sucedi�, la asignamos al objeto fecha
        fecha.setDia(dia);
        fecha.setMes(mes);
        fecha.setAnio(anio);
        std::cout << "Fecha ingresada correctamente: "
                  << dia << "/" << mes << "/" << anio << std::endl;
        fechaValida = true; // La fecha es v�lida, salimos del bucle
    }
}
int mostrarSuministrosAsociados(Usuario &usu) {
    // Cargar los suministros desde el archivo
    ArchivoSuministro archivoSuministro("suministros.dat");
    int cantidad = archivoSuministro.CantidadSuministros();
    Suministro *vectorSuministros;

    vectorSuministros = new Suministro[cantidad];

    archivoSuministro.LeerSuministros(cantidad, vectorSuministros);

    //contamos para ver si hay
    int contador = 0;
    for (int x = 0; x < cantidad; ++x) {
    if (vectorSuministros[x].getUsuarioId() == usu.getId() && vectorSuministros[x].isActivo()){
        contador++;
    }
    }

    if(contador != 0){

            std::cout << "Suministros asociados al usuario " << usu.getNombre() << ":\n";

           for (int i = 0; i < cantidad; ++i) {
            if (vectorSuministros[i].getUsuarioId() == usu.getId() && vectorSuministros[i].isActivo()) {

                Fecha fechaAlta = vectorSuministros[i].getFechaAlta();
                Fecha fechaBaja = vectorSuministros[i].getFechaBaja();
                int idFechaBaja = fechaBaja.getId();


               vectorSuministros[i].mostrarSuministro();

            }
        }
}else{
                std::cout << "No se encontraron Suministros asociados al usuario :( \n";

}


    // Liberar la memoria din�mica
    delete[] vectorSuministros;
    return contador;
}

void mostrarRespuestas(Usuario &usu) {

    ArchivoRespuesta archivoRespuesta("respuestas.dat");
    int cantidadRespuestas = archivoRespuesta.CantidadRespuestas();
    RespuestaPedido *vectorRespuestas;


    vectorRespuestas = new RespuestaPedido[cantidadRespuestas];
    archivoRespuesta.LeerRespuestas(cantidadRespuestas, vectorRespuestas);


    ArchivoPedido archivoPedido("pedidos.dat");
    int cantidadPedidos = archivoPedido.CantidadPedidos();
    PedidoSuministro *vectorPedidos;

    vectorPedidos = new PedidoSuministro[cantidadPedidos];
    archivoPedido.LeerPedidos(cantidadPedidos, vectorPedidos);


       int contador = 0;
    for (int x = 0; x < cantidadRespuestas; ++x) {
    if (vectorRespuestas[x].getUsuarioId() == usu.getId() && vectorRespuestas[x].isActivo()){
        contador++;
    }
    }

    if(contador == 0){
         std::cout << " No se encontraron Respuestas asociadas al usuario :( \n";
    }else{

    std::cout << "Respuestas asociadas al usuario " << usu.getNombre() << " " << usu.getApellido() <<":\n";


    for (int i = 0; i < cantidadRespuestas; ++i) {
        if (vectorRespuestas[i].getUsuarioId() == usu.getId() && vectorRespuestas[i].isActivo()) {

            PedidoSuministro pedidoRelacionado;
            for (int j = 0; j < cantidadPedidos; ++j) {
                if (vectorRespuestas[i].getPedidoId() == vectorPedidos[j].getPedidoId()) {
                    pedidoRelacionado = vectorPedidos[j];
                    break;
                }
            }

            // Mostrar la informaci�n del pedido relacionado
            std::cout << "\n--- Informacion del Pedido ---\n";
            std::cout << "ID de Pedido: " << pedidoRelacionado.getPedidoId() << "\n";
            std::cout << "Tipo de Suministro: " << pedidoRelacionado.getTipoSuministro() << "\n";
            std::cout << "Direccion: " << pedidoRelacionado.getDireccion() << "\n";
            std::cout << "Codigo Postal: " << pedidoRelacionado.getCodigoPostal() << "\n";
            std::cout << "Fecha de Pedido: " << pedidoRelacionado.getFechaPedido().toString() << "\n";
            std::cout << "Contacto: " << pedidoRelacionado.getContacto() << "\n";
            std::cout << "Medidor: " << pedidoRelacionado.getMedidor() << "\n";
            std::cout << "Comentarios: " << pedidoRelacionado.getComentarios() << "\n";
            std::cout << "Activo: " << (pedidoRelacionado.isActivo() ? "Si" : "No") << "\n";
            std::cout << "-----------------------------\n";

            // Mostrar la informaci�n de la respuesta
            std::cout << "ID de Respuesta: " << vectorRespuestas[i].getRespuestaId() << "\n";
            std::cout << "Aceptado: " << (vectorRespuestas[i].getAceptado() ? "Si" : "No") << "\n";
            std::cout << "Fecha de Respuesta: " << vectorRespuestas[i].getFechaDeRespuesta().toString()<< "\n";
            std::cout << "Comentarios: " << vectorRespuestas[i].getComentarios() << "\n";
            std::cout << "Activo: " << (vectorRespuestas[i].isActivo() ? "Si" : "No") << "\n";
            std::cout << "-----------------------------\n";
        }
    }
  }


    delete[] vectorRespuestas;
    delete[] vectorPedidos;
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
    int numero;
    while (!(std::cin >> numero)) {
        std::cin.clear(); // Limpiar el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
        std::cout << "Entrada invalida. Por favor, ingrese un n�mero entero v�lido: ";
    }
    return numero;
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
    int dni = leerEntero(); // Usamos la funci�n para leer y validar el DNI
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


   // Crear el nuevo usuario utilizando el constructor que recibe todos los par�metros
    Usuario nuevoUsuario(idUsuario, nombre, apellido, dni, email, contrasena, contacto, fechaNacimiento,true);


    //system("cls");
    if (nuevoUsuario.getId() == 0) {
                    std::cout << "Error al registrarse. Int�ntelo nuevamente.\n";
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


   // Crear el nuevo usuario utilizando el constructor que recibe todos los par�metros
    Usuario nuevoUsuario(idUsuario, nombre, apellido, dni, email, contrasena, contacto, fechaNacimiento ,false);


    //system("cls");
    if (nuevoUsuario.getId() == 0) {
                    std::cout << "Error al registrarse. Int�ntelo nuevamente.\n";
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

PedidoSuministro cargarPedidoSuministro(int idUsuario) {
    ArchivoAcumuladorId archivo("acumulador.dat");
    AcumuladorId acum = archivo.LeerAcumuladorId(0);


    int pedidoId, codigoPostal, fechaPedidoid;
    char tipoSuministro[50], direccion[50], medidor[50], comentarios[100], contacto[50];

    pedidoId = acum.getIdSuministro();


    seleccionarTipoSuministro(tipoSuministro);

    std::cout << "Ingrese la direccion: ";
    std::cin.ignore(); // Limpiar el buffer antes de getline
    std::cin.getline(direccion, 50);

    std::cout << "Ingrese el codigo postal: ";
    codigoPostal = leerEntero();
    std::cin.ignore(); // Limpiar el buffer despu�s de la entrada num�rica

    std::cout << "Ingrese numero de contacto del domicilio: ";
    std::cin.getline(contacto, 50);

    seleccionarTipoMedidor(medidor);


    std::cout << "Ingrese comentarios adicionales: ";
    std::cin.getline(comentarios, 100);

    Fecha fechaPedido;
    fechaPedido.FechaActual();
    fechaPedido.setId(1);
    // Crear el objeto PedidoSuministro con los datos ingresados
    PedidoSuministro pedido(pedidoId, idUsuario, tipoSuministro, direccion, codigoPostal, fechaPedido, contacto, medidor, comentarios);

        if(pedido.getPedidoId() == 0){
                system("cls");
            std::cout << "Error al realizar el pedido de suministro. Intentelo nuevamente.\n";
    }else{
         system("cls");
        std::cout << "Pedido Enviado al Administrador Exitosamente!\n";
        std::cout << "Se estara revisando la peticion y se brindara el servicio lo antes posible.\n";

    pedidoId = pedidoId + 1;
    acum.setIdSuministros(pedidoId);
    archivo.EditarAcumuladorId(acum, 0);
    }
    return pedido;
}

void seleccionarTipoReclamo(char* tipoReclamo) {
    int opcion;
    bool opcionValida = false;

    while (!opcionValida) {
        std::cout << "Seleccione el tipo de reclamo que desea:\n";
        std::cout << "1. Reclamo por Malfuncionamiento\n";
        std::cout << "2. Reclamo por Facturacion Incorrecta\n";
        std::cout << "3. Reclamo por Demora en la Instalacion\n";
        std::cout << "4. Reclamo por Interrupciones Frecuentes\n";
        std::cout << "5. Reclamo por Atencion al Cliente\n";
        std::cout << "Seleccione una opcion (1-5): ";

        if (!(std::cin >> opcion)) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
            std::cout << "Entrada invalida. Por favor, intente nuevamente.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

            switch (opcion) {
                case 1:
                    strcpy(tipoReclamo, "Reclamo por Malfuncionamiento");
                    opcionValida = true;
                    break;
                case 2:
                    strcpy(tipoReclamo, "Reclamo por Facturacion Incorrecta");
                    opcionValida = true;
                    break;
                case 3:
                    strcpy(tipoReclamo, "Reclamo por Demora en la Instalacion");
                    opcionValida = true;
                    break;
                case 4:
                    strcpy(tipoReclamo, "Reclamo por Interrupciones Frecuentes");
                    opcionValida = true;
                    break;
                case 5:
                    strcpy(tipoReclamo, "Reclamo por Atencion al Cliente");
                    opcionValida = true;
                    break;
                default:
                    std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";

                    break;
            }
        }

        if (!opcionValida) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void seleccionarNivelPrioridad(char* nivelPrioridad) {
    int opcion;
    bool opcionValida = false;

    while (!opcionValida) {
        std::cout << "Seleccione el nivel de prioridad del reclamo:\n";
        std::cout << "1. Alta\n";
        std::cout << "2. Media\n";
        std::cout << "3. Baja\n";
        std::cout << "Seleccione una opcion (1-3): ";
            opcion = leerEntero();
            std::cin.ignore();

            switch (opcion) {
                case 1:
                    strcpy(nivelPrioridad, "Alta");
                    opcionValida = true;
                    break;
                case 2:
                    strcpy(nivelPrioridad, "Media");
                    opcionValida = true;
                    break;
                case 3:
                    strcpy(nivelPrioridad, "Baja");
                    opcionValida = true;
                    break;
                default:
                    std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                    break;
            }
        }

    }


// Funci�n para cargar un nuevo Reclamo
Reclamo cargarReclamo(Usuario &usu) {
    ArchivoSuministro archivoSumi("suministros.dat");
    ArchivoAcumuladorId archivoAcum("acumulador.dat");
    ArchivoReclamo archivoReclamo("reclamos.dat");

    AcumuladorId acum = archivoAcum.LeerAcumuladorId(0);
    int reclamoId = acum.getIdReclamos(); // Obtener el ID del pr�ximo reclamo
    int contador = 0;
    int suministroId, responsableDeAtencion;
    char descripcion[150], estado[50], tipoDeReclamo[50], respuesta[256], prioridad[50];

    // Mostrar los suministros asociados al usuario
    contador = mostrarSuministrosAsociados(usu);

    if (contador == 0) {
        std::cout << "No tienes ning�n suministro asociado sobre el cual puedas generar un reclamo.\n";
        return Reclamo(); // Devuelve un reclamo vac�o si no hay suministros
    } else {
        // Ingreso del ID del suministro
        std::cout << "Ingrese el ID del suministro del cual desea generar un reclamo:\n";
        suministroId = leerEntero();
        std::cin.ignore();

        Suministro suministroAGenerarReclamo = buscarSuministroPorId(suministroId, usu);
        if (suministroAGenerarReclamo.getSuministroId() != 0) {
            int posSuministro = archivoSumi.BuscarSuministro(suministroId);

            system("cls");

            // Selecci�n del tipo de reclamo
            seleccionarTipoReclamo(tipoDeReclamo);

            // Ingreso de la descripci�n
            std::cout << "Ingrese la descripci�n del reclamo: ";
            std::cin.getline(descripcion, sizeof(descripcion));

            // Fecha del reclamo
            Fecha fechaDeReclamo;
            fechaDeReclamo.FechaActual();
            fechaDeReclamo.setId(1);

            // Estado inicial del reclamo
            strcpy(estado, "pendiente");

            // ID del responsable de atenci�n
            responsableDeAtencion = 1;

            // Respuesta vac�a inicial
            strcpy(respuesta, "");

            // Nivel de prioridad
            seleccionarNivelPrioridad(prioridad);

            // Crear un nuevo objeto Reclamo
            Reclamo nuevoReclamo(reclamoId, usu.getId(), suministroId, descripcion,
                                  fechaDeReclamo, estado, tipoDeReclamo, responsableDeAtencion,
                                  respuesta, prioridad);

            if (nuevoReclamo.getReclamoId() != 0) {
                // Actualizar el suministro asociado
                suministroAGenerarReclamo.setReclamo(true);
                archivoSumi.EditarSuministro(suministroAGenerarReclamo, posSuministro);

                // Guardar el nuevo reclamo
                archivoReclamo.GuardarReclamo(nuevoReclamo);

                // Incrementar el ID de reclamos
                acum.setIdReclamos(acum.getIdReclamos() + 1);
                archivoAcum.EditarAcumuladorId(acum, 0);
            }

            return nuevoReclamo; // Retornar el nuevo reclamo creado
        }

        system("cls");
        std::cout << "No tienes ning�n suministro asociado con el ID ingresado.\n";
        return Reclamo(); // Devuelve un reclamo vac�o si el ID no es v�lido
    }
}

Suministro buscarSuministroPorId(int id,Usuario &usu) {
    ArchivoSuministro archivoS("suministros.dat");

    int cant = archivoS.CantidadSuministros();
    Suministro *vectorSuministros = new Suministro[cant];

    archivoS.LeerSuministros(cant, vectorSuministros);

    for (int i = 0; i < cant; ++i) {
        if (vectorSuministros[i].getSuministroId() == id &&
            vectorSuministros[i].getUsuarioId() == usu.getId()) {
            // Verifica que el suministro pertenece al usuario logueado
            Suministro suministroEncontrado = vectorSuministros[i]; // Copia el suministro encontrado
            delete[] vectorSuministros; // Libera la memoria antes de retornar
            return suministroEncontrado;
        }
    }

    delete[] vectorSuministros;
    return Suministro(); // Retorna un objeto Suministro vac�o si no se encuentra o si no pertenece al usuario
}

PedidoSuministro buscarPedidoPorId(int id){

ArchivoPedido archivoP("pedidos.dat");

int cant = archivoP.CantidadPedidos();

PedidoSuministro *vectorPedidos;

vectorPedidos = new PedidoSuministro[cant];

archivoP.LeerPedidos(cant,vectorPedidos);

 for (int i = 0; i < cant; ++i) {
        if(vectorPedidos[i].getPedidoId() == id){

            PedidoSuministro pedidoEncontrado = vectorPedidos[i]; // Copia el pedido encontrado
            delete[] vectorPedidos; // Libera la memoria antes de retornar
            return pedidoEncontrado;

        }
    }

delete []vectorPedidos;
return PedidoSuministro ();
}

int listaPedidos(){

ArchivoPedido archivoP("pedidos.dat");

int cant = archivoP.CantidadPedidos();

PedidoSuministro *vectorPedidos;

vectorPedidos = new PedidoSuministro[cant];

archivoP.LeerPedidos(cant,vectorPedidos);

int cantidadActivos = contarPedidosActivos(vectorPedidos,cant);

if(cantidadActivos!=0){
mostrarPedidos(vectorPedidos,cant);
}else{ std::cout<<"No tienes pedidos de suministros por el momento." << std::endl;}
delete []vectorPedidos;

return cantidadActivos;
}

PedidoSuministro seleccionarPedido(){
int idPedido = 0;
PedidoSuministro pedido;
std::cout << "Ingrese el ID del Pedido que desea Atender: \n";
 idPedido = leerEntero();
 pedido = buscarPedidoPorId(idPedido);

 return pedido;

}

Reclamo buscarReclamoPorId(int id) {
    ArchivoReclamo archivoR("reclamos.dat");

    int cant = archivoR.CantidadReclamos();
    Reclamo* vectorReclamos = new Reclamo[cant];

    archivoR.LeerReclamos(cant, vectorReclamos);

    for (int i = 0; i < cant; ++i) {
        if ((vectorReclamos[i].getReclamoId() == id)&&(vectorReclamos[i].isActivo())) {
            Reclamo reclamoEncontrado = vectorReclamos[i];
            delete[] vectorReclamos;
            return reclamoEncontrado;
        }
    }

    delete[] vectorReclamos;
    return Reclamo();
}

Reclamo buscarReclamoPorId(int id,bool realizado) {
    ArchivoReclamo archivoR("reclamos.dat");
    char pendiente[50] = "pendiente";
    char realizad[50] = "realizado";
    char estado[50];
    if(realizado){
        strcpy(estado,realizad);

    }else{
    strcpy(estado,pendiente);
    }

    int cant = archivoR.CantidadReclamos();
    Reclamo* vectorReclamos = new Reclamo[cant];

    archivoR.LeerReclamos(cant, vectorReclamos);

    for (int i = 0; i < cant; ++i) {
        if ((vectorReclamos[i].getReclamoId() == id)&&(vectorReclamos[i].isActivo())&&(!(strcmp(estado,vectorReclamos[i].getEstado())))) {
            Reclamo reclamoEncontrado = vectorReclamos[i];
            delete[] vectorReclamos;
            return reclamoEncontrado;
        }
    }

    delete[] vectorReclamos;
    return Reclamo();
}

Reclamo seleccionarReclamo(){
    int idReclamo = 0;
    Reclamo reclamo;
    std::cout << "Ingrese el ID del Reclamo que desea Atender: \n";
    idReclamo = leerEntero();
    reclamo = buscarReclamoPorId(idReclamo);
    return reclamo;
}

Reclamo seleccionarReclamo(bool realizado){
    int idReclamo = 0;
    Reclamo reclamo;
    std::cout << "Ingrese el ID del Reclamo que desea Atender: \n";
    idReclamo = leerEntero();
    reclamo = buscarReclamoPorId(idReclamo,realizado);
    return reclamo;
}

void creacionSuministro(PedidoSuministro pedido) {
    system("cls");
    ArchivoUsuario archivoU("usuarios.dat");
    int pos = archivoU.BuscarUsuario(pedido.getUsuarioId());
    Usuario usuarioPedido = archivoU.LeerUsuario(pos);

    std::cout << "Informacion del Perfil del Solicitante: \n";
    usuarioPedido.mostrarUsuario();

    std::cout << "Informacion del Pedido: \n";
    pedido.mostrarPedido();

    int acepted;
    bool opcionValida = false;
    ArchivoAcumuladorId archivoId("acumulador.dat");
    AcumuladorId acum = archivoId.LeerAcumuladorId(0);
    int idRespuesta = acum.getIdRespuestas();


    while (!opcionValida) {
        std::cout << "Desea Aceptar Esta Solicitud?: (En caso de Si insertar 1/ En caso de NO insertar 0)\n";
        acepted = leerEntero();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer

        if (acepted == 1) {
                //CREAMOS SUMINISTRO NUEVO


    ArchivoSuministro archivoS("suministros.dat");
    ArchivoPedido archivoP("pedidos.dat");
    ArchivoRespuesta archivoResp("respuestas.dat");


    //
    Fecha fechaAlta;
    fechaAlta.FechaActual();
    fechaAlta.setId(1);

    //logica para asignar consumo y kilowats
    float consumo = determinarConsumoPorMes(pedido.getTipoSuministro());
    float precio = determinarPrecioKwh(pedido.getMedidor());
    Fecha fechaBaja;

    Suministro suministroNuevo(pedido.getPedidoId(),pedido.getUsuarioId(),pedido.getTipoSuministro(),pedido.getDireccion(),pedido.getCodigoPostal(),
                               fechaAlta,fechaBaja,pedido.getContacto(),pedido.getMedidor(),consumo,precio,false,false,0);

    if(suministroNuevo.getSuministroId()== 0){

        std::cout << "ERROR AL CREAR EL SUMINISTRO!!\n";
        opcionValida = true; //termino bucle
    }else{
            //guardo suministro
            archivoS.GuardarSuministro(suministroNuevo);
            //borro pedido, no activo
            pedido.setActivo(false);
            int pos = archivoP.BuscarPedido(pedido.getPedidoId());
            archivoP.EditarPedido(pedido,pos);

            //mensaje de respuesta exitoso
             char comentarios[50];
            strcpy(comentarios, "Se acepto exitosamente la solicitud y se asigno el Suministro");

            //Guardo respuesta
            RespuestaPedido respuesta(idRespuesta,pedido.getUsuarioId(),pedido.getPedidoId(),true,fechaAlta,comentarios);
            if(respuesta.getRespuestaId()!= 0){
            archivoResp.GuardarRespuesta(respuesta);
            acum.setIdRespuestas(idRespuesta + 1);
            }else{std::cout << "ERROR AL GUARDAR LA RESPUESTA.\n";}

            system("cls");
            std::cout << "Pedido Aceptado, y Suministro Creado Exitosamente.\n";
            opcionValida = true;  // Salir del bucle porque la opci�n es v�lida

        }}
                                else if (acepted == 0) {
                                    system("cls");

                                char comentarios[50];
                                std::cout << "Ingrese comentarios relacionados al rechazo del pedido: ";
                                std::cin.getline(comentarios, 50);

                                Fecha fechaRespuesta;
                                fechaRespuesta.FechaActual();

                                int idRespuesta = acum.getIdRespuestas();
                                fechaRespuesta.setId(1);

                                          RespuestaPedido respuesta(idRespuesta,pedido.getUsuarioId(),pedido.getPedidoId(),false,fechaRespuesta,comentarios);

                                    ArchivoPedido archivoP("pedidos.dat");
                                    ArchivoRespuesta archivoRes("respuestas.dat");
                                    archivoRes.GuardarRespuesta(respuesta);

                                    pedido.setActivo(false);
                                    int pos = archivoP.BuscarPedido(pedido.getPedidoId());
                                    archivoP.EditarPedido(pedido,pos);

                                    acum.setIdRespuestas(idRespuesta + 1);

                                    archivoId.EditarAcumuladorId(acum,0);


                                    system("cls");
                                        std::cout << "Se Rechazo el Pedido.\n";
                                        //CREAR LOGICA PARA CREAR UNA RESPUESTA DE PEDIDO FALSE
                                        opcionValida = true;  // Salir del bucle porque la opci�n es v�lida

        } else {
            system("cls");
            std::cout << "Opcion invalida. Por favor, ingrese 1 para aceptar o 0 para rechazar.\n";
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


void accionesReclamos(Reclamo &reclamo, Usuario &usuario,Usuario& usuAdmin) {
    ArchivoReclamo archivoReclamo("reclamos.dat");
    int posReclamo = archivoReclamo.BuscarReclamo(reclamo.getReclamoId());

    ArchivoUsuario archivoU("usuarios.dat");
    int pos = archivoU.BuscarUsuario(reclamo.getUsuarioId());
    Usuario usu = archivoU.LeerUsuario(pos);
    char estado[50] = "realizado";
    int cantUsAdmin = 0;
    system("cls");
    int opcion = -1; // Inicializamos la opci�n con un valor que no sea v�lido

        while (opcion != 0) {
            // Mostrar men� de opciones
            std::cout << "===== MENU DE ACCIONES PARA RECLAMO =====\n";
            std::cout << "1. Responder Reclamo\n";
            std::cout << "0. Salir\n";
            std::cout << "Seleccione una opcion: ";

            opcion = leerEntero();
            std::cin.ignore();

            switch (opcion) {
                case 1:
                    system("cls");
                    usu.mostrarUsuario();
                    reclamo.mostrarReclamo();
                    std::cout << "Ingrese Respuesta: \n";
                    char respuesta[256]; // Tama�o fijo para la cadena de caracteres
                    std::cin.getline(respuesta, sizeof(respuesta)); // Capturar la entrada del usuario
                        // Declarar una cadena de caracteres constante
                    reclamo.setEstado(estado);
                    reclamo.setResponsableDeAtencion(usuario.getId());
                    reclamo.setRespuesta(respuesta); // Asignar la respuesta al reclamo
                    archivoReclamo.EditarReclamo(reclamo,posReclamo);
                    system("cls");
                    std::cout << "Respuesta registrada correctamente.\n";
                    opcion = 0;
                    break;

                case 0:
                    system("cls");
                    std::cout << "Saliendo...\n";
                    break;

                default:
                    std::cout << "Opci�n inv�lida. Intente nuevamente.\n";
            }
        }
    }


int listarReclamosEstado(bool estado) {
    system("cls");
    ArchivoReclamo archivoR("reclamos.dat");
    char pendiente[50] = "pendiente";
    char realizado[50] = "realizado";

    int cantidadReclamos = archivoR.CantidadReclamos();
    Reclamo* vectorReclamos = new Reclamo[cantidadReclamos];
    archivoR.LeerReclamos(cantidadReclamos, vectorReclamos);

    int auxR = 0;
    int auxP = 0;

    // Contador de reclamos realizados y pendientes
    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].isActivo()) {
            if (!strcmp(vectorReclamos[i].getEstado(), realizado)) {
                auxR++; // Contar como "realizado"
            } else if (!strcmp(vectorReclamos[i].getEstado(), pendiente)) {
                auxP++; // Contar como "pendiente"
            }
        }
    }

    // Mostrar los reclamos seg�n el estado
    if (estado) { // Mostrar "realizados"
        if (auxR == 0) {
            std::cout << "No hay reclamos REALIZADOS\n";
            delete[] vectorReclamos;
            return 0;
        } else {
            for (int i = 0; i < cantidadReclamos; i++) {
                if (!strcmp(vectorReclamos[i].getEstado(), realizado) && vectorReclamos[i].isActivo()) {
                    vectorReclamos[i].mostrarReclamo();
                }
            }
            delete[] vectorReclamos;
            return auxR;
        }
    } else { // Mostrar "pendientes"
        if (auxP == 0) {
            std::cout << "No hay reclamos PENDIENTES\n";
            delete[] vectorReclamos;
            return 0;
        } else {
            for (int i = 0; i < cantidadReclamos; i++) {
                if (!strcmp(vectorReclamos[i].getEstado(), pendiente) && vectorReclamos[i].isActivo()) {
                    vectorReclamos[i].mostrarReclamo();
                }
            }
            delete[] vectorReclamos;
            return auxP;
        }
    }
}


int mostrarSuministrosDeuda(Usuario &usu){
    ArchivoSuministro archivoSuministro("suministros.dat");

    int contador = 0;
    int cantidad = archivoSuministro.CantidadSuministros();
    Suministro *vectorSuministros;

    vectorSuministros = new Suministro[cantidad];

    archivoSuministro.LeerSuministros(cantidad, vectorSuministros);

    for (int x = 0; x < cantidad; ++x) {
    if (vectorSuministros[x].getUsuarioId() == usu.getId() && vectorSuministros[x].isActivo() && vectorSuministros[x].hasDeuda()) {
        contador++;
    }}

    if(contador !=0 ){
   for (int i = 0; i < cantidad; ++i) {
    if (vectorSuministros[i].getUsuarioId() == usu.getId() && vectorSuministros[i].isActivo() && vectorSuministros[i].hasDeuda()) {

        // Filtra por ID de usuario y estado activo
        std::cout << "ID de Suministro: " << vectorSuministros[i].getSuministroId() << "\n";
        std::cout << "Tipo de Suministro: " << vectorSuministros[i].getTipoSuministro() << "\n";
        std::cout << "Activo: " << (vectorSuministros[i].isActivo() ? "Si" : "No") << "\n";
        std::cout << "Direccion: " << vectorSuministros[i].getDireccion() << "\n";
        std::cout << "Codigo Postal: " << vectorSuministros[i].getCodigoPostal() << "\n";
        std::cout << "Fecha Alta: " << vectorSuministros[i].getFechaAlta().toString() << "\n"; // O ajusta si tienes una clase Fecha
        std::cout << "Fecha Baja: " << (vectorSuministros[i].getFechaBaja().getId() == 0 ? "Sigue Activo." : vectorSuministros[i].getFechaBaja().toString())<< "\n"; // O ajusta si tienes una clase Fecha
        std::cout << "Contacto: " << vectorSuministros[i].getContacto() << "\n";
        std::cout << "Medidor: " << vectorSuministros[i].getMedidor() << "\n";
        std::cout << "Consumo por Mes: " << vectorSuministros[i].getConsumoPorMes() << " kWh\n";
        std::cout << "Precio por kWh: $" << vectorSuministros[i].getPrecioKwh() << "\n";
        std::cout << "Deuda: " << (vectorSuministros[i].hasDeuda() ? "Si" : "No") << "\n";
        std::cout << "Reclamo: " << (vectorSuministros[i].hasReclamo() ? "Si" : "No") << "\n";
        std::cout << "Monto de Deuda: $" << vectorSuministros[i].getMontoDeuda() << "\n";
        std::cout << "-----------------------------\n";
}
   }
}
    return contador;
}
void usuariosConDeudas(ArchivoSuministro &archivoSumi, ArchivoUsuario &archivoUsu){
    int cantSuministros = archivoSumi.CantidadSuministros();
    Suministro* vecSumi = new Suministro[cantSuministros];
    archivoSumi.LeerSuministros(cantSuministros, vecSumi);

    /// LO DEMAS DE CODIGO LO ESTOY HACIENDO

}

void MenuEstadisticas1(){
    int opcion;
    std::cout << "\n===== MENU ESTADISTICAS =====\n";

    std::cout << "2. Estadisticas de Suministros\n";
    std::cout << "3. Estadisticas de Pedidos\n";

    std::cout << "0. Volver al menu anterior\n";
    std::cout << "===========================\n";
    std::cout << "Seleccione una opcion: ";

    std::cin >> opcion;
    system("cls"); // Limpiar pantalla despu�s de cada selecci�n

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
                std::cout << "Volviendo al Menu Anterior...\n";
                break;

            default:
                std::cout << "Opcion invalida. Por favor, intente nuevamente.\n";
                break;

    }
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
        //-----------       Y SI NO EXITE LO A�ADO               ----------
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

void mesDeudas(bool flag,ArchivoReclamo& archivoR, ArchivoUsuario& archivoU){
    int cantReclamos = archivoR.CantidadReclamos();
    Reclamo* vectReclamos = new Reclamo[cantReclamos];
    int i = 0;

    for(i = 0; i < cantReclamos; i++){
        vectReclamos[i] = archivoR.LeerReclamo(i);
    }


    if(flag){
        /// CODIGO PARA MES QUE HUBO MAS RECLAMOS
        ///     FALTA CORRECION FECHA
        for(i = 0; i < cantReclamos; i++){
            vectReclamos[i].getFechaReclamo();
        }
    }else{
        /// CODIGO PARA MES QUE HUBO MENOS RECLAMOS
        ///     FALTA CORRECION FECHA

    }
}

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

    // Obtener informaci�n del usuario con m�s reclamos
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

    // Mostrar informaci�n del usuario con m�s reclamos
    usuarioConMasReclamos.mostrarUsuario();

    // Mostrar todos los reclamos del usuario con m�s reclamos
    std::cout << "EL Usuario con m�s reclamos (" << nombreUsuarioConMasReclamos << " " << apellidoUsuarioConMasReclamos << "):\n";
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

    int* usuarios = new int[cantidadSuministros];  // Usamos cantidadSuministros como tama�o inicial, ya que no sabemos cu�ntos usuarios �nicos hay
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

    // Encontrar el usuario con m�s suministros
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

    // Obtener informaci�n del usuario con m�s suministros
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

    // Mostrar informaci�n del usuario con m�s suministros
    usuarioConMasSuministros.mostrarUsuario();

    // Mostrar todos los suministros del usuario con m�s suministros
    std::cout << "El Usuario con m�s suministros (" << nombreUsuarioConMasSuministros << " " << apellidoUsuarioConMasSuministros << "):\n";
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

    int* usuarios = new int[cantidadPedidos];  // Usamos cantidadPedidos como tama�o inicial, ya que no sabemos cu�ntos usuarios �nicos hay
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

    // Encontrar el usuario con m�s pedidos
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

    // Obtener informaci�n del usuario con m�s pedidos
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

    // Mostrar informaci�n del usuario con m�s pedidos
    usuarioConMasPedidos.mostrarUsuario();

    // Mostrar todos los pedidos del usuario con m�s pedidos
    std::cout << "El Usuario con m�s pedidos (" << nombreUsuarioConMasPedidos << " " << apellidoUsuarioConMasPedidos << "):\n";
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

    // Encontrar el usuario con m�s y menos reclamos
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
    // Obtener informaci�n de los usuarios con m�s y menos reclamos
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

    // Mostrar informaci�n del usuario con m�s reclamos
    std::cout << "El Usuario con m�s reclamos (" << nombreUsuarioConMasReclamos << " " << apellidoUsuarioConMasReclamos << ") tiene " << maxReclamos << " reclamos:\n";
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

    // Mostrar informaci�n del usuario con menos reclamos
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

    // Encontrar el usuario con m�s y menos suministros
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
    // Obtener informaci�n de los usuarios con m�s y menos suministros
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

    // Mostrar informaci�n de los usuarios con m�s suministros
    std::cout << "Usuarios con m�s suministros (" << maxSuministros << " suministros):\n";
    for (int i = 0; i < cantidadUsuariosConMaxSuministros; ++i) {
        std::cout << "ID del Usuario: " << idsUsuariosConMasSuministros[i] << "\n";
        std::cout << nombresUsuariosConMasSuministros[i] << " " << apellidosUsuariosConMasSuministros[i] << std::endl;
    }
    std::cout << "===============================================\n";

    // Mostrar informaci�n de los usuarios con menos suministros
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

    // Imprimir gr�fico de barras
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

    int* usuarios = new int[cantidadUsuariosTotales];  // Usamos la cantidad de usuarios totales como tama�o inicial
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

    // Encontrar el usuario con m�s y menos pedidos
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

    // Obtener informaci�n de los usuarios con m�s y menos pedidos
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

    // Mostrar informaci�n del usuario con m�s pedidos
    std::cout << "El Usuario con m�s pedidos (" << nombreUsuarioConMasPedidos << " " << apellidoUsuarioConMasPedidos << ") tiene " << maxPedidos << " pedidos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadPedidos; ++i) {
        if (vectorPedidos[i].getUsuarioId() == usuarioConMasPedidosId) {
            std::cout << "ID del Pedido: " << vectorPedidos[i].getPedidoId() << std::endl;
          /*  std::cout << "Tipo de Suministro: " << vectorPedidos[i].getTipoSuministro() << std::endl;
            std::cout << "Direccion: " << vectorPedidos[i].getDireccion() << std::endl;
            std::cout << "Codigo Postal: " << vectorPedidos[i].getCodigoPostal() << std::endl;
            std::cout << "Fecha del Pedido: " << vectorPedidos[i].getFechaPedido().toString() << std::endl;
            std::cout << "Contacto: " << vectorPedidos[i].getContacto() << std::endl;
            std::cout << "Medidor: " << vectorPedidos[i].getMedidor() << std::endl;
            std::cout << "Comentarios: " << vectorPedidos[i].getComentarios() << std::endl;
            std::cout << "Activo: " << (vectorPedidos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===============================================\n";*/
        }
    }

    // Mostrar informaci�n del usuario con menos pedidos
    std::cout << "El Usuario con menos pedidos (" << nombreUsuarioConMenosPedidos << " " << apellidoUsuarioConMenosPedidos << ") tiene " << minPedidos << " pedidos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadPedidos; ++i) {
        if (vectorPedidos[i].getUsuarioId() == usuarioConMenosPedidosId) {
            std::cout << "ID del Pedido: " << vectorPedidos[i].getPedidoId() << std::endl;
            //std::cout << "Tipo de Suministro: " << vectorPedidos[i].getTipoSuministro() << std::endl;
          //  std::cout << "Direccion: " << vectorPedidos[i].getDireccion() << std::endl;
           // std::cout << "Codigo Postal: " << vectorPedidos[i].getCodigoPostal() << std::endl;
           // std::cout << "Fecha del Pedido: " << vectorPedidos[i].getFechaPedido().toString() << std::endl;
           // std::cout << "Contacto: " << vectorPedidos[i].getContacto() << std::endl;
            //std::cout << "Medidor: " << vectorPedidos[i].getMedidor() << std::endl;
           // std::cout << "Comentarios: " << vectorPedidos[i].getComentarios() << std::endl;
            //std::cout << "Activo: " << (vectorPedidos[i].isActivo() ? "Si" : "No") << std::endl;
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

    EstadisticaPedidosGrafico();
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

    std::cout << "Gr�fico de barras del cliente con mas pedidos y cliente con menos pedidos:\n";
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

    // Encontrar el usuario con m�s y menos reclamos
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
     // Obtener informaci�n de los usuarios con m�s y menos reclamos
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

    // Mostrar informaci�n del usuario con m�s reclamos
    std::cout << "El Usuario con m�s reclamos (" << nombreUsuarioConMasReclamos << " " << apellidoUsuarioConMasReclamos << ") tiene " << maxReclamos << " reclamos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].getUsuarioId() == usuarioConMasReclamosId) {
            std::cout << "===== INFORMACION DEL RECLAMO =====\n";
            std::cout << "ID del Reclamo: " << vectorReclamos[i].getReclamoId() << std::endl;
            /*std::cout << "ID del Usuario: " << vectorReclamos[i].getUsuarioId() << std::endl;
            std::cout << "ID del Suministro: " << vectorReclamos[i].getSuministroId() << std::endl;
            std::cout << "Descripcion: " << vectorReclamos[i].getDescripcion() << std::endl;
            std::cout << "Fecha del Reclamo: " << vectorReclamos[i].getFechaReclamo().toString() << std::endl;
            std::cout << "Estado: " << vectorReclamos[i].getEstado() << std::endl;
            std::cout << "Tipo de Reclamo: " << vectorReclamos[i].getTipoDeReclamo() << std::endl;
            std::cout << "Responsable de Atencion: " << vectorReclamos[i].getResponsableDeAtencion() << std::endl;
            std::cout << "Respuesta: " << vectorReclamos[i].getRespuesta() << std::endl;
            std::cout << "Prioridad: " << vectorReclamos[i].getPrioridad() << std::endl;
            std::cout << "Activo: " << (vectorReclamos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===================================\n";*/
        }
    }

    // Mostrar informaci�n del usuario con menos reclamos
    std::cout << "El Usuario con menos reclamos (" << nombreUsuarioConMenosReclamos << " " << apellidoUsuarioConMenosReclamos << ") tiene " << minReclamos << " reclamos:\n";
    std::cout << "===============================================\n";
    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].getUsuarioId() == usuarioConMenosReclamosId) {
            std::cout << "===== INFORMACION DEL RECLAMO =====\n";
            std::cout << "ID del Reclamo: " << vectorReclamos[i].getReclamoId() << std::endl;
           /* std::cout << "ID del Usuario: " << vectorReclamos[i].getUsuarioId() << std::endl;
            std::cout << "ID del Suministro: " << vectorReclamos[i].getSuministroId() << std::endl;
            std::cout << "Descripcion: " << vectorReclamos[i].getDescripcion() << std::endl;
            std::cout << "Fecha del Reclamo: " << vectorReclamos[i].getFechaReclamo().toString() << std::endl;
            std::cout << "Estado: " << vectorReclamos[i].getEstado() << std::endl;
            std::cout << "Tipo de Reclamo: " << vectorReclamos[i].getTipoDeReclamo() << std::endl;
            std::cout << "Responsable de Atencion: " << vectorReclamos[i].getResponsableDeAtencion() << std::endl;
            std::cout << "Respuesta: " << vectorReclamos[i].getRespuesta() << std::endl;
            std::cout << "Prioridad: " << vectorReclamos[i].getPrioridad() << std::endl;
            std::cout << "Activo: " << (vectorReclamos[i].isActivo() ? "Si" : "No") << std::endl;
            std::cout << "===================================\n";*/
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

    // Imprimir gr�fico de barras
    std::cout << "Grafico con cliente con mas reclamos y cliente con menos reclamos." << std::endl;
    imprimirGraficoBarras(maxReclamos, nombreUsuarioConMasReclamos, minReclamos, nombreUsuarioConMenosReclamos);

    delete[] vectorReclamos;
    delete[] vectorUsuarios;
    delete[] usuarios;
    delete[] conteoReclamos;

}
void Promedios(){
    int cli = 0, sum = 0, ped=0, rec=0;
    float con = 0.0f;
    double promedio = 0;
    std::cout << "\nTotales:" <<std::endl;
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
void Totales(){
    int cli = 0, sum = 0, ped=0, rec=0;
    float con = 0.0f;
    double promedio = 0;
    std::cout << "\nTotales:" <<std::endl;
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
    std::cout << "\n\tEl promedio de consumo por suministro es: " << promedio << " kWh/Cliente\n" << std::endl;

}

int TotalClientes() {
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    if (cantidadUsuariosTotales == 0) {
        std::cout << "\n\tNo hay usuarios registrados." << std::endl;
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
        std::cout << "\n\tNo hay suministros registrados." << std::endl;
        return 0;
    }

    std::cout << "\n\tCantidad total de suministros: " << cantidadSuministrosTotales << std::endl;
    return cantidadSuministrosTotales;
}

int TotalPedidos() {
    ArchivoPedido archivoP("pedidos.dat");

    int cantidadPedidosTotales = archivoP.CantidadPedidos();
    if (cantidadPedidosTotales == 0) {
        std::cout << "\n\tNo hay pedidos registrados." << std::endl;
        return 0;
    }

    std::cout << "\n\tCantidad total de pedidos: " << cantidadPedidosTotales << std::endl;
    return cantidadPedidosTotales;
}

int TotalReclamos() {
    ArchivoReclamo archivoR("reclamos.dat");

    int cantidadReclamosTotales = archivoR.CantidadReclamos();
    if (cantidadReclamosTotales == 0) {
        std::cout << "\n\tNo hay reclamos registrados." << std::endl;
        return 0;
    }

    std::cout << "\n\tCantidad total de reclamos: " << cantidadReclamosTotales << std::endl;
    return cantidadReclamosTotales;
}

float TotalConsumo() {
    ArchivoSuministro archivoS("suministros.dat");

    int cantidadSuministrosTotales = archivoS.CantidadSuministros();
    if (cantidadSuministrosTotales == 0) {
        std::cout << "\n\tNo hay suministros registrados." << std::endl;
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

    const int NUM_TIPOS = 4; // N�mero de tipos diferentes de suministros
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
        std::cout << "\n\tNo hay suministros registrados." << std::endl;
        return;
    }

    const int NUM_TIPOS = 4; // N�mero de tipos diferentes de suministros
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

Suministro buscarSuministroPorIdDeuda(int sumId,Usuario &usu) {
    ArchivoSuministro archivoS("suministros.dat");

    int cant = archivoS.CantidadSuministros();
    Suministro* vectorSuministros = new Suministro[cant];

    archivoS.LeerSuministros(cant, vectorSuministros);

    for (int i = 0; i < cant; ++i) {
        if (vectorSuministros[i].getSuministroId() == sumId &&
            vectorSuministros[i].getUsuarioId() == usu.getId() &&
            vectorSuministros[i].hasDeuda() &&
            vectorSuministros[i].isActivo()) {
            Suministro suministroEncontrado = vectorSuministros[i];
            delete[] vectorSuministros;
            return suministroEncontrado;
        }
    }

    delete[] vectorSuministros;
    return Suministro();
}

Suministro seleccionarSuministroDeuda(Usuario &usu){

    int idSum = 0;
    Suministro suministro;
    std::cout << "Ingrese el ID del Suministro que desea Abonar: \n";
    idSum = leerEntero();
    suministro = buscarSuministroPorIdDeuda(idSum,usu);
    return suministro;
}


// Funci�n para intercambiar dos usuarios
void intercambiarUsuarios(Usuario& a, Usuario& b) {
    Usuario temp = a;
    a = b;
    b = temp;
}

// Ordenar los usuarios usando el algoritmo de burbuja
void ordenarUsuariosPorNombre(Usuario* usuarios, int cantidad) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - i - 1; ++j) {
            if (strcmp(usuarios[j].getNombre(), usuarios[j + 1].getNombre()) > 0) {
                intercambiarUsuarios(usuarios[j], usuarios[j + 1]);
            }
        }
    }
}

void listadoUsuarios() {
    ArchivoUsuario archivoU("usuarios.dat");

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    if (cantidadUsuariosTotales == 0) {
        std::cout << "No hay usuarios registrados." << std::endl;
        return;
    }

    // Usar memoria din�mica para almacenar usuarios
    Usuario* usuarios = new Usuario[cantidadUsuariosTotales];
    archivoU.LeerUsuarios(cantidadUsuariosTotales, usuarios);

    // Ordenar usuarios manualmente por nombre usando bubble sort
    ordenarUsuariosPorNombre(usuarios, cantidadUsuariosTotales);

    std::cout << "===== LISTADO DE USUARIOS ORDENADOS =====\n";
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        usuarios[i].mostrarUsuario();
    }
    std::cout << "=========================================\n";

    // Liberar la memoria din�mica
    delete[] usuarios;
}

void listadoSuministros() {
    ArchivoSuministro archivoS("suministros.dat");

    int cantidadSuministrosTotales = archivoS.CantidadSuministros();
    if (cantidadSuministrosTotales == 0) {
        std::cout << "No hay suministros registrados." << std::endl;
        return;
    }

    // Usar memoria din�mica para almacenar suministros
    Suministro* suministros = new Suministro[cantidadSuministrosTotales];
    archivoS.LeerSuministros(cantidadSuministrosTotales, suministros);

    std::cout << "===== LISTADO DE SUMINISTROS =====\n";
    for (int i = 0; i < cantidadSuministrosTotales; ++i) {
        suministros[i].mostrarSuministro();
    }
    std::cout << "=================================\n";

    // Liberar la memoria din�mica
    delete[] suministros;
}


void listadoFacturas() {
    ArchivoFactura archivoF("facturas.dat");

    int cantidadFacturasTotales = archivoF.CantidadFacturas();
    if (cantidadFacturasTotales == 0) {
        std::cout << "No hay facturas registradas." << std::endl;
        return;
    }

    // Usar memoria din�mica para almacenar facturas
    Factura* facturas = new Factura[cantidadFacturasTotales];
    archivoF.LeerFacturas(cantidadFacturasTotales, facturas);

    std::cout << "===== LISTADO DE FACTURAS =====\n";
    for (int i = 0; i < cantidadFacturasTotales; ++i) {
        facturas[i].mostrarFactura();
    }
    std::cout << "===============================\n";

    // Liberar la memoria din�mica
    delete[] facturas;
}

void listadoPedidos() {
    ArchivoPedido archivoP("pedidos.dat");

    int cantidadPedidosTotales = archivoP.CantidadPedidos();
    if (cantidadPedidosTotales == 0) {
        std::cout << "No hay pedidos registrados." << std::endl;
        return;
    }

    // Usar memoria din�mica para almacenar pedidos
    PedidoSuministro* pedidos = new PedidoSuministro[cantidadPedidosTotales];
    archivoP.LeerPedidos(cantidadPedidosTotales, pedidos);

    std::cout << "===== LISTADO DE PEDIDOS =====\n";
    for (int i = 0; i < cantidadPedidosTotales; ++i) {
        pedidos[i].mostrarPedido();
    }
    std::cout << "==============================\n";

    // Liberar la memoria din�mica
    delete[] pedidos;
}


void listadoReclamos() {
    ArchivoReclamo archivoR("reclamos.dat");

    int cantidadReclamosTotales = archivoR.CantidadReclamos();
    if (cantidadReclamosTotales == 0) {
        std::cout << "No hay reclamos registrados." << std::endl;
        return;
    }

    // Usar memoria din�mica para almacenar reclamos
    Reclamo* reclamos = new Reclamo[cantidadReclamosTotales];
    archivoR.LeerReclamos(cantidadReclamosTotales, reclamos);

    std::cout << "===== LISTADO DE RECLAMOS =====\n";
    for (int i = 0; i < cantidadReclamosTotales; ++i) {
        reclamos[i].mostrarReclamo();
    }
    std::cout << "===============================\n";

    // Liberar la memoria din�mica
    delete[] reclamos;
}


// Funci�n para encontrar clientes con m�s y menos facturas
void EstadisticaFacturas() {

    ArchivoUsuario archivoU("usuarios.dat");
    ArchivoFactura archivoF("facturas.dat");

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    int cantidadFacturasTotales = archivoF.CantidadFacturas();

    if (cantidadUsuariosTotales == 0) {
        std::cout << "\nNo hay usuarios registrados." << std::endl;
        return;
    }

    if (cantidadFacturasTotales == 0) {
        std::cout << "\nNo hay facturas registradas. Todos los usuarios est�n sin facturas." << std::endl;
        return;
    }

    // Usar memoria din�mica para almacenar usuarios y facturas
    Usuario* usuarios = new Usuario[cantidadUsuariosTotales];
    Factura* facturas = new Factura[cantidadFacturasTotales];

    archivoU.LeerUsuarios(cantidadUsuariosTotales, usuarios);
    archivoF.LeerFacturas(cantidadFacturasTotales, facturas);

    // Array para contar facturas por usuario
    int* facturasPorUsuario = new int[cantidadUsuariosTotales]();

    // Contar las facturas por usuario
    for (int i = 0; i < cantidadFacturasTotales; ++i) {
        int idUsuario = facturas[i].getIdUsuario();
        for (int j = 0; j < cantidadUsuariosTotales; ++j) {
            if (usuarios[j].getId() == idUsuario) {
                facturasPorUsuario[j]++;
                break;
            }
        }
    }

    int maxFacturas = 0, minFacturas = INT_MAX;
    int usuarioMaxFacturas = -1, usuarioMinFacturas = -1;

    // Encontrar el usuario con m�s y menos facturas
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (facturasPorUsuario[i] > maxFacturas) {
            maxFacturas = facturasPorUsuario[i];
            usuarioMaxFacturas = i;
        }
        if (facturasPorUsuario[i] < minFacturas && facturasPorUsuario[i] > 0) {
            minFacturas = facturasPorUsuario[i];
            usuarioMinFacturas = i;
        }
    }

    // Mostrar resultados
    if (usuarioMaxFacturas == usuarioMinFacturas) {
        std::cout << "\nEl cliente con m�s facturas es el mismo que el cliente con menos facturas:\nID "
                  << usuarios[usuarioMaxFacturas].getId() << " ("
                  << usuarios[usuarioMaxFacturas].getNombre() << " "
                  << usuarios[usuarioMaxFacturas].getApellido() << ") con "
                  << maxFacturas << " facturas.\n";
        std::cout << "===============================================\n";
    } else {
        std::cout << "\nCliente con m�s facturas:\nID " << usuarios[usuarioMaxFacturas].getId() << " ("
                  << usuarios[usuarioMaxFacturas].getNombre() << " " << usuarios[usuarioMaxFacturas].getApellido() << ") con "
                  << maxFacturas << " facturas.\n";
        std::cout << "===============================================\n";
        std::cout << "\nCliente con menos facturas:\nID " << usuarios[usuarioMinFacturas].getId() << " ("
                  << usuarios[usuarioMinFacturas].getNombre() << " " << usuarios[usuarioMinFacturas].getApellido() << ") con "
                  << minFacturas << " facturas.\n";
        std::cout << "===============================================\n";
    }

    // Mostrar todos los clientes sin facturas
    std::cout << "\nClientes sin facturas:\n";
    bool hayUsuariosSinFactura = false;
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (facturasPorUsuario[i] == 0) {
            std::cout << "ID " << usuarios[i].getId() << " ("
                      << usuarios[i].getNombre() << " " << usuarios[i].getApellido() << ")\n";
            hayUsuariosSinFactura = true;
        }
    }

    if (!hayUsuariosSinFactura) {
        std::cout << "\nNo hay usuarios sin facturas.\n";
    }

    // Liberar la memoria din�mica
    delete[] usuarios;
    delete[] facturas;
    delete[] facturasPorUsuario;
}

void EstadisticaDeuda() {
    ArchivoUsuario archivoU("usuarios.dat");
    ArchivoSuministro archivoS("suministros.dat");

    int cantidadUsuariosTotales = archivoU.CantidadUsuarios();
    int cantidadSuministrosTotales = archivoS.CantidadSuministros();

    if (cantidadUsuariosTotales == 0) {
        std::cout << "\nNo hay usuarios registrados.\n" << std::endl;
        return;
    }

    if (cantidadSuministrosTotales == 0) {
        std::cout << "\nNo hay suministros registrados.\n" << std::endl;
        return;
    }

    // Usar memoria din�mica para almacenar usuarios y suministros
    Usuario* usuarios = new Usuario[cantidadUsuariosTotales];
    Suministro* suministros = new Suministro[cantidadSuministrosTotales];

    archivoU.LeerUsuarios(cantidadUsuariosTotales, usuarios);
    archivoS.LeerSuministros(cantidadSuministrosTotales, suministros);

    // Variables para rastrear la deuda
    float mayorDeuda = -1;
    float menorDeuda = -1;
    int idUsuarioMayorDeuda = -1;
    int idUsuarioMenorDeuda = -1;
    std::string nombreUsuarioMayorDeuda;
    std::string apellidoUsuarioMayorDeuda;
    std::string nombreUsuarioMenorDeuda;
    std::string apellidoUsuarioMenorDeuda;

    // Bucle para encontrar usuarios sin deuda
    std::cout << "\nClientes sin deuda:\n";
    for (int i = 0; i < cantidadUsuariosTotales; ++i) {
        if (usuarios[i].isAdmin()) {
            continue; // Saltar administradores
        }

        float deudaUsuario = 0;
        bool tieneDeuda = false;

        for (int j = 0; j < cantidadSuministrosTotales; ++j) {
            if (suministros[j].getUsuarioId() == usuarios[i].getId()) {
                deudaUsuario += suministros[j].getMontoDeuda();
                tieneDeuda = true;
            }
        }

        if (!tieneDeuda) {
            std::cout << "ID " << usuarios[i].getId() << " ("
                      << usuarios[i].getNombre() << " " << usuarios[i].getApellido() << ")\n";
            std::cout << "===============================================\n";
        }

        if (tieneDeuda) {
            if (mayorDeuda == -1 || deudaUsuario > mayorDeuda) {
                mayorDeuda = deudaUsuario;
                idUsuarioMayorDeuda = usuarios[i].getId();
                nombreUsuarioMayorDeuda = usuarios[i].getNombre();
                apellidoUsuarioMayorDeuda = usuarios[i].getApellido();
            }

            if (menorDeuda == -1 || (deudaUsuario < menorDeuda && tieneDeuda)) {
                menorDeuda = deudaUsuario;
                idUsuarioMenorDeuda = usuarios[i].getId();
                nombreUsuarioMenorDeuda = usuarios[i].getNombre();
                apellidoUsuarioMenorDeuda = usuarios[i].getApellido();
            }
        }
    }

    // Mostrar resultados
    if (idUsuarioMayorDeuda == idUsuarioMenorDeuda) {
        std::cout << "\nEl cliente con mayor deuda es el mismo que el cliente con menor deuda: ID "
                  << idUsuarioMayorDeuda << " ("
                  << nombreUsuarioMayorDeuda << " " << apellidoUsuarioMayorDeuda << ") con $"
                  << mayorDeuda << " de deuda.\n";

        std::cout << "===============================================\n";
    } else {
        std::cout << "\nCliente con mayor deuda: ID " << idUsuarioMayorDeuda << " ("
                  << nombreUsuarioMayorDeuda << " " << apellidoUsuarioMayorDeuda << ") con $"
                  << mayorDeuda << " de deuda.\n";
        std::cout << "===============================================\n";
        std::cout << "Cliente con menor deuda: ID " << idUsuarioMenorDeuda << " ("
                  << nombreUsuarioMenorDeuda << " " << apellidoUsuarioMenorDeuda << ") con $"
                  << menorDeuda << " de deuda.\n";
        std::cout << "===============================================\n";
    }

    // Liberar la memoria din�mica
    delete[] usuarios;
    delete[] suministros;
}






