#pragma once
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
    PedidoSuministro(int pedidoId, int usuarioId,  char* tipoSuministro,  char* direccion, int codigoPostal,
                     int fechaPedido,  char* contacto,  char* medidor,  char* comentarios); // Actualizado

    // Getters
    int getPedidoId();
    int getUsuarioId();
    char* getTipoSuministro();
    char* getDireccion();
    int getCodigoPostal();
    int getFechaPedido();
    char* getContacto(); // Actualizado
    char* getMedidor();
    char* getComentarios();
    bool isActivo();

    // Setters
    void setPedidoId(int pedidoId);
    void setUsuarioId(int usuarioId);
    void setTipoSuministro( char* tipoSuministro);
    void setDireccion( char* direccion);
    void setCodigoPostal(int codigoPostal);
    void setFechaPedido(int fechaPedido);
    void setContacto( char* contacto); // Actualizado
    void setMedidor( char* medidor);
    void setComentarios( char* comentarios);
    void setActivo(bool activo);

    void mostrarPedido();
};
