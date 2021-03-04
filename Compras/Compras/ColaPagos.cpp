#include "ColaPagos.h"
#include "Cliente.h"
#include "Carreta.h"


ColaPagos::ColaPagos(Cliente clientePagando,Carreta carretaCliente)
{
	this->clientePagando = clientePagando;
	this->carretaCliente=carretaCliente;
}

//Metodos set
void ColaPagos::setClienteSiguiente(ColaPagos *clienteSiguiente)
{
	this->clienteSiguiente=clienteSiguiente;
}
//Metodos get
Cliente ColaPagos::getClientePagando()
{
	return this->clientePagando;
}
Carreta ColaPagos::getCarretaCliente()
{
	return this->carretaCliente;
}

ColaPagos* ColaPagos::getClienteSiguiente()
{
	return this->clienteSiguiente;
}

