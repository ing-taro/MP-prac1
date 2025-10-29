#include "Contrato.h"

//metodo contador de contratos, incluido en estatico
int Contrato::contador=1;


//constructor de contrato
Contrato::Contrato(long int dni, Fecha f): idContrato(contador), fechaContrato(f) {
  //idContrato=contador; //ERROR es constante y debe ir en zona inicializadores
  Contrato::contador++;
  this->dniContrato=dni;
  //this->fechaContrato=f; //ERROR es tipo no primitivo y debe ir en zona inicializadores
}


//destructor de contrato
Contrato::~Contrato()
{
    //dtor
}


//metodo ver de la clase contrato
void Contrato::ver() const {

  cout << this->dniContrato << " (" << this->idContrato << " - ";

  this->fechaContrato.ver(); //llamo al ver del objeto fecha

  cout << ")";
}

//sobrecarga del operador de flujo
ostream& operator<<(ostream &s, const Contrato &c){

    s << c.getDniContrato() << " (" << c.getIdContrato()<< " - ";

    c.getFechaContrato();

    s << ")";

    return s;
}
