#pragma once
#include "Fecha.h"
#include "ArchivoUsuario.h"

class Reclamo {

private:
    int _reclamoId;
    int _usuarioId;
    int _suministroId;
    char _descripcion[150];
    Fecha _fechaReclamo; // Cambiado a objeto Fecha
    char _estado[50];
    char _tipoDeReclamo[50];
    int _responsableDeAtencion;
    char _respuesta[50];
    char _prioridad[50];
    bool _activo;

public:
    Reclamo();
    Reclamo(int reclamoId, int usuarioId, int suministroId, char* descripcion,
            Fecha fechaDeReclamo, char* estado, char* tipoDeReclamo, int responsableDeAtencion,
            char* respuesta, char* prioridad);

    // Getters
    int getReclamoId();
    int getUsuarioId();
    int getSuministroId();
    char* getDescripcion();
    Fecha getFechaReclamo(); // Ahora devuelve un objeto Fecha
    char* getEstado();
    char* getTipoDeReclamo();
    int getResponsableDeAtencion();
    char* getRespuesta();
    char* getPrioridad();
    bool isActivo();

    // Setters
    void setReclamoId(int id);
    void setUsuarioId(int id);
    void setSuministroId(int id);
    void setDescripcion(char* descripcion);
    void setFechaReclamo(Fecha fecha); // Ahora recibe un objeto Fecha
    void setEstado(char* estado);
    void setTipoDeReclamo(char* tipo);
    void setResponsableDeAtencion(int responsable);
    void setRespuesta(char* respuesta);
    void setPrioridad(char* prioridad);
    void setActivo(bool activo);

    void mostrarReclamo();
};
