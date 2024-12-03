#pragma once
#include "Fecha.h"
#include "Suministros.h"
#include "Periodo.h"
#include "ArchivoFacturas.h"
#include "Factura.h"
#include "Usuario.h"

int calcularMesesTranscurridos( Fecha fechaAlta,  Fecha fechaActual);
float calcularDeuda(Suministro &suministro);
void controlDeudaSuministros();
void sumarMeses(Periodo& periodo, int cantMeses);
bool sonPeriodosIguales( Periodo periodo1,  Periodo periodo2);
void mostrarFacturas(Factura* facturas, int cantidad);
void mostrarFacturasPorUsuario(Usuario usuario);
