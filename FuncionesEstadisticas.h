#pragma once
#include "Usuario.h"
#include "Factura.h"
#include "ArchivoFacturas.h"
#include "ArchivoUsuario.h"


void usuariosConMasDeudas(Usuario* vectorUsuarioFinal, float* vectorMontosFinal);
void recaudacionSuministros();
void recaudacionMetodoPago();
void analisisReclamosPorTipo();
void consumoPorTipoSuministro();
