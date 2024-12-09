#include "FuncionesEstadisticas.h"
#include "Funciones.h"
#include "ArchivoFacturas.h"
#include "ArchivoUsuario.h"
#include <iostream>
#include <iomanip>


void usuariosConMasDeudas(Usuario* vectorUsuarioFinal, float* vectorMontosFinal){
ArchivoFactura archivoFacturas("facturas.dat");
int cantFacturas = archivoFacturas.CantidadFacturas();
ArchivoUsuario archivoUsus("usuarios.dat");
int cantidadUsuarios = archivoUsus.CantidadUsuarios();
//INT DE USUARIOS ID MAS DEUDA

//Vector de Facturas
Factura *vectorFacturas = new Factura[cantFacturas];
archivoFacturas.LeerFacturas(cantFacturas,vectorFacturas);
//vector Usuarios
Usuario *vectorUsuarios = new Usuario[cantidadUsuarios];
float *vectorMontosDeudas = new float[cantidadUsuarios]();

//llenamos vector de montos
for(int i = 0; i<cantFacturas; i++){
   if(vectorFacturas[i].isPagada()== false){
    int idUsuario =  vectorFacturas[i].getIdUsuario();
    int posUsuario = archivoUsus.BuscarUsuario(idUsuario);

    vectorMontosDeudas[posUsuario] += vectorFacturas[i].getMonto();
   }
}
float montoMaximo1 = -1, montoMaximo2 = -1, montoMaximo3 = -1, montoMaximo4 = -1, montoMaximo5 = -1;
int posMax1 = -1, posMax2 = -1, posMax3 = -1, posMax4 = -1, posMax5 = -1;

for (int j = 0; j < 5; j++) {
    float maxDeuda = -1;  // Valor inicial mas bajo
    int posMax = -1;

    for (int x = 0; x < cantidadUsuarios; x++) {
        if (vectorMontosDeudas[x] > maxDeuda) {
            maxDeuda = vectorMontosDeudas[x];
            posMax = x;
        }
    }

    // Guardar el resultado seg�n la iteraci�n
    if (j == 0) {
        montoMaximo1 = maxDeuda;
        posMax1 = posMax;
    } else if (j == 1) {
        montoMaximo2 = maxDeuda;
        posMax2 = posMax;
    } else if (j == 2) {
        montoMaximo3 = maxDeuda;
        posMax3 = posMax;
    } else if (j == 3) {
        montoMaximo4 = maxDeuda;
        posMax4 = posMax;
    } else if (j == 4) {
        montoMaximo5 = maxDeuda;
        posMax5 = posMax;
    }

    // Marcar el maximo encontrado como procesado
    if (posMax != -1) {
        vectorMontosDeudas[posMax] = -1;  // Valor invaido para evitar que sea considerado de nuevo
    }
}
// Cargar los valores en los vectores de salida
    vectorMontosFinal[0] = montoMaximo1;
    vectorMontosFinal[1] = montoMaximo2;
    vectorMontosFinal[2] = montoMaximo3;
    vectorMontosFinal[3] = montoMaximo4;
    vectorMontosFinal[4] = montoMaximo5;

    // Obtener los usuarios correspondientes a los m�ximos
    Usuario usu1 = archivoUsus.LeerUsuario(posMax1);
    Usuario usu2 = archivoUsus.LeerUsuario(posMax2);
    Usuario usu3 = archivoUsus.LeerUsuario(posMax3);
    Usuario usu4 = archivoUsus.LeerUsuario(posMax4);
    Usuario usu5 = archivoUsus.LeerUsuario(posMax5);

    vectorUsuarioFinal[0] = usu1;
    vectorUsuarioFinal[1] = usu2;
    vectorUsuarioFinal[2] = usu3;
    vectorUsuarioFinal[3] = usu4;
    vectorUsuarioFinal[4] = usu5;

delete []vectorFacturas;
delete []vectorUsuarios;
delete []vectorMontosDeudas;
}

void recaudacionSuministros() {
    float recaudacionIndustrial = 0, recaudacionAgricola = 0, recaudacionResidencial = 0, recaudacionComercial = 0, totalRecaudacion = 0;
    ArchivoFactura archivoFacturas("facturas.dat");
    int cantFacturas = archivoFacturas.CantidadFacturas();
    ArchivoSuministro archivoSums("suministros.dat");
    int cantidadSums = archivoSums.CantidadSuministros();

    Factura *vectorFacturas = new Factura[cantFacturas];
    archivoFacturas.LeerFacturas(cantFacturas, vectorFacturas);

    for (int i = 0; i < cantFacturas; i++) {
        if (vectorFacturas[i].isPagada()) {
            int sumId = vectorFacturas[i].getIdSuministro();
            int posSum = archivoSums.BuscarSuministro(sumId);
            Suministro sum = archivoSums.LeerSuministro(posSum);

            // Variable para almacenar el tipo de suministro
            char tipoSum[50];

            // Copiar el valor de sum.getTipoSuministro() a tipoSum
            strcpy(tipoSum, sum.getTipoSuministro());

            // Comparar el tipo de suministro usando if-else
            if (strcmp(tipoSum, "Comercial") == 0) {
                recaudacionComercial += vectorFacturas[i].getMonto();
            } else if (strcmp(tipoSum, "Industrial") == 0) {
                recaudacionIndustrial += vectorFacturas[i].getMonto();
            } else if (strcmp(tipoSum, "Agricola") == 0) {
                recaudacionAgricola += vectorFacturas[i].getMonto();
            } else if (strcmp(tipoSum, "Residencial") == 0) {
                recaudacionResidencial += vectorFacturas[i].getMonto();
            }
        }
    }
    totalRecaudacion = recaudacionResidencial + recaudacionAgricola + recaudacionComercial + recaudacionIndustrial;

    // Calcular porcentajes
    float porcentajeComercial = (totalRecaudacion > 0) ? (recaudacionComercial / totalRecaudacion) * 100 : 0;
    float porcentajeIndustrial = (totalRecaudacion > 0) ? (recaudacionIndustrial / totalRecaudacion) * 100 : 0;
    float porcentajeAgricola = (totalRecaudacion > 0) ? (recaudacionAgricola / totalRecaudacion) * 100 : 0;
    float porcentajeResidencial = (totalRecaudacion > 0) ? (recaudacionResidencial / totalRecaudacion) * 100 : 0;

    // Mostrar la informacion de manera organizada
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nRecaudacion total: " << totalRecaudacion << "$ \n";
    std::cout << "\nRecaudacion por tipo de suministro:\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Comercial:      $" << recaudacionComercial << " (" << porcentajeComercial << "%)\n";
    std::cout << "Industrial:     $" << recaudacionIndustrial << " (" << porcentajeIndustrial << "%)\n";
    std::cout << "Agricola:       $" << recaudacionAgricola << " (" << porcentajeAgricola << "%)\n";
    std::cout << "Residencial:    $" << recaudacionResidencial << " (" << porcentajeResidencial << "%)\n";
    std::cout << "---------------------------------------\n";

    delete[] vectorFacturas;
}

void recaudacionMetodoPago() {
    float recaudacionTarjeta = 0, recaudacionTransferencia = 0, recaudacionPaypal = 0, totalRecaudacion = 0;
    ArchivoFactura archivoFacturas("facturas.dat");
    int cantFacturas = archivoFacturas.CantidadFacturas();

    Factura *vectorFacturas = new Factura[cantFacturas];
    archivoFacturas.LeerFacturas(cantFacturas, vectorFacturas);

    for (int i = 0; i < cantFacturas; i++) {
        if (vectorFacturas[i].isPagada()) {
            // Obtener el tipo de método de pago
            char metodoPago[50];
            strcpy(metodoPago, vectorFacturas[i].getMetodoPago());

            // Comparar el método de pago y sumar el monto correspondiente
            if (strcmp(metodoPago, "Tarjeta de credito/debito") == 0) {
                recaudacionTarjeta += vectorFacturas[i].getMonto();
            } else if (strcmp(metodoPago, "Transferencia bancaria") == 0) {
                recaudacionTransferencia += vectorFacturas[i].getMonto();
            } else if (strcmp(metodoPago, "Paypal") == 0) {
                recaudacionPaypal += vectorFacturas[i].getMonto();
            }
        }
    }

    totalRecaudacion = recaudacionTarjeta + recaudacionTransferencia + recaudacionPaypal;

    // Calcular porcentajes
    float porcentajeTarjeta = (totalRecaudacion > 0) ? (recaudacionTarjeta / totalRecaudacion) * 100 : 0;
    float porcentajeTransferencia = (totalRecaudacion > 0) ? (recaudacionTransferencia / totalRecaudacion) * 100 : 0;
    float porcentajePaypal = (totalRecaudacion > 0) ? (recaudacionPaypal / totalRecaudacion) * 100 : 0;

    // Mostrar la informacion de manera organizada
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nRecaudacion total: " << totalRecaudacion << "$ \n";
    std::cout << "\nRecaudacion por metodo de pago:\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Tarjeta de credito/debito: $" << recaudacionTarjeta << " (" << porcentajeTarjeta << "%)\n";
    std::cout << "Transferencia bancaria:    $" << recaudacionTransferencia << " (" << porcentajeTransferencia << "%)\n";
    std::cout << "Paypal:                    $" << recaudacionPaypal << " (" << porcentajePaypal << "%)\n";
    std::cout << "---------------------------------------\n";

    delete[] vectorFacturas;
}

