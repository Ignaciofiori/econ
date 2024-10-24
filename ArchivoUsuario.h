#pragma once
#include <string>
#include "Usuario.h"

class ArchivoUsuario{
    private:
        std::string _nombreArchivo;

    public:

        ArchivoUsuario(std::string nombreArchivo);
        bool GuardarUsuario(Usuario usuario);
        bool GuardarUsuario(Usuario usuario, int posicion);
        int Buscar(int idUsuario);
        Usuario LeerUsuario(int posicion);
        int CantidadUsuarios();
        void LeerUsuario(int cantidadUsuarios, Usuario *vector);
};
