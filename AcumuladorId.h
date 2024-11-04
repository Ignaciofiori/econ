#pragma once


class AcumuladorId {
private:
    int _idSuministro; // Acumulador para el ID de suministros
    int _idUsuarios;   // Acumulador para el ID de usuarios
    int _idReclamos;   // Acumulador para el ID de reclamos
    int _idFechas;
public:
    // Constructor por defecto
    AcumuladorId();

    // Getters
    int getIdSuministro();
    int getIdUsuarios();
    int getIdReclamos();
    int getIdFechas();

    // Setters
    void setIdSuministros(int id);
    void setIdUsuarios(int id);
    void setIdReclamos(int id);
    void setIdFechas(int id);
};