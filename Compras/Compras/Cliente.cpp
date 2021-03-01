#include "Cliente.h"
#include <iostream>

Cliente::Cliente(int codigoCliente)
{
	this->codigoCliente = codigoCliente;
}
Cliente::Cliente()
{
}

//Metodos get
int Cliente::getCodigoCliente()
{
	return codigoCliente;
}
//Metodos set
void Cliente::setCodigoCliente(int codigoCliente)
{
	this->codigoCliente = codigoCliente;
}