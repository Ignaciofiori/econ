#include "ArchivoRespuestas.h"
#include <cstring>

ArchivoRespuesta::ArchivoRespuesta(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoRespuesta::GuardarRespuesta(RespuestaPedido respuesta) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&respuesta, sizeof(RespuestaPedido), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoRespuesta::EditarRespuesta(RespuestaPedido respuesta, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(RespuestaPedido) * posicion, SEEK_SET);
    bool ok = fwrite(&respuesta, sizeof(RespuestaPedido), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoRespuesta::BuscarRespuesta(int idRespuesta) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }
    RespuestaPedido respuesta;
    int i = 0;
    while (fread(&respuesta, sizeof(RespuestaPedido), 1, pArchivo)) {
        if (respuesta.getRespuestaId() == idRespuesta) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

RespuestaPedido ArchivoRespuesta::LeerRespuesta(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return RespuestaPedido();
    }

    RespuestaPedido respuesta;
    fseek(pArchivo, sizeof(RespuestaPedido) * posicion, SEEK_SET);
    fread(&respuesta, sizeof(RespuestaPedido), 1, pArchivo);
    fclose(pArchivo);

    return respuesta;
}

int ArchivoRespuesta::CantidadRespuestas() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(RespuestaPedido);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoRespuesta::LeerRespuestas(int cantidadRespuestas, RespuestaPedido *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    RespuestaPedido respuesta;
    while (i < cantidadRespuestas && fread(&respuesta, sizeof(RespuestaPedido), 1, pArchivo)) {
        if (respuesta.isActivo()) {  // Solo guarda respuestas activas en el vector
            vector[i] = respuesta;
            i++;
        }
    }
    fclose(pArchivo);
}
