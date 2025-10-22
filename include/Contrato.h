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

    protected:

    private:
};

#endif // CONTRATO_H
