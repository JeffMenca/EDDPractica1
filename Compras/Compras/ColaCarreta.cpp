#include "ColaCarreta.h"
#include "Cliente.h"


ColaCarreta::ColaCarreta(Cliente clienteEsperando)
{
	this->clienteEsperando = clienteEsperando;
}

//Metodos set
void ColaCarreta::setClienteSiguiente(ColaCarreta *clienteSiguiente)
{
	this->clienteSiguiente=clienteSiguiente;
}
//Metodos get
Cliente ColaCarreta::getClienteEsperando()
{
	return this->clienteEsperando;
}

ColaCarreta* ColaCarreta::getClienteSiguiente()
{
	return this->clienteSiguiente;
}

