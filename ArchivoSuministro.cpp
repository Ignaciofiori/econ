#include "ArchivoSuministro.h"
#include <cstring>

ArchivoSuministro::ArchivoSuministro(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoSuministro::GuardarSuministro(Suministro suministro) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&suministro, sizeof(Suministro), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoSuministro::EditarSuministro(Suministro suministro, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Suministro) * posicion, SEEK_SET);
    bool ok = fwrite(&suministro, sizeof(Suministro), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoSuministro::BuscarSuministro(int idSuministro) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }
    Suministro suministro;
    int i = 0;
    while (fread(&suministro, sizeof(Suministro), 1, pArchivo)) {
        if (suministro.getSuministroId() == idSuministro) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Suministro ArchivoSuministro::LeerSuministro(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return Suministro();
    }

    Suministro suministro;
    fseek(pArchivo, sizeof(Suministro) * posicion, SEEK_SET);
    fread(&suministro, sizeof(Suministro), 1, pArchivo);
    fclose(pArchivo);

    return suministro;
}

int ArchivoSuministro::CantidadSuministros() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Suministro);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoSuministro::LeerSuministros(int cantidadRegistros, Suministro *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    Suministro suministro;
    while (i < cantidadRegistros && fread(&suministro, sizeof(Suministro), 1, pArchivo)) {
        if (suministro.isActivo()) {  // Solo guarda suministros activos en el vector
            vector[i] = suministro;
            i++;
        }
        // Si no está activo, no se incrementa i y se sobrescribirá en la próxima iteración
    }
    fclose(pArchivo);
}
