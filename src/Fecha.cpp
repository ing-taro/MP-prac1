#include "Fecha.h"

#include <iostream>

using namespace std;

Fecha::Fecha(int d, int m, int a){

    Dia = a;

    Mes = m;

    Anio = a;
}

Fecha::~Fecha(){
}

int Fecha::getDia() const {
    return Dia;
}

int Fecha::getMes() const {
    return Mes;
}

int Fecha::getAnio() const {
    return Anio;
}

void Fecha::setFecha(const int &D,const  int &M,const int &A)  {

    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    this->Anio=A; //VIP debo asignar año para que al llamar a bisiesto() tenga el año bien

    if (this->bisiesto()) //si el año es bisiesto, febrero tiene 29 días
        diaMes[2]=29;

    if (Mes<1)  //si el mes es incorrecto
      this->Mes=1;

    else if (Mes>12) //si el mes es incorrecto
      this->Mes=12;

    else
      this->Mes=Mes;

    dmax=diaMes[this->Mes]; //una vez fijado el mes veo cuantos dias tiene ese mes como maximo

    if (Dia>dmax) //si dia es superior al numero de dias de dicho mes
      this->Dia=dmax;

    else if (Dia<1) //si dia es inferior a 1
      this->Dia=1;

    else
      this->Dia=Dia;

}

