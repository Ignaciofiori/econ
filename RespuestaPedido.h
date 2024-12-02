#pragma once
#include "Fecha.h"

class RespuestaPedido {

private:
    int _respuestaId;
    int _usuarioId;
    int _pedidoId;
    bool _aceptado;
    bool _activo;
    char _comentarios[150];
    Fecha _fechaDeRespuesta;  // Cambié el tipo de fechaDeRespuesta a un objeto Fecha

public:
    RespuestaPedido();
    RespuestaPedido(int respuestaId, int usuarioId, int pedidoId, bool aceptado,
             Fecha& fechaDeRespuesta,  char* comentarios);  // Cambié el tipo de fecha

// Getters
    int getRespuestaId();
    int getUsuarioId();
    int getPedidoId();
    bool getAceptado();
    Fecha getFechaDeRespuesta();  // Cambié el tipo de retorno a Fecha
    char* getComentarios();
    bool isActivo();

// Setters
    void setRespuestaId(int id);
    void setUsuarioId(int id);
    void setPedidoId(int id);
    void setAceptado(bool aceptado);
    void setFechaDeRespuesta( Fecha& fecha);  // Cambié el tipo del parámetro a Fecha
    void setComentarios( char* comentarios);
    void setActivo(bool activo);
};
