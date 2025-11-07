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

        bool cancelarContrato(int idContrato); //true si el Contrato existe, false si no

        bool bajaCliente(long int dni); //true si el Cliente existe, false si no

        int descuento (float porcentaje) const; //devuelve a cuantos aplica el descuento

        int nContratosTP() const;

        void cargarDatos();//crea 3 clientes y 7 contratos. metodo creado para no

        virtual void ver() const;  //tener que meter datos cada vez que pruebo el programa






    private:
};

#endif // EMPRESA_H
