#include "Contrato.h"
#include <iostream>

using namespace std;

// Inicialización de la variable estática. Empieza en 1.
int Contrato::contador = 1;

// Constructor de Contrato
Contrato::Contrato(long int dni, Fecha f)
    : idContrato(Contrato::contador), fechaContrato(f)
{
    // Asignación del DNI
    this->dniContrato = dni;

    // Incrementar el contador para el siguiente contrato
    Contrato::contador++;
}

// Destructor de Contrato (Virtual)
Contrato::~Contrato()
{
    // dtor
}

// Constructor de Copia (Garantiza ID único y maneja el miembro const)
Contrato::Contrato(const Contrato& c)
    // Asigna un NUEVO ID, incrementando el contador. Copia la fecha.
    : idContrato(Contrato::contador), fechaContrato(c.fechaContrato)
{
    // Incrementar el contador para el siguiente contrato
    Contrato::contador++;

    // Copia el DNI
    this->dniContrato = c.dniContrato;
}


// Método ver de la clase Contrato
void Contrato::ver() const {
    // Muestra DNI, ID y Fecha. Utilizamos la sobrecarga del operador << de Fecha.
    cout << "DNI: " << this->dniContrato
         << " | ID Contrato: " << this->idContrato
         << " | Fecha: " << this->fechaContrato << ")"; // Usa operator<< para Fecha.
}

// Sobrecarga del operador de flujo (<<)
ostream& operator<<(ostream &s, const Contrato &c) {
    // Utiliza los getters de la clase Contrato. Ya usamos el operator<< de Fecha.
    s << c.getDniContrato() << " (" << c.getIdContrato() << " - " << c.getFechaContrato() << ")";
    return s;
}
