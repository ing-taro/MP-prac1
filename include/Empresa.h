#ifndef EMPRESA_H
#define EMPRESA_H
#include "Cliente.h"
#include "Contrato.h"
#include "ContratoMovil.h"
#include "ContratoTP.h"
#include "Fecha.h"

#include <iostream>

using namespace std;


class Empresa
{
    Cliente *clientes [100]; // Array estático de punteros a Clientes

    int ncli; // Contador de clientes

    const int nmaxcli; // Constante de capacidad

    Contrato **contratos; // Array dinámico de punteros a Contratos

    int ncon; // Contador de contratos

    int nmaxcon; // Capacidad máxima de contratos (no constante)

    protected:

        int altacliente(Cliente *c);

        int buscarcliente(long int dni) const;


    public:

        Empresa();

        virtual ~Empresa();

        void crearContrato();






    private:
};

#endif // EMPRESA_H
