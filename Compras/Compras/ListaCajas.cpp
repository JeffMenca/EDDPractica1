#include "ListaCajas.h"
#include "Caja.h"

ListaCajas::ListaCajas(Caja cajaIngresada)
{
	this->cajaIngresada=cajaIngresada;
}

//Metodos set
void ListaCajas::setCajaSiguiente(ListaCajas *cajaSiguiente)
{
	this->cajaSiguiente=cajaSiguiente;
}
void ListaCajas::setCaja(Caja caja)
{
	this->cajaIngresada=caja;
}
void ListaCajas::setCajaAnterior(ListaCajas *cajaAnterior)
{
	this->cajaAnterior=cajaAnterior;
}

//Metodos get
Caja ListaCajas::getCaja()
{
	return this->cajaIngresada;
}

ListaCajas* ListaCajas::getCajaSiguiente()
{
	return this->cajaSiguiente;
}

ListaCajas* ListaCajas::getCajaAnterior()
{
	return this->cajaAnterior;
}

