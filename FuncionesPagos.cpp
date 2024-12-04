#include "FuncionesPagos.h"
#include "Funciones.h"
#include "ArchivoFacturas.h"
#include "Factura.h"
#include "Periodo.h"
#include "ArchivoAcumulador.h"
#include "AcumuladorId.h"


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
        //codigo para calcular precio del mont

        char medidor[50];
        char tipoSuministro[50];
        strcpy(tipoSuministro,suministro.getTipoSuministro());
        strcpy(medidor,suministro.getMedidor());

         float precioKwh = determinarPrecioKwh(medidor);
         float cantKwh = determinarConsumoPorMes(tipoSuministro);

        float montoFactura = precioKwh * cantKwh;
        float anteriorMonto = suministro.getMontoDeuda();
            // Crear la nueva factura
          Factura facturaNueva(acum.getIdFacturas(),suministro.getUsuarioId(),suministro.getSuministroId(),montoFactura,periodoFactura,fechaActual,"Factura Faltante de Pago",false);
            //Guardamos la Factura
          archivoFacturas.GuardarFactura(facturaNueva);
                //seteamos ids de Factuas
          int nuevoIdFacturas = acum.getIdFacturas()+1;
          acum.setIdFacturas(nuevoIdFacturas);
          archivoId.EditarAcumuladorId(acum,0);
            //Marcamos Suministro con Deuda
          suministro.setDeuda(true);
          suministro.setMontoDeuda(montoFactura+anteriorMonto);
          //Guardamos el suministro
          archivoSuministros.EditarSuministro(suministro,posSuministro);

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




int calcularMesesTranscurridos( Fecha fechaAlta,  Fecha fechaActual) {
    int aniosDiferencia = fechaActual.getAnio() - fechaAlta.getAnio();
    int mesesDiferencia = fechaActual.getMes() - fechaAlta.getMes();

    return (aniosDiferencia * 12) + mesesDiferencia;
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


int mostrarFacturasPagadasPorUsuario(Usuario usu){
    ArchivoFactura archivoFactura("facturas.dat");
    int cantFacturas = archivoFactura.CantidadFacturas();
    Factura *vectorFacturas = new Factura[cantFacturas];
    archivoFactura.LeerFacturas(cantFacturas,vectorFacturas);

    int contador = 0;
    for(int x =0; x<cantFacturas; x++){
        if(vectorFacturas[x].getIdUsuario() == usu.getId() && vectorFacturas[x].isPagada()){
            contador++;
        }
    }

       for(int i =0; i<cantFacturas; i++){
        if(vectorFacturas[i].getIdUsuario() == usu.getId() && vectorFacturas[i].isPagada()){
            vectorFacturas[i].mostrarFactura();
        }
    }



delete []vectorFacturas;
return contador;
}

int mostrarFacturasDeudaUsuario(Usuario usu) {
 ArchivoFactura archivoFactura("facturas.dat");
    int cantFacturas = archivoFactura.CantidadFacturas();
    Factura *vectorFacturas = new Factura[cantFacturas];
    archivoFactura.LeerFacturas(cantFacturas,vectorFacturas);

    int contador = 0;
    for(int x =0; x<cantFacturas; x++){
        if(vectorFacturas[x].getIdUsuario() == usu.getId() && vectorFacturas[x].isPagada() == false){
            contador++;
        }
    }

       for(int i =0; i<cantFacturas; i++){
        if(vectorFacturas[i].getIdUsuario() == usu.getId() && vectorFacturas[i].isPagada()== false){
            vectorFacturas[i].mostrarFactura();
        }
    }



delete []vectorFacturas;
return contador;
}

Factura seleccionarFactura(Usuario usu){
    ArchivoFactura archivoFactura("facturas.dat");
    int cantidadFac = archivoFactura.CantidadFacturas();
    Factura *vectorFacturas = new Factura[cantidadFac];
    archivoFactura.LeerFacturas(cantidadFac,vectorFacturas);

    int idFactura = 0;
    Factura factura;
    std::cout << "Ingrese el ID de la Factura que desea Pagar: \n";
    idFactura = leerEntero();
    std::cin.ignore();

    for(int i = 0; i < cantidadFac ; i++){
        if(vectorFacturas[i].getIdUsuario()== usu.getId()&& idFactura == vectorFacturas[i].getIdFactura() && vectorFacturas[i].isPagada()== false ){

            factura = vectorFacturas[i];
        }
    }


    delete []vectorFacturas;
    return factura;

}

void pagarFactura(Factura factura) {
    ArchivoFactura archivoFacturas("facturas.dat");
    ArchivoSuministro archivoSuministros("suministros.dat");
    int posFactura = archivoFacturas.BuscarFactura(factura.getIdFactura());
    int posSuministro = archivoSuministros.BuscarSuministro(factura.getIdSuministro());
    Suministro suministroFactura = archivoSuministros.LeerSuministro(posSuministro);
    float montoDeuda;
    char metodoPago[50];
    int opcion;

    // Solicitar el método de pago
    while (true) {
        std::cout << "Debes abonar: " << factura.getMonto() << "$." << std::endl;
        std::cout << "Selecciona un metodo de pago:" << std::endl;
        std::cout << "1. Tarjeta de credito/debito" << std::endl;
        std::cout << "2. Transferencia bancaria" << std::endl;
        std::cout << "3. Paypal" << std::endl;
        std::cout << "Elige una opcion: ";
        opcion = leerEntero();

        switch (opcion) {
            case 1:
                std::strcpy(metodoPago, "Tarjeta de credito/debito");
                break;
            case 2:
                std::strcpy(metodoPago, "Transferencia bancaria");
                break;
            case 3:
                std::strcpy(metodoPago, "Paypal");
                break;
            default:
                std::cout << "Opcion no valida. Por favor, selecciona una opcion valida." << std::endl;
                continue; // Repetir el bucle hasta que se seleccione una opción válida
        }
        break; // Salir del bucle una vez seleccionado un método de pago válido
    }

    // Confirmación del pago
    while (true) {
        system("cls");
        std::cout << "Seleccionaste el siguiente metodo de pago --> " << metodoPago << std::endl;
        std::cout << "Suministro Relacionado a Factura:" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        suministroFactura.mostrarSuministro(); // Implementa este método
        std::cout << "---------------------------------" << std::endl << std::endl;
        std::cout << "Deseas realizar esta transaccion de pago? (0 - NO, 1 - SI): ";
        int pagar = leerEntero();
        std::cin.ignore();

        switch (pagar) {
            case 0:
                system("cls");
                std::cout << "Has seleccionado NO realizar la transaccion." << std::endl;
                return; // Finalizar la función
            case 1:
                system("cls");

                 montoDeuda = suministroFactura.getMontoDeuda();
                suministroFactura.setMontoDeuda(montoDeuda - factura.getMonto());
                if(suministroFactura.getMontoDeuda()== 0){
                    suministroFactura.setDeuda(false);
                }

                factura.setMetodoPago(metodoPago);
                factura.setIsPagada(true);

                archivoFacturas.EditarFactura(factura,posFactura);
                archivoSuministros.EditarSuministro(suministroFactura,posSuministro);
                system("cls");
                std::cout << "Factura Pagada Exitosamente :)" << std::endl;
                return; // Finalizar la función
            default:
                std::cout << "Opcion no valida. Por favor, selecciona 0 (NO) o 1 (SI)." << std::endl;
                system("pause");
        }
    }
}
