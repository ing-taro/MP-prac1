#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include <iostream> //cin, cout
#include "Fecha.h"
#include "Contrato.h" // Clase base Contrato

using namespace std;

class ContratoTP: public Contrato {
private:
    // Miembros estáticos para la Tarifa Plana
    static int minutosTP;
    static float precioTP;
    static const float precioExcesoMinutos; // 0.15 inamovible

    // Miembro de instancia
    int minutosHablados;

public:
    // Constructor
    ContratoTP(long int dni, Fecha f, int m);

    // Destructor (Virtual, esencial para el polimorfismo)
    virtual ~ContratoTP();

    // Getters y Setters Estáticos/Miembro
    static int getLimiteMinutos() { return ContratoTP::minutosTP; }
    static float getPrecio() { return ContratoTP::precioTP; }
    static void setTarifaPlana(int m, float p); // Setter estático para la tarifa

    int getMinutosHablados() const { return this->minutosHablados; }
    void setMinutosHablados(int m) { this->minutosHablados = m; }

    // MÉTODOS POLIMÓRFICOS

    // 1. Método ver() - Implementación de la visualización
    virtual void ver() const override;

    // 2. Método factura() - Implementación de la función pura de la base
    virtual float factura() const override;
};

// Sobrecarga del operador de inserción para ContratoTP
ostream& operator<<(ostream &s, const ContratoTP &c);

#endif // CONTRATOTP_H
