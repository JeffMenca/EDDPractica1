#include "Caja.h"
class ListaCajas
{
private:
	Caja cajaIngresada;
	ListaCajas *cajaSiguiente;
	ListaCajas *cajaAnterior;

public:
    ListaCajas(Caja);
	void setCajaSiguiente(ListaCajas *cajaSiguiente);
	void setCajaAnterior(ListaCajas *cajaAnterior);
	Caja getCaja();
	ListaCajas* getCajaSiguiente();
	ListaCajas* getCajaAnterior();
};