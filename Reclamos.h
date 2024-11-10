#pragma once

class Reclamo {

private:
    int _reclamoId;
    int _usuarioId;
    int _suministroId;
    char _descripcion[150];
    int _fechaReclamo;
    char _estado[50];
    char _tipoDeReclamo[50];
    int _responsableDeAtencion;
    char _respuesta[50];
    char _prioridad[50];
    bool _activo;

public:
    Reclamo();
    Reclamo(int reclamoId,int usuarioId,int suministroId, const char* descripcion,
            int fechaDeReclamo, const char* estado, const char* tipoDeReclamo,int responsableDeAtencion,
            const char* respuesta, const char* prioridad);

// Getters
    int getReclamoId() ;
    int getUsuarioId() ;
    int getSuministroId() ;
    const char* getDescripcion() ;
    int getFechaReclamo() ;
    const char* getEstado() ;
    const char* getTipoDeReclamo() ;
    int getResponsableDeAtencion() ;
    const char* getRespuesta() ;
    const char* getPrioridad() ;
    bool isActivo();
    // Setters
    void setReclamoId(int id);
    void setUsuarioId(int id);
    void setSuministroId(int id);
    void setDescripcion(const char* descripcion);
    void setFechaReclamo(int fecha);
    void setEstado(const char* estado);
    void setTipoDeReclamo(const char* tipo);
    void setResponsableDeAtencion(int responsable);
    void setRespuesta(const char* respuesta);
    void setPrioridad(const char* prioridad);
    void setActivo(bool activo);

};
