#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream>
#include "Fecha.h" // Dependencia de la clase Fecha

using namespace std;

class Contrato
{
private:
    static int contador;      // Generador de ID únicos (Común a todos los contratos)
    const int idContrato;     // ID único de cada contrato (constante)
    long int dniContrato;
    Fecha fechaContrato;      // Fecha de alta del contrato

public:
    // Constructor principal
    Contrato(long int dni, Fecha f);

    // DESTRUCTOR VIRTUAL (CRÍTICO para el polimorfismo y para liberar memoria correctamente)
    virtual ~Contrato();

    // CONSTRUCTOR DE COPIA EXPLÍCITO (CRÍTICO, evita errores al copiar objetos Contrato)
    Contrato(const Contrato& c);

    // Getters
    int getIdContrato() const { return this->idContrato; }
    long int getDniContrato() const { return this->dniContrato; }
    Fecha getFechaContrato() const { return this->fechaContrato; }

    // Setters
    void setFechaContrato(Fecha f) { this->fechaContrato = f; }
    void setDniContrato(long int dni) { this->dniContrato = dni; }

    // MÉTODOS POLIMÓRFICOS

    // 1. Método ver() - VIRTUAL
    // Permite que las clases derivadas lo redefinan y se ejecute la versión correcta.
    virtual void ver() const;

    // 2. Método factura() - VIRTUAL PURO (= 0)
    // Hace que la clase Contrato sea ABSTRACTA (no se pueden crear objetos Contrato directamente)
    virtual float factura() const = 0;
};

// Sobrecarga del operador de inserción (para imprimir objetos Contrato)
ostream& operator<<(ostream &s, const Contrato &c);

#endif // CONTRATO_H
