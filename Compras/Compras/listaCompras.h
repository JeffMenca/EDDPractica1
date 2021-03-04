#include "Carreta.h"
#include "Cliente.h"
class ListaCompras
{
private:
	Cliente clienteComprando;
    Carreta carretaCliente;
	ListaCompras *compradorSiguiente;

public:
    ListaCompras(Cliente,Carreta);
	void setCompradorSiguiente(ListaCompras *compradorSiguiente);
	Carreta getCarretaCliente();
	Cliente getClienteComprando();
	ListaCompras* getCompradorSiguiente();
};