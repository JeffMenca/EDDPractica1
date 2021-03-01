#include "Caja.h"

//Constructor
Caja::Caja(int numeroCaja, double tiempoServicio, bool estadoLibre, int codigoCliente, int codigoCarreta)
{
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
    this->estadoLibre = estadoLibre;
    this->codigoCliente = codigoCliente;
    this->codigoCarreta = codigoCarreta;
}

//Metodos get
int Caja::getNumeroCaja()
{
	return numeroCaja;
}
double Caja::getTiempoServicio()
{
	return tiempoServicio;
}
bool Caja::getEstadoLibre()
{
	return estadoLibre;
}
int Caja::getCodigoCliente()
{
	return codigoCliente;
}
int Caja::getCodigoCarreta()
{
	return codigoCarreta;
}

//Metodos set
void Caja::setNumeroCaja(int numeroCaja)
{
	this->numeroCaja = numeroCaja;
}
void Caja::setTiempoServicio(double tiempoServicio)
{
	this->tiempoServicio = tiempoServicio;
}
void Caja::setEstadoLibre(bool estadoLibre)
{
	this->estadoLibre = estadoLibre;
}
void Caja::setCodigoCliente(int codigoCliente)
{
	this->codigoCliente = codigoCliente;
}
void Caja::setCodigoCarreta(int codigoCarreta)
{
	this->codigoCarreta = codigoCarreta;
}