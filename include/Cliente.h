#ifndef CLIENTE_H
#define CLIENTE_H
#include "Fecha.h" // Incluimos la clase Fecha

#include <iostream>

using namespace std;

class Cliente
{
private:
    long int dni; // <-- CORREGIDO a long int
    char *nombre; // Puntero a la cadena de nombre
    Fecha fechaAlta; // Miembro objeto de la clase Fecha

public:
    // Constructor (Realiza copia profunda de nombre)
    Cliente(long int d, const char *nom, Fecha f); // <-- nom es const char*

    // Constructor de copia (NECESARIO por el puntero char*)
    Cliente(const Cliente& c);

    // Destructor (NECESARIO por el puntero char*)
    virtual ~Cliente();

    // Sobrecarga del operador de asignación (NECESARIO por el puntero char*)
    Cliente& operator=(const Cliente& c);

    // Getters
    long int getDni() const { return dni; } // Implementado en línea
    const char* getNombre() const { return nombre; } // Devuelve puntero constante (seguridad)
    Fecha getFecha() const { return fechaAlta; } // Devuelve copia de la Fecha

    // Setters
    void setNombre(const char *nom); // <-- nom es const char*
    void setFecha(Fecha f);

    // Sobrecarga del operador == (comparación)
    bool operator==(const Cliente& c) const; // <-- Paso por referencia constante

    // Sobrecarga del operador != (añadido para completar)
    bool operator!=(const Cliente& c) const { return !(*this == c); }
};

// Sobrecarga del operador de inserción (función no miembro)
ostream& operator<<(ostream &s, const Cliente &c);


#endif // CLIENTE_H
