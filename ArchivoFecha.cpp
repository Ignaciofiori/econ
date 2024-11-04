#include "ArchivoFecha.h"
#include <cstring>

ArchivoFecha::ArchivoFecha(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoFecha::GuardarFecha(Fecha fecha) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&fecha, sizeof(Fecha), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoFecha::EditarFecha(Fecha fecha, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Fecha) * posicion, SEEK_SET);
    bool ok = fwrite(&fecha, sizeof(Fecha), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoFecha::BuscarFecha(int idFecha) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }
    Fecha fecha;
    int i = 0;
    while (fread(&fecha, sizeof(Fecha), 1, pArchivo)) {
        if (fecha.getId() == idFecha) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Fecha ArchivoFecha::LeerFecha(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return Fecha();
    }

    Fecha fecha;
    fseek(pArchivo, sizeof(Fecha) * posicion, SEEK_SET);
    fread(&fecha, sizeof(Fecha), 1, pArchivo);
    fclose(pArchivo);

    return fecha;
}

int ArchivoFecha::CantidadFechas() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Fecha);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoFecha::LeerFechas(int cantidadRegistros, Fecha *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    Fecha fecha;
    while (i < cantidadRegistros && fread(&fecha, sizeof(Fecha), 1, pArchivo)) {

            vector[i] = fecha;
            i++;

    }
    fclose(pArchivo);
}
