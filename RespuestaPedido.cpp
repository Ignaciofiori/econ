#include <cstring>
#include "RespuestaPedido.h"
#include "Fecha.h"  // Asegúrate de incluir la clase Fecha

// Constructor por defecto
RespuestaPedido::RespuestaPedido() {
    _respuestaId = 0;
    _usuarioId = 0;
    _pedidoId = 0;
    _aceptado = false;
    _activo = false;
    strcpy(_comentarios, "");
    // Inicializamos _fechaDeRespuesta con un objeto Fecha por defecto
}

// Constructor parametrizado
RespuestaPedido::RespuestaPedido(int respuestaId, int usuarioId, int pedidoId, bool aceptado,
             Fecha& fechaDeRespuesta,  char* comentarios) {
    _respuestaId = respuestaId;
    _usuarioId = usuarioId;
    _pedidoId = pedidoId;
    _aceptado = aceptado;
    _fechaDeRespuesta = fechaDeRespuesta;  // Se asigna el objeto Fecha
    strcpy(_comentarios, comentarios);
    _activo = true;
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

Fecha RespuestaPedido::getFechaDeRespuesta() {
    return _fechaDeRespuesta;  // Devuelves el objeto Fecha
}

 char* RespuestaPedido::getComentarios() {
    return _comentarios;
}

bool RespuestaPedido::isActivo() {
    return _activo;
}

// Setters
void RespuestaPedido::setRespuestaId(int id) {
    _respuestaId = id;
}

void RespuestaPedido::setUsuarioId(int id) {
    _usuarioId = id;
}

void RespuestaPedido::setPedidoId(int id) {
    _pedidoId = id;
}

void RespuestaPedido::setAceptado(bool aceptado) {
    _aceptado = aceptado;
}

void RespuestaPedido::setFechaDeRespuesta( Fecha& fecha) {
    _fechaDeRespuesta = fecha;  // Asignas el objeto Fecha
}

void RespuestaPedido::setComentarios( char* comentarios) {
    strcpy(_comentarios, comentarios);
}

void RespuestaPedido::setActivo(bool activo) {
    _activo = activo;
}
