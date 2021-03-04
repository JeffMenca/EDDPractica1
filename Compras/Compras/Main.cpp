#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
#include "Caja.h"
#include "Carreta.h"
#include "PilaCarreta.h"
#include "ColaCarreta.h"
#include "ColaPagos.h"
#include "Cliente.h"
#include "listaCompras.h"
#include "listaCajas.h"

using namespace std;

//Prototipos
void agregarCarreta(Carreta); //Prototipo de pila de carretas
Carreta sacarCarreta(); //Prototipo de sacar carreta
void mostrarCarreta(); //Prototipo de ver pila
void agregarColaCarreta(Cliente cliente); //Prototipo de agregar a cola carreta
Cliente sacarColaCarreta(); //Protitipo para sacar de cola carreta
void mostrarColaCarreta(); //Protitipo para mostrar de cola carreta
void agregarColaPagos(Cliente cliente,Carreta carreta); //Prototipo de agregar a cola pagos
Cliente sacarColaPagos(); //Protitipo para sacar de cola pagos
void mostrarColaPagos(); //Protitipo para mostrar de cola pagos
Cliente sacarListaCompras(int numeroRandom); //Prototipo para sacar de lista de compras
void agregarListaCompras (Cliente cliente,Carreta carreta); //Protitipo para agregar a lista de compras
void mostrarListaCompras(); //Prototipo para mopstrar la lista de compras
void agregarListaCajas (Caja caja); //Protitipo para agregar a lista de cajas
void mostrarListaCajas(); //Prototipo para mopstrar la lista de cajas

PilaCarreta *pilaCarretas=NULL,*pilaCarretas2=NULL;
ColaCarreta *colaCarretaFrente=NULL,*colaCarretaFin=NULL;
ColaPagos *colaPagosFrente=NULL,*colaPagosFin=NULL;
ListaCompras *listaComprasInicio=NULL,*listaComprasFinal=NULL;
ListaCajas *listaCajasInicio=NULL,*listaCajasFinal=NULL;


int main()
{
	//Pilas y colas
	int cantidadCajas,cantidadCarretas,cantidadClientes,clientesTotales=1,tiempoServicio;
	srand((unsigned)time(NULL));
	cout<<"---SIMULACION DE COMPRAS---"<<endl;
	cout<<""<<endl;
	cout<<"--Ingrese los datos para la simulacion--"<<endl;
	cout<<""<<endl;
	//Numero de cajas del sistema
	cout<<"Ingrese el numero de cajas que tendra el supermercado"<<endl;
	cin>>cantidadCajas;
	cout<<"Ingrese el tiempo de servicio (pasos) de las cajas del supermercado"<<endl;
	cin>>tiempoServicio;
	for (int i = 1; i <= cantidadCajas; i++)
	{
		Caja nuevaCaja(i,tiempoServicio,tiempoServicio,true,NULL,NULL);
		agregarListaCajas(nuevaCaja);
	}
	mostrarListaCajas();
	//Numero de carretas del sistema
	cout<<""<<endl;
	cout<<"Ingrese el numero de carretas que tendra el supermercado"<<endl;
	cin>>cantidadCarretas;
	for (int i = 1; i <= cantidadCarretas; i++)
	{
		Carreta nuevaCarreta(i);
		int numeroRandom=rand()%2;
		if (numeroRandom==0)
			agregarCarreta(nuevaCarreta);
		else
			agregarCarreta(nuevaCarreta);
	}
	//Clientes nuevos que ingresaran
	cout<<""<<endl;
	cout<<"Cuantos clientes nuevos ingresaran"<<endl;
	cin>>cantidadClientes;
	for (int i = clientesTotales; i <=cantidadClientes; i++)
	{
		Cliente nuevoCliente(i);
		agregarColaCarreta(nuevoCliente);
	}
	clientesTotales+=cantidadClientes;



	//Cliente sale de la fila y obtiene carreta
	Carreta carreta=sacarCarreta();
	//Clientes comprando y pagando
	int numeroRandom=rand()%101; //Generar numero random
	sacarListaCompras(numeroRandom);


	_getch();
}

//Metodos para la pila de carretas
void agregarCarreta(Carreta carreta)
{
	PilaCarreta *nueva_carreta=new PilaCarreta(carreta);
	nueva_carreta->setCarretaSiguiente(pilaCarretas);
	pilaCarretas=nueva_carreta;
	cout<<""<<endl;
	cout<<"-La carreta con codigo "<<carreta.getNumeroCarreta()<<" fue agregada a la pila de carretas"<<endl;
}

Carreta sacarCarreta()
{
	Carreta carreta(0);
	if (pilaCarretas!=NULL)
	{
		PilaCarreta *aux=pilaCarretas;
		carreta=aux->getCarretaIngresada();
		pilaCarretas=aux->getCarretaSiguiente();
		delete aux;
		Cliente cliente=sacarColaCarreta();
		if (cliente.getCodigoCliente()!=NULL)
		{
			cout<<""<<endl;
			cout<<"-El cliente con codigo "<<cliente.getCodigoCliente()<<" salio de la cola tomando la carreta con codigo "<<
				carreta.getNumeroCarreta()<<" de la pila 1"<<endl;
			agregarListaCompras(cliente,carreta);
		}
		return carreta;
	}
	else if (pilaCarretas2!=NULL){
		PilaCarreta *aux=pilaCarretas2;
		carreta=aux->getCarretaIngresada();
		pilaCarretas2=aux->getCarretaSiguiente();
		delete aux;
		Cliente cliente=sacarColaCarreta();
		if (cliente.getCodigoCliente()!=NULL)
		{
			cout<<""<<endl;
			cout<<"-El cliente con codigo "<<cliente.getCodigoCliente()<<" salio de la cola tomando la carreta con codigo "<<
				carreta.getNumeroCarreta()<<" de la pila 2"<<endl;
			agregarListaCompras(cliente,carreta);
		}
		return carreta;
	}
	else{
		cout<<""<<endl;
		cout<<"-La pila de carretas esta vacia"<<endl;
		return NULL;
	}
}

void mostrarCarreta()
{
	Carreta carreta(0);
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
		cout<<carreta.getNumeroCarreta()<<"."<<endl;
	}
	else{
		cout<<""<<endl;
		cout<<"-La pila de carretas esta vacia"<<endl;
	}
}

//Metodo para la cola de carretas
void agregarColaCarreta(Cliente cliente)
{
	ColaCarreta *nuevo_cliente=new ColaCarreta(cliente);
	nuevo_cliente->setClienteSiguiente(NULL);
	if (colaCarretaFrente==NULL)
		colaCarretaFrente=nuevo_cliente;
	else
		colaCarretaFin->setClienteSiguiente(nuevo_cliente);
	colaCarretaFin=nuevo_cliente;
	cout<<""<<endl;
	cout<<"-El cliente con codigo "<<cliente.getCodigoCliente()<<" se unio a la cola de carretas"<<endl;
}

Cliente sacarColaCarreta()
{
	Cliente cliente(0);
	if (colaCarretaFrente!=NULL)
	{
		cliente=colaCarretaFrente->getClienteEsperando();
		ColaCarreta *aux=colaCarretaFrente;
		if (colaCarretaFrente==colaCarretaFin)
		{
			colaCarretaFrente=NULL;
			colaCarretaFin=NULL;
		}
		else
			colaCarretaFrente=colaCarretaFrente->getClienteSiguiente();
		delete aux;
		//cout<<"-El cliente con codigo "<<cliente.getCodigoCliente()<<" salio de la cola de carretas"<<endl;
		return cliente;
	}
	else{
		cout<<""<<endl;
		cout<<"-La fila de clientes esta vacia"<<endl;
		cliente.setCodigoCliente(NULL);
		return cliente;
	}
}

void mostrarColaCarreta()
{
	Cliente cliente(0);
	if (colaCarretaFrente!=NULL)
	{
		ColaCarreta *aux=colaCarretaFrente;
		while(aux!=NULL)
		{
			cliente=aux->getClienteEsperando();
			cout<<cliente.getCodigoCliente() <<",";
			aux=aux->getClienteSiguiente();
		}
	}
	else{
		cout<<""<<endl;
		cout<<"-La fila de clientes esta vacia"<<endl;
	}
}

//Metodos para la lista de compras
void agregarListaCompras (Cliente cliente,Carreta carreta)
{
	ListaCompras *nueva_listaCompras=new ListaCompras(cliente,carreta);
	nueva_listaCompras->setCompradorSiguiente(NULL);
	if (listaComprasInicio==NULL)
		listaComprasInicio=nueva_listaCompras;
	else
		listaComprasFinal->setCompradorSiguiente(nueva_listaCompras);
	listaComprasFinal=nueva_listaCompras;
	listaComprasFinal->setCompradorSiguiente(listaComprasInicio);
	cout<<""<<endl;
	cout<<"-El cliente con codigo "<<cliente.getCodigoCliente()<<" esta comprando con la carreta "<<carreta.getNumeroCarreta()<<endl;
}

Cliente sacarListaCompras(int numeroRandom)
{
	Cliente cliente(0);
	Carreta carreta(0);
	if (listaComprasInicio!=NULL)
	{
		cliente=listaComprasInicio->getClienteComprando();
		ListaCompras *aux=listaComprasInicio;
		ListaCompras *aux2=listaComprasInicio;
		ListaCompras *anterior=listaComprasInicio;
		while(aux2!=NULL){
			ListaCompras *aux3=aux2->getCompradorSiguiente();
			Cliente cliente=aux3->getClienteComprando();
			if (cliente.getCodigoCliente()==numeroRandom)
			{
				anterior=aux2;
				Cliente cliente=anterior->getClienteComprando();
				break;
			}	
			else
				aux2=aux2->getCompradorSiguiente();
			if(aux2==listaComprasInicio)
				break;
		}

		while(aux!=NULL)
		{
			Cliente cliente=aux->getClienteComprando();
			Carreta carreta=aux->getCarretaCliente();
			if (cliente.getCodigoCliente()==numeroRandom)
			{
				if (listaComprasInicio==listaComprasFinal)
				{
					listaComprasInicio=NULL;
					listaComprasFinal=NULL;
				}
				else
				{
					anterior->setCompradorSiguiente(aux->getCompradorSiguiente());
				}
				if(aux==listaComprasInicio)
					listaComprasInicio=listaComprasInicio->getCompradorSiguiente();
				agregarColaPagos(cliente,carreta);
				delete aux;
				return cliente;
			}
			else
				aux=aux->getCompradorSiguiente();
			if(aux==listaComprasInicio)
				break;
		}
		cout<<""<<endl;
		cout<<"-Ningun cliente ha terminado de comprar"<<endl;

	}
	else{
		cout<<""<<endl;
		cout<<"-No hay nadie comprando"<<endl;
		return NULL;
	}
}

void mostrarListaCompras()
{
	Cliente cliente(0);
	if (listaComprasInicio!=NULL)
	{
		ListaCompras *aux=listaComprasInicio;
		while(aux!=NULL)
		{
			cliente=aux->getClienteComprando();
			cout<<cliente.getCodigoCliente() <<",";
			aux=aux->getCompradorSiguiente();
			if(aux==listaComprasInicio)
				break;
		}
	}
	else{
		cout<<""<<endl;
		cout<<"-La lista de compras esta vacia"<<endl;
	}
}

//Metodo para la cola de pagos
void agregarColaPagos(Cliente cliente,Carreta carreta)
{
	ColaPagos *nuevo_cliente=new ColaPagos(cliente,carreta);
	nuevo_cliente->setClienteSiguiente(NULL);
	if (colaPagosFrente==NULL)
		colaPagosFrente=nuevo_cliente;
	else
		colaPagosFin->setClienteSiguiente(nuevo_cliente);
	colaPagosFin=nuevo_cliente;
	cout<<""<<endl;
	cout<<"-El cliente con codigo "<<cliente.getCodigoCliente()<<" termino de comprar y se unio a la cola de pagos"<<endl;
}

Cliente sacarColaPagos()
{
	Cliente cliente(0);
	if (colaPagosFrente!=NULL)
	{
		cliente=colaPagosFrente->getClientePagando();
		ColaPagos *aux=colaPagosFrente;
		if (colaPagosFrente==colaPagosFin)
		{
			colaPagosFrente=NULL;
			colaPagosFin=NULL;
		}
		else
			colaPagosFrente=colaPagosFrente->getClienteSiguiente();
		delete aux;
		//cout<<"-El cliente con codigo "<<cliente.getCodigoCliente()<<" salio de la cola de carretas"<<endl;
		return cliente;
	}
	else{
		cout<<""<<endl;
		cout<<"-La fila de pagos esta vacia"<<endl;
		cliente.setCodigoCliente(NULL);
		return cliente;
	}
}

void mostrarColaPagos()
{
	Cliente cliente(0);
	if (colaPagosFrente!=NULL)
	{
		ColaPagos *aux=colaPagosFrente;
		while(aux!=NULL)
		{
			cliente=aux->getClientePagando();
			cout<<cliente.getCodigoCliente() <<",";
			aux=aux->getClienteSiguiente();
		}
	}
	else{
		cout<<""<<endl;
		cout<<"-La fila de pagos esta vacia"<<endl;
	}
}

void agregarListaCajas (Caja caja)
{
	ListaCajas *nueva_listaCajas=new ListaCajas(caja);
	nueva_listaCajas->setCajaSiguiente(NULL);
	nueva_listaCajas->setCajaAnterior(NULL);
	if (listaCajasInicio==NULL)
		listaCajasInicio=nueva_listaCajas;
	else
		listaCajasFinal->setCajaSiguiente(nueva_listaCajas);
	ListaCajas *listaCajasAux=listaCajasFinal;
	listaCajasFinal=nueva_listaCajas;
	listaCajasFinal->setCajaAnterior(listaCajasAux);
	cout<<""<<endl;
	cout<<"-Se agrego una caja con numero "<<caja.getNumeroCaja()<<endl;
}

void mostrarListaCajas()
{
	Caja caja;
	if (listaCajasInicio!=NULL)
	{
		ListaCajas *aux=listaCajasInicio;
		while(aux!=NULL)
		{
			caja=aux->getCaja();
			cout<<caja.getNumeroCaja() <<" con anterior-> ";
			if (aux!=listaCajasInicio)
			{
				ListaCajas *aux2=aux->getCajaAnterior();
				caja=aux2->getCaja();
				cout<<caja.getNumeroCaja()<<endl;
			}
			else
				cout<<endl;
			aux=aux->getCajaSiguiente();
		}
	}
	else{
		cout<<""<<endl;
		cout<<"-La lista de compras esta vacia"<<endl;
	}
}


