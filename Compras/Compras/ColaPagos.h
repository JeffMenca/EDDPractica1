#include "Carreta.h"
#include "Cliente.h"
class ColaPagos
{
private:
	Cliente clientePagando;
	Carreta carretaCliente;
	ColaPagos *clienteSiguiente;

public:
	ColaPagos(Cliente,Carreta);
	void setClienteSiguiente(ColaPagos *clienteSiguiente);
	Cliente getClientePagando();
	Carreta getCarretaCliente();
	ColaPagos* getClienteSiguiente();
};