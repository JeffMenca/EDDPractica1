#include "PilaCarreta.h"
#include "Carreta.h"


PilaCarreta::PilaCarreta(Carreta carretaIngresada)
{
	this->carretaIngresada = carretaIngresada;
}

//Metodos set
void PilaCarreta::setCarretaSiguiente(PilaCarreta *carretaSiguiente)
{
	this->carretaSiguiente=carretaSiguiente;
}
//Metodos get
Carreta PilaCarreta::getCarretaIngresada()
{
	return this->carretaIngresada;
}

PilaCarreta* PilaCarreta::getCarretaSiguiente()
{
	return this->carretaSiguiente;
}

