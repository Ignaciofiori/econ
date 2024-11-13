#pragma once
#include <string>
#include "RespuestaPedido.h"  // Incluye el archivo de la clase RespuestaPedido

class ArchivoRespuesta {
private:
    std::string _nombreArchivo;

public:
    ArchivoRespuesta(std::string nombreArchivo);
    bool GuardarRespuesta(RespuestaPedido respuesta);
    bool EditarRespuesta(RespuestaPedido respuesta, int posicion);
    int BuscarRespuesta(int idRespuesta);
    RespuestaPedido LeerRespuesta(int posicion);
    int CantidadRespuestas();
    void LeerRespuestas(int cantidadRespuestas, RespuestaPedido *vector);
};
