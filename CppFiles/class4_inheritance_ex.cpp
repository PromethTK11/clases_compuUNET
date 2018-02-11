//Ejemplo clase 02-02-18 Herencia multiple

#include <iostream>
#include <ctype.h>
#include <conio.h>

using namespace std;

//CLASES

class TARJETA{
	public:
		void leer();
		void mostrar();
	private:
		char cpu[10];
		float velocidad;
};

class MONITOR{
	public:
		void leer();
		void mostrar();
	private:
		char marca[10];
		char resolucion[12];
};

class COMPUTADORA:public TARJETA, public MONITOR{
	public:
		void leer();
		void mostrar();
	private:
		float precio;		
};

//Diseño de los metodos tarjeta
void TARJETA::leer(){
	cout << "-Datos de la tarjeta-" <<endl;
	cout << "CPU:";
	cin >> cpu;
	cout << "\nVelocidad:";
	cin >> velocidad;
	cout << endl;
}

void TARJETA::mostrar(){
	cout<<"CPU="<<cpu<<endl<<"Velocidad="
		<<velocidad<<endl;
}
//Diseño de los metodos monitor
void MONITOR::leer(){
	cout<<"-Datos del monitor-"<<endl;
	cout<<"Resolucion:"<<endl;
	cin>>resolucion;
	cout<<"Marca:"<<endl;
	cin>>marca;
}
void MONITOR::mostrar(){
	cout<<"Resolucion="<<resolucion<<endl<<"Marca="
		<<marca<<endl;
}
//Diseño de los metodos computadora
void COMPUTADORA::leer(){
	cout<<"-Datos de la computadora-"<<endl;
	cout<<"Precio:"<<endl;
	cin>>precio;
	TARJETA::leer();
	MONITOR::leer();
}
void COMPUTADORA::mostrar(){
	cout<<"Precio="<<precio<<endl;
	TARJETA::mostrar();
	MONITOR::mostrar();
}
//CUERPO PRINCIPAL
int main(){
	COMPUTADORA unet[15];
	char resp;
	int cc=0;
	do{
		unet[cc].leer();
		cout<<"Otra computadora a procesar?(S/N):";
		cin>>resp;
		resp=toupper(resp);
		cin.get();
		cc++;
	}while(resp=='S'&&cc<15);
	system("cls");
	cout<<"\tListado de computadoras procesadas\n"<<endl;
	for (int p=0;p<cc;p++){
		cout<<"Computadora No."<<p+1<<endl;
		unet[p].mostrar();
		cout<<endl;
	}
	cout<<"Fin del programa"<<endl;
	cin.get();
}
