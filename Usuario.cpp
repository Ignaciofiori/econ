#include "Usuario.h"

// Constructor por defecto
Usuario::Usuario(){}

 Usuario::Usuario(int id, std::string nombre, std::string apellido, std::string email,
                 std::string contrasena, std::string contacto, std::string fechaNacimiento, bool admin) {
    _id = id;
    _nombre = nombre;
    _apellido = apellido;
    _email = email;
    _contrasena = contrasena;
    _contacto = contacto;
    _fechaNacimiento = fechaNacimiento;
    _admin = admin;
}

// Getters
int Usuario::getId()  {
    return _id;
}

std::string Usuario::getNombre()  {
    return _nombre;
}

std::string Usuario::getApellido()  {
    return _apellido;
}

std::string Usuario::getEmail()  {
    return _email;
}

std::string Usuario::getContrasena()  {
    return _contrasena;
}

std::string Usuario::getContacto()  {
    return _contacto;
}

std::string Usuario::getFechaNacimiento()  {
    return _fechaNacimiento;
}

bool Usuario::isAdmin()  {
    return _admin;
}

// Setters
void Usuario::setId(int id) {
    _id = id;
}

void Usuario::setNombre( std::string nombre) {
    _nombre = nombre;
}

void Usuario::setApellido( std::string apellido) {
    _apellido = apellido;
}

void Usuario::setEmail( std::string email) {
    _email = email;
}

void Usuario::setContrasena( std::string contrasena) {
    _contrasena = contrasena;
}

void Usuario::setContacto( std::string contacto) {
    _contacto = contacto;
}

void Usuario::setFechaNacimiento( std::string fechaNacimiento) {
    _fechaNacimiento = fechaNacimiento;
}

void Usuario::setAdmin(bool admin) {
    _admin = admin;
}
