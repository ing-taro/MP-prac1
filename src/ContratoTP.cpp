#include "ContratoTP.h"

int ContratoTP::minutosTP=300;

float ContratoTP::precioTP=10;

const float ContratoTP::precioExcesoMinutos=0.15;


//destructor
ContratoTP::~ContratoTP()
{
    //dtor
}


ContratoTP::ContratoTP(long int dni, Fecha f, int m):Contrato(dni, f){

    this->minutosHablados = m;
}


void ContratoTP::setTarifaPlana(int m, float p) {

  ContratoTP::minutosTP=m; //puedo poner minutosTP=m ...pongo ContratoTP::minutosTP para recordar que es estatico

  ContratoTP::precioTP=p;  //puedo poner precioTP=p  ...pongo ContratoTP::precioTP para recordar que es estatico

}


float ContratoTP::calcularFactura() const {
    float costeTotal = ContratoTP::precioTP; // Precio fijo de la tarifa plana

    if (this->minutosHablados > ContratoTP::minutosTP) {
        int exceso = this->minutosHablados - ContratoTP::minutosTP;

        // Usamos el miembro estático constante precioExcesoMinutos
        costeTotal += exceso * ContratoTP::precioExcesoMinutos;
    }

    return costeTotal;
}
