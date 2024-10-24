#include "Usuario.h"
#include <cstring>
// Constructor por defecto
Usuario::Usuario(){}

 Usuario::Usuario(int id,  const char* nombre,  const char* apellido,  const char* email,
                  const char* contrasena,  const char* contacto,  const char* fechaNacimiento, bool admin) {
    _id = id;
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_email, email);
    strcpy(_contrasena, contrasena);
    strcpy(_contacto, contacto);
    strcpy(_fechaNacimiento, fechaNacimiento);
    _admin = admin;
}

// Getters
int Usuario::getId()  {
    return _id;
}

const char* Usuario::getNombre()  {
    return _nombre;
}

const char* Usuario::getApellido()  {
    return _apellido;
}

const char* Usuario::getEmail()  {
    return _email;
}

const char* Usuario::getContrasena()  {
    return _contrasena;
}

const char* Usuario::getContacto()  {
    return _contacto;
}

const char* Usuario::getFechaNacimiento()  {
    return _fechaNacimiento;
}

bool Usuario::isAdmin()  {
    return _admin;
}

// Setters
void Usuario::setId(int id) {
    _id = id;
}

void Usuario::setNombre(const char* nombre) {
    strcpy(_nombre, nombre);
}

void Usuario::setApellido(const char* apellido) {
    strcpy(_apellido, apellido);
}

void Usuario::setEmail(const char* email) {
    strcpy(_email, email);
}

void Usuario::setContrasena(const char* contrasena) {
    strcpy(_contrasena, contrasena);
}

void Usuario::setContacto(const char* contacto) {
    strcpy(_contacto, contacto);
}

void Usuario::setFechaNacimiento(const char* fechaNacimiento) {
    strcpy(_fechaNacimiento, fechaNacimiento);
}

void Usuario::setAdmin(bool admin) {
    _admin = admin;
}
