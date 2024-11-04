#include "ArchivoAcumuladorId.h"
#include <cstring>

ArchivoAcumuladorId::ArchivoAcumuladorId(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoAcumuladorId::GuardarAcumuladorId(AcumuladorId acumulador) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&acumulador, sizeof(AcumuladorId), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoAcumuladorId::EditarAcumuladorId(AcumuladorId acumulador, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(AcumuladorId) * posicion, SEEK_SET);
    bool ok = fwrite(&acumulador, sizeof(AcumuladorId), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


AcumuladorId ArchivoAcumuladorId::LeerAcumuladorId(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return AcumuladorId();
    }

    AcumuladorId acumulador;
    fseek(pArchivo, sizeof(AcumuladorId) * posicion, SEEK_SET);
    fread(&acumulador, sizeof(AcumuladorId), 1, pArchivo);
    fclose(pArchivo);

    return acumulador;
}

int ArchivoAcumuladorId::CantidadAcumuladorId() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(AcumuladorId);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoAcumuladorId::LeerAcumuladorId(int cantidadRegistros, AcumuladorId *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    AcumuladorId acumulador;
    while (i < cantidadRegistros && fread(&acumulador, sizeof(AcumuladorId), 1, pArchivo)) {

            vector[i] = acumulador;
            i++;

    }
    fclose(pArchivo);
}


