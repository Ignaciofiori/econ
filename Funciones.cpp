#include <iostream>
#include "Funciones.h"
#include <cstdlib>
#include <limits> // Para std::numeric_limits
#include <string>
#include <iostream>
#include "ArchivoFecha.h"  // Aseg�rate de incluir el archivo correcto

int contarPedidosActivos(PedidoSuministro* pedidos, int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; ++i) {
        if (pedidos[i].isActivo()) {
            ++contador;
        }
    }
    return contador;
}

void mostrarSuministros(Suministro* suministros, int cantidad) {
    ArchivoFecha archivoF("fechas.dat");
    for (int i = 0; i < cantidad; ++i) {
        if (suministros[i].isActivo()) {

            // Buscar y leer la fecha de alta
            int posAlta = archivoF.BuscarFecha(suministros[i].getFechaAlta());
            Fecha fechaAlta = archivoF.LeerFecha(posAlta);

            Fecha fechaBaja;
            bool tieneFechaBaja = suministros[i].getFechaBaja() != 0;

            if (tieneFechaBaja) {
                // Buscar y leer la fecha de baja si existe
                int posBaja = archivoF.BuscarFecha(suministros[i].getFechaBaja());
                fechaBaja = archivoF.LeerFecha(posBaja);
            }

            // Mostrar los detalles del suministro
            std::cout << "ID de Suministro: " << suministros[i].getSuministroId() << "\n";
            std::cout << "ID de Usuario: " << suministros[i].getUsuarioId() << "\n";
            std::cout << "Tipo de Suministro: " << suministros[i].getTipoSuministro() << "\n";
            std::cout << "Direccion: " << suministros[i].getDireccion() << "\n";
            std::cout << "Codigo Postal: " << suministros[i].getCodigoPostal() << "\n";
            std::cout << "Fecha de Alta: " << fechaAlta.toString() << "\n";
            std::cout << "Fecha de Baja: "
                      << (tieneFechaBaja ? fechaBaja.toString() : "Sigue Activo") << "\n";
            std::cout << "Contacto: " << suministros[i].getContacto() << "\n";
            std::cout << "Medidor: " << suministros[i].getMedidor() << "\n";
            std::cout << "Consumo por Mes: " << suministros[i].getConsumoPorMes() << " kWh\n";
            std::cout << "Precio por kWh: $" << suministros[i].getPrecioKwh() << "\n";
            std::cout << "Deuda: " << (suministros[i].hasDeuda() ? "S�" : "No") << "\n";
            std::cout << "Monto de Deuda: $" << suministros[i].getMontoDeuda() << "\n";
            std::cout << "Reclamo: " << (suministros[i].hasReclamo() ? "S�" : "No") << "\n";
            std::cout << "-----------------------------\n";
        }
    }
}

void mostrarPedidos(PedidoSuministro* pedidos, int cantidad) {
    ArchivoFecha archivoF("fechas.dat");
    for (int i = 0; i < cantidad; ++i) {
        if(pedidos[i].isActivo()){

        int pos = archivoF.BuscarFecha(pedidos[i].getFechaPedido());
        Fecha fechaPedido = archivoF.LeerFecha(pos);

        std::cout << "ID de Pedido: " << pedidos[i].getPedidoId() << "\n";
        std::cout << "ID de Usuario: " << pedidos[i].getUsuarioId() << "\n";
        std::cout << "Tipo de Suministro: " << pedidos[i].getTipoSuministro() << "\n";
        std::cout << "Direccion: " << pedidos[i].getDireccion() << "\n";
        std::cout << "Codigo Postal: " << pedidos[i].getCodigoPostal() << "\n";
        std::cout << "Fecha de Pedido: " << fechaPedido.toString() << "\n";
        std::cout << "Contacto: " << pedidos[i].getContacto() << "\n";
        std::cout << "Medidor: " << pedidos[i].getMedidor() << "\n";
        std::cout << "Comentarios: " << pedidos[i].getComentarios() << "\n";
        std::cout << "-----------------------------\n";
        }
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

void mostrarRespuestasPedido(RespuestaPedido* respuestas, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Respuesta Pedido #" << (i + 1) << ":\n";
        std::cout << "ID de Respuesta: " << respuestas[i].getRespuestaId() << "\n";
        std::cout << "ID de Usuario: " << respuestas[i].getUsuarioId() << "\n";
        std::cout << "ID de Pedido: " << respuestas[i].getPedidoId() << "\n";
        std::cout << "Aceptado: " << (respuestas[i].getAceptado() ? "SI" : "No") << "\n";
        std::cout << "Fecha de Respuesta: " << respuestas[i].getFechaDeRespuesta() << "\n";
        std::cout << "Comentarios: " << respuestas[i].getComentarios() << "\n";
        std::cout << "Activo: " << (respuestas[i].isActivo() ? "SI" : "No") << "\n";
        std::cout << "-----------------------------\n";
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
        return 500.0f; // Consumo medio-bajo
    } else if (strcmp(tipoSuministro, "Industrial") == 0) {
        return 2000.0f; // Mayor consumo
    } else if (strcmp(tipoSuministro, "Agricola") == 0) {
        return 1000.0f; // Consumo medio-alto
    } else if (strcmp(tipoSuministro, "Residencial") == 0) {
        return 300.0f; // Menor consumo
    } else {
        return 0.0f;
    }
}

float determinarPrecioKwh(char* tipoMedidor) {
    if (strcmp(tipoMedidor, "Medidor Electromecanico") == 0) {
        return 100.0f;
    } else if (strcmp(tipoMedidor, "Medidor Digital") == 0) {
        return 150.0f;
    } else if (strcmp(tipoMedidor, "Medidor Inteligente") == 0) {
        return 300.0f;
    } else if (strcmp(tipoMedidor, "Medidor Bidireccional") == 0) {
        return 350.0f;
    } else if (strcmp(tipoMedidor, "Medidor Trifasico") == 0) {
        return 370.0f;
    } else if (strcmp(tipoMedidor, "Medidor Monofasico") == 0) {
        return 280.0f;
    } else if (strcmp(tipoMedidor, "Medidor de Prepago") == 0) {
        return 180.0f;
    } else {
        return 0.0f; // Por si ocurre un error
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

void mostrarSuministrosAsociados(Usuario &usu) {
    // Cargar los suministros desde el archivo
    ArchivoSuministro archivoSuministro("suministros.dat");
    ArchivoFecha archivoFecha("fechas.dat");

    int cantidad = archivoSuministro.CantidadSuministros();
    Suministro *vectorSuministros;

    vectorSuministros = new Suministro[cantidad];

    archivoSuministro.LeerSuministros(cantidad, vectorSuministros);

    std::cout << "Suministros asociados al usuario " << usu.getNombre() << ":\n";

   for (int i = 0; i < cantidad; ++i) {
    if (vectorSuministros[i].getUsuarioId() == usu.getId() && vectorSuministros[i].isActivo()) {
        int posAlta = archivoFecha.BuscarFecha(vectorSuministros[i].getFechaAlta());
        int posBaja = archivoFecha.BuscarFecha(vectorSuministros[i].getFechaBaja());
        Fecha fechaAlta = archivoFecha.LeerFecha(posAlta);
        Fecha fechaBaja = archivoFecha.LeerFecha(posBaja);

        // Filtra por ID de usuario y estado activo
        std::cout << "ID de Suministro: " << vectorSuministros[i].getSuministroId() << "\n";
        std::cout << "Tipo de Suministro: " << vectorSuministros[i].getTipoSuministro() << "\n";
        std::cout << "Activo: " << (vectorSuministros[i].isActivo() ? "Si" : "No") << "\n";
        std::cout << "Direccion: " << vectorSuministros[i].getDireccion() << "\n";
        std::cout << "Codigo Postal: " << vectorSuministros[i].getCodigoPostal() << "\n";
        std::cout << "Fecha Alta: " << fechaAlta.toString() << "\n"; // O ajusta si tienes una clase Fecha
        std::cout << "Fecha Baja: " << (vectorSuministros[i].getFechaBaja() == 0 ? "Sigue Activo." : fechaBaja.toString()) << "\n"; // O ajusta si tienes una clase Fecha
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


    // Liberar la memoria din�mica
    delete[] vectorSuministros;
}

void mostrarRespuestas(Usuario &usu) {

    ArchivoRespuesta archivoRespuesta("respuestas.dat");
    ArchivoFecha archivoFechas("fechas.dat");
    int cantidadRespuestas = archivoRespuesta.CantidadRespuestas();
    RespuestaPedido *vectorRespuestas;


    vectorRespuestas = new RespuestaPedido[cantidadRespuestas];


    archivoRespuesta.LeerRespuestas(cantidadRespuestas, vectorRespuestas);


    ArchivoPedido archivoPedido("pedidos.dat");
    int cantidadPedidos = archivoPedido.CantidadPedidos();
    PedidoSuministro *vectorPedidos;

    vectorPedidos = new PedidoSuministro[cantidadPedidos];


    archivoPedido.LeerPedidos(cantidadPedidos, vectorPedidos);

    std::cout << "Respuestas asociadas al usuario " << usu.getNombre() << ":\n";


    for (int i = 0; i < cantidadRespuestas; ++i) {
        if (vectorRespuestas[i].getUsuarioId() == usu.getId() && vectorRespuestas[i].isActivo()) {

            PedidoSuministro pedidoRelacionado;
            for (int j = 0; j < cantidadPedidos; ++j) {
                if (vectorRespuestas[i].getPedidoId() == vectorPedidos[j].getPedidoId()) {
                    pedidoRelacionado = vectorPedidos[j];
                    break;
                }
            }

            int posFechaRespuesta = archivoFechas.BuscarFecha(vectorRespuestas[i].getFechaDeRespuesta());
            Fecha fechaRespuesta = archivoFechas.LeerFecha(posFechaRespuesta);
            int posFechaPedido = archivoFechas.BuscarFecha(pedidoRelacionado.getFechaPedido());
            Fecha fechaPedido = archivoFechas.LeerFecha(posFechaPedido);
            // Mostrar la informaci�n del pedido relacionado
            std::cout << "\n--- Informacion del Pedido ---\n";
            std::cout << "ID de Pedido: " << pedidoRelacionado.getPedidoId() << "\n";
            std::cout << "Tipo de Suministro: " << pedidoRelacionado.getTipoSuministro() << "\n";
            std::cout << "Direccion: " << pedidoRelacionado.getDireccion() << "\n";
            std::cout << "Codigo Postal: " << pedidoRelacionado.getCodigoPostal() << "\n";
            std::cout << "Fecha de Pedido: " << fechaPedido.toString() << "\n";
            std::cout << "Contacto: " << pedidoRelacionado.getContacto() << "\n";
            std::cout << "Medidor: " << pedidoRelacionado.getMedidor() << "\n";
            std::cout << "Comentarios: " << pedidoRelacionado.getComentarios() << "\n";
            std::cout << "Activo: " << (pedidoRelacionado.isActivo() ? "Si" : "No") << "\n";
            std::cout << "-----------------------------\n";

            // Mostrar la informaci�n de la respuesta
            std::cout << "ID de Respuesta: " << vectorRespuestas[i].getRespuestaId() << "\n";
            std::cout << "Aceptado: " << (vectorRespuestas[i].getAceptado() ? "Si" : "No") << "\n";
            std::cout << "Fecha de Respuesta: " << fechaRespuesta.toString()<< "\n";
            std::cout << "Comentarios: " << vectorRespuestas[i].getComentarios() << "\n";
            std::cout << "Activo: " << (vectorRespuestas[i].isActivo() ? "Si" : "No") << "\n";
            std::cout << "-----------------------------\n";
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

Usuario registrarse() {
    ArchivoFecha archivoFecha("fechas.dat");
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
    int idFecha = acum.getIdFechas();
    cargarFecha(fechaNacimiento);
    fechaNacimiento.setId(idFecha);


   // Crear el nuevo usuario utilizando el constructor que recibe todos los par�metros
    Usuario nuevoUsuario(idUsuario, nombre, apellido, dni, email, contrasena, contacto, idFecha,false);


    //system("cls");
    if (nuevoUsuario.getId() == 0) {
                    std::cout << "Error al registrarse. Int�ntelo nuevamente.\n";
                }else {

    archivoFecha.GuardarFecha(fechaNacimiento);
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


    int pedidoId, codigoPostal, fechaPedidoid, fechaId;
    char tipoSuministro[50], direccion[50], medidor[50], comentarios[100], contacto[50];

    pedidoId = acum.getIdSuministro();
    fechaId = acum.getIdFechas();

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
    fechaPedido.setId(fechaId);
    // Crear el objeto PedidoSuministro con los datos ingresados
    PedidoSuministro pedido(pedidoId, idUsuario, tipoSuministro, direccion, codigoPostal, fechaPedido.getId(), contacto, medidor, comentarios);

        if(pedido.getPedidoId() == 0){
                system("cls");
            std::cout << "Error al realizar el pedido de suministro. Intentelo nuevamente.\n";
    }else{
         system("cls");
        std::cout << "\Pedido Enviado al Administrador Exitosamente!\n";
        std::cout << "Se estara revisando la peticion y se brindara el servicio lo antes posible.\n";


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

        if (!(std::cin >> opcion)) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
            std::cout << "Entrada invalida. Por favor, intente nuevamente.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

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

        if (!opcionValida) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Funci�n para cargar un nuevo Reclamo
Reclamo cargarReclamo(Usuario &usu) {
    ArchivoAcumuladorId archivoAcum("acumulador.dat");
    ArchivoFecha archivoFecha("fechas.dat");
    ArchivoReclamo archivoReclamo("reclamos.dat");

    AcumuladorId acum = archivoAcum.LeerAcumuladorId(0);
    int reclamoId = acum.getIdReclamos();
    int fechaId = acum.getIdFechas();

    int suministroId, responsableDeAtencion;
    char descripcion[150], estado[50], tipoDeReclamo[50], respuesta[50], prioridad[50];

    mostrarSuministrosAsociados(usu);

        std::cout << "Ingrese el ID del Suministro del cual desea Generar un Reclamo: \n";
        suministroId = leerEntero();
        std::cin.ignore();

    Suministro suministroAGenerarReclamo = buscarSuministroPorId(suministroId,usu);
    if(suministroAGenerarReclamo.getSuministroId()!= 0){
    system("cls");
             //tipo de reclamo
    seleccionarTipoReclamo(tipoDeReclamo);


    std::cout << "Ingrese la descripcion del reclamo: ";
    std::cin.getline(descripcion, 150);

    Fecha fechaDeReclamo;
    fechaDeReclamo.FechaActual();
    fechaDeReclamo.setId(fechaId);

   //seteamos estado
    strcpy(estado, "pendiente");

    //id atencion
    responsableDeAtencion = 1;

//seteo respuesta en string vacio
    strcpy(respuesta, "");

//nivel prioridad
  seleccionarNivelPrioridad(prioridad);


    // Crear un nuevo objeto Reclamo con los datos ingresados
    Reclamo nuevoReclamo(reclamoId, usu.getId(), suministroId, descripcion, fechaDeReclamo.getId(), estado, tipoDeReclamo, responsableDeAtencion, respuesta, prioridad);

    if(nuevoReclamo.getReclamoId()!=0){

        archivoFecha.GuardarFecha(fechaDeReclamo);
        archivoReclamo.GuardarReclamo(nuevoReclamo);

     acum.setIdReclamos(acum.getIdReclamos()+1);
     acum.setIdFechas(acum.getIdFechas()+1);

     archivoAcum.EditarAcumuladorId(acum,0);
    }


    return nuevoReclamo ;
    }
        system("cls");
        std::cout << "No tienes ningun Suministro asociado con el id ingresado." << std::endl;
        return Reclamo();

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

    ArchivoFecha archivoF("fechas.dat");
    ArchivoSuministro archivoS("suministros.dat");
    ArchivoPedido archivoP("pedidos.dat");
    ArchivoRespuesta archivoResp("respuestas.dat");

    //tenemos ids
    int idFecha = acum.getIdFechas();

    //
    Fecha fechaAlta;
    fechaAlta.FechaActual();
    fechaAlta.setId(idFecha);

    //logica para asignar consumo y kilowats
    float consumo = determinarConsumoPorMes(pedido.getTipoSuministro());
    float precio = determinarPrecioKwh(pedido.getMedidor());

    Suministro suministroNuevo(pedido.getPedidoId(),pedido.getUsuarioId(),pedido.getTipoSuministro(),pedido.getDireccion(),pedido.getCodigoPostal(),
                               fechaAlta.getId(),0,pedido.getContacto(),pedido.getMedidor(),consumo,precio,false,false,0);

    if(suministroNuevo.getSuministroId()== 0){

        std::cout << "ERROR AL CREAR EL SUMINISTRO!!\n";
        opcionValida = true; //termino bucle
    }else{

            //guardo fecha nueva
            archivoF.GuardarFecha(fechaAlta);
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
            RespuestaPedido respuesta(idRespuesta,pedido.getUsuarioId(),pedido.getPedidoId(),true,fechaAlta.getId(),comentarios);
            if(respuesta.getRespuestaId()!= 0){
            archivoResp.GuardarRespuesta(respuesta);
            acum.setIdRespuestas(idRespuesta + 1);
            }else{std::cout << "ERROR AL GUARDAR LA RESPUESTA.\n";}

            acum.setIdFechas(idFecha + 1);
            archivoId.EditarAcumuladorId(acum,0);

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

                                int idFecha = acum.getIdFechas();
                                int idRespuesta = acum.getIdRespuestas();
                                fechaRespuesta.setId(idFecha);

                                          RespuestaPedido respuesta(idRespuesta,pedido.getUsuarioId(),pedido.getPedidoId(),false,fechaRespuesta.getId(),comentarios);

                                    ArchivoPedido archivoP("pedidos.dat");
                                    ArchivoRespuesta archivoRes("respuestas.dat");
                                    ArchivoFecha archivoF("fechas.dat");
                                    archivoF.GuardarFecha(fechaRespuesta);
                                    archivoRes.GuardarRespuesta(respuesta);

                                    pedido.setActivo(false);
                                    int pos = archivoP.BuscarPedido(pedido.getPedidoId());
                                    archivoP.EditarPedido(pedido,pos);


                                    acum.setIdFechas(idFecha+1);
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


void menuSecundario(Usuario usu) {
    int idUsuario = usu.getId();
    int opcion = -1;
    PedidoSuministro pedido;
    int cantidadPedidos;
    //MENU USUARIOS ADMIN
    if(usu.isAdmin()){
               while (opcion != 0) {
        std::cout << "\n===== MENU Admin =====\n";
        std::cout << "1. Ver Perfil\n";
        std::cout << "2. Ver Pedidos de Suministros\n";
        std::cout << "3. Estadisticas \n";
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
                cantidadPedidos = listaPedidos();

                if(cantidadPedidos!=0){
                pedido = seleccionarPedido();

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
    Reclamo reclamo;
    bool cargado;
       while (opcion != 0) {
        std::cout << "\n===== MENU Cliente =====\n";
        std::cout << "1. Ver Perfil\n";
        std::cout << "2. Pedir Suministro\n";
        std::cout << "3. Ver Suministros Asociados\n";
        std::cout << "4. Ver Respuestas a tu pedidos\n";
        std::cout << "5. Generar Reclamo\n";
        std::cout << "0. Cerrar Sesion (Desloguearse)\n";
        std::cout << "===========================\n";
        std::cout << "Seleccione una opcion: ";

        std::cin >> opcion;
        system("cls"); // Limpiar pantalla despu�s de cada selecci�n

       switch (opcion) {
    case 1:
        std::cout << "Perfil de " << usu.getNombre() << ":\n";
        usu.mostrarUsuario(); // M�todo para mostrar el perfil del usuario
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
        // C�digo para ver respuestas a los pedidos
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
