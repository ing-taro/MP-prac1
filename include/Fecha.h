#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    // Constructor (parámetros por valor)
    Fecha(int dia, int m, int anio);

    // Destructor
    ~Fecha();

    // GETTERS
    int getDia() const { return dia; }
    int getMes() const { return this->mes; }
    int getAnio() const { return this->anio; }

    // SETTER (parámetros por valor)
    void setFecha(int dia, int mes, int a);

    // Método para mostrar la fecha (dd/mm/aaaa)
    void ver() const;

    // Función que comprueba si el año es bisiesto
    bool bisiesto() const;

    // Operador pre-incremento (++f)
    Fecha operator++();

    // Operador post-incremento (f++)
    Fecha operator++(int);

    // Operador suma (f + dias)
    Fecha operator+(int i) const;

    // Operadores friend
    friend ostream& operator<<(ostream &s, const Fecha &f);
    friend Fecha operator+(int i, const Fecha &f);
};

// Sobrecarga del operador suma para invertir el orden (dias + f)
Fecha operator+(int i, const Fecha &f);

// Sobrecarga del operador de inserción
ostream& operator<<(ostream &s, const Fecha &f);

#endif // FECHA_H

