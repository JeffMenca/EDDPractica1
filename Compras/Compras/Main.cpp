#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
#include <string> 
#include <fstream>
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
void agregarCarreta(Carreta); //Prototipo de pila de carretas 1
void agregarCarreta2(Carreta); //Prototipo de pila de carretas 2
Carreta sacarCarreta(); //Prototipo de sacar carreta
string mostrarCarreta(); //Prototipo de ver pila
string mostrarCarreta2(); //Prototipo de ver pila
void agregarColaCarreta(Cliente cliente); //Prototipo de agregar a cola carreta
Cliente sacarColaCarreta(); //Protitipo para sacar de cola carreta
string mostrarColaCarreta(); //Protitipo para mostrar de cola carreta
void agregarColaPagos(Cliente cliente,Carreta carreta); //Prototipo de agregar a cola pagos
ColaPagos sacarColaPagos(); //Protitipo para sacar de cola pagos
string mostrarColaPagos(); //Protitipo para mostrar de cola pagos
Cliente sacarListaCompras(int numeroRandom); //Prototipo para sacar de lista de compras
void agregarListaCompras (Cliente cliente,Carreta carreta); //Protitipo para agregar a lista de compras
string mostrarListaCompras(); //Prototipo para mopstrar la lista de compras
void agregarListaCajas (Caja caja); //Protitipo para agregar a lista de cajas
string mostrarListaCajas(); //Prototipo para mopstrar la lista de cajas
void pasarACaja ();//Prototipo para pasar a caja
void salirDeCaja ();//Prototipo para sacar de caja
void generarGrafica ();

PilaCarreta *pilaCarretas=NULL,*pilaCarretas2=NULL;
ColaCarreta *colaCarretaFrente=NULL,*colaCarretaFin=NULL;
ColaPagos *colaPagosFrente=NULL,*colaPagosFin=NULL;
ListaCompras *listaComprasInicio=NULL,*listaComprasFinal=NULL;
ListaCajas *listaCajasInicio=NULL,*listaCajasFinal=NULL;


int main()
{
	//Pilas y colas
	int cantidadCajas,cantidadCarretas,cantidadClientes,clientesTotales=1,tiempoServicio,paso=1,opcion=1;
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
		Caja nuevaCaja(i,tiempoServicio,tiempoServicio+1,true,NULL,NULL);
		agregarListaCajas(nuevaCaja);
	}
	cout<<""<<endl;
	system("pause");
	system("cls");
	//Numero de carretas del sistema
	cout<<""<<endl;
	cout<<"Ingrese el numero de carretas que tendra el supermercado por pila"<<endl;
	cin>>cantidadCarretas;
	int pila=1;
	for (int i = 1; i <= cantidadCarretas*2; i++)
	{
		Carreta nuevaCarreta(i);
		if (pila==1){
			agregarCarreta(nuevaCarreta);
			pila=0;
		}
		else{
			agregarCarreta2(nuevaCarreta);
			pila=1;
		}
	}
	cout<<""<<endl;
	system("pause");
	while(opcion!=0){
		//Clientes nuevos que ingresaran
		system("cls");
		cout<<""<<endl;
		cout<<"***Paso "<<paso<<"***"<<endl;
		cout<<""<<endl;
		cout<<"Cuantos clientes nuevos ingresaran"<<endl;
		cin>>cantidadClientes;
		for (int i = clientesTotales; i <clientesTotales+cantidadClientes; i++)
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
		pasarACaja();
		salirDeCaja();

		//Siguiente paso
		cout<<""<<endl;
		paso++;
		cout<<"Ingrese 1 para el siguiente paso, 2 para mostrar el grafico o 0 para terminar el proceso"<<endl;
		cin>>opcion;
		if (opcion==2)
		{
			generarGrafica();
		}
	}
	cout<<""<<endl;
	cout<<"---Simulacion terminada---"<<endl;
	_getch();
}

//Metodos para la pila de carretas
void agregarCarreta(Carreta carreta)
{
	PilaCarreta *nueva_carreta=new PilaCarreta(carreta);
	nueva_carreta->setCarretaSiguiente(pilaCarretas);
	pilaCarretas=nueva_carreta;
	cout<<""<<endl;
	cout<<"-La carreta con codigo "<<carreta.getNumeroCarreta()<<" fue agregada a la pila de carretas 1"<<endl;
}
void agregarCarreta2(Carreta carreta)
{
	PilaCarreta *nueva_carreta=new PilaCarreta(carreta);
	nueva_carreta->setCarretaSiguiente(pilaCarretas2);
	pilaCarretas2=nueva_carreta;
	cout<<""<<endl;
	cout<<"-La carreta con codigo "<<carreta.getNumeroCarreta()<<" fue agregada a la pila de carretas 2"<<endl;
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

string mostrarCarreta()
{
	Carreta carreta(0);
	string graficaPilaCarretas="",auxiliarGrafica="Pila1";
	if (pilaCarretas!=NULL)
	{
		PilaCarreta *aux=pilaCarretas;
		while(aux->getCarretaSiguiente() !=NULL)
		{
			carreta=aux->getCarretaIngresada();
			//cout<<carreta.getNumeroCarreta()<<",";
			graficaPilaCarretas+=auxiliarGrafica+"->"+"carreta"+std::to_string(carreta.getNumeroCarreta())+";\n";
			auxiliarGrafica="carreta"+std::to_string(carreta.getNumeroCarreta());
			aux=aux->getCarretaSiguiente();
		}
		carreta=aux->getCarretaIngresada();
		graficaPilaCarretas+=auxiliarGrafica+"->"+"carreta"+std::to_string(carreta.getNumeroCarreta())+";\n";
		//cout<<carreta.getNumeroCarreta()<<"."<<endl;
	}
	else{
		//cout<<""<<endl;
		//cout<<"-La pila de carretas esta vacia"<<endl;
	}
	return graficaPilaCarretas;
}

string mostrarCarreta2()
{
	Carreta carreta(0);
	string graficaPilaCarretas="",auxiliarGrafica="Pila2";
	if (pilaCarretas!=NULL)
	{
		PilaCarreta *aux=pilaCarretas2;
		while(aux->getCarretaSiguiente() !=NULL)
		{
			carreta=aux->getCarretaIngresada();
			//cout<<carreta.getNumeroCarreta()<<",";
			graficaPilaCarretas+=auxiliarGrafica+"->"+"carreta"+std::to_string(carreta.getNumeroCarreta())+";\n";
			auxiliarGrafica=+"carreta"+std::to_string(carreta.getNumeroCarreta());
			aux=aux->getCarretaSiguiente();
		}
		carreta=aux->getCarretaIngresada();
		graficaPilaCarretas+=auxiliarGrafica+"->"+"carreta"+std::to_string(carreta.getNumeroCarreta())+";\n";
		//cout<<carreta.getNumeroCarreta()<<"."<<endl;
	}
	else{
		//cout<<""<<endl;
		//cout<<"-La pila de carretas esta vacia"<<endl;
	}
	return graficaPilaCarretas;
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

string mostrarColaCarreta()
{
	string graficaColaCarretas="",auxiliarGrafica="ColaCarreta";
	Cliente cliente(0);
	if (colaCarretaFrente!=NULL)
	{
		ColaCarreta *aux=colaCarretaFrente;
		while(aux!=NULL)
		{
			cliente=aux->getClienteEsperando();
			graficaColaCarretas+=auxiliarGrafica+"->"+"ClienteColaCarreta"+std::to_string(cliente.getCodigoCliente())+";\n";
			auxiliarGrafica="ClienteColaCarreta"+std::to_string(cliente.getCodigoCliente());
			//cout<<cliente.getCodigoCliente() <<",";
			aux=aux->getClienteSiguiente();
		}
	}
	else{
		//cout<<""<<endl;
		//cout<<"-La fila de clientes esta vacia"<<endl;
	}
	return graficaColaCarretas;
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

string mostrarListaCompras()
{
	Cliente cliente(0);
	string graficaListaCompras="",auxiliarGrafica="ListaCompras";
	if (listaComprasInicio!=NULL)
	{
		ListaCompras *aux=listaComprasInicio;
		while(aux!=NULL)
		{
			cliente=aux->getClienteComprando();
			graficaListaCompras+=auxiliarGrafica+"->"+"ClienteListaCompras"+std::to_string(cliente.getCodigoCliente())+";\n";
			auxiliarGrafica="ClienteListaCompras"+std::to_string(cliente.getCodigoCliente());
			//cout<<cliente.getCodigoCliente() <<",";
			aux=aux->getCompradorSiguiente();
			if(aux==listaComprasInicio)
				break;
		}
	}
	else{
		//cout<<""<<endl;
		//cout<<"-La lista de compras esta vacia"<<endl;
	}
	return graficaListaCompras;
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

ColaPagos sacarColaPagos()
{
	Cliente cliente(0);
	Carreta carreta(0);
	if (colaPagosFrente!=NULL)
	{
		cliente=colaPagosFrente->getClientePagando();
		carreta=colaPagosFrente->getCarretaCliente();
		ColaPagos *aux=colaPagosFrente;
		if (colaPagosFrente==colaPagosFin)
		{
			colaPagosFrente=NULL;
			colaPagosFin=NULL;
		}
		else
			colaPagosFrente=colaPagosFrente->getClienteSiguiente();
		ColaPagos datos(cliente,carreta);
		delete aux;
		return datos;
	}
	else{
		cliente.setCodigoCliente(NULL);
		carreta.setNumeroCarreta(NULL);
		ColaPagos datos(cliente,carreta);
		return datos;
	}
}

string mostrarColaPagos()
{
	string graficaColaPagos="",auxiliarGrafica="ColaPagos";
	Cliente cliente(0);
	if (colaPagosFrente!=NULL)
	{
		ColaPagos *aux=colaPagosFrente;
		while(aux!=NULL)
		{
			cliente=aux->getClientePagando();
			graficaColaPagos+=auxiliarGrafica+"->"+"ClienteColaPagos"+std::to_string(cliente.getCodigoCliente())+";\n";
			auxiliarGrafica="ClienteColaPagos"+std::to_string(cliente.getCodigoCliente());
			//cout<<cliente.getCodigoCliente() <<",";
			aux=aux->getClienteSiguiente();
		}
	}
	else{
		//cout<<""<<endl;
		//cout<<"-La fila de clientes esta vacia"<<endl;
	}
	return graficaColaPagos;
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

string mostrarListaCajas()
{
	Caja caja;
	string graficaListaCajas="",auxiliarGrafica="ListaCajas";
	if (listaCajasInicio!=NULL)
	{
		ListaCajas *aux=listaCajasInicio;
		while(aux!=NULL)
		{
			caja=aux->getCaja();
			graficaListaCajas.append("\""+auxiliarGrafica+"->Caja" + std::to_string(caja.getNumeroCaja()) 
				+"\nLibre?: "+std::to_string(caja.getEstadoLibre())+"\nCliente: "+std::to_string(caja.getCodigoCliente())
				+"\nCarreta: "+std::to_string(caja.getCodigoCarreta())+ "\"");
			//cout<<cliente.getCodigoCliente() <<",";
			aux=aux->getCajaSiguiente();
			if(aux==listaCajasInicio)
				break;
		}
	}
	else{
		//cout<<""<<endl;
		//cout<<"-La lista de compras esta vacia"<<endl;
	}
	return graficaListaCajas;
}

void pasarACaja ()
{
	Caja caja;
	bool disponible=false;
	if (listaCajasInicio!=NULL)
	{
		ListaCajas *aux=listaCajasInicio;
		while(aux!=NULL)
		{ 
			caja=aux->getCaja();
			if (caja.getEstadoLibre()==true)
			{
				ColaPagos cola=sacarColaPagos();
				Cliente cliente=cola.getClientePagando();
				Carreta carreta=cola.getCarretaCliente();
				if (cliente.getCodigoCliente()!=NULL)
				{
					caja.setEstadoLibre(false);
					caja.setCodigoCliente(cliente.getCodigoCliente());
					caja.setCodigoCarreta(carreta.getNumeroCarreta());
					aux->setCaja(caja);
					cout<<""<<endl;
					cout<<"-El cliente "<<cliente.getCodigoCliente()<<" esta pagando en la caja numero "<<caja.getNumeroCaja() <<endl;
					disponible=true;
					break;
				}
				else{
					cout<<""<<endl;
					cout<<"-No hay nadie en la cola de pagos"<<endl;
					disponible=true;
					break;
				}
			}
			else
				cout<<endl;
			aux=aux->getCajaSiguiente();
		}
		if (disponible==false)
		{
			cout<<""<<endl;
			cout<<"-No existen cajas disponibles en este momento"<<endl;
		}
	}
	else{
		cout<<""<<endl;
		cout<<"-No existen cajas"<<endl;
	}
}
void salirDeCaja ()
{
	Caja caja;
	if (listaCajasInicio!=NULL)
	{
		ListaCajas *aux=listaCajasInicio;
		while(aux!=NULL)
		{ 
			caja=aux->getCaja();
			if (caja.getEstadoLibre()==false)
			{
				Cliente cliente(caja.getCodigoCliente());
				Carreta carreta=(caja.getCodigoCarreta());
				caja.setTiempoRestante(caja.getTiempoRestante()-1);
				if (caja.getTiempoRestante()==0)
				{
					caja.setTiempoRestante(caja.getTiempoServicio()+1);
					caja.setCodigoCarreta(NULL);
					caja.setCodigoCliente(NULL);
					caja.setEstadoLibre(true);
					cout<<""<<endl;
					cout<<"-El cliente "<<cliente.getCodigoCliente()<<" termino de comprar y devolvera la carreta con codigo "
						<<carreta.getNumeroCarreta()<<endl;
					Carreta nuevaCarreta(carreta.getNumeroCarreta());
					int numeroRandom=rand()%2;
					if (numeroRandom==0)
						agregarCarreta(nuevaCarreta);
					else
						agregarCarreta2(nuevaCarreta);
				}
				aux->setCaja(caja);
			}
			aux=aux->getCajaSiguiente();
		}
	}
}


void generarGrafica () 
{
	cout<<""<<endl;
	cout<<"---Se genero el grafico---"<<endl;
	cout<<""<<endl;
	system("pause");

	string pila1=mostrarCarreta();
	string pila2=mostrarCarreta2();
	string colaCarreta=mostrarColaCarreta();
	string listaCompras=mostrarListaCompras();
	string colaPagos=mostrarColaPagos();
	string listaCajas=mostrarListaCajas();
	ofstream file("archivo.dot");
	file << "digraph G {\n";

	file << "subgraph cluster_0 {\n";
	file << "style=filled;\n";
	file << "color=lightgrey;\n";
	file << "node [style=filled,color=white];\n";
	file << pila1;
	file << "label = \" Pila 1 \";\n";
	file << "}\n";

	file << "subgraph cluster_1 {\n";
	file << "style=filled;\n";
	file << "color=lightgrey;\n";
	file << "node [style=filled,color=white];\n";
	file << pila2;
	file << "label = \" Pila 2 \";\n";
	file << "}\n";

	file << "subgraph cluster_2 {\n";
	file << "style=filled;\n";
	file << "color=lightgrey;\n";
	file << "node [style=filled,color=white];\n";
	file << colaCarreta;
	file << "label = \" Cola de carreta \";\n";
	file << "}\n";

	file << "subgraph cluster_3 {\n";
	file << "style=filled;\n";
	file << "color=lightgrey;\n";
	file << "node [style=filled,color=white];\n";
	file << listaCompras;
	file << "label = \" Lista de compras \";\n";
	file << "}\n";

	file << "subgraph cluster_4 {\n";
	file << "style=filled;\n";
	file << "color=lightgrey;\n";
	file << "node [style=filled,color=white];\n";
	file << colaPagos;
	file << "label = \" Cola de pagos \";\n";
	file << "}\n";

	file << "subgraph cluster_5 {\n";
	file << "style=filled;\n";
	file << "color=lightgrey;\n";
	file << "node [style=filled,color=white];\n";
	file << listaCajas;
	file << "label = \" Lista de cajas \";\n";
	file << "}\n";

	file << "}\n";
	file.close();
	system("dot -Tpng archivo.dot -o imagen.png");
	ifstream image("imagen.png");
	_getch();
}


