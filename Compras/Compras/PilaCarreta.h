#include "Carreta.h"
class PilaCarreta
{
private:
    Carreta carretaIngresada;
	PilaCarreta *carretaSiguiente;

public:
    PilaCarreta(Carreta);
	void setCarretaSiguiente(PilaCarreta *carretaSiguiente);
	Carreta getCarretaIngresada();
	PilaCarreta* getCarretaSiguiente();
};