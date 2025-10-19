#include "Cliente.h"
#include <cstdlib>
#include <cstring> //strlen, strcpy
#include <iomanip> //std::setprecision
#include <sstream> //stringstream



//Cliente::Cliente(long int d, char *nom, Fecha f):fechaAlta(f.getDia(), f.getMes(), f.getAnio()) {
Cliente::Cliente(long int d, char *nom, Fecha f):fechaAlta(f) { //esta cabecera es mas corta (invoco

  this->dni=d;                                                  //constructor copia de fecha
                                                                //en vez de constructor de 3 parametros)
  //this->nombre=nombre;  //MAL!!!!
  this->nombre=new char[strlen(nom)+1];
  strcpy(this->nombre, nom);

  //this->fechaAlta=f;//MAL!!!! los tipos no primitivos debe ir en zona inicializadores
}

//Destructor
Cliente::~Cliente()
{
    delete [] this->nombre;
}


