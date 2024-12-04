#pragma once
#include "Fecha.h"
#include "Suministros.h"
#include "Periodo.h"
#include "ArchivoFacturas.h"
#include "Factura.h"
#include "Usuario.h"

int calcularMesesTranscurridos( Fecha fechaAlta,  Fecha fechaActual);
void controlDeudaSuministros();
void sumarMeses(Periodo& periodo, int cantMeses);
bool sonPeriodosIguales( Periodo periodo1,  Periodo periodo2);
int mostrarFacturasDeudaUsuario(Usuario usuario);
int mostrarFacturasPagadasPorUsuario(Usuario usuario);
Factura seleccionarFactura(Usuario usu);
void pagarFactura(Factura factura);
