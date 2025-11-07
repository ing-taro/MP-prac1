#include "ContratoMovil.h"
#include "Contrato.h"
#include <iostream>
#include <iomanip>
#include <cstring> // Para strlen, strcpy

using namespace std;

// ---------------------------------------------------------------------
// 1. CONSTRUCTOR PRINCIPAL (Copia profunda de la nacionalidad)
// ---------------------------------------------------------------------

// El parámetro 'nac' es const char* para seguridad y compatibilidad con el .h
ContratoMovil::ContratoMovil(long int dni, Fecha f, float p, int m, const char *nac)
    : Contrato(dni, f) // Llama al constructor de la clase base
{
    this->precioMinuto = p;
    this->minutosHablados = m;

    // Asignación dinámica y copia profunda para el recurso char*
    this->nacionalidad = new char[strlen(nac) + 1];
    strcpy(this->nacionalidad, nac);
}

// ---------------------------------------------------------------------
// 2. CONSTRUCTOR DE COPIA (Regla del Cinco - Copia profunda)
// ---------------------------------------------------------------------

ContratoMovil::ContratoMovil(const ContratoMovil& c)
    // CRÍTICO: Llama al constructor de copia de la clase base (que genera un nuevo ID)
    : Contrato(c)
{
    this->precioMinuto = c.precioMinuto;
    this->minutosHablados = c.minutosHablados;

    // Copia profunda para la cadena 'nacionalidad'
    this->nacionalidad = new char[strlen(c.nacionalidad) + 1];
    strcpy(this->nacionalidad, c.nacionalidad);
}

// ---------------------------------------------------------------------
// 3. DESTRUCTOR (Regla del Cinco - Libera memoria dinámica)
// ---------------------------------------------------------------------

ContratoMovil::~ContratoMovil()
{
    // Libera la memoria asignada dinámicamente para la nacionalidad
    delete [] this->nacionalidad;
}

// ---------------------------------------------------------------------
// 4. OPERADOR DE ASIGNACIÓN (Regla del Cinco - Asignación profunda)
// ---------------------------------------------------------------------

ContratoMovil& ContratoMovil::operator=(const ContratoMovil& c) {
    if (this != &c) { // Evitar auto-asignación
        // No podemos llamar al operator= de Contrato (por el miembro const),
        // pero sí asignamos el resto de los miembros.

        this->precioMinuto = c.precioMinuto;
        this->minutosHablados = c.minutosHablados;

        // 1. Liberar memoria antigua de nacionalidad
        delete [] this->nacionalidad;

        // 2. Asignar nueva memoria y copiar
        this->nacionalidad = new char[strlen(c.nacionalidad) + 1];
        strcpy(this->nacionalidad, c.nacionalidad);
    }
    return *this;
}

// ---------------------------------------------------------------------
// 5. SETTER PARA NACIONALIDAD (Manejo de memoria)
// ---------------------------------------------------------------------

void ContratoMovil::setNacionalidad(const char *nac) {
    // 1. Liberar la memoria antigua
    delete[] this->nacionalidad;

    // 2. Asignar nueva memoria y copiar
    this->nacionalidad = new char[strlen(nac) + 1];
    strcpy(this->nacionalidad, nac);
}

// ---------------------------------------------------------------------
// 6. MÉTODOS POLIMÓRFICOS
// ---------------------------------------------------------------------

// Implementación del método virtual ver()
void ContratoMovil::ver() const {
    // 1. Mostrar los datos de la clase base
    Contrato::ver();

    // 2. Mostrar los datos específicos de ContratoMovil
    cout << " | Tipo: Movil"
         << " | Minutos Hablados: " << this->minutosHablados
         << " | Precio/Minuto: " << fixed << setprecision(2) << this->precioMinuto << "€"
         << " | Nacionalidad: " << this->nacionalidad;
}

// Implementación de la función virtual pura factura()
float ContratoMovil::factura() const {
    // Factura = minutos hablados * precio por minuto
    return this->minutosHablados * this->precioMinuto;
}

// ---------------------------------------------------------------------
// 7. SOBRECARGA DEL OPERADOR <<
// ---------------------------------------------------------------------

ostream& operator<<(ostream &s, const ContratoMovil &c) {
    // 1. Llama al operador de inserción de la clase base (Contrato)
    s << (Contrato &)c;

    // 2. Añade la información específica de ContratoMovil y la factura
    s << " [Minutos Hablados: " << c.getMinutosHablados()
      << ", Precio/m: " << fixed << setprecision(2) << c.getPrecioMinuto()
      << ", Nacionalidad: " << c.getNacionalidad()
      << ", Factura: " << fixed << setprecision(2) << c.factura() << "€]";

    return s;
}
