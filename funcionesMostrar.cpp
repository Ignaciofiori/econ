#include <iostream>
#include "funcionesMostrar.h"

void mostrarRespuestasPedido(RespuestaPedido* respuestas, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Respuesta Pedido #" << (i + 1) << ":\n";
        std::cout << "ID de Respuesta: " << respuestas[i].getRespuestaId() << "\n";
        std::cout << "ID de Usuario: " << respuestas[i].getUsuarioId() << "\n";
        std::cout << "ID de Pedido: " << respuestas[i].getPedidoId() << "\n";
        std::cout << "Aceptado: " << (respuestas[i].getAceptado() ? "SI" : "No") << "\n";
        std::cout << "Fecha de Respuesta: " << respuestas[i].getFechaDeRespuesta().toString() << "\n";
        std::cout << "Comentarios: " << respuestas[i].getComentarios() << "\n";
        std::cout << "Activo: " << (respuestas[i].isActivo() ? "SI" : "No") << "\n";
        std::cout << "-----------------------------\n";
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
            std::cout << "FECHA DE NACIMIENTO: " << vectorUsuarios[i].getFechaNacimiento().toString() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}

void mostrarSuministros(Suministro* suministros, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        if (suministros[i].isActivo()) {


            bool tieneFechaBaja = suministros[i].getFechaBaja().getId() != 0;

            // Mostrar los detalles del suministro
            std::cout << "ID de Suministro: " << suministros[i].getSuministroId() << "\n";
            std::cout << "ID de Usuario: " << suministros[i].getUsuarioId() << "\n";
            std::cout << "Tipo de Suministro: " << suministros[i].getTipoSuministro() << "\n";
            std::cout << "Direccion: " << suministros[i].getDireccion() << "\n";
            std::cout << "Codigo Postal: " << suministros[i].getCodigoPostal() << "\n";
            std::cout << "Fecha de Alta: " << suministros[i].getFechaAlta().toString() << "\n";
            std::cout << "Fecha de Baja: "
                      << (tieneFechaBaja ? suministros[i].getFechaBaja().toString() : "Sigue Activo") << "\n";
            std::cout << "Contacto: " << suministros[i].getContacto() << "\n";
            std::cout << "Medidor: " << suministros[i].getMedidor() << "\n";
            std::cout << "Consumo por Mes: " << suministros[i].getConsumoPorMes() << " kWh\n";
            std::cout << "Precio por kWh: $" << suministros[i].getPrecioKwh() << "\n";
            std::cout << "Deuda: " << (suministros[i].hasDeuda() ? "Sí" : "No") << "\n";
            std::cout << "Monto de Deuda: $" << suministros[i].getMontoDeuda() << "\n";
            std::cout << "Reclamo: " << (suministros[i].hasReclamo() ? "Sí" : "No") << "\n";
            std::cout << "-----------------------------\n";
        }
    }
}

void mostrarPedidos(PedidoSuministro* pedidos, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        if(pedidos[i].isActivo()){

        std::cout << "ID de Pedido: " << pedidos[i].getPedidoId() << "\n";
        std::cout << "ID de Usuario: " << pedidos[i].getUsuarioId() << "\n";
        std::cout << "Tipo de Suministro: " << pedidos[i].getTipoSuministro() << "\n";
        std::cout << "Direccion: " << pedidos[i].getDireccion() << "\n";
        std::cout << "Codigo Postal: " << pedidos[i].getCodigoPostal() << "\n";
        std::cout << "Fecha de Pedido: " <<pedidos[i].getFechaPedido().toString() << "\n";
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
        std::cout << "Fecha de Reclamo: " << reclamos[i].getFechaReclamo().toString() << "\n";
        std::cout << "Estado: " << reclamos[i].getEstado() << "\n";
        std::cout << "Tipo de Reclamo: " << reclamos[i].getTipoDeReclamo() << "\n";
        std::cout << "Responsable de Atencion: " << reclamos[i].getResponsableDeAtencion() << "\n";
        std::cout << "Respuesta: " << reclamos[i].getRespuesta() << "\n";
        std::cout << "Prioridad: " << reclamos[i].getPrioridad() << "\n";
        std::cout << "-----------------------------\n";
    }
}

void mostrarReclamosCliente(int idUsuario) {
    ArchivoReclamo archivoR("reclamos.dat");

    int cantidadReclamos = archivoR.CantidadReclamos();
    if (cantidadReclamos == 0) {
        std::cout << "No hay reclamos para mostrar." << std::endl;
        return;
    }

    ArchivoUsuario archivoU("usuarios.dat");
    Reclamo* vectorReclamos = new Reclamo[cantidadReclamos];
    archivoR.LeerReclamos(cantidadReclamos, vectorReclamos);

    for (int i = 0; i < cantidadReclamos; ++i) {
        if (vectorReclamos[i].getUsuarioId() == idUsuario) {
            int posUsuario = archivoU.BuscarUsuario(vectorReclamos[i].getResponsableDeAtencion());
            Usuario responsable = archivoU.LeerUsuario(posUsuario);

            std::cout << "Reclamo #" << (i + 1) << ":\n";
            std::cout << "ID de Reclamo: " << vectorReclamos[i].getReclamoId() << "\n";
            std::cout << "ID de Suministro: " << vectorReclamos[i].getSuministroId() << "\n";
            std::cout << "Descripcion: " << vectorReclamos[i].getDescripcion() << "\n";
            std::cout << "Fecha de Reclamo: " << vectorReclamos[i].getFechaReclamo().toString() << "\n";
            std::cout << "Estado: " << vectorReclamos[i].getEstado() << "\n";
            std::cout << "Tipo de Reclamo: " << vectorReclamos[i].getTipoDeReclamo() << "\n";
            std::cout << "Responsable de Atencion: " << responsable.getNombre() << " " << responsable.getApellido() << "\n";
            std::cout << "Respuesta: " << vectorReclamos[i].getRespuesta() << "\n";
            std::cout << "Prioridad: " << vectorReclamos[i].getPrioridad() << "\n";
            std::cout << "-----------------------------\n";
        }
    }

    delete[] vectorReclamos;
}

