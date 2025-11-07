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
    int pos = this->buscarcliente(dni);

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



void Empresa::cargarDatos() {

    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);

    this->clientes[0] = new Cliente(75547001, "Peter Lee", f1);

    this->clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29,2,2000));

    this->clientes[2] = new Cliente(37000017, "Luis Bono", f2);

    this->ncli=3;

    this->contratos[0] = new ContratoMovil(75547001, f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m

    this->contratos[1] = new ContratoMovil(75547001, f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m

    this->contratos[2] = new ContratoTP(37000017, f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)

    this->contratos[3] = new ContratoTP(75547001, f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)

    this->contratos[4] = new ContratoMovil(45999000, f2, 0.10, 202, "ESPAÑOL"); //habla 202m a 0.10/m

    this->contratos[5] = new ContratoMovil(75547001, f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m

    this->contratos[6] = new ContratoTP(45999000, f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)

    this->ncon=7;

}


void Empresa::ver() const {

    cout << endl << "La Empresa tiene " << ncli << " clientes y " << ncon << " contratos" << endl
         << "Clientes:" << endl;

    for(int i=0; i<ncli; i++)
        cout << *this->clientes[i] << endl;

    cout << endl << "Contratos:" << endl;

    for(int j=0; j<ncon; j++)
        if(typeid(*contratos[j])==typeid(ContratoTP)) {

            ContratoTP *cTP = dynamic_cast<ContratoTP*>(contratos[j]);

            cTP->ver();

            cout << " - " << cTP->factura() << "€" << endl;
        }

        else {

            ContratoMovil *cm = dynamic_cast<ContratoMovil*>(contratos[j]);

            cm->ver();

            cout << " - " << cm->factura() << "€" << endl;

        }
}



int Empresa::descuento (float porcentaje) const {

    int n = 0;

    for(int i=0; i<this->ncon; i++)

        if(dynamic_cast<ContratoMovil*>(contratos[i])!=0) {

            float nuevoPrecio;

            n++;

            ContratoMovil *cm = dynamic_cast<ContratoMovil*>(contratos[i]);

            nuevoPrecio = cm->getPrecioMinuto()*(1.00-porcentaje/100);

            cm->setPrecioMinuto(nuevoPrecio);

            contratos[i] = dynamic_cast<Contrato*>(cm);

        }

    return n;
}


