#include "ContratoTP.h"
#include "Contrato.h" // Incluimos la clase base para la herencia
#include <iostream>
#include <iomanip>

using namespace std;

int ContratoTP::minutosTP = 300;
float ContratoTP::precioTP = 10;
const float ContratoTP::precioExcesoMinutos = 0.15; // Inamovible


// Constructor principal
ContratoTP::ContratoTP(long int dni, Fecha f, int m)
    : Contrato(dni, f) // Llama al constructor de la clase base
{
    this->minutosHablados = m;
}

// Destructor
ContratoTP::~ContratoTP()
{
    // dtor
}


// Setter estático para modificar la tarifa plana (minutos y precio)
void ContratoTP::setTarifaPlana(int m, float p) {
    ContratoTP::minutosTP = m;
    ContratoTP::precioTP = p;
}



// método virtual ver()
void ContratoTP::ver() const {
    // Mostrar los datos de la clase base
    Contrato::ver();

    // Mostrar los datos específicos de ContratoTP
    cout << " | Tipo: Tarifa Plana"
         << " | Minutos Hablados: " << this->minutosHablados
         << " | Limite TP: " << ContratoTP::minutosTP << "m"
         << " | Precio TP: " << fixed << setprecision(2) << ContratoTP::precioTP << "€";
}

// Implementación de la función virtual pura factura()
float ContratoTP::factura() const {
    float costeTotal = ContratoTP::precioTP; // Precio fijo de la tarifa plana

    if (this->minutosHablados > ContratoTP::minutosTP) {
        int exceso = this->minutosHablados - ContratoTP::minutosTP;

        // Coste total = Tarifa Plana + (Exceso * Precio Exceso)
        costeTotal += exceso * ContratoTP::precioExcesoMinutos;
    }

    return costeTotal;
}

// Sobrecarga del operador de inserción para ContratoTP
ostream& operator<<(ostream &s, const ContratoTP &c) {

    s << (Contrato &)c;

    s << " [Minutos Hablados: " << c.getMinutosHablados()
      << ", Factura: " << fixed << setprecision(2) << c.factura() << "€]";

    return s;
}
