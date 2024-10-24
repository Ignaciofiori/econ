#pragma once
#include <string>

class Usuario {
private:
   int _id;
   std::string _nombre;
   std::string _apellido;
   std::string _email;
   std::string _contrasena;
   std::string _contacto;
   std::string _fechaNacimiento;
   bool _admin;

public:
    Usuario();
    Usuario(int id,  std::string nombre,  std::string apellido,  std::string email,
            std::string contrasena,  std::string contacto,  std::string fechaNacimiento, bool admin);
   // Getters
   int getId() ;
   std::string getNombre() ;
   std::string getApellido() ;
   std::string getEmail() ;
   std::string getContrasena() ;
   std::string getContacto() ;
   std::string getFechaNacimiento() ;
   bool isAdmin() ;

   // Setters
   void setId(int id);
   void setNombre( std::string nombre);
   void setApellido( std::string apellido);
   void setEmail( std::string email);
   void setContrasena( std::string contrasena);
   void setContacto( std::string contacto);
   void setFechaNacimiento( std::string fechaNacimiento);
   void setAdmin(bool admin);
};
