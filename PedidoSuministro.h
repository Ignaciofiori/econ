#pragma once
#include "Fecha.h"
#include <cstring>

class PedidoSuministro {
private:
    int _pedidoId;
    int _usuarioId;
    char _tipoSuministro[50];
    char _direccion[50];
    int _codigoPostal;
    Fecha _fechaPedido; // Cambiado para ser un objeto Fecha
    char _contacto[50];
    char _medidor[50];
    char _comentarios[100];
    bool _activo;

public:
    // Constructores
    PedidoSuministro();
    PedidoSuministro(int pedidoId, int usuarioId, char* tipoSuministro, char* direccion,
                     int codigoPostal, Fecha fechaPedido, char* contacto,
                     char* medidor, char* comentarios);

    // Getters
    int getPedidoId();
    int getUsuarioId();
    char* getTipoSuministro();
    char* getDireccion();
    int getCodigoPostal();
    Fecha getFechaPedido(); // Devuelve el objeto Fecha
    char* getContacto();
    char* getMedidor();
    char* getComentarios();
    bool isActivo();

    // Setters
    void setPedidoId(int pedidoId);
    void setUsuarioId(int usuarioId);
    void setTipoSuministro(char* tipoSuministro);
    void setDireccion(char* direccion);
    void setCodigoPostal(int codigoPostal);
    void setFechaPedido(Fecha fechaPedido); // Usa un objeto Fecha
    void setContacto(char* contacto);
    void setMedidor(char* medidor);
    void setComentarios(char* comentarios);
    void setActivo(bool activo);

    // Método para mostrar la información del pedido
    void mostrarPedido();
};
