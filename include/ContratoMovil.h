#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H

#include <iostream>
#include "Fecha.h"
#include "Contrato.h" // Clase base

using namespace std;

class ContratoMovil: public Contrato {
private:
    float precioMinuto;
    int minutosHablados;
    char *nacionalidad;

public:
    // Constructor
    ContratoMovil(long int dni, Fecha f, float p, int m, const char *nac);

    // Constructor de Copia (NECESARIO por el puntero nacionalidad)
    ContratoMovil(const ContratoMovil& c);

    // Destructor
    virtual ~ContratoMovil();

    // Sobrecarga del operador de asignación
    ContratoMovil& operator=(const ContratoMovil& c);

    // Getters
    float getPrecioMinuto() const { return this->precioMinuto; }
    int getMinutosHablados() const { return this->minutosHablados; }
    const char* getNacionalidad() const { return this->nacionalidad; }

    // Setters
    void setPrecioMinuto(float p) { this->precioMinuto = p; }
    void setMinutosHablados(int m) { this->minutosHablados = m; }
    void setNacionalidad(const char *nac);

    // MÉTODOS POLIMÓRFICOS

    //Método ver()
    virtual void ver() const override;

    // Método factura()
    virtual float factura() const override;
};

// Sobrecarga del operador de inserción
ostream& operator<<(ostream &s, const ContratoMovil &c);

#endif // CONTRATOMOVIL_H
