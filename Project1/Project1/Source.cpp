#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
#include <fstream>
using namespace std;

int main () 
{
	cout<<"---Prueba Graphviz---"<<endl;

	ofstream file("archivo.dot");
	file << "digraph G {\n";
	file << "padre -> hijo;\n";
	file << "padre -> hija;\n";
	file << "}\n";
	file.close();
	system("dot -Tpng archivo.dot -o imagen.png");
	//system("nohup display imagen.png &" );
	_getch();
}