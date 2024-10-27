#pragma once
#include <string>

class Usuario {
private:
   int _id ;
   char _nombre[50];
   char _apellido[50];
   int  _dni;
   char _email[50];
   char _contrasena[50];
   char _contacto[50];
   char _fechaNacimiento[50];
   bool _admin;
   bool _activo;

public:
    Usuario();
    Usuario(int id,   const char* nombre, const char* apellido,int dni ,const char* email,
             const char* contrasena,   const char* contacto,   const char* fechaNacimiento, bool admin);
   // Getters
    int getId() ;
    const char* getNombre() ;
    const char* getApellido() ;
    int getDni();
    const char* getEmail() ;
    const char* getContrasena() ;
    const char* getContacto() ;
    const char* getFechaNacimiento() ;
    bool isAdmin();
    bool isActivo();

   // Setters
   void setId(int id);
   void setNombre(  const char* nombre);
   void setApellido(  const char* apellido);
   void setDni(int dni);
   void setEmail(  const char* email);
   void setContrasena(  const char* contrasena);
   void setContacto(  const char* contacto);
   void setFechaNacimiento(  const char* fechaNacimiento);
   void setAdmin(bool admin);
   void setActivo(bool activo);

   void mostrarUsuario();
};
