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

//menues

void menuPrincipal();
void menuSecundario(Usuario usu);

void menuReclamos();

void menuRegistros();

void menuEstadisticas();
void menuSecEstadisticas();

void menuUsuariosEstadisticas();
void menuSuministrosEstadisticas();
void menuFacturasEstadisticas();
void menuReclamosEstadisticas();
void menuPedidosEstadisticas();

void menuTotales();
void menuListado();


