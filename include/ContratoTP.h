#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include <iostream>
#include "Fecha.h"
#include "Contrato.h"

using namespace std;

class ContratoTP: public Contrato {
      static int minutosTP;
      static float precioTP;
      int minutosHablados;
      static const float precioExcesoMinutos;

public:
     //constructor
     ContratoTP(long int dni, Fecha f, int m);
     virtual ~ContratoTP(); //sea necesario o no, lo pongo para asegurar
     //ContratoTP(const ContratoTP& c);  //no creo que se necesite usar un constructor de copia, teniendo en cuenta que no estamos manejando punteros ni memoria din�mica
     //ContratoTP& operator=(const ContratoTP& c); //Lo mismo para el operador de asignaci�n

    static int getLimiteMinutos() { return ContratoTP::minutosTP; }
    static float getPrecio() { return ContratoTP::precioTP; }
    static void setTarifaPlana(int m, float p); //el el .cpp se pone la cabecera sin la palabra static

    virtual float calcularFactura()const;



};



#endif // CONTRATOTP_H
