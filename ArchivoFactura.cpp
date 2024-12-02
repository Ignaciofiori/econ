#include "ArchivoFacturas.h"
#include <cstring>

ArchivoFactura::ArchivoFactura(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoFactura::GuardarFactura(Factura factura) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&factura, sizeof(Factura), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoFactura::EditarFactura(Factura factura, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Factura) * posicion, SEEK_SET);
    bool ok = fwrite(&factura, sizeof(Factura), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoFactura::BuscarFactura(int idFactura) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }
    Factura factura;
    int i = 0;
    while (fread(&factura, sizeof(Factura), 1, pArchivo)) {
        if (factura.getIdFactura() == idFactura) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Factura ArchivoFactura::LeerFactura(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return Factura();
    }

    Factura factura;
    fseek(pArchivo, sizeof(Factura) * posicion, SEEK_SET);
    fread(&factura, sizeof(Factura), 1, pArchivo);
    fclose(pArchivo);

    return factura;
}

int ArchivoFactura::CantidadFacturas() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Factura);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoFactura::LeerFacturas(int cantidadFacturas, Factura *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    Factura factura;
    while (i < cantidadFacturas && fread(&factura, sizeof(Factura), 1, pArchivo)) {
        vector[i] = factura;
        i++;
    }
    fclose(pArchivo);
}
