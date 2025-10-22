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
