#include "Caja.h"

//Constructor
Caja::Caja(int numeroCaja, int tiempoServicio,int tiempoRestante, bool estadoLibre, int codigoCliente, int codigoCarreta)
{
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
	this->tiempoRestante=tiempoRestante;
    this->estadoLibre = estadoLibre;
    this->codigoCliente = codigoCliente;
    this->codigoCarreta = codigoCarreta;
}
Caja::Caja()
{
}

//Metodos get
int Caja::getNumeroCaja()
{
	return numeroCaja;
}
int Caja::getTiempoServicio()
{
	return tiempoServicio;
}
int Caja::getTiempoRestante()
{
	return tiempoRestante;
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
void Caja::setTiempoServicio(int tiempoServicio)
{
	this->tiempoServicio = tiempoServicio;
}
void Caja::setTiempoRestante(int tiempoRestante)
{
	this->tiempoRestante = tiempoRestante;
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