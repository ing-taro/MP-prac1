#include "Empresa.h"
#include "Cliente.h"
#include "Contrato.h"
#include "ContratoMovil.h"
#include "ContratoTP.h"
#include "Fecha.h"


// Implementación del constructor
// Inicializa la constante nmaxcli en la lista de inicialización
Empresa::Empresa() : nmaxcli(100) {

    // Inicializa los contadores
    this->ncli = 0;
    this->ncon = 0;

    // Inicializa la capacidad máxima de contratos
    this->nmaxcon = 10;

    // Crea el array dinámico de punteros a Contrato
    this->contratos = new Contrato* [this->nmaxcon];
}



Empresa::~Empresa(){

    //Eliminar los objetos Contrato
    for(int i = 0; i < this->ncon; i++) {
        delete this->contratos[i]; //Elimina el objeto al que apunta el puntero
    }

    //Eliminar el array de punteros a Contrato
    delete [] this->contratos;

    //Eliminar los objetos Cliente
    for(int i = 0; i < this->ncli; i++) {
        delete this->clientes[i]; //Elimina el objeto al que apunta el puntero
    }

}



int Empresa::altacliente(Cliente *c){
    int pos = -1; // Inicialmente, -1 indica que no cabe o no se ha insertado

    // Comprobar si queda espacio en el array de clientes
    if (this->ncli < this->nmaxcli) {

        // El anexo asume que los clientes se guardan de forma consecutiva (sin huecos)
        // Se añade el puntero al nuevo cliente en la primera posición disponible
        this->clientes[this->ncli] = c;

        // Guardar la posición donde se ha insertado (que es el valor actual de ncli)
        pos = this->ncli;

        // Incrementar el contador de clientes
        this->ncli++;

    } else {
        // Si no cabe, mostrar un mensaje (opcional)
        cout << "Clientes llenos";
        pos = -1;
    }

    // Devolver la posición de inserción o -1
    return pos;
}



int Empresa::buscarcliente(long int dni) const {

    for (int i = 0; i < this->ncli; i++) {

        if (this->clientes[i]->getDni() == dni) {

            return i;
        }
    }

    return -1;
}



void Empresa::crearContrato() {

    long int dni;

    int pos;

    cout << endl << "Introduzca dni: ";

    cin >> dni;

    pos=this->buscarcliente(dni);

    if (pos==-1) { //el cliente no existe y hay que darlo de alta

        int dia, mes, anio;

        char nombre[100];

        Cliente *c;

        cin.ignore();

        cout << "Nombre del cliente: ";

        cin.getline(nombre,100);

        cout << "dia: ";

        cin >> dia;

        cout << "mes: ";

        cin >> mes;

        cout << "anio: ";

        cin >> anio;

        c=new Cliente(dni, nombre, Fecha(dia, mes, anio));

        pos=this->altacliente(c);
    }
    //viendo cuanto vale la variable pos sé si el cliente se ha dado de alta o no
    if (pos!=-1) { //el cliente existe o se ha dado de alta
    //PREGUNTAR QUE TIPO DE CONTRATO QUIERE Y LOS DATOS NECESARIOS
    //CREAR EL OBJETO CONTRATO CORRESPONDIENTE Y AÑADIR AL ARRAY
    //contratos UN PUNTERO A DICHO OBJETO

        int tipo;

        this->ncon++;

        do {

            cout << "Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): ";

            cin >> tipo;

        } while(tipo!=1 && tipo!=2);

        if(tipo==1) {
            int m, d, mes, a;

            cout << "Fecha del contrato" << endl
                 << "dia: ";
            cin >> d;
            cout << "mes: ";
            cin >> mes;
            cout << "anio: ";
            cin >> a;
            cout << "minutos hablados: ";
            cin >> m;

            this->contratos[ncon-1] = new ContratoTP(dni, Fecha(d, mes, a), m);
        }

        else if(tipo==2) {
            int m, d, mes, a;
            float p_m;
            char nac[100];

            cout << "Fecha del contrato" << endl
                 << "dia: ";
            cin >> d;
            cout << "mes: ";
            cin >> mes;
            cout << "anio: ";
            cin >> a;
            cout << "minutos hablados: ";
            cin >> m;
            cout << "Precio minuto: ";
            cin >> p_m;
            cout << "Nacionalidad: ";
            cin >> nac;

            this->contratos[ncon-1] = new ContratoMovil(dni, Fecha(d, mes, a), p_m, m, nac);
        }
    }
}


bool Empresa::cancelarContrato(int idcontrato){

    for(int i = 0; i < this->ncon; i++){

        //verificosi coincide
        if(this->contratos[i]->getIdContrato() == idcontrato){

            delete this->contratos[i]; //elimino el puntero

            //bucle para decrementar el puntero
            for (int j = i + 1; j < this->ncon; j++) {

            this->contratos[j - 1] = this->contratos[j]; //muevo el puntero a la posicioón j-1

        }

        // Decremento ya que eliminé 1 contrato
        this->ncon--;

        return true;

        }
    }

    return false;
}



bool Empresa::bajaCliente(long int dni) {

    // para hacernos la vida más fácil llamamos al método para buscarlo
    int pos = this->buscarCliente(dni);

    // Si no existe
    if (pos == -1) {
        return false;
    }

    // Recorremos los contratos para verificar si tiene alguno
    for (int i = 0; i < this->ncon; i++) {

        //verifico si coincide
        if (this->contratos[i]->getDniContrato() == dni) {

            // si tiene minimo 1 contrato no lo puedo dar de baja
            cout << "ERROR: El cliente tiene contratos activos. No se puede dar de baja." <<endl;

            return false;
        }
    }

    delete this->clientes[pos];//elimino el puntero

    //bucle para decrementar el puntero
    for (int j = pos + 1; j < this->ncli; j++) {

        this->clientes[j - 1] = this->clientes[j];//muevo el puntero a la posicioón j-1
    }

    //Decrementar ya que eliminé 1 cliente
    this->ncli--;

    return true;
}


int Empresa::nContratosTP() const
{
    int contador = 0;

    for(int i=0; i<ncon; i++)
    {
        if(typeid(*contratos[i]) == typeid(ContratoTP))
        {
            contador++;
        }
    }

    return contador;
}

