#include <iostream>		//Ejercicio de herencia:
#include <ctype.h>
#include <string.h>

using namespace std;

class UNET{
	public:
		void leer();
		void mostrar();
	private:
		char nombre[12],apellido[12];
	protected:
		char ci[10];
};

class ESTUDIANTE:public UNET{
	public:
		void leer_e();
		void mostrar_e();
		int buscar_e(char [10]);
	private:
		float indice;
};

class EMPLEADO:public UNET{
	public:
		void leer_emp();
		void mostrar_emp();
		int buscar_emp(char [10]);
	private:
		float sueldo;
};

//Diseño de los métodos UNET///////////////////////////////////////////////////////

void UNET::leer(){
	cout<<"Dar cedula:"<<endl;
	cin.getline(ci,10);	
	cout<<"Dar nombre:"<<endl;
	cin>>nombre;
	cout<<"Dar apellido:"<<endl;
	cin>>apellido;
}

void UNET::mostrar(){
	cout<<ci<<"\t"<<nombre<<"\t"<<apellido<<"\t\t";
}

//Diseño de los metodos ESTUDIANTE//////////////////////////////////////////////

void ESTUDIANTE::leer_e(){
	leer();
	cout<<"Dar indice:"<<endl;
	cin>>indice;
}

void ESTUDIANTE::mostrar_e(){
	mostrar();
	cout<<indice<<endl;
}

int ESTUDIANTE::buscar_e(char in[10]){
	if (strcmp(in,ci)==0){
		return 1;
	}else return 0;
}

//Metodos de EMPLEADO///////////////////////////////////////////////////////

void EMPLEADO::leer_emp(){
	leer();
	cout<<"Dar sueldo:"<<endl;
	cin>>sueldo;
}

void EMPLEADO::mostrar_emp(){
	mostrar();
	cout<<sueldo<<endl;
}

int EMPLEADO::buscar_emp(char in[10]){
	if (strcmp(in,ci)==0){
		return 1;
	}else return 0;
}

//Cuerpo principal///////////////////////////////////////////////////////

int main(){
	ESTUDIANTE list[100];
	EMPLEADO list1[100];
	int resp;
	int ce=0,cemp=0,result=0;
	char cibusq[10];
	do{
		do{
		system("cls");
		cout<<"\tMENU"<<endl;
		cout<<"Ingrese:\t1\tPara registrar un estudiante"<<endl
			<<"Ingrese:\t2\tPara registrar un empleado"<<endl
			<<"Ingrese:\t3\tPara buscar un estudiante"<<endl
			<<"Ingrese:\t4\tPara buscar un empleado"<<endl
			<<"Ingrese:\t5\tPara listar los estudiante"<<endl
			<<"Ingrese:\t6\tPara listar los empleado"<<endl
			<<"Ingrese:\t7\tPara salir del programa"<<endl
			<<"RESPUESTA: ";
		cin >> resp;
		cin.sync();
		}while(resp<1||resp>7);	
		if (resp==1){
			list[ce].leer_e();
			ce++;
			cin.get();
		}
		if (resp==2){
			list1[cemp].leer_emp();
			cemp++;
			cin.get();
		}
		if (resp==3){
			result=0;
			cout<<"Ingrese cedula de identidad a buscar: "<<endl;
			cin.getline(cibusq,10);	
			cin.sync();
			while(list[result].buscar_e(cibusq)!=1&&result<ce){
			result++;	
			};
			if (result<ce){
				cout<<"\t[Cedula encontrada, datos del portador]\n" << endl;
				cout<<"Cedula\tNombre\tApellido\tIndice"<<endl;
				list[result].mostrar_e();
			}else{
				cout << "Cedula no encontrada..."<<endl;
			}
		}
		if (resp==4){
			result=0;
			cout<<"Ingrese cedula de identidad a buscar: "<<endl;
			cin.getline(cibusq,10);	
			cin.sync();
			while(list1[result].buscar_emp(cibusq)!=1&&result<cemp){
			result++;	
			};
			if (result<cemp){
				cout<<"\t[Cedula encontrada, datos del portador]\n" << endl;
				cout<<"Cedula\tNombre\tApellido\tSueldo"<<endl;
				list1[result].mostrar_emp();
			}else{
				cout << "Cedula no encontrada..."<<endl;
			}
		}
		if (resp==5){
			cout<<"\tListado de estudiantes"<<endl;
    		cout<<"Cedula\tNombre\tApellido\tIndice"<<endl;
        	for (int k=0;k<ce;k++)list[k].mostrar_e();
        	cout<<endl;       	
		}
		if (resp==6){
			cout<<"\tListado de empleados"<<endl;
    		cout<<"Cedula\tNombre\tApellido\tSueldo"<<endl;
        	for (int k=0;k<ce;k++)list1[k].mostrar_emp();
        	cout<<endl;
        }
		cout<<"\n\nPresione una tecla para continuar...";
    	cin.get(); 
	}while(resp!=7);
	cout<<"\nCerrando programa...\t...\t...";
	cin.get();
}
