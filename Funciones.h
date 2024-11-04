#pragma once
#include "Usuario.h"
#include "Suministros.h"
#include "ArchivoUsuario.h"
#include "ArchivoSuministro.h"
#include "Fecha.h"
#include "ArchivoFecha.h"
#include "ArchivoAcumulador.h"
#include "AcumuladorId.h"
void mostrarUsuarios(Usuario* vectorUsuarios, int cantidadUsuarios);
void mostrarUsuarios(Suministro* vectorSuministros, int cantidadSuministros);
void bannerBienvenida();
void menuPrincipal();
Usuario registrarse();
bool confirmarContrasena();
int leerEntero();
void menuSecundario(Usuario usu);
Usuario login();
Usuario busquedaUsuarioPorEmail(const char *email);
void cargarFecha(Fecha &fecha );
void mostrarFechas(Fecha *vectorFechas, int cantidadFechas) ;
