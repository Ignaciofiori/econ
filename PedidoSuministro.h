#pragma once
#include <string>

class PedidoSuministro {
private:
    int _pedidoId;
    int _usuarioId;
    char _tipoSuministro[50];
    char _direccion[50];
    int _codigoPostal;
    int _fechaPedido;
    int _contacto;
    char _medidor[50];
    char _comentarios[100];

public:

    PedidoSuministro();
    PedidoSuministro(int pedidoId, int usuarioId, const char* tipoSuministro, const char* direccion, int codigoPostal,
                     int fechaPedido, int contacto, const char* medidor, const char* comentarios);

    // Getters
    int getPedidoId() ;
    int getUsuarioId() ;
    const char* getTipoSuministro() ;
    const char* getDireccion() ;
    int getCodigoPostal() ;
    int getFechaPedido() ;
    int getContacto() ;
    const char* getMedidor() ;
    const char* getComentarios() ;

    // Setters
    void setPedidoId(int pedidoId);
    void setUsuarioId(int usuarioId);
    void setTipoSuministro(const char* tipoSuministro);
    void setDireccion(const char* direccion);
    void setCodigoPostal(int codigoPostal);
    void setFechaPedido(int fechaPedido);
    void setContacto(int contacto);
    void setMedidor(const char* medidor);
    void setComentarios(const char* comentarios);
};

