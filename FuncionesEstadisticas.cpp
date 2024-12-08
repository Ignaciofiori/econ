/*#include "FuncionesEstadisticas.h"
#include "Funciones.h"
#include <iostream>
void MenuUsuariosEstadisticas() {
        int opcion=  -1;
    while (opcion !=0) {
            int opcion = -1;
        // Mostrar el menú
        std::cout << "\n----- Menu de Usuarios y Estadisticas -----" << std::endl;
        std::cout << "1. Mostrar listado de usuarios" << std::endl;
        std::cout << "2. Mostrar estadisticas generales" << std::endl;
        std::cout << "3. Buscar usuario por ID" << std::endl;
        std::cout << "4. Estadisticas avanzadas" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "\n------------------------------------------" << std::endl;
        std::cout << "Seleccione una opcion: ";
        opcion = leerEntero();
        std::cin.ignore();

        // Manejar las opciones del menú con un switch
        switch (opcion) {
            case 1:
                system("cls");
                std::cout << "Opcion 1: Mostrar listado de usuarios." << std::endl;
                // Agregar funcionalidad aquí
                break;

            case 2:
                 system("cls");
                std::cout << "Opcion 2: Mostrar estadisticas generales." << std::endl;
                // Agregar funcionalidad aquí
                break;

            case 3:
                 system("cls");
                std::cout << "Opcion 3: Buscar usuario por ID." << std::endl;
                // Agregar funcionalidad aquí
                break;

            case 4:
                 system("cls");
                std::cout << "Opcion 4: Estadisticas avanzadas." << std::endl;
                // Agregar funcionalidad aquí
                break;

            case 0:
                 system("cls");
                std::cout << "Saliendo del Menu..." << std::endl;
                    opcion = 0;
                    return;

            default:
                std::cout << "Opción inválida. Por favor, intente nuevamente." << std::endl;
                break;
        }
    }
}

void MenuSuministrosEstadisticas() {
    int opcion = -1;

    while (opcion != 0) {
        // Mostrar el menú
        std::cout << "\n----- Menu de Suministros y Estadisticas -----" << std::endl;
        std::cout << "1. Mostrar listado de suministros" << std::endl;
        std::cout << "2. Mostrar estadisticas de consumo" << std::endl;
        std::cout << "3. Buscar suministro por ID" << std::endl;
        std::cout << "4. Ver consumos elevados" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "\n----------------------------------------------" << std::endl;
        std::cout << "Seleccione una opcion: ";
        opcion = leerEntero();
        std::cin.ignore();

        // Manejar las opciones del menú con un switch
        switch (opcion) {
            case 1:
                system("cls");
                std::cout << "Opcion 1: Mostrar listado de suministros." << std::endl;
                // Agregar funcionalidad aquí
                break;

            case 2:
                system("cls");
                std::cout << "Opcion 2: Mostrar estadisticas de consumo." << std::endl;
                // Agregar funcionalidad aquí
                break;

            case 3:
                system("cls");
                std::cout << "Opcion 3: Buscar suministro por ID." << std::endl;
                // Agregar funcionalidad aquí
                break;

            case 4:
                system("cls");
                std::cout << "Opcion 4: Ver consumos elevados." << std::endl;
                // Agregar funcionalidad aquí
                break;

            case 0:
                system("cls");
                std::cout << "Saliendo del Menu..." << std::endl;
                opcion = 0;
                return;

            default:
                std::cout << "Opción inválida. Por favor, intente nuevamente." << std::endl;
                break;
        }
    }
}

void MenuFacturasEstadisticas() {
    int opcion = -1;

    while (opcion != 0) {
        // Mostrar el menú
        std::cout << "\n----- Menu de Facturas y Estadisticas -----" << std::endl;
        std::cout << "1. Mostrar listado de facturas" << std::endl;
        std::cout << "2. Mostrar estadísticas de facturación" << std::endl;
        std::cout << "3. Buscar factura por ID" << std::endl;
        std::cout << "4. Consultar facturas impagas" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "\n----------------------------" << std::endl;
        std::cout << "Seleccione una opcion: ";
        opcion = leerEntero();
        std::cin.ignore();

        // Manejar las opciones del menú con un switch
        switch (opcion) {
            case 1:
                system("cls");
                std::cout << "Opcion 1: Mostrar listado de facturas." << std::endl;
                // Implementar funcionalidad para mostrar todas las facturas
                break;

            case 2:
                system("cls");
                std::cout << "Opcion 2: Mostrar estadísticas de facturación." << std::endl;
                // Implementar funcionalidad para mostrar estadísticas generales de facturación
                break;

            case 3:
                system("cls");
                std::cout << "Opcion 3: Buscar factura por ID." << std::endl;
                // Implementar funcionalidad para buscar factura por ID
                break;

            case 4:
                system("cls");
                std::cout << "Opcion 4: Consultar facturas impagas." << std::endl;
                // Implementar funcionalidad para consultar facturas no pagadas
                break;

            case 0:
                system("cls");
                std::cout << "Saliendo del Menu de Facturas..." << std::endl;
                return;

            default:
                std::cout << "Opción inválida. Por favor, intente nuevamente." << std::endl;
                break;
        }
    }
}

void MenuTotalesEstadisticas() {
    int opcion = -1;

    while (opcion != 0) {
        // Mostrar el menú
        std::cout << "\n----- Menu de Totales y Estadisticas -----" << std::endl;
        std::cout << "1. Mostrar totales generales" << std::endl;
        std::cout << "2. Mostrar totales por categoría" << std::endl;
        std::cout << "3. Buscar total por ID" << std::endl;
        std::cout << "4. Consultar totales pendientes" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "\n------------------------------------------" << std::endl;
        std::cout << "Seleccione una opcion: ";
        opcion = leerEntero();
        std::cin.ignore();

        // Manejar las opciones del menú con un switch
        switch (opcion) {
            case 1:
                system("cls");
                std::cout << "Opcion 1: Mostrar totales generales." << std::endl;
                // Implementar funcionalidad para mostrar totales generales
                break;

            case 2:
                system("cls");
                std::cout << "Opcion 2: Mostrar totales por categoría." << std::endl;
                // Implementar funcionalidad para mostrar totales por categoría
                break;

            case 3:
                system("cls");
                std::cout << "Opcion 3: Buscar total por ID." << std::endl;
                // Implementar funcionalidad para buscar total por ID
                break;

            case 4:
                system("cls");
                std::cout << "Opcion 4: Consultar totales pendientes." << std::endl;
                // Implementar funcionalidad para consultar totales pendientes
                break;

            case 0:
                system("cls");
                std::cout << "Saliendo del Menu de Totales..." << std::endl;
                return;

            default:
                std::cout << "Opción inválida. Por favor, intente nuevamente." << std::endl;
                break;
        }
    }
}
*/
