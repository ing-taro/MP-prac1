#include "Empresa.h"
#include "Cliente.h"
#include "Contrato.h"
#include "ContratoMovil.h"
#include "ContratoTP.h"
#include "Fecha.h"


// Implementación del constructor
// Inicializa la constante nmaxcli en la lista de inicialización
Empresa::Empresa() : nmaxcli(100) {

    // Inicializa los contadores
    this->ncli = 0;
    this->ncon = 0;

    // Inicializa la capacidad máxima de contratos
    this->nmaxcon = 10;

    // Crea el array dinámico de punteros a Contrato
    this->contratos = new Contrato* [this->nmaxcon];
}

Empresa::~Empresa()
{
    delete[] this->clientes;


}
