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


//sobrecarga del operador =
Cliente& Cliente::operator=(const Cliente& c) {
  if (this != &c) { //si no es x=x
    this->dni=c.dni;
    delete [] this->nombre;
    //this->nombre=c.nombre;  //MAL!!!!
    this->nombre=new char[strlen(c.nombre)+1];
    strcpy(this->nombre, c.nombre);
    this->fechaAlta=c.fechaAlta;
  }
  return *this;
}


//Getter
long int Cliente::getDni()const{

    return this->dni;

}


//Getter
const char* Cliente::getNombre() const {

    return nombre;

}

//Getter
Fecha Cliente::getFecha() const {

    return fechaAlta;

}


//Setter
void Cliente::setNombre(char *nom){

    if (this->nombre == nom)
        return;


    delete[] this->nombre;


    this->nombre = new char[strlen(nom)+1];
    strcpy(this->nombre, nom);

}


void Cliente::setFecha(Fecha f){

    this->fechaAlta = f;

}














