#pragma once

class RespuestaPedido{

private:
    int _respuestaId;
    int _usuarioId;
    int _pedidoId;
    bool _aceptado;
    bool _activo;
    char _comentarios[150];
    int _fechaDeRespuesta;

public:
    RespuestaPedido();
    RespuestaPedido(int respuestaId, int usuarioId, int pedidoId, bool aceptado,
            int fechaDeRespuesta, const char* comentarios);

// Getters
    int getRespuestaId();
    int getUsuarioId();
    int getPedidoId();
    bool getAceptado();
    int getFechaDeRespuesta();
    const char* getComentarios();
    bool isActivo();

    // Setters
    void setRespuestaId(int id);
    void setUsuarioId(int id);
    void setPedidoId(int id);
    void setAceptado(bool aceptado);
    void setFechaDeRespuesta(int fecha);
    void setComentarios(const char* comentarios);
    void setActivo(bool activo);
};
