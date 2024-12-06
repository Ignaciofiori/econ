#include "FuncionesPrecios.h"
#include "Funciones.h"



float determinarPrecioKwh(char* tipoMedidor) {
    ArchivoPreciosMed archivoPrecios("precios-medidores.dat");
    PreciosMedidores precios = archivoPrecios.LeerPreciosMed(0);


    if (strcmp(tipoMedidor, "Medidor Electromecanico") == 0) {
        return precios.getPrecioElectromecanico();
    } else if (strcmp(tipoMedidor, "Medidor Digital") == 0) {
        return precios.getPrecioDigital();
    } else if (strcmp(tipoMedidor, "Medidor Inteligente") == 0) {
        return precios.getPrecioInteligente();
    } else if (strcmp(tipoMedidor, "Medidor Bidireccional") == 0) {
        return precios.getPrecioBidireccional();
    } else if (strcmp(tipoMedidor, "Medidor Trifasico") == 0) {
        return precios.getPrecioTrifasico();
    } else if (strcmp(tipoMedidor, "Medidor Monofasico") == 0) {
        return precios.getPrecioMonofasico();
    } else if (strcmp(tipoMedidor, "Medidor de Prepago") == 0) {
        return precios.getPrecioPrepago();
    } else {
        return 0.0f; // Por si ocurre un error
    }
}

void controlarPrecios(){
    ArchivoPreciosMed archivoPrecios("precios-medidores.dat");
    PreciosMedidores precios = archivoPrecios.LeerPreciosMed(0);

    ArchivoSuministro archivoSuministo("suministros.dat");
    int cantSums = archivoSuministo.CantidadSuministros();

    Suministro *vectorSuministros = new Suministro[cantSums];
    archivoSuministo.LeerSuministros(cantSums,vectorSuministros);

    for(int i = 0;i<cantSums; i++){
        char tipoMedidor[50];
        strcpy(tipoMedidor,vectorSuministros[i].getMedidor());

        int posicionSum = archivoSuministo.BuscarSuministro(vectorSuministros[i].getSuministroId());



        if(vectorSuministros[i].isActivo()){


    if (strcmp(tipoMedidor, "Medidor Electromecanico") == 0) {
        vectorSuministros[i].setPrecioKwh(precios.getPrecioElectromecanico());
    } else if (strcmp(tipoMedidor, "Medidor Digital") == 0) {
         vectorSuministros[i].setPrecioKwh(precios.getPrecioDigital());
    } else if (strcmp(tipoMedidor, "Medidor Inteligente") == 0) {
       vectorSuministros[i].setPrecioKwh(precios.getPrecioInteligente());
    } else if (strcmp(tipoMedidor, "Medidor Bidireccional") == 0) {
        vectorSuministros[i].setPrecioKwh(precios.getPrecioBidireccional());
    } else if (strcmp(tipoMedidor, "Medidor Trifasico") == 0) {
         vectorSuministros[i].setPrecioKwh(precios.getPrecioTrifasico());
    } else if (strcmp(tipoMedidor, "Medidor Monofasico") == 0) {
         vectorSuministros[i].setPrecioKwh(precios.getPrecioMonofasico());
    } else if (strcmp(tipoMedidor, "Medidor de Prepago") == 0) {
       vectorSuministros[i].setPrecioKwh(precios.getPrecioPrepago());
    }
        }

        archivoSuministo.EditarSuministro(vectorSuministros[i],posicionSum);
    }





delete []vectorSuministros;
}

void actualizarPrecios(){


int opc;
    ArchivoPreciosMed archivoPreciosMed("precios-medidores.dat");
        PreciosMedidores precios = archivoPreciosMed.LeerPreciosMed(0);
        precios.mostrarPrecios();
cout << "0- Volver al Menu Anterior " << std::endl;
cout << "Ingrese el numero de medidor que desea actualizar: " ;

opc = leerEntero();

std::cin.ignore();
float nuevoPrecio;

    switch (opc) {
        case 1:
            cout << "Ingrese Precio de Medidor Electromecanico: " ;
                nuevoPrecio = leerEntero();
                std::cin.ignore();
                precios.setPrecioElectromecanico(nuevoPrecio);

            break;
        case 2:
            cout << "Ingrese Precio Medidor Digital: " ;
            nuevoPrecio = leerEntero();
              std::cin.ignore();
                precios.setPrecioDigital(nuevoPrecio);
            break;
        case 3:
            cout << "Ingrese Precio Medidor Inteligente: " ;
            nuevoPrecio = leerEntero();
              std::cin.ignore();
                precios.setPrecioInteligente(nuevoPrecio);
            break;
        case 4:
            cout << "Ingrese Precio Medidor Bidireccional: " ;
            nuevoPrecio = leerEntero();
              std::cin.ignore();
                precios.setPrecioBidireccional(nuevoPrecio);
            break;
        case 5:
            cout << "Ingrese Precio Medidor Trifasico: " ;
            nuevoPrecio = leerEntero();
              std::cin.ignore();
                precios.setPrecioTrifasico(nuevoPrecio);
            break;
        case 6:
            cout << "Ingrese Precio Medidor Monofasico: " ;
            nuevoPrecio = leerEntero();
              std::cin.ignore();
                precios.setPrecioMonofasico(nuevoPrecio);
            break;
        case 7:
            cout << "Ingrese Precio Medidor de Prepago: " ;
           nuevoPrecio = leerEntero();
             std::cin.ignore();
                precios.setPrecioPrepago(nuevoPrecio);
            break;
        case 0:
              cout << "Volviendo al Menu Anterior.." << endl;
              return ;
        default:
            cout << "Opcion no valida. Por favor, Seleccione Nuevamente." << endl;
            break;
    }
    if(archivoPreciosMed.EditarPreciosMed(precios,0)){
        system("cls");
       cout << "Precio Actualizado Exitosamente." << endl;
    }
}


