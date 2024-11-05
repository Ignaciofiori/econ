#include "ArchivoPedido.h"
#include <cstring>

ArchivoPedido::ArchivoPedido(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoPedido::GuardarPedido(PedidoSuministro pedido) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&pedido, sizeof(PedidoSuministro), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoPedido::EditarPedido(PedidoSuministro pedido, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(PedidoSuministro) * posicion, SEEK_SET);
    bool ok = fwrite(&pedido, sizeof(PedidoSuministro), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoPedido::BuscarPedido(int idPedido) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }
    PedidoSuministro pedido;
    int i = 0;
    while (fread(&pedido, sizeof(PedidoSuministro), 1, pArchivo)) {
        if (pedido.getPedidoId() == idPedido) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

PedidoSuministro ArchivoPedido::LeerPedido(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return PedidoSuministro();
    }

    PedidoSuministro pedido;
    fseek(pArchivo, sizeof(PedidoSuministro) * posicion, SEEK_SET);
    fread(&pedido, sizeof(PedidoSuministro), 1, pArchivo);
    fclose(pArchivo);

    return pedido;
}

int ArchivoPedido::CantidadPedidos() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(PedidoSuministro);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoPedido::LeerPedidos(int cantidadPedidos, PedidoSuministro *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    PedidoSuministro pedido;
    while (i < cantidadPedidos && fread(&pedido, sizeof(PedidoSuministro), 1, pArchivo)) {
        vector[i] = pedido;
        i++;
    }
    fclose(pArchivo);
}
