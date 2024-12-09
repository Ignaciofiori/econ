#pragma once
#include "RespuestaPedido.h"
#include "Usuario.h"
#include "Suministros.h"
#include "Reclamos.h"
#include "AcumuladorId.h"
#include "PedidoSuministro.h"
#include "ArchivoUsuario.h"
#include "ArchivoSuministro.h"
#include "ArchivoAcumulador.h"
#include "ArchivoReclamo.h"
#include "ArchivoPedido.h"
#include "ArchivoRespuestas.h"

void mostrarRespuestasPedido(RespuestaPedido* respuestas, int cantidad);
void mostrarUsuarios(Usuario* vectorUsuarios, int cantidadUsuarios);
void mostrarReclamos(Reclamo* reclamos, int cantidad);
void mostrarSuministros(Suministro *vectorSuministro, int cantidad);
void mostrarPedidos(PedidoSuministro *vectorPedidos, int cantidad);
void mostrarReclamosCliente(int idUsuario);
int mostrarUsuariosAdmin();
void seleccionarUsuarioAdmin(Reclamo& reclamo);
int listarReclamosEstadoDerivados(Usuario usu);
