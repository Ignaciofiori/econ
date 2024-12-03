#pragma once
#include "funcionesMostrar.h"
#include "ArchivoUsuario.h"
#include "ArchivoSuministro.h"
#include "ArchivoAcumulador.h"
#include "ArchivoReclamo.h"
#include "ArchivoPedido.h"
#include "ArchivoRespuestas.h"

int contarPedidosActivos(PedidoSuministro* pedidos, int cantidad);
int listaPedidos();
void bannerBienvenida();
void menuPrincipal();
Usuario registrarse();
bool confirmarContrasena();
int leerEntero();
void menuSecundario(Usuario usu);
Usuario login();
Usuario busquedaUsuarioPorEmail(char *email);
void cargarFecha(Fecha &fecha );
PedidoSuministro cargarPedidoSuministro(int idUsuario);
void seleccionarTipoSuministro(char* tipoSuministro);
void creacionSuministro(PedidoSuministro pedido);
PedidoSuministro buscarPedidoPorId(int id);
float determinarConsumoPorMes( char* tipoSuministro);
float determinarPrecioKwh( char* tipoMedidor);
int mostrarSuministrosAsociados(Usuario &usu);
void  mostrarRespuestas(Usuario &usu);
Reclamo cargarReclamo(Usuario &usu);
void seleccionarTipoReclamo(char* tipoReclamo);
void seleccionarNivelPrioridad(char* nivelPrioridad);
Suministro buscarSuministroPorId(int id,Usuario &usu);

int listarReclamosEstado(bool estado);
Reclamo seleccionarReclamo();
Reclamo buscarReclamoPorId(int id);
void accionesReclamos(Reclamo &reclamo);
Reclamo seleccionarReclamo(bool realizado);
Reclamo buscarReclamoPorId(int id,bool realizado);
int mostrarSuministrosDeuda(Usuario &usu);
Suministro seleccionarSuministroDeuda(Usuario &usu);
Suministro buscarSuministroPorIdDeuda(int idSum,Usuario &usu);



//estadisticas
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
