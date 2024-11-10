#pragma once

#include "ArchivoUsuario.h"
#include "ArchivoSuministro.h"
#include "ArchivoFecha.h"
#include "ArchivoAcumulador.h"
#include "ArchivoReclamo.h"
#include "ArchivoPedido.h"

void mostrarPedidos(PedidoSuministro *vectorPedidos, int cantidad);
void listaPedidos();
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
Usuario busquedaUsuarioPorEmail(const char *email);
void cargarFecha(Fecha &fecha );
PedidoSuministro cargarPedidoSuministro(int idUsuario);
void seleccionarTipoSuministro(char* tipoSuministro);
