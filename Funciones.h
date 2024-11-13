#pragma once
#include "ArchivoUsuario.h"
#include "ArchivoSuministro.h"
#include "ArchivoFecha.h"
#include "ArchivoAcumulador.h"
#include "ArchivoReclamo.h"
#include "ArchivoPedido.h"
#include "ArchivoRespuestas.h"

int contarPedidosActivos(PedidoSuministro* pedidos, int cantidad);
void mostrarSuministros(Suministro *vectorSuministro, int cantidad);
void mostrarPedidos(PedidoSuministro *vectorPedidos, int cantidad);
int listaPedidos();
void mostrarRespuestasPedido(RespuestaPedido* respuestas, int cantidad);
void mostrarUsuarios(Usuario* vectorUsuarios, int cantidadUsuarios);
void mostrarUsuarios(Suministro* vectorSuministros, int cantidadSuministros);
void mostrarFechas(Fecha *vectorFechas, int cantidadFechas) ;
void mostrarReclamos(Reclamo* reclamos, int cantidad);
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
void mostrarSuministrosAsociados(Usuario &usu);
void  mostrarRespuestas(Usuario &usu);
Reclamo cargarReclamo(Usuario &usu);
void seleccionarTipoReclamo(char* tipoReclamo);
void seleccionarNivelPrioridad(char* nivelPrioridad);
Suministro buscarSuministroPorId(int id,Usuario &usu);
