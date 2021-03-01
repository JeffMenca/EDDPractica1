#include <iostream>
using namespace std;

class Caja
{
private:
    int numeroCaja;
    float tiempoServicio;
    bool estadoLibre;
    int codigoCliente;
    int codigoCarreta;

public:
    Caja(int, double, bool, int, int);
    void getNumeroCaja();
    void getTiempoServicio();
    void getEstadoLibre();
    void getCodigoCliente();
    void getCodigoCarreta();
};

Caja::Caja(int numeroCaja, double tiempoServicio, bool estadoLibre, int codigoCliente, int codigoCarreta)
{
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
    this->estadoLibre = estadoLibre;
    this->codigoCliente = codigoCliente;
    this->codigoCarreta = codigoCarreta;
}

void Caja::getNumeroCaja()
{
    cout << "El numero de caja es:" << (numeroCaja) << endl;
}
void Caja::getTiempoServicio()
{
    cout << "El tiempo de servicio de la caja es:" << (tiempoServicio) << endl;
}
void Caja::getEstadoLibre()
{
    cout << "La caja esta libre?:" << (estadoLibre) << endl;
}
void Caja::getCodigoCliente()
{
    cout << "El codigo del cliente actuak:" << (codigoCliente) << endl;
}
void Caja::getCodigoCarreta()
{
    cout << "El codigo de carreta que usa el cliente es:" << (codigoCarreta) << endl;
}


int main()
{
    Caja nuevaCaja(1,1.5,true,10,5);
    nuevaCaja.getCodigoCliente();
}