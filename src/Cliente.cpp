#include "Cliente.h"
#include <cstdlib>
#include <cstring> // strlen, strcpy
#include <iomanip>
#include <sstream>

// Constructor
Cliente::Cliente(long int d, const char *nom, Fecha f): fechaAlta(f){
    this->dni = d;

    this->nombre = new char[strlen(nom) + 1];

    strcpy(this->nombre, nom);
}

// Constructor de Copia
Cliente::Cliente(const Cliente& c): fechaAlta(c.fechaAlta){
    this->dni = c.dni;

    this->nombre = new char[strlen(c.nombre) + 1];

    strcpy(this->nombre, c.nombre);
}

// Destructor (
Cliente::~Cliente(){
    delete [] this->nombre;
}


// Sobrecarga del operador de asignación
Cliente& Cliente::operator=(const Cliente& c) {
    if (this != &c) {
        this->dni = c.dni;

        delete [] this->nombre;

        this->nombre = new char[strlen(c.nombre) + 1];

        strcpy(this->nombre, c.nombre);

        this->fechaAlta = c.fechaAlta;
    }
    return *this;
}


// Setter
void Cliente::setNombre(const char *nom) {

    delete[] this->nombre;

    this->nombre = new char[strlen(nom) + 1];

    strcpy(this->nombre, nom);
}


// Setter
void Cliente::setFecha(Fecha f) {
    this->fechaAlta = f;
}

// Sobrecarga del operador ==
bool Cliente::operator==(const Cliente& c) const {

    if (this->dni != c.dni) return false;

    if (strcmp(this->nombre, c.nombre) != 0) return false;

    if (this->fechaAlta.getDia() != c.fechaAlta.getDia() ||
        this->fechaAlta.getMes() != c.fechaAlta.getMes() ||
        this->fechaAlta.getAnio() != c.fechaAlta.getAnio()) return false;

    return true;
}


// sobrecarga del operador de inserción
ostream& operator<<(ostream &s, const Cliente &c) {

    s << c.getNombre() << " (" << c.getDni() << " - " << c.getFecha() << ")";

    return s;
}
