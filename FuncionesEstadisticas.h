#pragma once
#include "Usuario.h"
#include "PedidoSuministro.h"
#include "Suministros.h"
#include "Reclamos.h"
#include "ArchivoPedido.h"
#include "ArchivoSuministro.h"
#include "ArchivoUsuario.h"
#include "ArchivoReclamo.h"
void EstadisticaReclamos();
void MenuEstadisticas();
void EstadisticaSuministros();
void EstadisticaPedidos();
void EstadisticaReclamos1();
void MenuEstadisticas1();
void EstadisticaSuministros1();
void EstadisticaPedidos1();
void EstadisticaPedidosGrafico();
void EstadisticaReclamosGrafico();
void imprimirGraficoBarras(int maxPedidos, const char* nombreMax, int minPedidos, const char* nombreMin);
void imprimirGraficoBarras1(int maxSuministros, const char* nombreMax, int minSuministros, const char* nombreMin, bool variosMax, bool variosMin);
void Totales();
int TotalClientes();
int TotalSuministros();
int TotalPedidos();
int TotalReclamos();
float TotalConsumo();
void TotalSuministrosPorTipo();
void TotalSuministrosConsumoPorTipo();
void TotalDeuda();
