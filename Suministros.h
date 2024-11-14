#pragma once

class Suministro {
private:
    int _suministroId;
    int _usuarioId;
    char _tipoSuministro[50];
    bool _activo;
    char _direccion[50];
    int _codigoPostal;
    int _fechaAlta; // Cambiado a int para almacenar el ID de la clase Fecha
    int _fechaBaja; // Cambiado a int para almacenar el ID de la clase Fecha
    char _contacto[50];
    char _medidor[50];
    float _consumoPorMes;
    float _precioKwh;
    bool _deuda;
    bool _reclamo;
    float _montoDeuda;

public:
    Suministro();

    Suministro(int suministroId, int usuarioId, const char* tipoSuministro, const char* direccion,
               int codigoPostal, int fechaAlta, int fechaBaja, const char* contacto,
               const char* medidor, float consumoPorMes, float precioKwh, bool deuda, bool reclamo,
               float montoDeuda);

    // Getters
    int getSuministroId();
    int getUsuarioId();
    const char* getTipoSuministro();
    bool isActivo();
    const char* getDireccion();
    int getCodigoPostal();
    int getFechaAlta(); // Cambiado a int para representar el ID de la clase Fecha
    int getFechaBaja(); // Cambiado a int para representar el ID de la clase Fecha
    const char* getContacto();
    const char* getMedidor();
    float getConsumoPorMes();
    float getPrecioKwh();
    bool hasDeuda();
    bool hasReclamo();
    float getMontoDeuda();

    // Setters
    void setSuministroId(int id);
    void setUsuarioId(int id);
    void setTipoSuministro(const char* tipo);
    void setActivo(bool estado);
    void setDireccion(const char* dir);
    void setCodigoPostal(int cp);
    void setFechaAlta(int fechaId); // Cambiado a int para representar el ID de la clase Fecha
    void setFechaBaja(int fechaId); // Cambiado a int para representar el ID de la clase Fecha
    void setContacto(const char* cont);
    void setMedidor(const char* med);
    void setConsumoPorMes(float consumo);
    void setPrecioKwh(float precio);
    void setDeuda(bool tieneDeuda);
    void setReclamo(bool tieneReclamo);
    void setMontoDeuda(float monto);
    void mostrarSuministro();
};
