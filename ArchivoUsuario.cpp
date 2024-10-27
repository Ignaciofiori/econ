#include "ArchivoUsuario.h"
#include <cstring>

ArchivoUsuario::ArchivoUsuario(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoUsuario::GuardarUsuario(Usuario usuario){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&usuario, sizeof(Usuario), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoUsuario::EditarUsuario(Usuario usuario, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Usuario) * posicion, SEEK_SET);
    bool ok = fwrite(&usuario, sizeof(Usuario), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoUsuario::BuscarUsuario(int idUsuario){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Usuario usuario;
    int i = 0;
    while(fread(&usuario, sizeof(Usuario), 1, pArchivo)){
        if(usuario.getId() == idUsuario){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Usuario ArchivoUsuario::LeerUsuario(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return Usuario();
    }

    Usuario usuario ;

    fseek(pArchivo, sizeof(Usuario) * posicion, SEEK_SET);
    fread(&usuario, sizeof(Usuario), 1, pArchivo);
    fclose(pArchivo);

    return usuario;
}

int ArchivoUsuario::CantidadUsuarios(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Usuario);
    fclose(pArchivo);
    return cantidadRegistros;
}


void ArchivoUsuario::LeerUsuarios(int cantidadRegistros, Usuario *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    Usuario usuario;
    while (i < cantidadRegistros && fread(&usuario, sizeof(Usuario), 1, pArchivo)) {
        if (usuario.isActivo()) {  // Solo guarda usuarios activos en el vector
            vector[i] = usuario;
            i++;
        }
        // Si no est� activo, no se incrementa la i y se sobrescribir� en la pr�xima iteraci�n
    }
    fclose(pArchivo);
}

