#pragma once
#include "Usuario.h"
#include "Factura.h"
#include "ArchivoFacturas.h"
#include "ArchivoUsuario.h"

void MenuUsuariosEstadisticas();
void MenuSuministrosEstadisticas();
void MenuFacturasEstadisticas();
void MenuTotalesEstadisticas();
void usuariosConMasDeudas(Usuario* vectorUsuarioFinal, float* vectorMontosFinal);
