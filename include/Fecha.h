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

        //GETTERS
        int getDia() const;

        int getMes() const;

        int getAnio() const;

        //SETTERS

        void setFecha(const int &Dia,const  int &Mes,const int &Anio);

        void ver()const;

         //es bisiesto si es divisible entre 400 o es divisible entre 4 y no entre 100, es bisiesto
        bool bisiesto() const;

        Fecha operator++(int);

        Fecha operator++();

    protected:

    private:
};

#endif // FECHA_H
