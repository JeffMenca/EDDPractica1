#include "Carreta.h"
#include <iostream>
using namespace std;


Carreta::Carreta(int numeroCarreta)
{
	this->numeroCarreta = numeroCarreta;
}
Carreta::Carreta()
{
}

//Metodos get
int Carreta::getNumeroCarreta()
{
	return numeroCarreta;
}
//Metodos set
void Carreta::setNumeroCarreta(int numeroCarreta)
{
	this->numeroCarreta = numeroCarreta;
}