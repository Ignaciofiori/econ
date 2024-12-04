#include "ArchivoPreciosMedidores.h"
#include <cstring>

ArchivoPreciosMed::ArchivoPreciosMed(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoPreciosMed::GuardarPreciosMed(PreciosMedidores preciosMed) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&preciosMed, sizeof(PreciosMedidores), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoPreciosMed::EditarPreciosMed(PreciosMedidores preciosMed, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(PreciosMedidores) * posicion, SEEK_SET);
    bool ok = fwrite(&preciosMed, sizeof(PreciosMedidores), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoPreciosMed::BuscarPreciosMed(int idMedidor) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }
    PreciosMedidores preciosMed;
    int i = 0;
    while (fread(&preciosMed, sizeof(PreciosMedidores), 1, pArchivo)) {
        // Si la clase `PreciosMedidores` tiene un identificador único, úsalo aquí
        // Ejemplo: if (preciosMed.getIdMedidor() == idMedidor) {
        // fclose(pArchivo);
        // return i;
        // }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

PreciosMedidores ArchivoPreciosMed::LeerPreciosMed(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return PreciosMedidores();
    }

    PreciosMedidores preciosMed;
    fseek(pArchivo, sizeof(PreciosMedidores) * posicion, SEEK_SET);
    fread(&preciosMed, sizeof(PreciosMedidores), 1, pArchivo);
    fclose(pArchivo);

    return preciosMed;
}

int ArchivoPreciosMed::CantidadPreciosMed() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(PreciosMedidores);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoPreciosMed::LeerPreciosMed(int cantidadRegistros, PreciosMedidores* vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    PreciosMedidores preciosMed;
    while (i < cantidadRegistros && fread(&preciosMed, sizeof(PreciosMedidores), 1, pArchivo)) {
        // Si la clase `PreciosMedidores` tiene un método para verificar validez, úsalo aquí
        // Ejemplo: if (preciosMed.isValido()) {
        vector[i] = preciosMed;
        i++;
        // }
    }
    fclose(pArchivo);
}
