#include <cstring>
#include "RespuestaPedido.h"

RespuestaPedido::RespuestaPedido(){
    _respuestaId = 0;
    _usuarioId = 0;
    _pedidoId = 0;
    _aceptado = 0;
    _activo = false;
    strcpy(_comentarios, "");
    _fechaDeRespuesta = 0;
}

RespuestaPedido::RespuestaPedido(int respuestaId, int usuarioId, int pedidoId, bool aceptado,
            int fechaDeRespuesta, const char* comentarios){

    _respuestaId = respuestaId;
    _usuarioId = usuarioId;
    _pedidoId = pedidoId;
    _aceptado = aceptado;
    _activo = true;
    strcpy(_comentarios, comentarios);
    _fechaDeRespuesta = fechaDeRespuesta;
}

// Getters

int RespuestaPedido::getRespuestaId() {
    return _respuestaId;
}

int RespuestaPedido::getUsuarioId() {
    return _usuarioId;
}

int RespuestaPedido::getPedidoId() {
    return _pedidoId;
}
bool RespuestaPedido::getAceptado() {
    return _aceptado;
}
bool RespuestaPedido::isActivo(){
    return _activo;
}
int RespuestaPedido::getFechaDeRespuesta() {
    return _fechaDeRespuesta;
}

const char* RespuestaPedido::getComentarios() {
    return _comentarios;
}


// Setters
void RespuestaPedido::setRespuestaId(int respuestaId) {
    _respuestaId = respuestaId;
}

void RespuestaPedido::setUsuarioId(int usuarioId) {
    _usuarioId = usuarioId;
}

void RespuestaPedido::setPedidoId(int pedidoId) {
    _pedidoId = pedidoId;
}


void RespuestaPedido::setAceptado(bool aceptado) {
    _aceptado, aceptado;
}

void RespuestaPedido::setFechaDeRespuesta(int fechaDeRespuesta) {
    _fechaDeRespuesta = fechaDeRespuesta;
}

void RespuestaPedido::setComentarios(const char* comentarios) {
    strcpy(_comentarios, comentarios);
}

void RespuestaPedido::setActivo(bool activo){
    _activo = activo;
    }
