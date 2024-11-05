#pragma once
#include "PedidoSuministro.h"
#include <string>

class ArchivoPedido {
private:
    std::string _nombreArchivo;

public:
    ArchivoPedido(std::string nombreArchivo);
    bool GuardarPedido(PedidoSuministro pedido);
    bool EditarPedido(PedidoSuministro pedido, int posicion);
    int BuscarPedido(int idPedido);
    PedidoSuministro LeerPedido(int posicion);
    int CantidadPedidos();
    void LeerPedidos(int cantidadPedidos, PedidoSuministro *vector);
};
