#pragma once
#include "funcionesMostrar.h"
#include "ArchivoUsuario.h"
#include "ArchivoSuministro.h"
#include "ArchivoAcumulador.h"
#include "ArchivoReclamo.h"
#include "ArchivoPedido.h"
#include "ArchivoRespuestas.h"

//banner
void bannerBienvenida();

//registro y login

Usuario registrarse();
Usuario login();
Usuario nuevoAdmin();


//menues

void menuPrincipal();
void menuSecundario(Usuario usu);

void MenuEstadisticas();
void MenuEstadisticas1();

void MenuUsuariosEstadisticas();


//chequeador
bool confirmarContrasena();
bool esFechaPasada( Fecha& fecha);
int leerEntero();

//listados

int listarReclamosEstado(bool estado);
int listaPedidos();

void listadoUsuarios();

void listadoSuministros();

void listadoFacturas();

void listadoPedidos();

void listadoReclamos();


//estadisticas
void EstadisticaUsuarios();
void EstadisticaDeuda();
void EstadisticaFacturas();

void EstadisticaReclamos();
void EstadisticaSuministros();
void EstadisticaPedidos();
void EstadisticaReclamos1();

void EstadisticaSuministros1();
void EstadisticaPedidos1();
void EstadisticaPedidosGrafico();
void EstadisticaReclamosGrafico();
void imprimirGraficoBarras(int maxPedidos, const char* nombreMax, int minPedidos, const char* nombreMin);
void imprimirGraficoBarras1(int maxSuministros, const char* nombreMax, int minSuministros, const char* nombreMin, bool variosMax, bool variosMin);

//totales
void Totales();
int TotalClientes();
int TotalSuministros();
int TotalPedidos();
int TotalReclamos();
float TotalConsumo();
void TotalSuministrosPorTipo();
void TotalSuministrosConsumoPorTipo();
void TotalDeuda();

//contador

int contarPedidosActivos(PedidoSuministro* pedidos, int cantidad);

//cargas

void cargarFecha(Fecha &fecha );
PedidoSuministro cargarPedidoSuministro(int idUsuario);
Reclamo cargarReclamo(Usuario &usu);

//creador

void creacionSuministro(PedidoSuministro pedido);

//buscador

Usuario busquedaUsuarioPorEmail(char *email);
Suministro buscarSuministroPorIdDeuda(int idSum,Usuario &usu);
Reclamo buscarReclamoPorId(int id);
PedidoSuministro buscarPedidoPorId(int id);
Suministro buscarSuministroPorId(int id,Usuario &usu);
Reclamo buscarReclamoPorId(int id,bool realizado);


//determinar

float determinarConsumoPorMes( char* tipoSuministro);
float determinarPrecioKwh( char* tipoMedidor);

//mostrar

int mostrarSuministrosAsociados(Usuario &usu);
void mostrarRespuestas(Usuario &usu);
int mostrarSuministrosDeuda(Usuario &usu);

void usuariosConDeudas(ArchivoSuministro &archivoSumi, ArchivoUsuario &archivoUsu);

//acciones
void accionesReclamos(Reclamo &reclamo, Usuario &usuario,Usuario& usuAdmin);

//seleccion
void seleccionarTipoSuministro(char* tipoSuministro);
void seleccionarTipoReclamo(char* tipoReclamo);
void seleccionarNivelPrioridad(char* nivelPrioridad);
Reclamo seleccionarReclamo();
Reclamo seleccionarReclamo(bool realizado);
Suministro seleccionarSuministroDeuda(Usuario &usu);
PedidoSuministro seleccionarPedido();


