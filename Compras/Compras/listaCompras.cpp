#include "listaCompras.h"
#include "PilaCarreta.h"
#include "Carreta.h"
#include "Cliente.h"


ListaCompras::ListaCompras(Cliente clienteComprando,Carreta carretaCliente)
{
	this->clienteComprando=clienteComprando;
	this->carretaCliente=carretaCliente;
}

//Metodos set
void ListaCompras::setCompradorSiguiente(ListaCompras *compradorSiguiente)
{
	this->compradorSiguiente=compradorSiguiente;
}
//Metodos get
Carreta ListaCompras::getCarretaCliente()
{
	return this->carretaCliente;
}

Cliente ListaCompras::getClienteComprando()
{
	return this->clienteComprando;
}

ListaCompras* ListaCompras::getCompradorSiguiente()
{
	return this->compradorSiguiente;
}

