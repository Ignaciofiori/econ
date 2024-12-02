#pragma once
#include "Fecha.h"

class Suministro {
private:
    int _suministroId;
    int _usuarioId;
    char _tipoSuministro[50];
    bool _activo;
    char _direccion[50];
    int _codigoPostal;
    Fecha _fechaAlta; // Cambiado a objeto Fecha
    Fecha _fechaBaja; // Cambiado a objeto Fecha
    char _contacto[50];
    char _medidor[50];
    float _consumoPorMes;
    float _precioKwh;
    bool _deuda;
    bool _reclamo;
    float _montoDeuda;

public:
    Suministro();

    Suministro(int suministroId, int usuarioId, char* tipoSuministro, char* direccion,
               int codigoPostal, Fecha fechaAlta, Fecha fechaBaja, char* contacto,
               char* medidor, float consumoPorMes, float precioKwh, bool deuda, bool reclamo,
               float montoDeuda);

    // Getters
    int getSuministroId();
    int getUsuarioId();
    char* getTipoSuministro();
    bool isActivo();
    char* getDireccion();
    int getCodigoPostal();
    Fecha getFechaAlta(); // Cambiado a retornar Fecha
    Fecha getFechaBaja(); // Cambiado a retornar Fecha
    char* getContacto();
    char* getMedidor();
    float getConsumoPorMes();
    float getPrecioKwh();
    bool hasDeuda();
    bool hasReclamo();
    float getMontoDeuda();

    // Setters
    void setSuministroId(int id);
    void setUsuarioId(int id);
    void setTipoSuministro(char* tipo);
    void setActivo(bool estado);
    void setDireccion(char* dir);
    void setCodigoPostal(int cp);
    void setFechaAlta(Fecha fecha); // Cambiado a recibir Fecha
    void setFechaBaja(Fecha fecha); // Cambiado a recibir Fecha
    void setContacto(char* cont);
    void setMedidor(char* med);
    void setConsumoPorMes(float consumo);
    void setPrecioKwh(float precio);
    void setDeuda(bool tieneDeuda);
    void setReclamo(bool tieneReclamo);
    void setMontoDeuda(float monto);
    void mostrarSuministro();
};
