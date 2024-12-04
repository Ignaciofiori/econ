#pragma once
#include <iostream>
using namespace std;

class PreciosMedidores {
private:
    float _precioElectromecanico;
    float _precioDigital;
    float _precioInteligente;
    float _precioBidireccional;
    float _precioTrifasico;
    float _precioMonofasico;
    float _precioPrepago;

public:
    // Constructores
    PreciosMedidores();
    PreciosMedidores(float electromecanico, float digital, float inteligente,
                     float bidireccional, float trifasico, float monofasico, float prepago);

    // Getters
    float getPrecioElectromecanico();
    float getPrecioDigital();
    float getPrecioInteligente();
    float getPrecioBidireccional();
    float getPrecioTrifasico();
    float getPrecioMonofasico();
    float getPrecioPrepago();

    // Setters
    void setPrecioElectromecanico(float precio);
    void setPrecioDigital(float precio);
    void setPrecioInteligente(float precio);
    void setPrecioBidireccional(float precio);
    void setPrecioTrifasico(float precio);
    void setPrecioMonofasico(float precio);
    void setPrecioPrepago(float precio);

    // Metodo para mostrar precios
    void mostrarPrecios();
};

