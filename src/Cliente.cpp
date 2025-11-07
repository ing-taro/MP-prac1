#include "Cliente.h"
#include <cstdlib>
#include <cstring> // strlen, strcpy
#include <iomanip>
#include <sstream>

// Constructor (Realiza copia profunda)
Cliente::Cliente(long int d, const char *nom, Fecha f)
    : fechaAlta(f) // Llama al constructor de copia de Fecha
{
    this->dni = d;

    // Asignación dinámica y copia profunda para el nombre
    this->nombre = new char[strlen(nom) + 1];
    strcpy(this->nombre, nom);
}

// Constructor de Copia (NECESARIO: Regla del 5. Evita Shallow Copy de 'nombre')
Cliente::Cliente(const Cliente& c)
    : fechaAlta(c.fechaAlta) // Llama al constructor de copia de Fecha
{
    this->dni = c.dni;

    // Copia profunda para la cadena 'nombre'
    this->nombre = new char[strlen(c.nombre) + 1];
    strcpy(this->nombre, c.nombre);
}

// Destructor (NECESARIO: Libera memoria asignada a 'nombre')
Cliente::~Cliente()
{
    // Libera el array de caracteres del nombre
    delete [] this->nombre;
}


// Sobrecarga del operador de asignación (NECESARIO: Regla del 5. Evita Shallow Copy)
Cliente& Cliente::operator=(const Cliente& c) {
    if (this != &c) { // Evita auto-asignación (x = x)
        this->dni = c.dni;

        // 1. Liberar la memoria antigua de 'nombre'
        delete [] this->nombre;

        // 2. Asignar nueva memoria y realizar copia profunda
        this->nombre = new char[strlen(c.nombre) + 1];
        strcpy(this->nombre, c.nombre);

        // 3. Asignar la Fecha (llama al operator= de la clase Fecha)
        this->fechaAlta = c.fechaAlta;
    }
    return *this;
}


// Setter para el nombre (Realiza copia profunda y maneja la memoria)
void Cliente::setNombre(const char *nom) { // <-- Ahora recibe const char*

    // 1. Liberar la memoria antigua
    delete[] this->nombre;

    // 2. Asignar nueva memoria y copiar
    this->nombre = new char[strlen(nom) + 1];
    strcpy(this->nombre, nom);
}


// Setter para la fecha (Llama al operator= de la clase Fecha)
void Cliente::setFecha(Fecha f) {
    this->fechaAlta = f;
}

// Sobrecarga del operador == (comparación)
bool Cliente::operator==(const Cliente& c) const { // <-- Recibe por ref const

    // 1. Comparar DNI
    if (this->dni != c.dni) return false;

    // 2. Comparar Nombre (contenidos de las cadenas)
    if (strcmp(this->nombre, c.nombre) != 0) return false;

    // 3. Comparar Fecha (se asume que Fecha no tiene operator==, si no se usaría: this->fechaAlta == c.fechaAlta)
    if (this->fechaAlta.getDia() != c.fechaAlta.getDia() ||
        this->fechaAlta.getMes() != c.fechaAlta.getMes() ||
        this->fechaAlta.getAnio() != c.fechaAlta.getAnio()) return false;

    return true; // Todos los campos coinciden
}


// Implementación de la sobrecarga del operador de inserción (función no miembro)
// formato: nombre (dni - fecha)
ostream& operator<<(ostream &s, const Cliente &c) {
    // Usamos los getters para acceder a los datos
    s << c.getNombre() << " (" << c.getDni() << " - " << c.getFecha() << ")";
    return s;
}
