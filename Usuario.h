#pragma once
#include "Fecha.h"
#include <string>

class Usuario {
private:
    int _id;
    char _nombre[50];
    char _apellido[50];
    int _dni;
    char _email[50];
    char _contrasena[50];
    char _contacto[50];
    Fecha _fechaNacimiento; // Cambiado a tipo Fecha
    bool _admin;
    bool _activo;

public:
    Usuario();
    Usuario(int id, char* nombre, char* apellido, int dni, char* email,
            char* contrasena, char* contacto, Fecha fechaNacimiento, bool admin);

    // Getters
    int getId();
    char* getNombre();
    char* getApellido();
    int getDni();
    char* getEmail();
    char* getContrasena();
    char* getContacto();
    Fecha getFechaNacimiento(); // Cambiado para devolver un objeto Fecha
    bool isAdmin();
    bool isActivo();

    // Setters
    void setId(int id);
    void setNombre(char* nombre);
    void setApellido(char* apellido);
    void setDni(int dni);
    void setEmail(char* email);
    void setContrasena(char* contrasena);
    void setContacto(char* contacto);
    void setFechaNacimiento(Fecha fechaNacimiento); // Cambiado para aceptar un objeto Fecha
    void setAdmin(bool admin);
    void setActivo(bool activo);

    void mostrarUsuario();
    void cargarUsuario();
};
