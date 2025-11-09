#include "Contrato.h"
#include <iostream>

using namespace std;


int Contrato::contador = 1;

// Constructor de Contrato
Contrato::Contrato(long int dni, Fecha f)
    : idContrato(Contrato::contador), fechaContrato(f)
{

    this->dniContrato = dni;

    Contrato::contador++;
}

// Destructor de Contrato
Contrato::~Contrato()
{
    // dtor
}

// Constructor de Copia
Contrato::Contrato(const Contrato& c): idContrato(Contrato::contador), fechaContrato(c.fechaContrato)
{
    // Incrementar el contador para el siguiente contrato
    Contrato::contador++;

    // Copio el DNI
    this->dniContrato = c.dniContrato;
}


// Método ver de la clase Contrato
void Contrato::ver() const {
    cout << "DNI: " << this->dniContrato

         << " | ID Contrato: " << this->idContrato

         << " | Fecha: " << this->fechaContrato << ")";

}


// Sobrecarga del operador de flujo
ostream& operator<<(ostream &s, const Contrato &c) {
    // Utiliza los getters de la clase Contrato.
    s << c.getDniContrato() << " (" << c.getIdContrato() << " - " << c.getFechaContrato() << ")";
    return s;
}
