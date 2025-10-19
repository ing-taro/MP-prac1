#ifndef CLIENTE_H
#define CLIENTE_H
#include "Fecha.h"

#include <iostream>

using namespace std;

//debemos crear constrructor
//destructor
//getters
//setters
//metodos
//sobrecarga de operadores

class Cliente
{
    int dni;

    char *nombre;

    Fecha fechaAlta;

    public:

        //constructor
        Cliente(long int d, char *nom, Fecha f);

        //destructor
        virtual ~Cliente();

        Cliente& operator=(const Cliente& c);

        //getters
        long int getDni() const;

        const char* getNombre() const; //VIP devolver un puntero constante para evitar que desde el main() se puede modificar el nombre

        Fecha getFecha() const;




};


#endif // CLIENTE_H
