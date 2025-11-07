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
    char *nacionalidad; // ¡ATENCIÓN! Recurso dinámico (requiere Regla del 5)

public:
    // Constructor (Realiza copia profunda de nacionalidad)
    ContratoMovil(long int dni, Fecha f, float p, int m, const char *nac); // <-- nom es const char*

    // Constructor de Copia (NECESARIO por el puntero 'nacionalidad')
    ContratoMovil(const ContratoMovil& c);

    // Destructor (VIRTUAL, esencial para liberar 'nacionalidad' en polimorfismo)
    virtual ~ContratoMovil();

    // Sobrecarga del operador de asignación (NECESARIO por el puntero 'nacionalidad')
    ContratoMovil& operator=(const ContratoMovil& c);

    // Getters
    float getPrecioMinuto() const { return this->precioMinuto; }
    int getMinutosHablados() const { return this->minutosHablados; }
    const char* getNacionalidad() const { return this->nacionalidad; }

    // Setters (Debe manejar la memoria: delete[] + new[])
    void setPrecioMinuto(float p) { this->precioMinuto = p; }
    void setMinutosHablados(int m) { this->minutosHablados = m; }
    void setNacionalidad(const char *nac); // Recibe const char* para seguridad

    // MÉTODOS POLIMÓRFICOS

    // 1. Método ver() - Implementación de la visualización
    virtual void ver() const override;

    // 2. Método factura() - Implementación de la función pura de la base
    virtual float factura() const override;
};

// Sobrecarga del operador de inserción para ContratoMovil
ostream& operator<<(ostream &s, const ContratoMovil &c);

#endif // CONTRATOMOVIL_H
