#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream>
#include "Fecha.h" // Dependencia de la clase Fecha

using namespace std;

class Contrato
{
private:
    static int contador;
    const int idContrato;
    long int dniContrato;
    Fecha fechaContrato;      // Fecha de alta del contrato

public:
    // Constructor principal
    Contrato(long int dni, Fecha f);

    // DESTRUCTOR VIRTUAL
    virtual ~Contrato();

    // CONSTRUCTOR DE COPIA EXPLÍCITO
    Contrato(const Contrato& c);

    // Getters
    int getIdContrato() const { return this->idContrato; }
    long int getDniContrato() const { return this->dniContrato; }
    Fecha getFechaContrato() const { return this->fechaContrato; }

    // Setters
    void setFechaContrato(Fecha f) { this->fechaContrato = f; }
    void setDniContrato(long int dni) { this->dniContrato = dni; }

    // MÉTODOS POLIMÓRFICOS

    // Método ver()
    virtual void ver() const;

    //Método factura()
    // Hace que la clase Contrato sea ABSTRACTA
    virtual float factura() const = 0;
};

// Sobrecarga del operador de inserción (para imprimir objetos Contrato)
ostream& operator<<(ostream &s, const Contrato &c);

#endif // CONTRATO_H
