#ifndef CONTRATO_H
#define CONTRATO_H
#include "Fecha.h"

class Contrato
{

  static int contador; //estatico

  const int idContrato;

  long int dniContrato;

  Fecha fechaContrato;

    public:
        Contrato(long int dni, Fecha f);
        virtual ~Contrato();

        int getIdContrato() const { return this->idContrato; }

        long int getDniContrato() const { return this->dniContrato; }

        Fecha getFechaContrato() const { return this->fechaContrato; }

        void setFechaContrato(Fecha f) { this->fechaContrato=f; }

        void setDniContrato(long int dni) { this->dniContrato=dni; }

        void ver() const;


    protected:

    private:
};

ostream& operator<<(ostream &s, const Contrato &c);

#endif // CONTRATO_H
