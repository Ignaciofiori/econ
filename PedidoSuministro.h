#pragma once
#include <string>
#include <cstring>

class PedidoSuministro {
private:
    int _pedidoId;
    int _usuarioId;
    char _tipoSuministro[50];
    char _direccion[50];
    int _codigoPostal;
    int _fechaPedido;
    char _contacto[50]; // Cambiado de int a char[]
    char _medidor[50];
    char _comentarios[100];
    bool _activo;

public:

    PedidoSuministro();
    PedidoSuministro(int pedidoId, int usuarioId, const char* tipoSuministro, const char* direccion, int codigoPostal,
                     int fechaPedido, const char* contacto, const char* medidor, const char* comentarios); // Actualizado

    // Getters
    int getPedidoId();
    int getUsuarioId();
    const char* getTipoSuministro();
    const char* getDireccion();
    int getCodigoPostal();
    int getFechaPedido();
    const char* getContacto(); // Actualizado
    const char* getMedidor();
    const char* getComentarios();
    bool isActivo();

    // Setters
    void setPedidoId(int pedidoId);
    void setUsuarioId(int usuarioId);
    void setTipoSuministro(const char* tipoSuministro);
    void setDireccion(const char* direccion);
    void setCodigoPostal(int codigoPostal);
    void setFechaPedido(int fechaPedido);
    void setContacto(const char* contacto); // Actualizado
    void setMedidor(const char* medidor);
    void setComentarios(const char* comentarios);
    void setActivo(bool activo);

    void mostrarPedido();
};
