#include <iostream>
#include <ctype>
#include <conio>

using namespace std;

class UNET{
	public:
		void leer();
		void mostrar();
	private:
		char nombre[12],ci[10],apellido[12];
};

class ESTUDIANTE:public UNET{
	public:
		void leer_e();
		void mostrar_e();
	private:
		float indice;
};

//Diseño de los métodos UNET

void UNET::leer(){
	cout<<"Dar cedula:"<<endl;
	cin>>ci;
	cout<<"Dar nombre:"<<endl;
	cin>>nombre;
	cout<<"Dar apellido:"<<endl;
	cin>>apellido;
}

void UNET::mostrar(){
	cout<<ci<<"\t"<<nombre<<"\t"<<apellido<<"\t\t";
}

//Diseño de los metodos ESTUDIANTE

void ESTUDIANTE::leer_e(){
	leer();
	cout<<"Dar indice:"<<endl;
	cin>>indice;
}

void ESTUDIANTE::mostrar_e(){
	mostrar();
	cout<<indice<<endl;
}

//Cuerpo principal

void main(){
	ESTUDIANTE list[10];
	char resp;
	int ce=0;
	do{
		list[ce].leer_e();
		cout <<"Existe otro estudiante? (S/N):"<<endl;
		cin >> resp;
		resp=toupper(resp);
		ce++;
	}while (resp=='S'&&ce<10);
	clrscr();
	cout<<"\tListado de estudiantes"<<endl;
        cout<<"Cedula\tNombre\tApellido\tIndice"<<endl;
        for (int k=0;k<ce;k++)list[k].mostrar_e();
        cout<<endl;
        getch();
}
