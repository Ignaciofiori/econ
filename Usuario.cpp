#include "Usuario.h"
#include <cstring>
#include <iostream>
// Constructor por defecto
Usuario::Usuario() {
    _id = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    _dni = 0;
    strcpy(_email, "");
    strcpy(_contrasena, "");
    strcpy(_contacto, "");
    _fechaNacimiento = 0;
    _admin = false;
    _activo = false;
}
 Usuario::Usuario(int id,  const char* nombre,  const char* apellido,int dni  ,const char* email,
                  const char* contrasena,  const char* contacto,  int fechaNacimiento, bool admin) {
    _id = id;
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    _dni = dni;
    strcpy(_email, email);
    strcpy(_contrasena, contrasena);
    strcpy(_contacto, contacto);
    _fechaNacimiento = fechaNacimiento;
    _admin = admin;
    _activo = true;
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
int Usuario::getDni()  {
    return _dni;
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

int Usuario::getFechaNacimiento()  {
    return _fechaNacimiento;
}

bool Usuario::isAdmin()  {
    return _admin;
}
bool Usuario::isActivo()  {
    return _activo;
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
void Usuario::setDni(int dni) {
    _dni = dni;
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

void Usuario::setFechaNacimiento(int fechaNacimiento) {
    _fechaNacimiento = fechaNacimiento;
}

void Usuario::setAdmin(bool admin) {
    _admin = admin;
}
void Usuario::setActivo(bool activo) {
    _activo = activo;
}

     void Usuario::mostrarUsuario() {
ArchivoFecha archivo("fechas.dat");
int pos = archivo.BuscarFecha(getFechaNacimiento());
Fecha fecha = archivo.LeerFecha(pos);

    std::cout << "===== INFORMACION DEL USUARIO =====\n";
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Apellido: " << getApellido() << std::endl;
    std::cout << "DNI: " << getDni() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Contrasena: " << getContrasena() << std::endl;
    std::cout << "Contacto: " << getContacto() << std::endl;
    std::cout << "Fecha de Nacimiento: " << fecha.toString() << std::endl;
    std::cout << "Administrador: " << (isAdmin() ? "Si" : "No") << std::endl;
    std::cout << "Activo: " << (isActivo() ? "Si" : "No") << std::endl;
    std::cout << "===================================\n";
}
