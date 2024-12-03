#include "FuncionesPagos.h"
#include "Funciones.h"
#include "ArchivoFacturas.h"
#include "Factura.h"
#include "Periodo.h"
#include "ArchivoAcumulador.h"
#include "AcumuladorId.h"

int calcularMesesTranscurridos( Fecha fechaAlta,  Fecha fechaActual) {
    int aniosDiferencia = fechaActual.getAnio() - fechaAlta.getAnio();
    int mesesDiferencia = fechaActual.getMes() - fechaAlta.getMes();

    return (aniosDiferencia * 12) + mesesDiferencia;
}

float calcularDeuda(Suministro &suministro) {
    //consigo posicion del suministro en el archivo
    ArchivoSuministro archivoS("suministros.dat");
    int posSuministro = archivoS.BuscarSuministro(suministro.getSuministroId());

    //seteo fechaActual
    Fecha fechaActual;
    fechaActual.FechaActual();

    //



    int cantidadMesesAPagar = calcularMesesTranscurridos(suministro.getFechaAlta(), fechaActual);

    float montoDeuda = cantidadMesesAPagar * (suministro.getConsumoPorMes() * suministro.getPrecioKwh());

    if (montoDeuda > 0) {
        suministro.setMontoDeuda(montoDeuda);
        suministro.setDeuda(true);
        archivoS.EditarSuministro(suministro, posSuministro);
    } else {
        suministro.setMontoDeuda(0);
        suministro.setDeuda(false);
        archivoS.EditarSuministro(suministro, posSuministro);  // Actualizar registro sin deuda
    }

    return montoDeuda;
}

void generarFacturasPendientes(Suministro& suministro) {
    ArchivoSuministro archivoSuministros("suministros.dat");
    int posSuministro = archivoSuministros.BuscarSuministro(suministro.getSuministroId());

    ArchivoFactura archivoFacturas("facturas.dat");
    int cantidadFacturas = archivoFacturas.CantidadFacturas();

    ArchivoAcumuladorId archivoId("acumulador.dat");
    AcumuladorId acum = archivoId.LeerAcumuladorId(0);

    Factura *vectorFacturas = new Factura[cantidadFacturas];

    archivoFacturas.LeerFacturas(cantidadFacturas,vectorFacturas);

    Fecha fechaAlta = suministro.getFechaAlta();
    Fecha fechaActual;
    fechaActual.FechaActual();

    int mesesPendientes = calcularMesesTranscurridos(fechaAlta,fechaActual);

    Periodo periodoFactura;
    periodoFactura.setAnio(fechaAlta.getAnio());
    periodoFactura.setMes(fechaAlta.getMes());

   for (int i = 0; i < mesesPendientes; ++i) {

        sumarMeses(periodoFactura,i); // Obtener Fecha de Periodo


        // Validar si ya existe una factura para este suministro y periodo
        bool existeFactura = false;
        for (int x = 0; x < cantidadFacturas ; x++) {
            if (vectorFacturas[x].getIdSuministro() == suministro.getSuministroId() && sonPeriodosIguales(periodoFactura,vectorFacturas[x].getPeriodo()) ){
                    existeFactura = true;
            }
        }

        if (!existeFactura) {
            // Crear la nueva factura

          Factura facturaNueva(acum.getIdFacturas(),suministro.getUsuarioId(),suministro.getSuministroId(),1420,periodoFactura,fechaActual,"",false);

          archivoFacturas.GuardarFactura(facturaNueva);

          int nuevoIdFacturas = acum.getIdFacturas()+1;
          acum.setIdFacturas(nuevoIdFacturas);
          archivoId.EditarAcumuladorId(acum,0);

          suministro.setDeuda(true);
          suministro.setMontoDeuda(1420);

        }
}

    delete []vectorFacturas;
}

void controlDeudaSuministros(){

    ArchivoSuministro archivo("suministros.dat");
    int cantSums = archivo.CantidadSuministros();
    Suministro *vectorSuministros;
    vectorSuministros = new Suministro[cantSums];
    archivo.LeerSuministros(cantSums,vectorSuministros);

    for(int i=0; i<cantSums;i++){
        if(vectorSuministros[i].isActivo()){

         generarFacturasPendientes(vectorSuministros[i]);

        }
    }
        delete []vectorSuministros;

}

bool sonPeriodosIguales( Periodo periodo1,  Periodo periodo2) {
    return (periodo1.getAnio() == periodo2.getAnio() && periodo1.getMes() == periodo2.getMes());
}

void sumarMeses(Periodo& periodo, int cantMeses){

    int mes  = periodo.getMes();
    int anio = periodo.getAnio();

    int nuevoMes = mes + cantMeses;

    if(nuevoMes > 12){
        nuevoMes = nuevoMes - 12;
        anio = anio + 1;
    }

    periodo.setAnio(anio);
    periodo.setMes(nuevoMes);

}

void mostrarFacturas(Factura* facturas, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Factura #" << (i + 1) << ":\n";
        std::cout << "ID de Factura: " << facturas[i].getIdFactura() << "\n";
        std::cout << "ID de Usuario: " << facturas[i].getIdUsuario() << "\n";
        std::cout << "ID de Suministro: " << facturas[i].getIdSuministro() << "\n";
        std::cout << "Periodo: " << facturas[i].getPeriodo().toString() << "\n"; // Asumo que `Periodo` tiene `toString()`.
        std::cout << "Fecha de Emisión: " << facturas[i].getFecha().toString() << "\n"; // Asumo que `Fecha` tiene `toString()`.
        std::cout << "Método de Pago: " << facturas[i].getMetodoPago() << "\n";
        std::cout << "Pagada: " << (facturas[i].isPagada() ? "Sí" : "No") << "\n";
        std::cout << "-----------------------------\n";
    }
}

void mostrarFacturasPorUsuario(Usuario usuario) {
    ArchivoFactura archivoFactura("facturas.dat");
    int cantFacturas = archivoFactura.CantidadFacturas();
    Factura *vectorFacturas = new Factura[cantFacturas];
    archivoFactura.LeerFacturas(cantFacturas,vectorFacturas);
    int idUsuario = usuario.getId(); // Asumo que el Usuario tiene un método para obtener su ID.
    int contador = 0;
    for(int x= 0; x< cantFacturas;x++){
        if(vectorFacturas[x].getIdUsuario() == idUsuario && vectorFacturas[x].isPagada() == false ){
            contador++;
        }

    }
    if(contador == 0){
         std::cout << "No tienes facturas :C #  :\n";

    }else{

    for (int i = 0; i < cantFacturas; ++i) {
        if (vectorFacturas[i].getIdUsuario() == idUsuario && vectorFacturas[i].isPagada() == false ) { // Filtrar facturas por ID de usuario.
            std::cout << "Factura #" << (i + 1) << ":\n";
            std::cout << "ID de Factura: " << vectorFacturas[i].getIdFactura() << "\n";
            std::cout << "ID de Usuario: " << vectorFacturas[i].getIdUsuario() << "\n";
            std::cout << "ID de Suministro: " << vectorFacturas[i].getIdSuministro() << "\n";
            std::cout << "Monto: " << vectorFacturas[i].getMonto() <<"$. \n";
            std::cout << "Periodo: " << vectorFacturas[i].getPeriodo().toString() << "\n"; // Asumo que `Periodo` tiene `toString`.
            std::cout << "Fecha de Emision: " << vectorFacturas[i].getFecha().toString() << "\n"; // Asumo que `Fecha` tiene `toString`.
            std::cout << "Metodo de Pago: " << vectorFacturas[i].getMetodoPago() << "\n";
            std::cout << "Pagada: " << (vectorFacturas[i].isPagada() ? "Sí" : "No") << "\n";
            std::cout << "-----------------------------\n";
        }
    }
    }
    delete []vectorFacturas;

}

