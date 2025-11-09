#ifndef CLIENTE_H
#define CLIENTE_H
#include "Fecha.h"

#include <iostream>

using namespace std;

class Cliente
{
private:
    long int dni;
    char *nombre;
    Fecha fechaAlta;

public:
    // Constructor
    Cliente(long int d, const char *nom, Fecha f);

    // Constructor de copia
    Cliente(const Cliente& c);

    // Destructor
    virtual ~Cliente();

    // Sobrecarga del operador de asignación
    Cliente& operator=(const Cliente& c);

    // Getters
    long int getDni() const { return dni; }
    const char* getNombre() const { return nombre; }
    Fecha getFecha() const { return fechaAlta; }

    // Setters
    void setNombre(const char *nom);
    void setFecha(Fecha f);

    // Sobrecarga del operador ==
    bool operator==(const Cliente& c) const;

    // Sobrecarga del operador !=
    bool operator!=(const Cliente& c) const { return !(*this == c); }
};

// Sobrecarga del operador de inserción
ostream& operator<<(ostream &s, const Cliente &c);


#endif // CLIENTE_H
