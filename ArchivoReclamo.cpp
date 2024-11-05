#include "ArchivoReclamo.h"
#include <cstring>

ArchivoReclamo::ArchivoReclamo(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoReclamo::GuardarReclamo(Reclamo reclamo) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&reclamo, sizeof(Reclamo), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoReclamo::EditarReclamo(Reclamo reclamo, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Reclamo) * posicion, SEEK_SET);
    bool ok = fwrite(&reclamo, sizeof(Reclamo), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoReclamo::BuscarReclamo(int idReclamo) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }
    Reclamo reclamo;
    int i = 0;
    while (fread(&reclamo, sizeof(Reclamo), 1, pArchivo)) {
        if (reclamo.getReclamoId() == idReclamo) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Reclamo ArchivoReclamo::LeerReclamo(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return Reclamo();
    }

    Reclamo reclamo;
    fseek(pArchivo, sizeof(Reclamo) * posicion, SEEK_SET);
    fread(&reclamo, sizeof(Reclamo), 1, pArchivo);
    fclose(pArchivo);

    return reclamo;
}

int ArchivoReclamo::CantidadReclamos() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Reclamo);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoReclamo::LeerReclamos(int cantidadReclamos, Reclamo *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    Reclamo reclamo;
    while (i < cantidadReclamos && fread(&reclamo, sizeof(Reclamo), 1, pArchivo)) {
        vector[i] = reclamo;
        i++;
    }
    fclose(pArchivo);
}
