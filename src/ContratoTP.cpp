#include "ContratoTP.h"

int ContratoTP::minutosTP=300;

float ContratoTP::precioTP=10;

const float ContratoTP::precioExcesoMinutos=0.15;

//destructor
ContratoTP::~ContratoTP()
{
    //dtor
}


void ContratoTP::setTarifaPlana(int m, float p) {

  ContratoTP::minutosTP=m; //puedo poner minutosTP=m ...pongo ContratoTP::minutosTP para recordar que es estatico

  ContratoTP::precioTP=p;  //puedo poner precioTP=p  ...pongo ContratoTP::precioTP para recordar que es estatico

}

