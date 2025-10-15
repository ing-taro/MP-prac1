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

void Fecha::ver() const{
    if (this->Dia < 10)
        cout << "0";
  cout << this->Dia << "/";
    if (this->Mes < 10)
        cout << "0";
  cout <<this->Mes << "/" <<this->Anio;
}

bool Fecha::bisiesto() const {
    if (this->Anio%400==0 || (this->Anio%4==0 && this->Anio%100!=0))
        return true;
    else
        return false;
}

//F3=F2++
Fecha Fecha::operator++(int) {
   Fecha temp = *this;

   ++(*this);

   return temp;
}

Fecha Fecha::operator++() {   //++f
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (this->bisiesto()) //si el año es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    dmax=diaMes[this->Mes];

    this->Dia++;

    if (this->Dia>dmax) { //si al incrementar dia superamos el numero de dias de dicho mes
        this->Dia=1;      //pasamos a 1
        this->Mes++;  //del mes siguiente

        if (this->Mes>12) { //si al incrementar mes pasamos de 12 meses
            this->Mes=1;    //pasamos al mes 1
            this->Anio++;   //del año siguiente
        }
    }

    return *this; //devolvemos el objeto fecha ya incrementado
}

Fecha Fecha::operator+(int dias) const {
    Fecha temp = *this;

    for (int i = 0; i < dias; i++) {
        int dmax;
        int diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        if (temp.bisiesto())
            diaMes[2] = 29;

        dmax = diaMes[temp.Mes];
        temp.Dia++;

        if (temp.Dia > dmax) {
            temp.Dia = 1;
            temp.Mes++;
            if (temp.Mes > 12) {
                temp.Mes = 1;
                temp.Anio++;
            }
        }
    }

    return temp;
}

Fecha operator+(int dias, const Fecha& f) {
    Fecha temp(f.getDia(), f.getMes(), f.getAnio());

    for (int i = 0; i < dias; i++) {
        int dmax;
        int diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        if (temp.bisiesto())
            diaMes[2] = 29;

        dmax = diaMes[temp.getMes()];

        temp.setFecha(temp.getDia() + 1, temp.getMes(), temp.getAnio());
        if (temp.getDia() > dmax) {
            temp.setFecha(1, temp.getMes() + 1, temp.getAnio());
            if (temp.getMes() > 12) {
                temp.setFecha(1, 1, temp.getAnio() + 1);
            }
        }
    }

    return temp;
}


