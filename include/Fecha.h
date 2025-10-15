#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;
//constructor de 3 parametros: dia, mes y año
//int dia, mes, anio, fecha(d,m,a)

//setfecha(d,m,a)
//getmes()
//verfecha()
//funcion bisiesto
//f3=f4++ sobrecarga de operador por la izquierda
//++f4 sobrecarga del operador por la derecha


class Fecha
{
    int Dia;

    int Mes;

    int Anio;

    public:
        //constructor
        Fecha(int Dia, int Mes, int Anio);

        //Destructor
        ~Fecha();


    protected:

    private:
};

#endif // FECHA_H
