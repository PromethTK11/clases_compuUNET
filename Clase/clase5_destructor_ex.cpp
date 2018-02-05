//Clase 05-02-2018 Funciones constructoras y destructoras ejemplo

#include <iostream>
#include <string>
#include <conio>

using namespace std;

class producto {
	public :
		producto();					//Funcion constructora
		producto (float, char *);	//Funcion constructora 2 se diferencian en parametros
		void mostrar();				//Se invocan por si solas
		~producto();				//Funcion destructora
	private :
		float precio;
		char nombre[12];		
};

//Diseño de las funciones constructoras

producto::producto() {
	cout << "Nombre del producto:" << endl;
	cin.getline(nombre,12);
	cout << "Precio del producto:" << endl;
	cin >> precio;
}

producto::producto(float px, char *nx) {
	precio = px;
	strcpy(nombre, nx);
}

//Diseño de métodos mostrar

void producto::mostrar(){
	cout << nombre << "\t" << precio << endl;
}

//Diseño de la funcion destructora

producto::~producto() {
	cout << "Destruyendo el objeto en memoria..." << endl;
	getch();
}

//Cuerpo principal

void main()
{
	producto supermercado[6], bodega(95.15,"azucar");
	cout << "Listado de productos procesados:" << endl;
	cout << "Nombre \t Precio" << endl;
	for (int k=0;k<6;k++)
		supermercado[k].mostrar();
	bodega.mostrar();
	getch();
}
