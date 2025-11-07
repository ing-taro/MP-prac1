#include "Fecha.h"
#include <iostream>
#include <cstring> // Incluido por si acaso, aunque no es necesario aquí.

using namespace std;

// Constructor: utiliza setFecha para la validación de los parámetros.
Fecha::Fecha(int d, int m, int a) {
    this->setFecha(d, m, a);
}

// Destructor (vacío)
Fecha::~Fecha() {
    // No se libera memoria dinámica
}

// Implementación de setFecha (VALIDA LA FECHA ANTES DE ASIGNAR)
void Fecha::setFecha(int d, int m, int a) {
    int dmax;
    // Array que guarda los días máximos de cada mes (posición 0 no usada).
    int diaMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    this->anio = a; // VIP: Asignar año para que bisiesto() funcione

    if (this->bisiesto())
        diaMes[2] = 29;

    // 1. VALIDAR Y ASIGNAR MES
    if (m < 1)
      this->mes = 1;
    else if (m > 12)
      this->mes = 12;
    else
      this->mes = m;

    dmax = diaMes[this->mes]; // Máximo de días para el mes validado

    // 2. VALIDAR Y ASIGNAR DÍA
    if (d > dmax)
      this->dia = dmax;
    else if (d < 1)
      this->dia = 1;
    else
      this->dia = d;
}

// Implementación de bool bisiesto() const
bool Fecha::bisiesto() const {
    // La fórmula es: divisible entre 400 O (divisible entre 4 Y no entre 100)
    if ((this->anio % 4 == 0 && this->anio % 100 != 0) || this->anio % 400 == 0)
        return true;
    else
        return false;
}

// Implementación de void ver() const
void Fecha::ver() const {
    if (this->dia < 10)
        cout << "0";
    cout << this->dia << "/";
    if (this->mes < 10)
        cout << "0";
    cout << this->mes << "/" << this->anio;
}

// Implementación del operador pre-incremento (++f)
Fecha Fecha::operator++() {
    int dmax, diaMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (this->bisiesto())
        diaMes[2] = 29;
    dmax = diaMes[this->mes];

    this->dia++;

    if (this->dia > dmax) { // Si pasa al siguiente mes
        this->dia = 1;
        this->mes++;

        if (this->mes > 12) { // Si pasa al siguiente año
            this->mes = 1;
            this->anio++;
        }
    }
    return *this; // Devuelve el objeto modificado
}

// Implementación del operador post-incremento (f++)
Fecha Fecha::operator++(int i) {
    Fecha f(*this); // Guarda el valor original
    ++(*this);      // Llama al pre-incremento para avanzar la fecha
    return f;       // Devuelve la copia guardada (valor original)
}

// Implementación del operador suma (f + dias)
Fecha Fecha::operator+(int i) const {
    Fecha suma = *this; // Crea una copia para trabajar
    for (int j = 0; j < i; j++)
        ++suma; // Usa el pre-incremento para avanzar día por día
    return suma;
}

// Implementación de la sobrecarga del operador suma (dias + f)
// Usa la versión miembro (f + dias) para la lógica
Fecha operator+(int i, const Fecha &f) {
    return f + i;
}

// Implementación de la sobrecarga del operador de inserción (cout << f)
ostream& operator<<(ostream &s, const Fecha &f) {
    // Array para obtener el nombre del mes
    const char *meses[] = {"", "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"};

    // Formato: dd mes aaaa (ej: 05 abr 2024)
    if (f.dia < 10)
        s << "0";
    s << f.dia << " " << meses[f.mes] << " " << f.anio;
    return s; // Importante: retornar el stream
}
