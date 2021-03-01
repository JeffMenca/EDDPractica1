#include "Cliente.h"
class ColaCarreta
{
private:
    Cliente clienteEsperando;
	ColaCarreta *clienteSiguiente;

public:
    ColaCarreta(Cliente);
	void setClienteSiguiente(ColaCarreta *clienteSiguiente);
	Cliente getClienteEsperando();
	ColaCarreta* getClienteSiguiente();
};