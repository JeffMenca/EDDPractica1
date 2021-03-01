#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include "Caja.h"
#include "Carreta.h"
#include "PilaCarreta.h"
#include "ColaCarreta.h"
#include "Cliente.h"
using namespace std;

//Prototipos
void agregarCarreta(PilaCarreta *&,Carreta); //Prototipo de pila de carretas
void sacarCarreta(PilaCarreta *&,Carreta &); //Prototipo de sacar carreta
void mostrarCarreta(PilaCarreta *&,Carreta &); //Prototipo de ver pila
void agregarColaCarreta(ColaCarreta *&frente,ColaCarreta *&fin,Cliente cliente); //Prototipo de agregar a cola carreta
void sacarColaCarreta(ColaCarreta *&frente,ColaCarreta *&fin,Cliente cliente); //Protitipo para sacar de cola carreta
void mostrarColaCarreta(ColaCarreta *&frente,ColaCarreta *&fin,Cliente cliente); //Protitipo para mostrar de cola carreta

int main()
{
	PilaCarreta *pilaCarretas=NULL;
	ColaCarreta *colaCarretaFrente=NULL;
	ColaCarreta *colaCarretaFin=NULL;

	Carreta nuevaCarreta(1);
	Cliente nuevoCliente(10);


	agregarColaCarreta(colaCarretaFrente,colaCarretaFin,nuevoCliente);
	nuevoCliente.setCodigoCliente(20);
	agregarColaCarreta(colaCarretaFrente,colaCarretaFin,nuevoCliente);
	sacarColaCarreta(colaCarretaFrente,colaCarretaFin,nuevoCliente);
	mostrarColaCarreta(colaCarretaFrente,colaCarretaFin,nuevoCliente);

	//sacarCarreta(pilaCarretas,nuevaCarreta);
	//mostrarCarreta(pilaCarretas,nuevaCarreta);
	_getch();
}

void agregarCarreta(PilaCarreta *&pilaCarretas,Carreta carreta)
{
	PilaCarreta *nueva_carreta=new PilaCarreta(carreta);
	nueva_carreta->setCarretaSiguiente(pilaCarretas);
	pilaCarretas=nueva_carreta;
	cout<<"La carreta con codigo "<<carreta.getNumeroCarreta()<<" fue agregada a la pila de carretas"<<endl;
}

void sacarCarreta(PilaCarreta *&pilaCarretas,Carreta &carreta)
{
	PilaCarreta *aux=pilaCarretas;
	if (pilaCarretas!=NULL)
	{
		carreta=aux->getCarretaIngresada();
		pilaCarretas=aux->getCarretaSiguiente();
		delete aux;
		cout<<"La carreta con codigo "<<carreta.getNumeroCarreta()<<" salio de la pila de carretas"<<endl;
	}
	else{
		cout<<"La pila de carretas esta vacia"<<endl;
	}
}

void mostrarCarreta(PilaCarreta *&pilaCarretas,Carreta &carreta)
{
	if (pilaCarretas!=NULL)
	{
		PilaCarreta *aux=pilaCarretas;
		while(aux->getCarretaSiguiente() !=NULL)
		{
			carreta=aux->getCarretaIngresada();
			cout<<carreta.getNumeroCarreta()<<",";
			aux=aux->getCarretaSiguiente();
		}
		carreta=aux->getCarretaIngresada();
		cout<<carreta.getNumeroCarreta()<<".";
	}
	else{
		cout<<"La pila de carretas esta vacia"<<endl;
	}
}

void agregarColaCarreta(ColaCarreta *&frente,ColaCarreta *&fin,Cliente cliente)
{
	ColaCarreta *nuevo_cliente=new ColaCarreta(cliente);
	nuevo_cliente->setClienteSiguiente(NULL);
	if (frente==NULL)
		frente=nuevo_cliente;
	else
		fin->setClienteSiguiente(nuevo_cliente);
	fin=nuevo_cliente;
	cout<<"El cliente con codigo "<<cliente.getCodigoCliente()<<" se unio a la cola de carretas"<<endl;
}

void sacarColaCarreta(ColaCarreta *&frente,ColaCarreta *&fin,Cliente cliente)
{
	if (frente!=NULL)
	{
		cliente=frente->getClienteEsperando();
		ColaCarreta *aux=frente;
		if (frente==fin)
		{
			frente=NULL;
			fin=NULL;
		}
		else
			frente=frente->getClienteSiguiente();
		delete aux;
		cout<<"El cliente con codigo "<<cliente.getCodigoCliente()<<" salio de la cola de carretas"<<endl;
	}
	else{
		cout<<"La fila de clientes esta vacia"<<endl;
	}
}

void mostrarColaCarreta(ColaCarreta *&frente,ColaCarreta *&fin,Cliente cliente)
{
	if (frente!=NULL)
	{
		ColaCarreta *aux=frente;
		while(aux!=NULL)
		{
			cliente=aux->getClienteEsperando();
			cout<<cliente.getCodigoCliente() <<",";
			aux=aux->getClienteSiguiente();
		}
	}
	else{
		cout<<"La fila de clientes esta vacia"<<endl;
	}
}
